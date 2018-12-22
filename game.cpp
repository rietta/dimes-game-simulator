#include <iostream>
#include <array>
#include <random>
using namespace std;

class Player {

    const int STARTING_HAND = 3;

    string name;
    int coins;

    int passToLeft;
    int passToRight;
    int passToPot;

    public:
   
        Player(string name) {
            this->name = name;
            this->coins = STARTING_HAND;
            resetPasses();
        }

        void resetPasses() {
            this->passToLeft = 0;
            this->passToRight = 0;
            this->passToPot = 0;
        }

        int diceValue() {
            return rand()%6 + 1;
        }

        void roll() {
            int value = diceValue();
            if(value == 4) {
                this->passToLeft += 1;
            } else if(value == 5) {
                this->passToRight += 1;
            } else if(value == 6) {
                this->passToPot += 1;
            }
            cout << "Player " << name << " rolls " << value << "\n";
        }

        void play() {
            resetPasses();
            for(int i = 0; i < coins; i++) {
                roll();
            }
        }

        void print() {
            cout << name << " : " << coins << " coins\n";
        }

        int getPassToRight() {
            return passToRight;
        }

        int getPassToLeft() {
            return passToLeft;
        }

        int getPassToPot() {
            return passToPot;
        }

        int getCoins() {
            return coins;
        }

        void add(int coinsToAdd) {
            coins += coinsToAdd;
        }

        void subtract(int coinsToRemove) {
            coins -= coinsToRemove;
        }

        bool playingThisRound() {
            return coins > 0 ? true : false;
        }
};

class Table {

    int coinsInPot = 0;
    int rounds = 0;

     std::array<Player*, 5> players = {
            new Player("Alice"),
            new Player("Bob"),
            new Player("Eve"),
            new Player("George"),
            new Player("Evelyn")
        };

    public:

    Table() {
    }

    int playerCount() {
        return players.size();
    }

    int indexToTheLeft(int idx) {
        int toReturn = idx - 1;
        if(toReturn < 0) {
            toReturn = playerCount() - 1;
        }
        return toReturn;
    }

    int indexToTheRight(int idx) {
        int toReturn = idx + 1;
        if(toReturn > playerCount() - 1) {
            toReturn = 0;
        }
        return toReturn;
    }

    void playRound() {
        for(int i = 0; i < playerCount(); i++) {
            if(players[i]->playingThisRound()) {
        
                players[i]->play();

                int coins = players[i]->getPassToLeft();
                if(coins > 0) {
                    players[indexToTheLeft(i)]->add(coins);
                    players[i]->subtract(coins);
                }

                coins = players[i]->getPassToRight();
                if(coins > 0) {
                    players[indexToTheRight(i)]->add(coins);
                    players[i]->subtract(coins);
                }

                coins = players[i]->getPassToPot();
                if(coins > 0) {
                    coinsInPot += coins;
                    players[i]->subtract(coins);
                }
            } // end if playingThisRound
        } // next i
        rounds += 1;
    } // playRound

    int winner() {
        int winnerCandidateIdx = -1;
        int playersWithCoins = 0;
        for(int i = 0; i < playerCount(); i++) {
            if(players[i]->getCoins() > 0) {
                winnerCandidateIdx = i;
                playersWithCoins += 1;
            } 
        }

        if(playersWithCoins > 1) {
            return -1;
        } else {
            return winnerCandidateIdx;
        }
    }

    void play() {
        int winnerIdx = -1;
        while(winnerIdx < 0) {
            playRound();
            winnerIdx = winner();
        }

        Player* winner = players[winnerIdx];

        cout << "======================================================\n" 
             << "Winner Declared After " << rounds << " rounds!\n"
             << "======================================================\n\n";
        print();
    }

    void print() {
        cout << "Dimes with " << playerCount() << " Players\n\n";
        for(int i = 0; i < playerCount(); i++) {
            cout << "[" << i << "] ";
            players[i]->print();
            cout << "\tPlayer to the Left is " << indexToTheLeft(i) << "\n";
            cout << "\tPlayer to the Right is " << indexToTheRight(i) << "\n";
        }
        cout << "\n\n" << coinsInPot << " coins in the pot.\n";
    }

};

int main() 
{
    // This is not secure, but just to do dice rolls
    srand ( time(NULL) );

    Table* table = new Table();
    table->print();
    table->play();
    return 0;
}
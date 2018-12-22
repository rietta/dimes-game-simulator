# Simulates a Game of Dimes Using Three Dice

This is a simulation of a family game of dimes. The game is as follows.

1. Each player gets a stack of 3 dimes to start the game.
2. If a player has no dimes, he or she is out of play
3. Player rolls a dice for each dime in his hand:
    - For 1-3, player keeps
    - For 4, passes a dime to player to the left
    - For 5, passes a dime to player to the right
    - For 6, passes a dime to the pot in the middle of the table
4. Repeat until only one player has any coins, who is then the winner

## Compiling the Program

`g++ -Wall dimes_game.cpp`

## Running the Program

`time ./a.out`

## Example Output

```
Dimes with 5 Players

[0] Alice : 3 coins
	Player to the Left is 4
	Player to the Right is 1
[1] Bob : 3 coins
	Player to the Left is 0
	Player to the Right is 2
[2] Eve : 3 coins
	Player to the Left is 1
	Player to the Right is 3
[3] George : 3 coins
	Player to the Left is 2
	Player to the Right is 4
[4] Evelyn : 3 coins
	Player to the Left is 3
	Player to the Right is 0


0 coins in the pot.

Starting Round 1
Player Alice rolls 3
Player Alice rolls 1
Player Alice rolls 1
Player Bob rolls 3
Player Bob rolls 6
Player Bob rolls 5
Player Eve rolls 2
Player Eve rolls 4
Player Eve rolls 5
Player George rolls 6
Player George rolls 6
Player George rolls 4
Player Evelyn rolls 3
Player Evelyn rolls 6
Player Evelyn rolls 4

Starting Round 2
Player Alice rolls 3
Player Alice rolls 1
Player Alice rolls 4
Player Bob rolls 3
Player Bob rolls 3
Player Eve rolls 6
Player Eve rolls 4
Player Eve rolls 6
Player George rolls 2
Player George rolls 5
Player Evelyn rolls 4
Player Evelyn rolls 1
Player Evelyn rolls 1

Starting Round 3
Player Alice rolls 4
Player Alice rolls 3
Player Bob rolls 2
Player Bob rolls 6
Player Bob rolls 2
Player George rolls 6
Player George rolls 1
Player Evelyn rolls 5
Player Evelyn rolls 2
Player Evelyn rolls 6

Starting Round 4
Player Alice rolls 2
Player Alice rolls 6
Player Bob rolls 5
Player Bob rolls 1
Player Eve rolls 3
Player George rolls 5
Player Evelyn rolls 4
Player Evelyn rolls 5

Starting Round 5
Player Alice rolls 1
Player Alice rolls 4
Player Bob rolls 6
Player Eve rolls 2
Player George rolls 4
Player Evelyn rolls 5

Starting Round 6
Player Alice rolls 3
Player Alice rolls 3
Player Eve rolls 5
Player Eve rolls 1
Player George rolls 6

Starting Round 7
Player Alice rolls 5
Player Alice rolls 6
Player Bob rolls 2
Player Eve rolls 6
======================================================
Winner Declared After 7 rounds!
Bob
======================================================

Dimes with 5 Players

[0] Alice : 0 coins
	Player to the Left is 4
	Player to the Right is 1
[1] Bob : 1 coins
	Player to the Left is 0
	Player to the Right is 2
[2] Eve : 0 coins
	Player to the Left is 1
	Player to the Right is 3
[3] George : 0 coins
	Player to the Left is 2
	Player to the Right is 4
[4] Evelyn : 0 coins
	Player to the Left is 3
	Player to the Right is 0


14 coins in the pot.

```
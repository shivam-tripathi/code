/*
 * Traditional Minesweeper game
 *
 * Hints to win the game!
 *	1) If you click on the tile with no mine but mines in adjacent 8 cells, you'll have cleared 8
 *  tiles.
 *
 *
 *
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 25
#define MAX_MINES 99
#define MAX_MOVES (MAX_SIZE*MAX_SIZE - MAX_MINES)

enum{
	BEGINNER,
	INTERMEDIATE,
	PRO
};




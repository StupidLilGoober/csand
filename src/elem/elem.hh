#pragma once
#include "../csand.hh"

#define ELEM_NONE 0 // The id for blank space, `nothing`
#define ELEM_SAND 1 // The id for, you guessed it, `sand`
#define ELEM_WALL 2 // The id for `wall`, to be replaced by other elements.

#define GRID_WIDTH 640
#define GRID_HEIGHT 480

struct elem_Sand {
  unsigned id = ELEM_SAND;
  int x = 0;
  int y = 0;
  char flags[16][5] = {"DUST"};
  Color color = YELLOW;
};

/* The function used by dust-like elements, and of course `sand` */
void elem_SandPhysics(int cell[GRID_WIDTH][GRID_HEIGHT], int x, int y) {
  if (cell[x][y + 1] == ELEM_NONE) {
    cell[x][y + 1] = cell[x][y]; // place element below
    cell[x][y] = ELEM_NONE;      // remove current element
  } else if (cell[x - 1][y + 1] == ELEM_NONE) {
    cell[x - 1][y + 1] = cell[x][y];
    cell[x][y] = ELEM_NONE;
  } else if (cell[x + 1][y + 1] == ELEM_NONE) {
    cell[x + 1][y + 1] = cell[x][y];
    cell[x][y] = 0;
  }
}
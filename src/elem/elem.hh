#pragma once
#include "../csand.hh"

#define ELEM_NONE 0   // The id for blank space, `nothing`
#define ELEM_SAND 1   // The id for, you guessed it, `sand`
#define ELEM_WALL 2   // The id for `wall`, to be replaced by other elements.

#define ELEM_SAND_COLOR YELLOW
#define ELEM_NONE_COLOR BLACK
#define ELEM_WALL_COLOR GRAY

#define GRID_WIDTH 620
#define GRID_HEIGHT 360

int elem_CurrentElem = ELEM_SAND;

/* The function used by dust-like elements, and of course `sand` */
void elem_SandPhysics(int cell[GRID_WIDTH][GRID_HEIGHT], int x, int y) {\
  // ensure that the sand doesn't fall off screen
  if ((y + 1) == GRID_HEIGHT) {
    return;
  }
  // main logic
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
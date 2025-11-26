#pragma once
#include "../csand.hh"
#include "../elem/elem.hh"

#define GRID_WIDTH 640
#define GRID_HEIGHT 480
#define GRID_CELL_PX_SIZE 15

typedef struct grid_Grid {
  int cell[GRID_WIDTH][GRID_HEIGHT]; // The grid itself. Represented using `cell[x][y]` for simplicity.

  void setup() {
    for (int x = 0; x < GRID_WIDTH; x++) {
      for (int y = 0; y < GRID_HEIGHT; y++) {
        cell[x][y] = ELEM_NONE;
      }
    }
  };

  void draw() {
    for (int x = 0; x < GRID_WIDTH; x++) {
      for (int y = 0; y < GRID_HEIGHT; y++) {
        DrawRectangle(GRID_CELL_PX_SIZE * x, GRID_CELL_PX_SIZE * y, GRID_CELL_PX_SIZE, GRID_CELL_PX_SIZE, get_color(cell[x][y]));
      }
    }
  };

  Color get_color(int ELEM_TYPE) {
    switch(ELEM_TYPE) {
      case(ELEM_NONE):
        return ELEM_NONE_COLOR;
      case(ELEM_SAND):
        return ELEM_SAND_COLOR;
      case(ELEM_WALL):
        return ELEM_WALL_COLOR;
    }
  };
} grid_Grid;
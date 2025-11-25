#include "csand.hh"

int main() {
  InitWindow(1240, 720, "csand");

  grid_Grid *grid = new grid_Grid;
  grid->cell[0][0] = ELEM_SAND;

  while (WindowShouldClose() == false) {
    ClearBackground(BLACK);
    BeginDrawing();
      grid->draw();
    EndDrawing();
  }

  delete grid;

  CloseWindow();
  return 0;
}
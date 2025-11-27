#include "csand.hh"

void HandleTools(Vector2 MousePos, int cell[GRID_WIDTH][GRID_HEIGHT]) {
  if (!IsCursorOnScreen) {
    return;
  }

  if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
    tool_UseTool((int)MousePos.x / GRID_CELL_PX_SIZE, (int)MousePos.y / GRID_CELL_PX_SIZE, cell);
  } else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
    tool_UseErase((int)MousePos.x / GRID_CELL_PX_SIZE, (int)MousePos.y / GRID_CELL_PX_SIZE, cell);
  }

  if (IsKeyPressed(KEY_ONE)) {
    elem_CurrentElem = ELEM_SAND;
  } else if (IsKeyPressed(KEY_ONE)) {
    elem_CurrentElem = ELEM_WALL;
  }
}

int main() {
  InitWindow(1240, 720, "csand");
  SetTargetFPS(100); // ticks per second

  Image logo = LoadImage("assets/logo.png");
  SetWindowIcon(logo);
  UnloadImage(logo);

  grid_Grid *grid = new grid_Grid;
  grid->setup();

  while (WindowShouldClose() == false) {
    ClearBackground(BLACK);
    grid->update();

    BeginDrawing();
      grid->draw();
    EndDrawing();

    // input
    Vector2 MousePos = GetMousePosition();
    HandleTools(MousePos, grid->cell);

    std::cout << GetFPS() << " t/s" << std::endl;
  }

  delete grid; 

  CloseWindow();
  return 0;
}
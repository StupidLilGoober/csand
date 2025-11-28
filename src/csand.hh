#pragma once
#include <stdio.h>
#include <iostream>
#include <raylib.h>
#include <stdlib.h>

#include "grid/grid.hh"
#include "tools/tool.hh"

float ScaleSize = 0.0f;

float GetScaleSize() {
  return (720.0f / (float)GetMonitorHeight(GetCurrentMonitor()));
}
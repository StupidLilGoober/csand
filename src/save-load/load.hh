#pragma once
#include "../csand.hh"
#include "string"
#include "iostream"
#include "fstream"

using namespace std;

int LoadGame(string name) {
  string file_path = "assets/data/saves/" + name;
  ifstream data(file_path);
  string text;
  data >> text;

  return 0;
}
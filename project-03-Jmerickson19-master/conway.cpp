// Joshua Erickson (CPSC-03)
#include <chrono>
#include <ctime>
#include <curses.h>
#include <iostream>
#include <stdlib.h>
#include <thread>
using namespace std;

const int ROWS = 48;
const int COLUMNS = 160;
const char ALIVE = '@';
const char DEAD = ' ';
const int NGHBRMAX = 3;
const int NGHBRMIN = 2;

void InitializeCurses() {
  initscr();
  cbreak();
  noecho();
  clear();
}

void PrintExitInstructions() {
  mvaddstr(ROWS + 1, 0, "Press ctrl+c to quit ");
  refresh();
}

void PrintRow(string row_to_print, int row) {
  mvaddstr(row, 0, row_to_print.c_str());
  refresh();
}

int FindNeighborCount(char universe[ROWS][COLUMNS], int row, int col) {
  int neighbors_count = 0;
  int rowcheck;
  int columncheck;
  for (int r = row - 1; r <= row + 1; r++) {
    for (int c = col - 1; c <= col + 1; c++) {
      if (!(r == row && c == col)) {
        if (r < 0) {
          rowcheck = r + ROWS;
        }
        else if (r >= ROWS) {
          rowcheck = r - ROWS;
        }
        else {
          rowcheck = r;
        }

        if (c < 0) {
          columncheck = c + COLUMNS;
        }
        else if (c >= COLUMNS) {
          columncheck = c - COLUMNS;
        }
        else {
          columncheck = c;
        }

        if (universe[rowcheck][columncheck] == ALIVE) {
          neighbors_count++;
        }
      }
    }
  }
  return neighbors_count;
}

void CopyUniverse(char fromuniverse[ROWS][COLUMNS],
                  char touniverse[ROWS][COLUMNS]) {
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLUMNS; c++) {
      touniverse[r][c] = fromuniverse[r][c];
    }
  }
}

void NextGeneration(char universe[ROWS][COLUMNS]) {
  char nextgen[ROWS][COLUMNS];
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLUMNS; c++) {
      int alive_neighbors = FindNeighborCount(universe, r, c);
      if (universe[r][c] == ALIVE) {
        if (alive_neighbors < NGHBRMIN) {
          nextgen[r][c] = DEAD;
        }
        else if (alive_neighbors >= NGHBRMIN && alive_neighbors <= NGHBRMAX) {
          nextgen[r][c] = universe[r][c];
        }
        else {
          nextgen[r][c] = DEAD;
        }
      }
      else {
        if (alive_neighbors == NGHBRMAX) {
          nextgen[r][c] = ALIVE;
        }
        else {
          nextgen[r][c] = universe[r][c];
        }
      }
    }
  }
  CopyUniverse(nextgen, universe);
}

void Print(char universe[ROWS][COLUMNS]) {
  string rowstr;
  for (int r = 0; r < ROWS; r++) {
    rowstr = "";
    for (int c = 0; c < COLUMNS; c++) {
      rowstr += universe[r][c];
    }
    PrintRow(rowstr, r);
  }
}

void InitializeUniverse(char universe[ROWS][COLUMNS]) {
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLUMNS; c++) {
      universe[r][c] = DEAD;
    }
  }
}

int main(int argc, char* argv[]) {

  char universe[ROWS][COLUMNS];

  if (argc == 1 || argc > 2) {
    cout << "Usage: ./game_of_life <desired shape>\n";
    cout << "Shape Options: <Glider> <Blinker> <Tub> <Pentadecathlon>\n";
    return 0;
  }

  InitializeUniverse(universe);
  string shape_option = argv[1];
  if (shape_option == "Glider") {
    universe[24][80] = ALIVE;
    universe[24][81] = ALIVE;
    universe[24][82] = ALIVE;
    universe[25][80] = ALIVE;
    universe[26][81] = ALIVE;
  }
  else if (shape_option == "Blinker") {
    universe[24][79] = ALIVE;
    universe[24][80] = ALIVE;
    universe[24][81] = ALIVE;
  }
  else if (shape_option == "Tub") {
    universe[24][80] = ALIVE;
    universe[25][79] = ALIVE;
    universe[25][81] = ALIVE;
    universe[26][80] = ALIVE;
  }
  else if (shape_option == "Pentadecathlon") {
    universe[19][80] = ALIVE;
    universe[20][80] = ALIVE;
    universe[21][79] = ALIVE;
    universe[21][81] = ALIVE;
    universe[22][80] = ALIVE;
    universe[23][80] = ALIVE;
    universe[24][80] = ALIVE;
    universe[25][80] = ALIVE;
    universe[26][79] = ALIVE;
    universe[26][81] = ALIVE;
    universe[27][80] = ALIVE;
    universe[28][80] = ALIVE;
  }

  InitializeCurses();
  PrintExitInstructions();
  Print(universe);
  while (true) {
    this_thread::sleep_for(chrono::milliseconds(250));
    NextGeneration(universe);
    Print(universe);
  }
  endwin();
  return 0;
}

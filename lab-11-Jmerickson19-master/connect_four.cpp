// Joshua Erickson (CPSC-03)

#include <iostream>
#include <ctime>

using namespace std;

const int ROWS = 6;
const int COLUMNS = 7;
const char BLANK = ' ';
const char PLAYER = 'X';
const char COMPUTER = 'O';
const string PLR_WIN = "The Player is a Connect Four champion!\n";
const string CPU_WIN = "The Computer is a Connect Four champion!\n";
const string DRAW = "The game ends in a draw!\n";
const string CONTINUE = "The game isn't over yet!\n";

void Print(char board[ROWS][COLUMNS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      if (j < COLUMNS) {
        cout << "|";
      }
      cout << board[i][j];
    }
    cout << "|";
    cout << endl;
  }
}

void SetPlayerMove(char board[ROWS][COLUMNS]) {
  int select_column;
  bool selection_valid = false;
  while (!selection_valid) {
    cout << "Select the column you would like to drop your piece into. (0-6)\n";
    cin >> select_column;
    if (select_column >= 0 && select_column < COLUMNS) {
      for (int r = ROWS - 1; r >= 0; r--) {
        if (board[r][select_column] == BLANK) {
          selection_valid = true;
          board[r][select_column] = PLAYER;
          break;
        }
      }
    }
    if (!selection_valid) {
      cout << "Invalid selection.\n";
    }
  }
}

void SetComputerMove(char board[ROWS][COLUMNS]) {
  srand(time(0));
  int select_column;
  bool selection_valid = false;
  while (!selection_valid) {
    select_column = rand() % 7;
    if (select_column >= 0 && select_column < COLUMNS) {
      for (int r = ROWS - 1; r >= 0; r--) {
        if (board[r][select_column] == BLANK) {
          selection_valid = true;
          board[r][select_column] = COMPUTER;
          break;
        }
      }
    }
  }
}

bool CheckRows(char board[ROWS][COLUMNS], char piece) {
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLUMNS - 3; c++) {
      if (board[r][c] == piece &&
          board[r][c + 1] == piece &&
          board[r][c + 2] == piece &&
          board[r][c + 3] == piece) {
        return true;
      }
    }
  }
  return false;
}

bool CheckColumns(char board[ROWS][COLUMNS], char piece) {
  for (int c = 0; c < COLUMNS; c++) {
    for (int r = ROWS - 1; r >= 3; r--) {
      if (board[r][c] == piece &&
          board[r - 1][c] == piece &&
          board[r - 2][c] == piece &&
          board[r - 3][c] == piece) {
        return true;
      }
    }
  }
  return false;
}

bool CheckDiagonals(char board[ROWS][COLUMNS], char piece) {
  for (int r = ROWS - 1; r > ROWS - 4; r--) {
    for (int c = 0; c < COLUMNS - 3; c++) {
      if (board[r][c] == piece &&
          board[r - 1][c + 1] == piece &&
          board[r - 2][c + 2] == piece &&
          board[r - 3][c + 3] == piece) {
        return true;
      }
    }
  }
  for (int r = ROWS - 1; r > ROWS - 4; r--) {
    for (int c = 3; c < COLUMNS; c++) {
      if (board[r][c] == piece &&
          board[r - 1][c - 1] == piece &&
          board[r - 2][c - 2] == piece &&
          board[r - 3][c - 3] == piece) {
        return true;
      }
    }
  }
  return false;
}

bool IsWinner(char board[ROWS][COLUMNS], char piece) {
  return CheckRows(board, piece) ||
         CheckColumns(board, piece) ||
         CheckDiagonals(board, piece);
}

bool IsBoardFull(char board[ROWS][COLUMNS]) {
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLUMNS; c++) {
      if (board[r][c] == BLANK) {
        return false;
      }
    }
  }
  return true;
}

string DetermineBoardState(char board[ROWS][COLUMNS]) {
  if (IsWinner(board, PLAYER)) {
    return PLR_WIN;
  }
  else if (IsWinner(board, COMPUTER)) {
    return CPU_WIN;
  }
  else if (IsBoardFull(board)){
    return DRAW;
  }
  return CONTINUE;
}

int main(int argc, char* argv[]) {

  char board[ROWS][COLUMNS] = {
    {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
    {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
    {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
    {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
    {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK},
    {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK} };

  Print(board);
  bool winner_found = false;
  char participant = PLAYER;

  do {
    if (participant == PLAYER) {
      cout << "Player's turn!\n";
      SetPlayerMove(board);
      Print(board);
      cout << endl;
      winner_found = IsWinner(board, participant);
      cout << DetermineBoardState(board);
      participant = COMPUTER;
    }
    else {
      cout << "Computer's turn!\n";
      SetComputerMove(board);
      Print(board);
      cout << endl;
      winner_found = IsWinner(board, participant);
      cout << DetermineBoardState(board);
      participant = PLAYER;
    }
  } while ((winner_found == false) && IsBoardFull(board) == false);
  return 0;
}

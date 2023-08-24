// Joshua Erickson (CPSC-03)

#include <iostream>
#include <ctime>

using namespace std;

const int ROWS = 3;
const int COLUMNS = 3;
const char BLANK = ' ';
const char PLAYER = 'x';
const char COMPUTER = 'o';
const string PLR_WIN = "The Player is the tic-tac-toe champion!\n";
const string CPU_WIN = "The Computer is the tic-tac-toe champion!\n";
const string DRAW = "The game is a draw!\n";
const string CONTINUE = "The game isn't over yet!\n";

void Print(char board[ROWS][COLUMNS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      cout << board[i][j];
      if (j < COLUMNS - 1) {
        cout << "|";
      }
    }
    cout << endl;
    if (i < ROWS - 1) {
      cout << "-+-+-" << endl;
    }
  }
}

void SetPlayerMove(char board[ROWS][COLUMNS]) {
  int select_row;
  int select_column;
  bool selection_valid = false;
  while (!selection_valid) {
    cout << "Enter the row you would like. (0-2)\n";
    cin >> select_row;
    cout << "Enter the column you would like. (0-2)\n";
    cin >> select_column;

    if (board[select_row][select_column] == BLANK) {
      selection_valid = true;
      board[select_row][select_column] = PLAYER;
    }
    else {
      cout << "Invalid selection.\n";
    }
  }
}

void SetComputerMove(char board[ROWS][COLUMNS]) {
  srand(time(0));
  int select_row;
  int select_column;
  bool selection_valid = false;
  while (!selection_valid) {
    select_row = rand() % 3;
    select_column = rand() % 3;
    if (board[select_row][select_column] == BLANK) {
      selection_valid = true;
      board[select_row][select_column] = COMPUTER;
      cout << "Computer selected:" << "("
           << select_row << "," << select_column << ")" << endl;
    }
  }
}

bool CheckRows(char board[ROWS][COLUMNS], char piece) {
  for (int r = 0; r < ROWS; r++) {
    if (board[r][0] == piece &&
        board[r][1] == piece &&
        board[r][2] == piece) {
      return true;
    }
  }
  return false;
}

bool CheckColumns(char board[ROWS][COLUMNS], char piece) {
  for (int c = 0; c < COLUMNS; c++) {
    if (board[0][c] == piece &&
        board[1][c] == piece &&
        board[2][c] == piece) {
      return true;
    }
  }
  return false;
}

bool CheckDiagonals(char board[ROWS][COLUMNS], char piece) {
  if (board[0][0] == piece &&
      board[1][1] == piece &&
      board[2][2] == piece) {
    return true;
  }
  else if (board[0][2] == piece &&
           board[1][1] == piece &&
           board[2][0] == piece) {
    return true;
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
    {BLANK, BLANK, BLANK},
    {BLANK, BLANK, BLANK},
    {BLANK, BLANK, BLANK} };

  Print(board);

  bool winner_found = false;
  char participant = PLAYER;

  do {
    if (participant == PLAYER) {
      SetPlayerMove(board);
      Print(board);
      winner_found = IsWinner(board, participant);
      participant = COMPUTER;
    }
    else {
      SetComputerMove(board);
      Print(board);
      winner_found = IsWinner(board, participant);
      participant = PLAYER;
    }
  } while ((winner_found == false) && IsBoardFull(board) == false);
  cout << DetermineBoardState(board);
  return 0;
}

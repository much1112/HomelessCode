#include <iostream>

using namespace std;

enum player {EMPTY=0, playerO=1, playerX=2};

void visualizeBoard(int gameBoard[3][3]) {
  cout << endl;
  for (int boardRow=0;boardRow<3;boardRow++) {
    for (int boardCol=0;boardCol<3;boardCol++) {
        if (gameBoard[boardRow][boardCol] == EMPTY) {
          cout << "- ";
        } else if (gameBoard[boardRow][boardCol] == playerO) {
          cout << "O ";
        } else if (gameBoard[boardRow][boardCol] == playerX) {
          cout << "X ";
        }
    }
    cout << endl;
  }
  cout << endl;
}

bool didPlayerWin(int gameBoard[3][3], player currentPlayer) {
  for (int boardRow=0;boardRow<3;boardRow++) {
      if (gameBoard[boardRow][0]==currentPlayer && gameBoard[boardRow][1]==currentPlayer && gameBoard[boardRow][2]==currentPlayer) {
        return true;
      }
      if (gameBoard[0][boardRow]==currentPlayer && gameBoard[1][boardRow]==currentPlayer && gameBoard[2][boardRow]==currentPlayer) {
        return true;
      }
  }

  if (gameBoard[0][0]==currentPlayer && gameBoard[1][1]==currentPlayer && gameBoard[2][2]==currentPlayer) return true;
  if (gameBoard[0][2]==currentPlayer && gameBoard[1][1]==currentPlayer && gameBoard[2][0]==currentPlayer) return true;

  return false;
}

int whoWin(int gameBoard[3][3]) {
  if (didPlayerWin(gameBoard,playerO)) 
    return playerO;
  if (didPlayerWin(gameBoard,playerX))
    return playerX;
  return EMPTY;
}

bool isValidInput(int gameBoard[3][3], int rowInput, int colInput) {
  return rowInput >= 1 && rowInput <= 3 && colInput >= 1 && colInput <= 3 && gameBoard[rowInput - 1][colInput - 1] == EMPTY;
}

int main() {

  int gameBoard[3][3]= {{EMPTY,EMPTY,EMPTY},
                        {EMPTY,EMPTY,EMPTY},
                        {EMPTY,EMPTY,EMPTY}};
  
  bool isOturn = true;

  while (true) {
    int gameResult = whoWin(gameBoard);
    if (gameResult != EMPTY) {
      cout << (gameResult == playerO ? "O wins!": "X wins!");
      break;
    }
    
    int rowInput,colInput;
    cout << (isOturn ? "O" : "X") << " player's turn (Please enter a valid empty place (row and column 1-3): ";
    cin >> rowInput >> colInput;

    if (!isValidInput(gameBoard, rowInput, colInput)) {
      continue;
    }

    gameBoard[rowInput - 1][colInput - 1] = (isOturn ? playerO : playerX);
    visualizeBoard(gameBoard);
    isOturn = !isOturn;
  }
  return 0;
}
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;

int main() {
  srand (time(NULL));
  string input;
  int score = 0;
  cout << "Simple Minesweeper\n";

  const int i = 6;
  const int j = 6;
  char board[i][j] = {
    {'0','0','0','0','0','0'},
    {'0','0','0','0','0','0'},
    {'0','0','0','0','0','0'},
    {'0','0','0','0','0','0'},
    {'0','0','0','0','0','0'},
    {'0','0','0','0','0','0'}
  };

  char displayboard[i][j] = {
    {'#','#','#','#','#','#'},
    {'#','#','#','#','#','#'},
    {'#','#','#','#','#','#'},
    {'#','#','#','#','#','#'},
    {'#','#','#','#','#','#'},
    {'#','#','#','#','#','#'}
  };

  cout << "Increase your score by guessing which squares don't have the mines!" << endl;

  //Generating where mines will be and determining values of spaces with mines close by
  for(int m = 0; m <= 5; m++) {
    int randomx = rand() % 6;
    int randomy = rand() % 6;
    if(board[randomx][randomy] == '*') {
      m--;
    }
    else {
      board[randomx][randomy] = '*';

      if(randomx-1 >= 0 && randomy-1  >= 0 && board[randomx-1][randomy-1] != '*') {
        int newVal = (int)board[randomx-1][randomy-1];
        newVal += 1;
        char ch = (char)newVal;
        board[randomx-1][randomy-1] = ch;
      }
      if(randomx-1 >= 0 && randomy+1 <= 5 && board[randomx-1][randomy+1] != '*') {
        int newVal = (int)board[randomx-1][randomy+1];
        newVal += 1;
        char ch = (char)newVal;
        board[randomx-1][randomy+1] = ch;
      }
      if(randomx+1 <= 5 && randomy-1 >= 0 && board[randomx+1][randomy-1] != '*') {
        int newVal = (int)board[randomx+1][randomy-1];
        newVal += 1;
        char ch = (char)newVal;
        board[randomx+1][randomy-1] = ch;
      }
      if(randomx+1 <= 5 && randomy+1 <= 5 && board[randomx+1][randomy+1] != '*') {
        int newVal = (int)board[randomx+1][randomy+1];
        newVal += 1;
        char ch = (char)newVal;
        board[randomx+1][randomy+1] = ch;
      }
      if(randomy-1 >= 0 && board[randomx][randomy-1] != '*') {
        int newVal = (int)board[randomx][randomy-1];
        newVal += 1;
        char ch = (char)newVal;
        board[randomx][randomy-1] = ch;
      }
      if(randomy+1 <= 5 && board[randomx][randomy+1] != '*') {
        int newVal = (int)board[randomx][randomy+1];
        newVal += 1;
        char ch = (char)newVal;
        board[randomx][randomy+1] = ch;
      }
      if(randomx-1 >= 0 && board[randomx-1][randomy] != '*') {
        int newVal = (int)board[randomx-1][randomy];
        newVal += 1;
        char ch = (char)newVal;
        board[randomx-1][randomy] = ch;
      }
      if(randomx+1 <= 5 && board[randomx+1][randomy] != '*') {
        int newVal = (int)board[randomx+1][randomy];
        newVal += 1;
        char ch = (char)newVal;
        board[randomx+1][randomy] = ch;
      }
    }
  }

  //Uncomment code to see board with mines before guessing
  /*for (int k = 0; k < 6; k++) {
    for (int l = 0; l < 6; l++) {
      cout << board[k][l];
      cout << " ";
    }
    cout << endl;
  }*/

  //Displaying empty board
  for (int k = 0; k < 6; k++) {
    for (int l = 0; l < 6; l++) {
      cout << displayboard[k][l];
      cout << " ";
    }
    cout << endl;
  }
  //The game and different possible outcomes
  for(int c = 0; c < 30; c++) {
    int a;
    int b;
    cout << "Guess a row.";
    cin >> a;
    cout << "Guess a column.";
    cin >> b;
    if(cin.fail()) {
      cout << "";
      cout << "Invalid input. Try again." << endl;
      cin.clear();
      cin.ignore();
      c--;
      continue;
    }
    else if(a<1 || a>6 || b< 1 || b>6)  {
      cout << "";
      cout << "Invalid input. Try again." << endl;
      c--;
      continue;
    }

    else if(board[a-1][b-1] == '*') {
      cout << "Game over!" << endl;
      cout << "Your Score: " << score;
      return 0;
    }

    else if(displayboard[a-1][b-1] != '#') {
      cout << "You already guessed that! Try again." << endl;
      c--;
      continue;
    }

    else if(board[a-1][b-1] != '#' && board[a-1][b-1] != '*') {
      score += 1;
    }
    else {
      score += 1;
    }

    for (int k = 0; k < 6; k++) {
      for (int l = 0; l < 6; l++) {
        if(k == a-1 && l == b-1) {
          cout << board[a-1][b-1];
          displayboard[k][l] = board[a-1][b-1];
        }
        else {
          cout << displayboard[k][l];
        }
        cout << " ";
      }
      cout << endl;
    }
  }
  cout << "Your Score: " << score << endl;
  cout << "You win!!!" << endl;
}


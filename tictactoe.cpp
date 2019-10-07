#include <iostream>
/*Written by Gregory Feng
Last edited 10/7/19
TicTacToe program created to play a tictactoe game.
In a 3 by 3 board 2 players alternate turns to see who can get 3 in a row first.
 */
using namespace std;

int main() {
  
  char board[4][4]={{' ','a','b','c'},{'1',' ',' ',' '},{'2',' ',' ',' '},{'3',' ',' ',' '}}; //Board initializations
  char numerical;
  int numerical1;
  char alphabetical;
  int a2n;
  char whoseturn;
  int xwins = 0;
  int owins = 0;
  int tiecount = 0;
  bool turnredo = false;
  bool endgame = false;

  cout << "Welcome to 2 player Tic Tac Toe!" << endl;
  cout << "Player 1 will have the designated marker X, and player 2 will have O!" << endl;
  whoseturn = 'X'; //Start as X
  while(endgame == false) { //Keep the game going until someone wins
    
    if (((board[1][1] == 'X') && (board[1][2] == 'X') && (board[1][3] == 'X')) || //X's wins conditions
        ((board[2][1] == 'X') && (board[2][2] == 'X') && (board[2][3] == 'X')) ||
	((board[3][1] == 'X') && (board[3][2] == 'X') && (board[3][3] == 'X')) ||
	((board[1][1] == 'X') && (board[2][1] == 'X') && (board[3][1] == 'X')) ||
	((board[1][2] == 'X') && (board[2][2] == 'X') && (board[3][2] == 'X')) ||
	((board[1][3] == 'X') && (board[2][3] == 'X') && (board[3][3] == 'X')) ||
	((board[3][1] == 'X') && (board[2][2] == 'X') && (board[1][3] == 'X')) ||
	((board[3][3] == 'X') && (board[2][2] == 'X') && (board[1][1] == 'X')))
    {
	endgame = true;
	cout << "X wins!" << endl;
	xwins++; //Wincount
	cout << "X has " << xwins << " wins and O has " << owins << " wins and there have been " << tiecount << " ties." << endl;
	board[1][1] = ' '; //Board reset
	board[1][2] = ' ';
	board[1][3] = ' ';
	board[2][1] = ' ';
	board[2][2] = ' ';
	board[2][3] = ' ';
	board[3][1] = ' ';
	board[3][2] = ' ';
	board[3][3] = ' ';
	
	break; //Exit the loop if someone wins
    }
    
    else if (((board[1][1] == 'O') && (board[1][2] == 'O') && (board[1][3] == 'O')) || //O win condition
        ((board[2][1] == 'O') && (board[2][2] == 'O') && (board[2][3] == 'O')) ||
	((board[3][1] == 'O') && (board[3][2] == 'O') && (board[3][3] == 'O')) ||
	((board[1][1] == 'O') && (board[2][1] == 'O') && (board[3][1] == 'O')) ||
	((board[1][2] == 'O') && (board[2][2] == 'O') && (board[3][2] == 'O')) ||
	((board[1][3] == 'O') && (board[2][3] == 'O') && (board[3][3] == 'O')) ||
	((board[3][1] == 'O') && (board[2][2] == 'O') && (board[1][3] == 'O')) ||
	((board[3][3] == 'O') && (board[2][2] == 'O') && (board[1][1] == 'O')))
    {
	endgame = true;
	cout << "O wins!" << endl;
	owins++; //Wincount
	cout << "X has " << xwins << " wins and O has " << owins << " wins and there have been " << tiecount << " ties." << endl;
	board[1][1] = ' '; //Board reset
	board[1][2] = ' ';
	board[1][3] = ' ';
	board[2][1] = ' ';
	board[2][2] = ' ';
	board[2][3] = ' ';
	board[3][1] = ' ';
	board[3][2] = ' ';
	board[3][3] = ' ';
	break;
    }
    else if ((!(board[1][1] == ' ')) && (!(board[1][2] == ' ')) && (!(board[1][3] == ' ')) && //Tie condition
	     (!(board[2][2] == ' ')) && (!(board[2][1] == ' ')) && (!(board[2][3] == ' ')) &&
	     (!(board[3][1] == ' ')) && (!(board[3][2] == ' ')) && (!(board[3][3] == ' '))) {
      tiecount++; //Tie count
	       cout << "It was a tie!" << endl;
	       cout << "X has " << xwins << " and O has " << owins << " wins and there have been " << tiecount << " ties." << endl;
	       break;
    }
    cout << whoseturn << "'s turn" << endl;
    cout << "Please input the alphabetical location of where you want to go!" << endl;
    cin >> alphabetical; //Takes in alphabetical input
    if (alphabetical == 'a') {
      a2n = 1;
    } else if (alphabetical == 'b') {
      a2n = 2;
    } else if (alphabetical == 'c') {
      a2n = 3;
    }
    cout << "Please input the numerical location of where you want to go!" << endl;
    cin >> numerical; //Takes in numerical input
    if (numerical == '1') {
      numerical1 = 1;
    } else if (numerical == '2') {
      numerical1 = 2;
    } else if (numerical == '3') {
      numerical1 = 3;
    }
    
    if (!(board[numerical1][a2n] == ' ')) { //Checks if something is already there or if it is an existing move
      cout << "Invalid move!" << endl;
      turnredo = true;
    }

    if (turnredo == false) { //Marking
    if (alphabetical == 'a') {
       if (numerical == '1') {
	 if ((board[1][1] == ' ')) {
	     board[1][1] = whoseturn;
	   }
       } else if (numerical == '2') {
	 if ((board[2][1] == ' ')) {
	   board[2][1] = whoseturn;
	 }
       } else if (numerical == '3') {
	 if ((board[3][1] == ' ')) {
	   board[3][1] = whoseturn;
	 }
      }

       
     } else if (alphabetical == 'b') {
       if (numerical == '1') {
	 if ((board[1][2] == ' ')) {
	     board[1][2] = whoseturn;
	   }
       } else if (numerical == '2') {
	 if ((board[2][2] == ' ')) {
	   board[2][2] = whoseturn;
	 }
       } else if (numerical == '3') {
	 if ((board[3][2] == ' ')) {
	   board[3][2] = whoseturn;
	 }
      }

       
     } else if (alphabetical == 'c') {
      if (numerical == '1') {
	if ((board[1][3] == ' ')) {
	    board[1][3] = whoseturn;
	  }
       } else if (numerical == '2') {
	    if ((board[2][3] == ' ')) {
	      board[2][3] = whoseturn;
	    }
       } else if (numerical == '3') {
	    if ((board[3][3] == ' ')) {
	    board[3][3] = whoseturn;
	    }
      } } }
    cout << "-----------------------------------------------------------------------------" << endl; //Boardprinting
  cout << "TicTacToe Board:" << endl;
  cout << board[0][0] << " " << board[0][1] << " " << board[0][2] << " " << board[0][3] << endl;
  cout << board[1][0] << " " << board[1][1] << " " << board[1][2] << " " << board[1][3] << endl;
  cout << board[2][0] << " " << board[2][1] << " " << board[2][2] << " " << board[2][3] << endl;
  cout << board[3][0] << " " << board[3][1] << " " << board[3][2] << " " << board[3][3] << endl;
cout << "-----------------------------------------------------------------------------" << endl;
 if (turnredo == false) { //If no invalid move was detected, switch turns
   if (whoseturn == 'X') {
     whoseturn = 'O'; }
   else if (whoseturn == 'O') {
     whoseturn = 'X'; 
     }
 } else { //If an invalid move was detected, you don't switch turns and don't mark the invalid input.
   turnredo = false;
 }
   
 }
   
}

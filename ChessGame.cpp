#include<iostream>
#include<string>

void start();

void Dispboard(char board[][8], int row);                                              //For Displaying Board

void PossibleMoves(char, char board[][8], int row);                                    //For showing Possible Moves

void King(char board[][8], int row);                                                   //For showing Possible Moves of King

void Queen(char board[][8], int row);                                                  //For showing Possible Moves of Queen

void RookR(char board[][8], int row);                                                  //For showing Possible Moves of Right Rook

void RookL(char board[][8], int row);                                                  //For showing Possible Moves of Left Rook

void BishopR(char board[][8], int row);                                                //For showing Possible Moves of Right Bishop

void BishopL(char board[][8], int row);                                                //For showing Possible Moves of Left Bishop

void KnightR(char board[][8], int row);                                                //For showing Possible Moves of Right Knight

void KnightL(char board[][8], int row);                                                //For showing Possible Moves of Left Knight

void Move(char board[][8], int row, char a, int b, char x);                            //For Next Move

using namespace std;


int main()
{
	start();                                                                            //main calls start function
}


void start()
{
	
	


	const int row = 8;                                                
	const int col = 8;                                                                  //chessboard made

	char board[row][col]= { {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}, {'-','-','-','-','-','-','-','-'}, {'-','-','-','-','-','-','-','-'},  {'-','-','-','-','-','-','-','-'},  {'-','-','-','-','-','-','-','-'},  {'-','-','-','-','-','-','-','-'}, {'-','-','-','-','-','-','-','-'}, {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'} };   //board initialised
	 
	Dispboard(board, row);                                                              //board displayed through function

	char x;                                                                   
	char a;                                                                             //for next move character
	int	b;                                                                              //for next move integer  e.g E7

	cout << "Enter the piece that you want to move:";
	cin >> x;                                                                           //for moving desired piece
	cout << endl;

	PossibleMoves(x, board, row);                                                       //Possible moves shown

	cout << "Where do you want to move the piece:";
	cout << endl;
	cin >> a >> b;                                                                      //Input taken for next moves

	Move(board, row, a, b, x);

	
}


void Dispboard(char board[][8], int row)
{
	cout << "   a b c d e f g h" << endl;                                                 //displaying grid
	cout << "   _______________" << endl;

	for (int i = 0; i < row; i++)
	{
		cout << i+1 << "| ";

		for (int j = 0; j < 8; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "|" << i + 1 << endl;                                                     //displaying board
	} 

	cout << "   ---------------" << endl;
	cout << "   a b c d e f g h" << endl << endl;
}

void PossibleMoves(char x, char board[][8], int row)                                      //showing possible moves           
{
	switch (x)
	{
	 case 'K': King(board, row);                                                          //possible moves of king
		 break;

	 case 'Q': Queen(board, row);                                                        // possible moves of Queen
		 break;

	 case 'R':
	 {
		char p;
		cout << "Select Rook (R or L):" << endl;
		cin >> p;
		if (p == 'R')
		{
			RookR(board, row);
		}

		else
		{
			RookL(board, row);
		}

	 }
	 break;

	 case 'B': 
	 {
		 char p;
		 cout << "Select Bishop (R or L):" << endl;
		 cin >> p;
		 if (p == 'R')
		 {
			 BishopR(board, row);
		 }

		 else
		 {
			 BishopL(board, row);
		 }

	 }
	 break;

	 case 'N':
	 {
		 char p;
		 cout << "Select Bishop (R or L):" << endl;
		 cin >> p;
		 if (p == 'R')
		 {
			 KnightR(board, row);
		 }

		 else
		 {
			 KnightL(board, row);
		 }
	 }
	 break;

	 default: cout << "Invalid Option" << endl;
		 break;
	}
}

void King(char board[][8], int row)
{
	//board[6][4] = 'X';
	//board[6][3] = 'X';
	//board[6][5] = 'X';

	int tempi;                                                                          
	int tempj;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == 'K' && i > 4)
			{
				tempi = i;
				tempj = j;                                                                 // to find indexes of K
			}
		}
	}

	//board[3][4] = 'P';
	
	if (board[tempi][tempj - 1] == '-')                                                  // Possible moves checked, if they have no piece on them and
	{                                                                                    // are inside the board, then replaced with X
		board[tempi][tempj - 1] = 'x';
	}

	if (board[tempi][tempj + 1] == '-')
	{
		board[tempi][tempj + 1] = 'x';
	}

	if (board[tempi - 1][tempj - 1] == '-')
	{
		board[tempi - 1][tempj - 1] = 'x';
	}

	if (board[tempi - 1][tempj + 1] == '-')
	{
		board[tempi - 1][tempj + 1] = 'x';
	}

	if (board[tempi - 1][tempj] == '-')
	{
		board[tempi - 1][tempj] = 'x';
	}

	if (board[tempi + 1][tempj - 1] == '-')
	{
		board[tempi + 1][tempj - 1] = 'x';
	}

	if (board[tempi + 1][tempj - 1] == '-')
	{
		board[tempi + 1][tempj - 1] = 'x';
	}

	if (board[tempi + 1][tempj] == '-')
	{
		board[tempi + 1][tempj] = 'x';
	}
	
	Dispboard(board, row);                                                              // Board is now displayed
}

void RookR(char board[][8], int row)                                                     //Right Rook
{
	int tempi;
	int tempj;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == 'R' && j > 4)
			{
				tempi = i;
				tempj = j;                                                               //to find indexes of R
			}
		}
	}

	
	for (int j = 0; j < 8; j++)
	{
		if (board[tempi][j] == '-')
		{
			board[tempi][j] = 'x';                                                       //Horizontal Movement of Rook
		}                                                                               
	}

	
	for (int i = 0; i < 8; i++)
	{
		if (board[i][tempj] == '-')
		{
			board[i][tempj] = 'x';                                                       //Vertical Movement of Rook
		}
	}

	Dispboard(board, row);
}

void RookL(char board[][8], int row)                                                     //Left Rook
{
	int tempi;
	int tempj;

	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == 'R' && j < 4)
			{
				tempi = i;
				tempj = j;                                                               //to find indexes of R
			}
		}
	}

	
	for (int j = 0; j < 8; j++)
	{
		if (board[tempi][j] == '-')
		{
			board[tempi][j] = 'x';                                                       //Horizontal Movement of Rook
		}
	}

	
	for (int i = 0; i < 8; i++)
	{
		if (board[i][tempj] == '-')
		{
			board[i][tempj] = 'x';                                                       //Vertical Movement of Rook
		}
	}

	Dispboard(board, row);
}


void Queen(char board[][8], int row)
{
	int tempi;
	int tempj;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == 'Q' && i > 4)
			{
				tempi = i;
				tempj = j;                                                                 // to find indexes of Q
			}
		}
	}
	 
	for (int i = tempi - 1, j = tempj - 1; i >= 0 && j >= 0; i--, j--)                     // for diagonal moves towards the left and straight
	{
		if (board[i][j] == '-')
		{
			board[i][j] = 'X';
		}
	}

	for (int i = tempi - 1, j = tempj + 1; i >= 0 && j < 8; i--, j++)                     // for diagonal moves towards the right and straight
	{
		if (board[i][j] == '-')
		{
			board[i][j] = 'X';
		}
		
	}

	for (int i = tempi + 1, j = tempj - 1; i < 8 && j >= 0; i++, j--)                      // for diagonal moves towards the left and back
	{
		if (board[i][j] == '-')
		{
			board[i][j] = 'X';
		}
		
	}

	for (int i = tempi + 1, j = tempj + 1; i < 8 && j < 8; i++, j++)                       // for diagonal moves towards the right and back
	{
		if (board[i][j] == '-')
		{
			board[i][j] = 'X';
		}
		
	}

	for (int i = tempi - 1; i >= 0; i--)                                                   // for straight moves ahead
	{
		if (board[i][tempj] == '-')
		{
			board[i][tempj] = 'X';
		}
		
	}

	for (int i = tempi + 1; i < 8; i++)                                                    // for straight moves back
	{
		if (board[i][tempj] == '-')
		{
			board[i][tempj] = 'X';
		}
		
	}
	 
	for (int j = tempj - 1; j >= 0; j--)                                                   // for straight moves left
	{
		if (board[tempi][j] == '-')
		{
			board[tempi][j] = 'X';
		}
		
	}

	for (int j = tempj + 1; j < 8; j++)
	{
		if (board[tempi][j] == '-')
		{
			board[tempj][j] = 'X';                                                          // for straight moves right
		}
		
	}

	Dispboard(board, row);

}

void BishopR(char board[][8], int row)                                                     //Right Bishop
{
	int tempi;
	int tempj;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == 'B' && j > 4)
			{
				tempi = i;
				tempj = j;                                                                 //to find indexes of B
			}
		}
	}

	for (int i = tempi - 1, j = tempj - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (board[i][j] == '-')
		{
			board[i][j] = 'x';                                                             // for movement straight and left
		}
	}

	for (int i = tempi - 1, j = tempj + 1; i >= 0 && j < 8; i--, j++)
	{
		if (board[i][j] == '-')
		{
			board[i][j] = 'x';                                                             // for movement straight and right
		}
	}

	for (int i = tempi + 1, j = tempj - 1; i < 8 && j >= 0; i++, j--)
	{
		if (board[i][j] == '-')
		{
			board[i][j] = 'x';                                                           // for movement behind and left
		}
	}

	for (int i = tempi + 1, j = tempj + 1; i < 8 && j < 8; i++, j++)
	{
		if (board[i][j] == '-')
		{
			board[i][j] = 'x';                                                           // for movement behind and right
		}
	}

	Dispboard(board, row);
}

void BishopL(char board[][8], int row)                                                    //Left Bishop
{
	int tempi;
	int tempj;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == 'B' && j < 4)
			{
				tempi = i;
				tempj = j;                                                                //to find indexes of B
			}
		}
	}

	for (int i = tempi - 1, j = tempj - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (board[i][j] == '-')
		{
			board[i][j] = 'x';                                                              // for movement straight and left
		}
	}

	for (int i = tempi - 1, j = tempj + 1; i >= 0 && j < 8; i--, j++)
	{
		if (board[i][j] == '-')
		{
			board[i][j] = 'x';                                                              // for movement straight and right
		}
	}

	for (int i = tempi + 1, j = tempj - 1; i < 8 && j >= 0; i++, j--)
	{
		if (board[i][j] == '-')
		{
			board[i][j] = 'x';                                                              // for movement behind and left
		}
	}

	for (int i = tempi + 1, j = tempj + 1; i < 8 && j < 8; i++, j++)
	{
		if (board[i][j] == '-')
		{
			board[i][j] = 'x';                                                               // for movement behind and right
		}
	}

	Dispboard(board, row);
}

void KnightR(char board[][8], int row)                                                       // Right Knight
{
	int tempi;
	int tempj;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == 'N' && j > 4)
			{
				tempi = i; 
				tempj = j;                                                                   // to find indexes of N
			}
		}
	}

	
	if (tempj - 2 >= 0 && tempi - 1 >= 0 && board[tempi - 1][tempj - 2] == '-')                          //possible moves checked as in King's Movement 
	{
		board[tempi - 1][tempj - 2] = 'x';
	}
	if (tempj - 2 >= 0 && tempi + 1 < 8 && board[tempi + 1][tempj - 2] == '-')
	{
		board[tempi + 1][tempj - 2] = 'x';
	}
	if (tempj - 1 >= 0 && tempi - 2 >= 0 && board[tempi - 2][tempj - 1] == '-')
	{
		board[tempi - 2][tempj - 1] = 'x';
	}
	if (tempj - 1 >= 0 && tempi + 2 < 8 && board[tempi + 2][tempj - 1] == '-')                           //hardcoded
	{
		board[tempi + 2][tempj - 1] = 'x';
	}
	if (tempj + 2 < 8 && tempi - 1 >= 0 && board[tempi - 1][tempj + 2] == '-')
	{
		board[tempi - 1][tempj + 2] = 'x';
	}
	if (tempj + 2 < 8 && tempi + 1 < 8 && board[tempi + 1][tempj + 2] == '-')
	{
		board[tempi + 1][tempj + 2] = 'x';
	}
	if (tempj + 1 < 8 && tempi - 2 >= 0 && board[tempi - 2][tempj + 1] == '-')
	{
		board[tempi - 2][tempj + 1] = 'x';
	}
	if (tempj + 1 < 8 && tempi + 2 < 8 && board[tempi + 2][tempj + 1] == '-')
	{
		board[tempi + 2][tempj + 1] = 'x';
	}

	Dispboard(board, row);
}

void KnightL(char board[][8], int row)
{
	int tempi;
	int tempj;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == 'N' && j < 4)
			{
				tempi = i;
				tempj = j;
			}
		}
	}

	// Check for possible moves
	if (tempj - 2 >= 0 && tempi - 1 >= 0 && board[tempi - 1][tempj - 2] == '-')                   //possible moves checked as in King's Movement 
	{
		board[tempi - 1][tempj - 2] = 'x';
	}
	if (tempj - 2 >= 0 && tempi + 1 < 8 && board[tempi + 1][tempj - 2] == '-')
	{
		board[tempi + 1][tempj - 2] = 'x';
	}
	if (tempj - 1 >= 0 && tempi - 2 >= 0 && board[tempi - 2][tempj - 1] == '-')
	{
		board[tempi - 2][tempj - 1] = 'x';
	}
	if (tempj - 1 >= 0 && tempi + 2 < 8 && board[tempi + 2][tempj - 1] == '-')
	{
		board[tempi + 2][tempj - 1] = 'x';
	}
	if (tempj + 2 < 8 && tempi - 1 >= 0 && board[tempi - 1][tempj + 2] == '-')                      //hardcoded
	{
		board[tempi - 1][tempj + 2] = 'x';
	}
	if (tempj + 2 < 8 && tempi + 1 < 8 && board[tempi + 1][tempj + 2] == '-')
	{
		board[tempi + 1][tempj + 2] = 'x';
	}
	if (tempj + 1 < 8 && tempi - 2 >= 0 && board[tempi - 2][tempj + 1] == '-')
	{
		board[tempi - 2][tempj + 1] = 'x';
	}
	if (tempj + 1 < 8 && tempi + 2 < 8 && board[tempi + 2][tempj + 1] == '-')
	{
		board[tempi + 2][tempj + 1] = 'x';
	}

	Dispboard(board, row);
}


void Move(char board[][8], int row, char a, int b, char x)
{
	int a1;
	
	switch (a)
	{
	case 'a': a1 = 0;
		break;

	case 'b': a1 = 1;
		break;

	case 'c': a1 = 2;
		break;

	case 'd': a1 = 3;
		break;
	
	case 'e': a1 = 4;
		break;

	case 'f': a1 = 5;
		break;

	case 'g': a1 = 6;
		break;

	case 'h': a1 = 7;
		break;
	}

	switch (x)
	{
	case 'K':
	{
		if (board[b - 1][a1] == 'X')
		{
			board[b - 1][a1] = 'K';
		}

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'K' && i > 4)
				{
					board[i][j] = '-';
				}
			}
		}
	}
	break;

	Dispboard(board, row);
	}
	
	
}
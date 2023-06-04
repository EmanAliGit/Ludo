#include "Game.h"

void Game::StartGame()
{
	int score = 0, NoOfSixes, dr = 0;
	bool won = false, killed = false;

	B.InitBoard(NOP);						//initializes the piece array with respect to number of players, initializes the cells array(class //board has a pointer to cell) i.e. IsSafe, IsHome etc.
	int Count = NOP, NoOfSixes, score = 0;		//maintaining a Count to decide if the Game Ends. Game Ends when Count //gets equal NOP-1
	B.PrintBoard();					//Prints cells ie printing the grid
	B.Printpieces();				//draw Piece’s shapes

	do								//do while loop to continue playing till game ends
	{
		NoOfSixes = 0;					//initializing NoOfSixes to 0 every time a player turn starts
		B.DispPlayerMsg();				//Turn message
		do								//do while loop to play again if player kills a piece
		{
			do							//do while loop to play again if dice roll evaluates 6, also keeping in view number of //sixes
			{
				dr = B.DiceRoll();		//Rolls dice and generates a number from 1 to 6
				score += dr;			//increments score of each turn
				if (dr == 6)
					NoOfSixes++;		//maintaining number of sixes
			} while (NoOfSixes <= 3);

			if (NoOfSixes == 3)
				score = 0;				//Set score to 0 if six comes thrice
			do
			{
				B.SelectPiece();
			} while (B.IsValidSelection() == false);					//Selecting a piece until a valid piece is selected

			B.CalculateDestination(score);							//updates E of board,calculates destination keeping in view the legality checks ie it should be within boundary of board and destination should not be in home
			killed = B.Pie[B.S.r][B.S.c]->IsKillHappen(B.E);		//checking if this move in piece position kills any piece
			B.Pie[B.S.r][B.S.c]->Move(B.E);		            //calls SetPieceStatus inside Move() function
			B.DisplayUpdatedBoard();								//Displays again the start and end position to display updated board
		} while (killed == true);

		won = B.P[B.turn].IsWin();		//Seeing if the current player has won i.e seeing if all its pieces //have IsWin()==true
		if (won)
			Count--;					//maintaining Count mentioned in step 3
		B.TurnChange();					//skips the turn of player who is out and changes the turn to next player
		won = false;					//setting won (mentioned in step 20) back to false for next turn
		score = 0;						//setting score back to 0 for next turn
	} while (Count >= NOP - 1);

}

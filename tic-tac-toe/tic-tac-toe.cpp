#include <iostream>

using namespace std;

void printBoard(char squares[9])
{
	cout << endl;
	cout << " " << squares[0] << " | " << squares[1] << " | " << squares[2] << " " << endl;
	cout << "---+---+---" << endl;
	cout << " " << squares[3] << " | " << squares[4] << " | " << squares[5] << " " << endl;
	cout << "---+---+---" << endl;
	cout << " " << squares[6] << " | " << squares[7] << " | " << squares[8] << " " << endl;
	cout << endl;
}

bool isGameWon(char squares[9])
{
	for (int i = 0; i < 3; i++)
	{
		if (squares[i * 3] == squares[i * 3 + 1] && squares[i * 3] == squares[i * 3 + 2])
		{
			return true;
		}

		if (squares[i] == squares[i + 3] && squares[i] == squares[i + 6])
		{
			return true;
		}
	}

	if (squares[0] == squares[4] && squares[0] == squares[8])
	{
		return true;
	}

	if (squares[2] == squares[4] && squares[2] == squares[6])
	{
		return true;
	}

	return false;
}

bool isGameStalemate(char squares[9])
{
	for (int i = 0; i < 9; i++)
	{
		if (squares[i] != 'X' && squares[i] != 'O')
		{
			return false;
		}
	}

	return true;
}


void main() {
	char squares[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	int playerTurn = 1;
	bool playing = true;

	do
	{
		printBoard(squares);

		char playerMark;

		if (playerTurn == 1)
		{
			playerMark = 'X';
		}
		else
		{
			playerMark = 'O';
		}

		cout << "Player " << playerTurn << "'s move: ";

		bool validMove;

		do
		{
			char nextMove;
			cin >> nextMove;
			validMove = true;

			if ('1' <= nextMove && nextMove <= '9')
			{
				int square = nextMove - '0';
				squares[square - 1] = playerMark;
			}
			else
			{
				cout << "Invalid Move. Try again." << endl;
				validMove = false;
			}
		} while (!validMove);

		bool isWon = isGameWon(squares);
		bool isStalemate = isGameStalemate(squares);

		if (isWon || isStalemate)
		{
			cout << endl;

			if (isWon)
			{
				cout << "Player " << playerTurn << " wins!" << endl;
			}
			else
			{
				cout << "Stalemate!" << endl;
			}

			cout << "Play again (y/n)? ";
			char playAgain;
			cin >> playAgain;

			if (playAgain == 'y')
			{
				playing = true;

				for (int i = 0; i < 9; i++)
				{
					squares[i] = '1' + i;
				}
			}
			else
			{
				playing = false;
			}

			playerTurn = 1;
		}
		else
		{
			if (playerTurn == 1)
			{
				playerTurn = 2;
			}
			else
			{
				playerTurn = 1;
			}
		}
	} while (playing);
}
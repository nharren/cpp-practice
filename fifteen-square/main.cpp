#include <iostream>
#include <ctime>

using namespace std;

enum Direction {
	up = 'w',
	down = 'z',
	left = 'a',
	right = 's'
};

void InitializeBoard(char[4][4]);
void PrintBoard(char[4][4]);
void LocateSpace(int&, int&, char[4][4]);
void Randomize(char[4][4]);
void Move(char[4][4], const Direction);

int main() 
{
	char board[4][4];
	InitializeBoard(board);
	Randomize(board);

	do
	{
		PrintBoard(board);
		cout << endl << "w = Up, z = Down, a = Left, s = Right" << endl;
		char nextMove;
		cin >> nextMove;
		Direction nextMoveDirection = (Direction)nextMove;
		Move(board, nextMoveDirection);
		cout << endl;
	} 
	while (true);

	return EXIT_SUCCESS;
}

void InitializeBoard(char board[4][4])
{
	const char initial[4][4] =
	{
		{ '1', '2', '3', '4' },
		{ '5', '6', '7', '8' },
		{ '9', 'A', 'B', 'C' },
		{ 'D', 'E', 'F', ' ' }
	};

	for (int row = 0; row < 4; ++row)
	{
		for (int column = 0; column < 4; ++column)
		{
			board[row][column] = initial[row][column];
		}
	}
}

void PrintBoard(char board[4][4])
{
	for (int row = 0; row < 4; ++row)
	{
		for (int column = 0; column < 4; ++column)
		{
			cout << board[row][column];
		}

		cout << endl;
	}
}

void LocateSpace(int& row, int& column, char board[4][4])
{
	for (int r = 0; r < 4; ++r)
	{
		for (int c = 0; c < 4; ++c)
		{
			if (board[r][c] == ' ')
			{
				row = r;
				column = c;
			}
		}
	}
}

void Randomize(char board[4][4])
{
	srand((unsigned int)time(0));

	for (int index = 0; index < 1000000; ++index)
	{
		const int nextMove = rand() % 4;

		switch (nextMove)
		{
			case 0:
			{
				Move(board, Direction::up);
				break;
			}
			case 1:
			{
				Move(board, Direction::down);
				break;
			}
			case 2:
			{
				Move(board, Direction::left);
				break;
			}
			case 3:
			{
				Move(board, Direction::right);
				break;
			}
		}
	}
}

void Move(char board[4][4], const Direction direction)
{
	int rowSpace;
	int columnSpace;
	
	LocateSpace(rowSpace, columnSpace, board);

	int rowMove = rowSpace;
	int columnMove = columnSpace;

	switch (direction)
	{
		case Direction::up:
		{
			rowMove = rowSpace + 1;
			break;
		}
		case Direction::down:
		{
			rowMove = rowSpace - 1;
			break;
		}
		case Direction::left:
		{
			columnMove = columnSpace + 1;
			break;
		}
		case Direction::right:
		{
			columnMove = columnSpace - 1;
			break;
		}
	}

	if (rowMove >= 0 && rowMove < 4 && columnMove >= 0 && columnMove < 4)
	{
		board[rowSpace][columnSpace] = board[rowMove][columnMove];
		board[rowMove][columnMove] = ' ';
	}
}


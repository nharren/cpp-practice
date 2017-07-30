#include <iostream>
#include <ctime>

using namespace std;

void Shuffle(bool cardsDealt[]);
void PrintCard(int card);
void PrintHand(int hand[], const int cardCount);
int GetNextCard(bool cardsDealt[]);
int ScoreHand(int hand[], const int cardCount);
void PrintScoresAndHands(int houseHand[], const int houseCardCount, int playerHand[], const int playerCardCount);

int main() 
{
	time_t currentTime;
	time(&currentTime);
	srand(currentTime);

	bool cardsDealt[52];
	int houseHand[12];
	int playerHand[12];
	int houseCardCount = 0;
	int playerCardCount = 0;

	while (true)
	{
		Shuffle(cardsDealt);

		playerHand[0] = GetNextCard(cardsDealt);
		houseHand[0] = GetNextCard(cardsDealt);
		playerHand[1] = GetNextCard(cardsDealt);
		houseHand[1] = GetNextCard(cardsDealt);

		houseCardCount = 2;
		playerCardCount = 2;

		cout << "--------------------------------------------------------" << endl;
		cout << "-----------------------New Hand-------------------------" << endl;
		cout << "--------------------------------------------------------" << endl;

		char playerChoice;
		bool playerHits = true;
		int playerScore = ScoreHand(playerHand, playerCardCount);

		do
		{
			cout << "House's Hand" << endl;
			cout << "** ";
			PrintCard(houseHand[1]);
			cout << endl;
			cout << "Player's Hand: Score = " << ScoreHand(playerHand, playerCardCount) << endl;
			PrintHand(playerHand, playerCardCount);

			cout << "Hit(h) or stay(s): ";
			cin >> playerChoice;

			if (playerChoice == 'h') {
				playerHand[playerCardCount] = GetNextCard(cardsDealt);
				++playerCardCount;
			}
			else if (playerChoice == 's')
			{
				playerHits = false;
			}
			else
			{
				cout << "Error: Try Again!" << endl;
			}

			cout << endl;
			playerScore = ScoreHand(playerHand, playerCardCount);
		} 
		while (playerHits && playerScore < 22);

		if (playerScore > 21)
		{
			cout << "**** The House Wins!!! ****" << endl;
			PrintScoresAndHands(houseHand, houseCardCount, playerHand, playerCardCount);
		}
		else
		{
			int houseScore = ScoreHand(houseHand, houseCardCount);

			while (houseScore < 17)
			{
				houseHand[houseCardCount] = GetNextCard(cardsDealt);
				++houseCardCount;
				houseScore = ScoreHand(houseHand, houseCardCount);
			}

			bool houseBusts = (houseScore > 21);

			if (houseBusts)
			{
				cout << "*** The Player Wins!!! ****" << endl;
				PrintScoresAndHands(houseHand, houseCardCount, playerHand, playerCardCount);
			}
			else
			{
				if (playerScore == houseScore)
				{
					cout << "**** Tie!!! ****" << endl;
					PrintScoresAndHands(houseHand, houseCardCount, playerHand, playerCardCount);
				}
				else if (playerScore > houseScore)
				{
					cout << "**** The Player Wins!!! ****" << endl;
					PrintScoresAndHands(houseHand, houseCardCount, playerHand, playerCardCount);
				}
				else
				{
					cout << "**** The House Wins!!! ****" << endl;
					PrintScoresAndHands(houseHand, houseCardCount, playerHand, playerCardCount);
				}
			}
		}
	}
	
	return EXIT_SUCCESS;
}

void Shuffle(bool cardsDealt[])
{
	for (int index = 0; index < 52; ++index)
	{
		cardsDealt[index] = false;
	}
}

void PrintCard(int card)
{
	const int rank = card % 13;

	if (rank == 0)
	{
		cout << 'A';
	}
	else if (rank < 9)
	{
		cout << rank + 1;
	}
	else if (rank == 9)
	{
		cout << 'T';
	}
	else if (rank == 10)
	{
		cout << 'J';
	}
	else if (rank == 11)
	{
		cout << 'Q';
	}
	else
	{
		cout << 'K';
	}

	const int suit = card / 13;

	if (suit == 0)
	{
		cout << 'C';
	} 
	else if (suit == 1)
	{
		cout << 'D';
	}
	else if (suit == 2)
	{
		cout << 'H';
	}
	else
	{
		cout << 'S';
	}
}

void PrintHand(int hand[], const int cardCount)
{
	for (int cardIndex = 0; cardIndex < cardCount; ++cardIndex)
	{
		const int nextCard = hand[cardIndex];
		PrintCard(nextCard);
		cout << " ";
	}

	cout << endl;
}

int GetNextCard(bool cardsDealt[])
{
	bool cardDealt = true;
	int newCard = -1;

	do
	{
		newCard = rand() % 52;
		
		if (!cardsDealt[newCard])
		{
			cardDealt = false;
		}
	} 
	while (cardDealt);

	return newCard;
}

int ScoreHand(int hand[], const int cardCount)
{
	int aceCount = 0;
	int score = 0;

	for (int cardIndex = 0; cardIndex < cardCount; ++cardIndex)
	{
		const int nextCard = hand[cardIndex];
		const int rank = nextCard % 13;

		if (rank == 0)
		{
			++aceCount;
			++score;
		}
		else if (rank < 9)
		{
			score = score + rank + 1;
		}
		else
		{
			score = score + 10;
		}
	}

	while (aceCount > 0 && score < 12)
	{
		--aceCount;
		score = score + 10;
	}

	return score;
}

void PrintScoresAndHands(int houseHand[], const int houseCardCount, int playerHand[], const int playerCardCount) 
{
	cout << "House's Hand: Score = " << ScoreHand(houseHand, houseCardCount) << endl;
	PrintHand(houseHand, houseCardCount);
	cout << "Player's Hand: Score = " << ScoreHand(playerHand, playerCardCount) << endl;
	PrintHand(playerHand, playerCardCount);
	cout << endl;
}
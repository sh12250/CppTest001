#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void Shuffle(int* firstNumber, int* secondNumber);

void TrumpPick()
{
	const int SHUFFLECOUNT = 400;
	int cards[52] = { 0, };
	char cardPatterns[4][4] = { "♠", "♡", "♣", "◇" };
	// char cardPatterns[4][8] = {"Spade", "Diamond", "Heart", "Clover"};

	// char cardPattern_Spade[4] = { '♠', '♥', '♣', '◆' };
	srand((unsigned int)time(NULL));
	int randIdx1, randIdx2, randIdx3, randIdx4 = 0;

	for (int i = 0; i < 52; i++)		// 카드 값 초기화
	{
		cards[i] = (i % 13) + 1;
		// printf("cards[%d] 의 값 : %d \n",i , cards[i]);

		if (cards[i] == 1)
		{
			cards[i] = 'A';
		}
		else if (cards[i] == 11)
		{
			cards[i] = 'J';
		}
		else if (cards[i] == 12)
		{
			cards[i] = 'Q';
		}
		else if (cards[i] == 13)
		{
			cards[i] = 'K';
		}
	}

	for (int i = 0; i < SHUFFLECOUNT; i++)
	{
		randIdx1 = rand() % 52;
		randIdx2 = rand() % 52;
		Shuffle(&cards[randIdx1], &cards[randIdx2]);
	}


	// printf("%d \n", cards[0]);
	while (true)
	{
		randIdx3 = rand() % 4;
		randIdx4 = rand() % 52;

		printf("┌───────┐ \n");
		printf("│ %s    │ \n", cardPatterns[randIdx3]);

		if (cards[randIdx4] == 65)
		{
			printf("│ %c     │ \n", cards[randIdx4]);
			printf("│      %c│ \n", cards[randIdx4]);
		}
		else if (cards[randIdx4] > 1 && cards[randIdx4] < 10)
		{
			printf("│ %d     │ \n", cards[randIdx4]);
			printf("│      %d│ \n", cards[randIdx4]);
		}
		else if (cards[randIdx4] == 10)
		{
			printf("│ %d    │ \n", cards[randIdx4]);
			printf("│     %d│ \n", cards[randIdx4]);
		}
		else if (cards[randIdx4] == 74)
		{
			printf("│ %c     │ \n", cards[randIdx4]);
			printf("│      %c│ \n", cards[randIdx4]);
		}
		else if (cards[randIdx4] == 75)
		{
			printf("│ %c     │ \n", cards[randIdx4]);
			printf("│      %c│ \n", cards[randIdx4]);
		}
		else if (cards[randIdx4] == 81)
		{
			printf("│ %c     │ \n", cards[randIdx4]);
			printf("│      %c│ \n", cards[randIdx4]);
		}

		printf("│     %s│ \n", cardPatterns[randIdx3]);
		printf("└───────┘ \n");


		_getch();
		system("cls");
	}
}

int main() 
{
	TrumpPick();

	return 0;
}

void Shuffle(int* firstNumber, int* secondNumber)
{
	int temp = 0;
	temp = *firstNumber;
	*firstNumber = *secondNumber;
	*secondNumber = temp;
}

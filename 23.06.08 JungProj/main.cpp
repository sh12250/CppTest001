#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>

using namespace std;

// 5�� ¥�� �迭 ����
// �������� �����ϰ� 5���� ���ڸ� �Է� �޾Ƽ� �迭�� �����ϴ� ��
// ���� ���� ������ ���� ����
void SelecttionSort(int* ptrArr, int arrSize);
void BubbleSort(int* ptrArr, int arrSize);
void InsertionSort(int* ptrArr, int arrSize);
void Shuffle(int* ptrArr, int arrSize, int shuffleCount);
void SwapOnce(int* firstNumber, int* secondNumber);
void ArrayFunc(int* ptrArr, int arrSize);
void ArrayFunc2(int array_[], int arrSize);

void SwapChar(char* firstChar, char* secondChar);
void MovePlayer(char* mapArr_, int mapSize);
void PrintMap(char* mapArr_, int mapSize);

// �����̵� ���ð��� �����ؼ� ����
// 3 ~ 15 ������ ���� �Է¹޾Ƽ� �ش� ����� �´� �����̵� ���� ����(normal)
// ex) 3 X 3 ����
// Ŭ��� �Ұ����� ������ �������� �ʴ´�(very hard)


void MovePlayer(char* mapArr_, int mapSize)
{
	const int MAX_ARR_ELEMENTS = 4;
	const int MIN_ARR_ELEMENTS = 0;

	//const int MAPSIZE = 25;
	//char mapArr[MAPSIZE][MAPSIZE] = { 0, };

	int xPosition = (mapSize - 1) / 2;
	int yPosition = (mapSize - 1) / 2;


	//mapArr[yPosition][xPosition] = '0';
	*((mapArr_ + (yPosition * mapSize)) + xPosition) = '0';


	PrintMap(mapArr_, mapSize);

	char userInput = 0;

	while (true)
	{
		userInput = _getch();
		system("cls");

		if (userInput == 'a' || userInput == 'A')
		{
			userInput = 0;

			if (xPosition != MIN_ARR_ELEMENTS)
			{
				SwapChar(((mapArr_ + (yPosition * mapSize)) + xPosition), ((mapArr_ + (yPosition * mapSize)) + xPosition - 1));
				xPosition--;
			}
		}
		else if (userInput == 'd' || userInput == 'D')
		{
			userInput = 0;

			if (xPosition != MAX_ARR_ELEMENTS)
			{
				SwapChar(((mapArr_ + (yPosition * mapSize)) + xPosition), ((mapArr_ + (yPosition * mapSize)) + xPosition + 1));
				xPosition++;
			}
		}
		else if (userInput == 'w' || userInput == 'W')
		{
			userInput = 0;

			if (yPosition != MIN_ARR_ELEMENTS)
			{
				SwapChar(((mapArr_ + (yPosition * mapSize)) + xPosition), ((mapArr_ + (yPosition * mapSize) - 1) + xPosition));
				yPosition--;
			}
		}
		else if (userInput == 's' || userInput == 'S')
		{
			userInput = 0;

			if (yPosition != MAX_ARR_ELEMENTS)
			{
				SwapChar(((mapArr_ + (yPosition * mapSize)) + xPosition), ((mapArr_ + (yPosition * mapSize) + 1) + xPosition));
				yPosition++;
			}
		}
		else if (userInput == 'q' || userInput == 'Q')
		{
			system("cls");
			break;
		}

		PrintMap(mapArr_, mapSize);
	}			// while()



}

void PrintMap(char* mapArr_, int mapSize)
{
	for (int y = 0; y < mapSize; y++)
	{
		for (int x = 0; x < mapSize; x++)
		{
			printf("%c ", *((mapArr_ + (y * mapSize)) + x) );
		}
		printf("\n");
	}
}


int main()
{
	/*
	// ������ ����
	// �����͸� ������ ũ�⸦ �� ���� ����Ѵ�
	int numbers[10] = { 0, };

	for(int i = 0; i<10;i++)
	{
		numbers[i] = (i + 1) * 10;
		printf("numbers[%d] : %d \n", i, numbers[i]);
	}

	int* ptrNum = &numbers[2];

	// �迭�� 5��° ���� �����Ϸ��� �Ҷ�
	// numbers[4];					// �迭������ ������
	// *(ptrNum + 4);			// �����͸� ����� ������

	// �ּҿ� �´��� ���� �ּҸ� ����Ų��
	printf("\n3���� �ڸ��� �ִ� �� + 1 >> %d \n", *(ptrNum + 1));
	printf("numbers �� ����ִ� ��  >> %p \n", numbers);
	printf("numbers[0] �� �ּ� ��  >> %p \n", &numbers[0]);
	// �迭�� ���������� ����ǹǷ� �迭�� ��� �ϳ��� �ּҸ� �˸� ��ü �迭�� �ּҸ� �� �� �ִ�
	
	// �迭�� 0��° �ּҸ� �־��ش�
	ArrayFunc2(numbers, 10);
	// �迭�� ũ�⸦ ���� �˷����� ������ ũ�⸦ �Ѿ�� ���� �������Ѵ�

	printf("numbers �� Size : %d \n", sizeof(numbers));
	// ������ ����
	
	// ���� �ǽ�
	int numbers[5] = { 0, };
	int* ptrNum = numbers;

	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	{
		cin >> numbers[i];
	}

	printf("\n���� �� \n");
	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	{
		printf("number[%d] �� �� : %d \n", i, *(ptrNum + i));
	}

	// SelecttionSort(numbers, sizeof(numbers) / sizeof(int));
	BubbleSort(numbers, sizeof(numbers) / sizeof(int));
	// InsertionSort(numbers, sizeof(numbers) / sizeof(int));

	printf("\n���� �� \n");
	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	{
		printf("number[%d] �� �� : %d \n", i, *(ptrNum + i));
	}
	// ���� �ǽ�

	// ������ �迭
	char char1_[25] = { 0, };

	for (int i = 0; i < 25; i++)
	{
		char1_[i] = '*';
	}
	//for (int i = 0; i < 25; i++)
	//{
	//	printf("%c ", char1_[i]);
	//	if (i % 5 == 4)
	//	{
	//		printf("\n");
	//	}
	//}

	printf("\n");

	char char2_[5][5] = { 0, };
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			if (x == 2 && y == 2)
			{
				char2_[y][x] = '0';
			}
			char2_[y][x] = '*';
		}
	}

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			printf("%c ", char2_[y][x]);
		}
		printf("\n");
	}
	// ������ �迭
	*/

	// char** mapArr2 = new char* [MAPSIZE];
	char mapArr2[5][5] = {0, };
	
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			// printf("%c ", mapArr2[y][x]);
			mapArr2[y][x] = '*';
		}
		printf("\n");
	}


	MovePlayer((char*)mapArr2, 5);

	// PrintMap((char*)mapArr2, 5);




	return 0;
}

// ��¥ ����
void Shuffle(int* ptrArr, int arrSize, int shuffleCount)
{
	int randIdx1, randIdx2 = 0;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < shuffleCount; i++)
	{
		randIdx1 = rand() % arrSize;
		randIdx2 = rand() % arrSize;
		SwapOnce((ptrArr + randIdx1), (ptrArr + randIdx2));
	}
}

// �����ͷ� �迭�� ��� �ΰ��� ���� �Լ�
void SwapOnce(int* firstNumber, int* secondNumber)
{
	int temp = 0;
	temp = *firstNumber;
	*firstNumber = *secondNumber;
	*secondNumber = temp;
}

void SwapChar(char* firstChar, char* secondChar)
{
	int temp = 0;
	temp = *firstChar;
	*firstChar = *secondChar;
	*secondChar = temp;
}

// int�� �迭�� �迭�� ũ�⸦ �Է¹޾� �迭�� ó������ ������ ����ϴ� �Լ�
void ArrayFunc(int* ptrArr, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		printf("ptrArr[%d] ������ �� : %d \n",i , *(ptrArr + i));
	}
}

// ������ ������[] �� ������ ������
void ArrayFunc2(int array_[], int arrSize) 
{
	// ������ ������ ũ��� �ü��(64��Ʈ)�� ���� �����͸� �ҷ��� �� �ִ� �ּ� ����
	//printf("�Լ����� numbers �� Size : %d \n", sizeof(array_));
	for (int i = 0; i < arrSize; i++)
	{
		printf("ptrArr[%d] ������ �� : %d \n", i, array_[i]);
	}
}

void SelecttionSort(int* ptrArr, int arrSize)
{
	int* minNum;
	for (int i = 0; i < arrSize - 1; i++)
	{
		minNum = ptrArr + i;
		for (int j = i; j < arrSize; j++)
		{
			if (*minNum > ptrArr[j])
			{
				minNum = &ptrArr[j];
			}
		}
		SwapOnce(minNum, ptrArr + i);
	}		// for() ����
}

void BubbleSort(int* ptrArr, int arrSize)
{
	for (int j = 1; j < arrSize; j++)
	{
		for (int i = 0; (i + 1) < arrSize; i++)
		{
			// printf("����� �ֳ�\n");
			if (*(ptrArr + i) > *(ptrArr + i + 1)) 
			{
				// printf("����� �ֳ�\n");
				SwapOnce(ptrArr + i, ptrArr + i + 1);
			}
		}
	}
}

void InsertionSort(int* ptrArr, int arrSize)
{
	for (int i = 1; i < arrSize; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (*(ptrArr + (i - j)) < *(ptrArr + (i - j - 1)))
			{
				// printf("������? \n");
				SwapOnce((ptrArr + (i - j)), (ptrArr + (i - j - 1)));
			}
		}
	}
}


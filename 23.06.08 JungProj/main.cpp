#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>

using namespace std;

// 5개 짜리 배열 만들어서
// 유저한테 램덤하게 5개의 숫자를 입력 받아서 배열에 저장하는 거
// 제일 쉬운 정렬은 선택 정렬
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

// 슬라이드 퍼플게임 구현해서 제출
// 3 ~ 15 사이의 값을 입력받아서 해당 사이즈에 맞는 슬라이딩 퍼즐 구현(normal)
// ex) 3 X 3 퍼즐
// 클리어가 불가능한 퍼즐은 존재하지 않는다(very hard)


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
	// 포인터 복습
	// 포인터를 쓸꺼면 크기를 딱 맞춰 써야한다
	int numbers[10] = { 0, };

	for(int i = 0; i<10;i++)
	{
		numbers[i] = (i + 1) * 10;
		printf("numbers[%d] : %d \n", i, numbers[i]);
	}

	int* ptrNum = &numbers[2];

	// 배열의 5번째 값에 접근하려고 할때
	// numbers[4];					// 배열에서의 역참조
	// *(ptrNum + 4);			// 포인터를 사용한 역참조

	// 주소와 맞닿은 다음 주소를 가리킨다
	printf("\n3번쨰 자리에 있는 값 + 1 >> %d \n", *(ptrNum + 1));
	printf("numbers 가 들고있는 값  >> %p \n", numbers);
	printf("numbers[0] 의 주소 값  >> %p \n", &numbers[0]);
	// 배열은 연속적으로 저장되므로 배열의 요소 하나의 주소를 알면 전체 배열의 주소를 알 수 있다
	
	// 배열의 0번째 주소만 넣어준다
	ArrayFunc2(numbers, 10);
	// 배열의 크기를 내가 알려주지 않으면 크기를 넘어서도 값을 역참조한다

	printf("numbers 의 Size : %d \n", sizeof(numbers));
	// 포인터 복습
	
	// 정렬 실습
	int numbers[5] = { 0, };
	int* ptrNum = numbers;

	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	{
		cin >> numbers[i];
	}

	printf("\n셔플 전 \n");
	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	{
		printf("number[%d] 의 값 : %d \n", i, *(ptrNum + i));
	}

	// SelecttionSort(numbers, sizeof(numbers) / sizeof(int));
	BubbleSort(numbers, sizeof(numbers) / sizeof(int));
	// InsertionSort(numbers, sizeof(numbers) / sizeof(int));

	printf("\n셔플 후 \n");
	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	{
		printf("number[%d] 의 값 : %d \n", i, *(ptrNum + i));
	}
	// 정렬 실습

	// 다차원 배열
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
	// 다차원 배열
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

// 진짜 셔플
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

// 포인터로 배열의 요소 두개를 섞는 함수
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

// int형 배열과 배열의 크기를 입력받아 배열의 처음부터 끝까지 출력하는 함수
void ArrayFunc(int* ptrArr, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		printf("ptrArr[%d] 역참조 값 : %d \n",i , *(ptrArr + i));
	}
}

// 변수형 변수명[] 도 포인터 변수다
void ArrayFunc2(int array_[], int arrSize) 
{
	// 포인터 변수의 크기는 운영체계(64비트)와 같다 데이터를 불러올 수 있는 최소 단위
	//printf("함수에서 numbers 의 Size : %d \n", sizeof(array_));
	for (int i = 0; i < arrSize; i++)
	{
		printf("ptrArr[%d] 역참조 값 : %d \n", i, array_[i]);
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
	}		// for() 종료
}

void BubbleSort(int* ptrArr, int arrSize)
{
	for (int j = 1; j < arrSize; j++)
	{
		for (int i = 0; (i + 1) < arrSize; i++)
		{
			// printf("돌고는 있냐\n");
			if (*(ptrArr + i) > *(ptrArr + i + 1)) 
			{
				// printf("섞고는 있냐\n");
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
				// printf("섞었니? \n");
				SwapOnce((ptrArr + (i - j)), (ptrArr + (i - j - 1)));
			}
		}
	}
}


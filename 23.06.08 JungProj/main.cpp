#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>

using namespace std;

void Shuffle(int* ptrArr, int arrSize, int shuffleCount);
void ShuffleOnce(int* firstNumber, int* secondNumber);
void ArrayFunc(int* ptrArr, int arrSize);
void ArrayFunc2(int array_[], int arrSize);

// 5개 짜리 배열 만들어서
// 유저한테 램덤하게 5개의 숫자를 입력 받아서 배열에 저장하는 거
// 제일 쉬운 정렬은 선택 정렬
void SelecttionSort(int* ptrArr, int arrSize)
{
	int* minNum;
	for (int i = 0; i < arrSize; i++)
	{
		minNum = ptrArr + i;
		for (int j = i; j < arrSize; j++)
		{
			if (ptrArr[j] < *minNum)
			{
				ShuffleOnce(minNum, ptrArr + j);
			}
		}
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
	*/
	int userInput = 0;
	int numbers[5] = { 0, };
	int* ptrNum = numbers;
	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	{
		cin >> userInput;
		numbers[i] = userInput;
	}

	printf("\n셔플 전 \n");
	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	{
		printf("number[%d] 의 값 : %d \n", i, *(ptrNum + i));
	}

	SelecttionSort(numbers, sizeof(numbers) / sizeof(int));

	printf("\n셔플 후 \n");
	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	{
		printf("number[%d] 의 값 : %d \n", i, *(ptrNum + i));
	}


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
		ShuffleOnce((ptrArr + randIdx1), (ptrArr + randIdx2));
	}
}

// 포인터로 배열의 요소 두개를 섞는 함수
void ShuffleOnce(int* firstNumber, int* secondNumber)
{
	int temp = 0;
	temp = *firstNumber;
	*firstNumber = *secondNumber;
	*secondNumber = temp;
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
	printf("함수에서 numbers 의 Size : %d \n", sizeof(array_));
	for (int i = 0; i < arrSize; i++)
	{
		printf("ptrArr[%d] 역참조 값 : %d \n", i, array_[i]);
	}
}
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

// 5�� ¥�� �迭 ����
// �������� �����ϰ� 5���� ���ڸ� �Է� �޾Ƽ� �迭�� �����ϴ� ��
// ���� ���� ������ ���� ����
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
	*/
	int userInput = 0;
	int numbers[5] = { 0, };
	int* ptrNum = numbers;
	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	{
		cin >> userInput;
		numbers[i] = userInput;
	}

	printf("\n���� �� \n");
	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	{
		printf("number[%d] �� �� : %d \n", i, *(ptrNum + i));
	}

	SelecttionSort(numbers, sizeof(numbers) / sizeof(int));

	printf("\n���� �� \n");
	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	{
		printf("number[%d] �� �� : %d \n", i, *(ptrNum + i));
	}


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
		ShuffleOnce((ptrArr + randIdx1), (ptrArr + randIdx2));
	}
}

// �����ͷ� �迭�� ��� �ΰ��� ���� �Լ�
void ShuffleOnce(int* firstNumber, int* secondNumber)
{
	int temp = 0;
	temp = *firstNumber;
	*firstNumber = *secondNumber;
	*secondNumber = temp;
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
	printf("�Լ����� numbers �� Size : %d \n", sizeof(array_));
	for (int i = 0; i < arrSize; i++)
	{
		printf("ptrArr[%d] ������ �� : %d \n", i, array_[i]);
	}
}
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

// ������ ����ϴ� ���α׷� �����
// int lineCount[9] = { 0, };
// int lineCount1[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
void NineNineTable(int number) 
{
	const int MAX_TABLE_NUM = 9;
	int tableNum[MAX_TABLE_NUM] = { 0, };
	int tableResultNum[MAX_TABLE_NUM] = { 0, };

	for (int i = 0; i < MAX_TABLE_NUM; i++)
	{
		tableNum[i] = i + 1;
		for (int j = 0; j < MAX_TABLE_NUM; j++)
		{
			tableResultNum[j] = tableNum[i] * (j + 1);
			if (i + 1 == number)
			{
				printf("%d X %d = %d \n", i + 1, j + 1, tableResultNum[j]);
			}
		}
	}
}
// ���� �迭 ����ؼ� �� 5�� ����.(�븻)
// * * * * * 
// �迭 ����ؼ� �Ʒ�ó�� 0�� ���������� �̵��ϸ� ����(�ϵ�)(�̰ɷ� �������)
// 0 * * * *  >> * 0 * * * >> * * 0 * * >> * * * 0 * 
// ... 
// * * * 0 * >> * * * * 0
// ���α׷� ����
// ���� ���α׷��� �����ؼ� a�� 0�� ����, d�� 0�� ������ �̵� �����ϰ� �����(���� �ϵ�)


void HomewrkHard()
{
	char board[5] = { 0, };

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 5; i++) 
		{
			board[i] = '*';
		}

		board[j] = '0';

		for (int i = 0; i < 5; i++)
		{
			printf("%c ", board[i]);
		}

		_getch();
		system("cls");
	}

	printf("\n\n");
}

void HomeWorkVeryHard()
{
	char userInput = 0;
	int board[5] = { 0, };

	for (int i = 0; i < 5; i++) 
	{
		board[i] = '*';
	}

	board[0] = '0';

	for (int i = 0; i < 5; i++) 
	{
		printf("%c ", board[i]);
	}



}


void Desciption001(int ), AddOne(int* , int* );

int main() 
{
	/*
	// �ּڰ��� �����ڵ�
	int number = 1;
	if (0 <= number) {

	}

	Desciption001(10);
	printf("Description001 �Լ��� ������ �� �ڸ��� ���ƿ� ����ؾ��Ѵ�. \n");

	// ���� �Ұ� preview
	int mainNumber1 = 0;
	int mainNumber2 = 0;
	AddOne(&mainNumber1, &mainNumber2);											// ( &�����̸� ) ���� ���, ������ ����� �ּҰ��� �Է��ϰڴٴ� ��

	printf("number�� ���� 1 : %d, 2 : %d \n\n", &mainNumber1, mainNumber2);
	// �ּڰ��� �����ڵ�

	// ĳ���� �׽�Ʈ
	// ( �ڷ���_ ) ���������� ���� ��Ȯ�� �� ����
	// ( (�ڷ���) ���� �̸� ) ������ ���, ������ ������ ( �ڷ��� )�� �ۼ��� �ڷ������� ��ȯ�Ѵ�
	char char_ = 'A';
	int int_ = (int)char_;
	printf("int�� ���� : %d \n", int_);

	float floatValue = 100.123;
	int_ = floatValue;

	printf("int�� ���� : %f \n", (float)int_);
	// ĳ���� �׽�Ʈ

	// �迭�̶� �������� �ǽ�
	// 5���� ������ ����
	const int MAX_ARRAY = 5;
	int numbers[MAX_ARRAY];
	//numbers[0] = 11;								2��°�� ���� ���
	//numbers[1] = 12;
	//numbers[2] = 13;
	//numbers[3] = 14;
	//numbers[4] = 15;

	for (int i = 0; i < MAX_ARRAY; i++) //					�ݺ������� ���� ���� ���� �� �ֱ� ����
	{
		// ���� �����ʿ� ���� ���� �극��ũ ����Ʈ
		// ������ f5, ����� f10, ������ shift + f5
		// ������� �����Ŀ� �� �� �ִ�
		numbers[i] = (i + 1) * 100;
		printf("�迭�� �� ���� ( �ε��� �ڴ� �� ) : ( %d, %d ) \n", i, numbers[i]);
	}

	// �迭�� �� �ٸ� �ʱ�ȭ ���
	int numbers2[5] = { 10,20,30,40,50 };

	// ��� ���� 0���� �ʱ�ȭ							���� ���� ���
	int numbers3[5] = { 0, };

	int number1 = 0;
	int number2 = 1;
	int number3 = 2;
	int number4 = 3;
	int number5 = 4;

	printf("�迭�� �� ���� ( �ε��� �ڴ� �� ) : ( %d, %d ) \n", 0, number1);
	printf("�迭�� �� ���� ( �ε��� �ڴ� �� ) : ( %d, %d ) \n", 1, number2);
	printf("�迭�� �� ���� ( �ε��� �ڴ� �� ) : ( %d, %d ) \n", 2, number3);
	printf("�迭�� �� ���� ( �ε��� �ڴ� �� ) : ( %d, %d ) \n", 3, number4);
	printf("�迭�� �� ���� ( �ε��� �ڴ� �� ) : ( %d, %d ) \n", 4, number5);
	// �迭�̶� �������� �ǽ�
	*/

	//int inputNum = 0;

	//scanf_s("%d", &inputNum);

	//NineNineTable(inputNum);

	//Homewrk();



	return 0;
}

void AddOne(int* localNumber1, int* localNumber2)								// ( ������* ) ���� ���, ������ �ּҰ��� �Է¹ްڴٴ� ��
{
	*localNumber1 += 1;															// ( *������ ) ���� ���, �ּҰ��� �ƴ� ����
	*localNumber2 += 1;
}

void Desciption001(int number) 
{
	printf("Number�� %d \n", number);
}
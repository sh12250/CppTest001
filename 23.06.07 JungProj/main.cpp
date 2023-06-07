#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

// ���ڿ��� �Է¹޾Ƽ� �빮�� - �ҹ��� - �빮�� - �ҹ��� ������ �����ؼ� ����ϴ� ���α׷� �ۼ�(easy) // 32
// ���� ���α׷��� �����ؼ� �Ųٷ� ����ϴ� ���α׷� �ۼ�(Hard)
void Change_to_BigSmall();
void Swap2(char* , char* );
void Swap(char , char );
void Shuffle(int* , int* );
// �ζǹ�ȣ 6�� ������ �Լ� Ȱ���ؼ� ������ ������ ���α׷�(�ߺ��� ����� ��)
void PrintLotto() 
{
	const int SHUFFLECOUNT = 300;
	const int LOTTOMAXNUM = 45;
	int lottoNum[45] = { 0, };
	int randomIdx1, randomIdx2 = 0;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < LOTTOMAXNUM; i++)
	{
		lottoNum[i] = i + 1;
	}

	for (int i = 0; i < SHUFFLECOUNT; i++)
	{
		randomIdx1 = (rand() % LOTTOMAXNUM);
		randomIdx2 = (rand() % LOTTOMAXNUM);
		Shuffle(&lottoNum[randomIdx1], &lottoNum[randomIdx2]);
	}

	printf("�ζǹ�ȣ�� ");
	Sleep(500);

	for (int i = 0; i < 6; i++)
	{
		printf("%d ", lottoNum[i]);
		Sleep(500);
	}
	printf(" �Դϴ� \n");
}

// ���� Ʈ���� ī�� �����ϰ� �̾Ƽ� ����ϴ� ���α׷�
// ��Ʈ int cards[52] = { 0,  };
//	   char cardPatterns[4] = { '��', '��', '��', '��' } >> �ȳ���
//	   A, 2, 3, 4, 5, 6, 7, 8, 9, 10 ,J ,Q ,K
// Spade / 5
//������������������
//����      ��
//��5      ��
//��      5��
//��      ����
//������������������
void TrumpPick()
{
	const int SHUFFLECOUNT = 400;
	int cards[52] = { 0, };
	char cardPatterns[4][4] = {"��", "��", "��", "��"};
	// char cardPatterns[4][8] = {"Spade", "Diamond", "Heart", "Clover"};

	// char cardPattern_Spade[4] = { '��', '��', '��', '��' };
	srand((unsigned int)time(NULL));
	int randIdx1, randIdx2, randIdx3, randIdx4 = 0;

	for (int i = 0; i < 52; i++)		// ī�� �� �ʱ�ȭ
	{
		cards[i] = (i % 13) + 1;
		// printf("cards[%d] �� �� : %d \n",i , cards[i]);

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

		printf("������������������ \n");
		printf("�� %s    �� \n", cardPatterns[randIdx3]);

		if (cards[randIdx4] == 65)
		{
			printf("�� %c     �� \n", cards[randIdx4]);
			printf("��      %c�� \n", cards[randIdx4]);
		}
		else if (cards[randIdx4] > 1 && cards[randIdx4] < 10)
		{
			printf("�� %d     �� \n", cards[randIdx4]);
			printf("��      %d�� \n", cards[randIdx4]);
		}
		else if (cards[randIdx4] == 10)
		{
			printf("�� %d    �� \n", cards[randIdx4]);
			printf("��     %d�� \n", cards[randIdx4]);
		}
		else if (cards[randIdx4] == 74)
		{
			printf("�� %c     �� \n", cards[randIdx4]);
			printf("��      %c�� \n", cards[randIdx4]);
		}
		else if (cards[randIdx4] == 75)
		{
			printf("�� %c     �� \n", cards[randIdx4]);
			printf("��      %c�� \n", cards[randIdx4]);
		}
		else if (cards[randIdx4] == 81)
		{
			printf("�� %c     �� \n", cards[randIdx4]);
			printf("��      %c�� \n", cards[randIdx4]);
		}

		printf("��     %s�� \n", cardPatterns[randIdx3]);
		printf("������������������ \n");


		_getch();
		system("cls");
	}

	//randIdx3 = rand() % 4;
	//
	//printf("������������������ \n");
	//printf("�� %s    �� \n", cardPatterns[randIdx3]);

	//if (cards[0] == 65)
	//{
	//	printf("�� %c     �� \n", cards[0]);
	//	printf("��      %c�� \n", cards[0]);
	//}
	//else if(cards[0] > 1 && cards[0] < 10)
	//{
	//	printf("�� %d     �� \n", cards[0]);
	//	printf("��      %d�� \n", cards[0]);
	//}
	//else if (cards[0] == 10)
	//{
	//	printf("�� %d    �� \n", cards[0]);
	//	printf("��     %d�� \n", cards[0]);
	//}
	//else if (cards[0] == 74)
	//{
	//	printf("�� %c     �� \n", cards[0]);
	//	printf("��      %c�� \n", cards[0]);
	//}
	//else if (cards[0] == 75)
	//{
	//	printf("�� %c     �� \n", cards[0]);
	//	printf("��      %c�� \n", cards[0]);
	//}
	//else if (cards[0] == 81)
	//{
	//	printf("�� %c     �� \n", cards[0]);
	//	printf("��      %c�� \n", cards[0]);
	//}

	//printf("��     %s�� \n", cardPatterns[randIdx3]);
	//printf("������������������ \n");
	//������������������
	//����      ��
	//��5      ��
	//��      5��
	//��      ����
	//������������������
}




int main(void)
{
	/*
	// ������ �迭 string
	// ũ�⸦ �� �����Ѵ�, ũ��� �ѹ� ���ϸ� �ٲ� �� ����
	char string_[15] = "Good morning!\n"; // ' '�� '\n'�� ��ĭ�� �����Ѵ�, 
	char stringCopy[16] = { 0, };


	// ����� ���ÿ� �ʱ�ȭ�ϸ� ���ڿ��� ũ�⸦ �� ��� �����ϴ�
	char string_2[] = "Good morning! \n";  // �������� NULL ���ڰ� ����
	int numbers[10] = { 0, };

	printf("%s", string_);
	printf("���� �迭�� ũ�� : %d \n", sizeof(string_) * sizeof(char));
	printf("���� �迭2�� ũ�� : %d \n", sizeof(string_2));
	printf("���� �迭�� ũ�� : %d \n", sizeof(numbers));
	printf("���� �迭�� ���� : %d \n", sizeof(numbers) / sizeof(int));

	bool isNullSameZero = false;
	if (0 == '\0') // C++������ 0�̴�
	{
		isNullSameZero = true;
	}
	
	printf("Null�� 0�� ���� ���ΰ�? : [%d] \n", isNullSameZero);

	char string3[4];
	string3[0] = 'H';
	string3[1] = 'i';
	string3[2] = '!';
	string3[3] = '\0'; // NULL ���� ������ ����� �� ?�� ��µȴ�

	char string4[4] = "Hi!";

	printf("string3 : %s \n", string3);
	printf("string4 : %s \n", string4);
	// ������ �迭 string
	

	// ���ڿ� �Է¹ޱ�
	char str[300] = { 0, };
	printf("���ڿ��� �Է��Ͻÿ� ( 200�� �̳��� ) : ");
	// ���� ���� ���ڿ�
	std::cin >> str;
	// ���� ������ �Է¹���

	printf("����� �Է��� �޾Ҵ���? >> %s", str);
	// ���ڿ� �Է¹ޱ�


	// ������ ����
	char str[10] = "Hello";
	char temp = '\0';

	// (str[0], str[4]) = (str[4], str[0]); // C#���� �ٽ� ����
	// temp = str[0];
	// str[0] = str[4]; // H << o
	// str[4] = temp; // o << o

	// �ּڰ��� ����
	Swap2(&str[0], &str[4]);

	// o o
	printf("str�� 0��° : %c, ", str[0]);
	printf("str�� 4��° : %c \n", str[4]);
	printf("str : %s \n", str);
	// ������ ����


	// ������
	int number = 100;
	int* ptrNumber = &number;

	printf("number ������ �ּҴ� : %p, �Ҵ�� ���� : %d \n", &number, number);
	printf("ptrNumber ������ �ּҴ� : %p, �Ҵ�� ���� : %p, �������� �� : %d \n", &ptrNumber, ptrNumber, *ptrNumber);
	printf("ptrNumber �� ũ�� : %d \n", sizeof(ptrNumber));
	// ������
	

	// �迭�� ������ ����
	// �迭 ����
	int number[10] = { 0, };
	for (int i = 0; i < 10; i++)
	{
		number[i] = i + 1;
	}
	// �迭 ����

	// �迭 ���
	printf("���� �� \n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", number[i]);
	}
	printf("\n");
	// �迭 ���

	// ���� ����
	const int shuffleCount = 100;
	int randomIdx1, randomIdx2 = 0; 
	srand((unsigned int)time(NULL));

	for (int i = 0; i < shuffleCount; i++)
	{
		randomIdx1 = rand() % 10;
		randomIdx2 = rand() % 10;
		Shuffle(&number[randomIdx1], &number[randomIdx2]);
	}
	// ���� ����

	// �迭 ���
	printf("���� �� \n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", number[i]);
	}
	printf("\n");
	// �迭 ���
	// �迭�� ������ ����
	
	*/
	 
	// DeclareNumbers();

	// Change_to_BigSmall();

	// PrintLotto();

	TrumpPick();

	return 0;
}


void Change_to_BigSmall() {
	char str[300] = { 0, };
	int change = 0;
	printf("���ڿ��� �Է��Ͻÿ� ( 200�� �̳� �����, ���� ����! ) : ");

	std::cin >> str;;
	//for (int i = 1; i < sizeof(str); i += 2)
	//{
	//	char save = str[i];
	// 
	//	if (str[i] >= 97 && str[i] <= 122)
	//	{
	//		save -= 32;
	//		//printf("%c", save);
	//		str[i] = save;
	//	}
	//}
	//for (int i = 1; i < sizeof(str); i += 2)
	//{
	//	char save = str[i];
	//
	//	if (str[i] >= 65 && str[i] <= 90)
	//	{
	//		save += 32;
	//		//printf("%c", save);
	//		str[i] = save;
	//	}
	//}


	for (int i = 0; i < sizeof(str); i++)
	{
		if (str[i] == NULL)
		{
			break;
		}
		char save = str[i];

		if (change == 0)
		{
			change = 1;
			if (str[i] >= 97 && str[i] <= 122)
			{
				save -= 32;
				str[i] = save;
			}
			else if (str[i] >= 65 && str[i] <= 90)
			{
				str[i] = save;
			}
			else
			{
				change = 0;
			}
		}
		else if (change == 1)
		{
			change = 0;
			if (str[i] >= 65 && str[i] <= 90)
			{
				save += 32;
				str[i] = save;
			}
			else if (str[i] >= 97 && str[i] <= 122)
			{
				str[i] = save;
			}
			else
			{
				change = 1;
			}
		}
	}

	printf("�̷��� �ٲ���ϴ� : %s \n\n", str);

	int strLength = 0;

	for (int i = 0; i < sizeof(str); i++)
	{
		char saveChar = 0;
		if (str[i] != NULL)
		{
			strLength++;
		}
		else if (str[i] == NULL)
		{
			strLength--;
			int strHalf = strLength / 2;
			printf("%d ", strHalf);
			for (int j = 0; j < sizeof(str); j++)
			{
				saveChar = str[strLength];
				str[strLength] = str[j];
				str[j] = saveChar;
				strLength--;
				if (j - 1 > (strHalf / 2) + 1)
				{
					printf("�Ųٷ� ���������ϴ� : %s \n\n", str);

					break;
				}
			}
			break;
		}
	}		// for()
}

void Swap2(char* firstChar, char* secondChar)
{
	// ������ ������ ����ϸ� ���� ������ ���� �� �ִ�
	printf("���� �� firstChar �� : %c, ", *firstChar);
	printf("���� �� secondChar �� : %c \n", *secondChar);
	char temp = '\0';

	temp = (*firstChar);
	(*firstChar) = (*secondChar);
	(*secondChar) = temp;

	printf("���� �� firstChar �� : %c, ", *firstChar);
	printf("���� �� secondChar �� : %c \n", *secondChar);
}

void Swap(char firstChar, char secondChar)
{
	printf("���� �� firstChar �� : %c, ", firstChar);
	printf("���� �� secondChar �� : %c \n", secondChar);
	char temp = '\0';

	temp = (firstChar);
	(firstChar) = (secondChar);
	(secondChar) = temp;

	printf("���� �� firstChar �� : %c, ", firstChar);
	printf("���� �� secondChar �� : %c \n", secondChar);
}

void Shuffle(int* firstNumber, int* secondNumber) 
{
	int temp = 0;
	temp = *firstNumber;
	*firstNumber = *secondNumber;
	*secondNumber = temp;
}
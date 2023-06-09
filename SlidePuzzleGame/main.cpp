#include <iostream>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

void CreatePuzzlePiece(int* , int* );			// ���� ���� �Լ�
void CreateAnswer(int* , int* );				// ������ ���� �Լ�
void PrintPuzzle(int* , int* , int ,int );		// ���� ��� �Լ�
void PlayPuzzle(int* , int* );					// ���� ���� �÷���

void SwapOnce(int* firstNumber, int* secondNumber);
void Shuffle(int* ptrArr, int arrSize);


const int MAXSIZE = 15;


// �����̵� ���ð��� �����ؼ� ����
// 3 ~ 6 ������ ���� �Է¹޾Ƽ� �ش� ����� �´� �����̵� ���� ����(normal)
// ex) 3 X 3 ����
// Ŭ��� �Ұ����� ������ �������� �ʴ´�(very hard)

int main()
{				
	int puzzlePiece[MAXSIZE][MAXSIZE] = { 0, };
	int userInput = 5;

	CreatePuzzlePiece((int*)puzzlePiece, &userInput);
	PlayPuzzle((int*)puzzlePiece, &userInput);

	cout << "Ŭ����!" << endl;

	Sleep(3000);
	system("cls");
	cout << endl << endl << endl << endl << endl 
		<< "     �÷������ּż� �����մϴ�"
		<< endl << endl << endl << endl << endl;


	return 0;
}

void PlayPuzzle(int* pieces, int* inputNum)
{
	const int BEGIN = 0;
	const int END = *inputNum - 1;

	int answer[MAXSIZE][MAXSIZE] = { 0, }; // �������� �迭

	CreateAnswer((int*)answer, inputNum);

	int clearCheck = 0;					// �������� �󸶳� ������ üũ

	int xPos = END;			// �� ����
	int yPos = END;			//    ��ġ

	char inputChar = 0;

	while (true)
	{
		clearCheck = 0;			// �׻� 0���� �ʱ�ȭ

		system("cls");
		PrintPuzzle(pieces, inputNum, xPos, yPos);

		if (xPos == END && yPos == END)										// ���� �� Ǯ���� üũ
		{
			for (int y = 0; y < *inputNum; y++)
			{
				if (*(pieces + (y * MAXSIZE)) != answer[y][0])				// ���� ���� ������� �־
				{
					break;
				}

				for (int x = 0; x < *inputNum; x++)
				{
					if (*(pieces + (y * MAXSIZE) + x) != answer[y][x])		// �������� �ϳ��� �ٸ��� �� �� �ʿ����
					{
						break;
					}
					else
					{
						clearCheck++;
					}
				}
			}

			if (clearCheck == *inputNum * *inputNum)					// �Է¹��� ���� ����, ���ΰ� �����ϱ� ����
			{
				break;
			}
		}			// if()

		inputChar = _getch();

		if (inputChar == 'w' || inputChar == 'W')		// ���� �̵�
		{
			inputChar = 0;
			if (yPos != BEGIN)
			{
				SwapOnce(pieces + (yPos * MAXSIZE) + xPos, pieces + ((yPos - 1) * MAXSIZE) + xPos);
				yPos--;
			}
		}
		else if (inputChar == 's' || inputChar == 'S')	// �Ʒ��� �̵�
		{
			inputChar = 0;
			if (yPos != END)
			{
				SwapOnce(pieces + (yPos * MAXSIZE) + xPos, pieces + ((yPos + 1) * MAXSIZE) + xPos);
				yPos++;
			}
		}
		else if (inputChar == 'a' || inputChar == 'A')	// �������� �̵�
		{
			inputChar = 0;
			if (xPos != BEGIN)
			{
				SwapOnce(pieces + (yPos * MAXSIZE) + xPos, pieces + (yPos * MAXSIZE) + xPos - 1);
				xPos--;
			}
		}
		else if (inputChar == 'd' || inputChar == 'D')	// ���������� �̵�
		{
			inputChar = 0;
			if (xPos != END)
			{
				SwapOnce(pieces + (yPos * MAXSIZE) + xPos, pieces + (yPos * MAXSIZE) + xPos + 1);
				xPos++;
			}
		}
		else if (inputChar == 'q' || inputChar == 'Q')	// ����
		{
			cout << endl << "������ �����մϴ�" << endl;
			break;
		}
		else											// �� �� ����
		{
			inputChar = 0;
			continue;
		}
	}				// while()
}

void PrintPuzzle(int* pieces, int* inputNum, int xPos_, int yPos_)
{
	for (int y = 0; y < *inputNum; y++)
	{
		for (int x = 0; x < *inputNum; x++)
		{
			if (y == yPos_ && x == xPos_)					// �� ��ġ
			{
				printf("   ");
			}
			else if (*(pieces + (y * MAXSIZE) + x) < 10)
			{
				printf(" %d ", *(pieces + (y * MAXSIZE) + x));
			}
			else												// �������� �׳� ���
			{
				printf("%d ", *(pieces + (y * MAXSIZE) + x));
			}

		}

		printf("\n");
	}
}

void CreatePuzzlePiece(int* pieces,int* inputNum)
{
	const int BEGIN = 0;
	const int END = *inputNum - 1;

	int xPos = END;
	int yPos = END;

	cout << "�����̵� ���� ����" << endl;
	cout << "3 ~ 15 ������ ���ڸ� �Է��� �ּ���" << endl;
	cout << "�Է� : ";

	cin >> *inputNum;

	cout << endl << *inputNum << " X " << *inputNum << "�����̵� ���� ����" << endl << endl;

	for (int y = 0; y < *inputNum; y++)				// ���� ����
	{
		for (int x = 0; x < *inputNum; x++)
		{
			*(pieces + (y * MAXSIZE) + x) = (y * *inputNum) + x + 1;
		}
	}

	*(pieces + (yPos * MAXSIZE) + xPos) = ' ';

	srand((unsigned int)time(NULL));
	int randMove = 0;
	// ���� ����
	for (int i = 0; i < 200; i++)
	{
		randMove = (rand() % 4) + 1;

		switch (randMove)
		{
		case 1:		// ���� �̵�
			if (yPos != BEGIN)
			{
				SwapOnce(pieces + (yPos * MAXSIZE) + xPos, pieces + ((yPos - 1) * MAXSIZE) + xPos);
				yPos--;
			}
			break;
		case 2:		// �Ʒ��� �̵�
			if (yPos != END)
			{
				SwapOnce(pieces + (yPos * MAXSIZE) + xPos, pieces + ((yPos + 1) * MAXSIZE) + xPos);
				yPos++;
			}
			break;
		case 3:		// �������� �̵�
			if (xPos != BEGIN)
			{
				SwapOnce(pieces + (yPos * MAXSIZE) + xPos, pieces + (yPos * MAXSIZE) + xPos - 1);
				xPos--;
			}
			break;
		case 4:		// ���������� �̵�
			if (xPos != END)
			{
				SwapOnce(pieces + (yPos * MAXSIZE) + xPos, pieces + (yPos * MAXSIZE) + xPos + 1);
				xPos++;
			}
			break;
		}
	}

	while (true)
	{
		if (xPos == END && yPos == END)
		{
			break;
		}

		if (yPos != END)
		{
			SwapOnce(pieces + (yPos * MAXSIZE) + xPos, pieces + ((yPos + 1) * MAXSIZE) + xPos);
			yPos++;
		}
		else if (xPos != END)
		{
			SwapOnce(pieces + (yPos * MAXSIZE) + xPos, pieces + (yPos * MAXSIZE) + xPos + 1);
			xPos++;
		}
	}

	Sleep(1000);
}

void CreateAnswer(int* pieces, int* inputNum)		// ������
{
	for (int y = 0; y < *inputNum; y++)
	{
		for (int x = 0; x < *inputNum; x++)
		{
			*(pieces + (y * MAXSIZE) + x) = (y * *inputNum) + x + 1;
		}
	}

	*(pieces + ((*inputNum - 1) * MAXSIZE) + (*inputNum - 1)) = ' ';
}

void Shuffle(int* ptrArr, int arrSize)				// ����
{
	int randX1, randX2 = 0;		// ���� x�� �ΰ�
	int randY1, randY2 = 0;		// ���� y�� �ΰ� 
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++)
	{
		randX1 = rand() % arrSize;
		randX2 = rand() % arrSize;
		randY1 = rand() % arrSize;
		randY2 = rand() % arrSize;
		SwapOnce(ptrArr + (randY1 * 15) + randX1, ptrArr + (randY2 * 15) + randX2);
	}
}

void SwapOnce(int* firstNumber, int* secondNumber)
{
	int temp = 0;
	temp = *firstNumber;
	*firstNumber = *secondNumber;
	*secondNumber = temp;
}
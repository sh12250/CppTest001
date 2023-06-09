#include <iostream>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

void CreatePuzzlePiece(int* , int* );			// 퍼즐 생성 함수
void CreateAnswer(int* , int* );				// 정답지 생성 함수
void PrintPuzzle(int* , int* , int ,int );		// 퍼즐 출력 함수
void PlayPuzzle(int* , int* );					// 실제 퍼즐 플레이

void SwapOnce(int* firstNumber, int* secondNumber);
void Shuffle(int* ptrArr, int arrSize);


const int MAXSIZE = 15;


// 슬라이드 퍼플게임 구현해서 제출
// 3 ~ 6 사이의 값을 입력받아서 해당 사이즈에 맞는 슬라이딩 퍼즐 구현(normal)
// ex) 3 X 3 퍼즐
// 클리어가 불가능한 퍼즐은 존재하지 않는다(very hard)

int main()
{				
	int puzzlePiece[MAXSIZE][MAXSIZE] = { 0, };
	int userInput = 5;

	CreatePuzzlePiece((int*)puzzlePiece, &userInput);
	PlayPuzzle((int*)puzzlePiece, &userInput);

	cout << "클리어!" << endl;

	Sleep(3000);
	system("cls");
	cout << endl << endl << endl << endl << endl 
		<< "     플레이해주셔서 감사합니다"
		<< endl << endl << endl << endl << endl;


	return 0;
}

void PlayPuzzle(int* pieces, int* inputNum)
{
	const int BEGIN = 0;
	const int END = *inputNum - 1;

	int answer[MAXSIZE][MAXSIZE] = { 0, }; // 정답지용 배열

	CreateAnswer((int*)answer, inputNum);

	int clearCheck = 0;					// 정답지랑 얼마나 같은지 체크

	int xPos = END;			// 내 시작
	int yPos = END;			//    위치

	char inputChar = 0;

	while (true)
	{
		clearCheck = 0;			// 항상 0으로 초기화

		system("cls");
		PrintPuzzle(pieces, inputNum, xPos, yPos);

		if (xPos == END && yPos == END)										// 퍼즐 다 풀었나 체크
		{
			for (int y = 0; y < *inputNum; y++)
			{
				if (*(pieces + (y * MAXSIZE)) != answer[y][0])				// 빨리 빨리 나가라고 넣어봄
				{
					break;
				}

				for (int x = 0; x < *inputNum; x++)
				{
					if (*(pieces + (y * MAXSIZE) + x) != answer[y][x])		// 정답지랑 하나라도 다르면 더 볼 필요없음
					{
						break;
					}
					else
					{
						clearCheck++;
					}
				}
			}

			if (clearCheck == *inputNum * *inputNum)					// 입력받은 수로 가로, 세로가 같으니까 제곱
			{
				break;
			}
		}			// if()

		inputChar = _getch();

		if (inputChar == 'w' || inputChar == 'W')		// 위로 이동
		{
			inputChar = 0;
			if (yPos != BEGIN)
			{
				SwapOnce(pieces + (yPos * MAXSIZE) + xPos, pieces + ((yPos - 1) * MAXSIZE) + xPos);
				yPos--;
			}
		}
		else if (inputChar == 's' || inputChar == 'S')	// 아래로 이동
		{
			inputChar = 0;
			if (yPos != END)
			{
				SwapOnce(pieces + (yPos * MAXSIZE) + xPos, pieces + ((yPos + 1) * MAXSIZE) + xPos);
				yPos++;
			}
		}
		else if (inputChar == 'a' || inputChar == 'A')	// 왼쪽으로 이동
		{
			inputChar = 0;
			if (xPos != BEGIN)
			{
				SwapOnce(pieces + (yPos * MAXSIZE) + xPos, pieces + (yPos * MAXSIZE) + xPos - 1);
				xPos--;
			}
		}
		else if (inputChar == 'd' || inputChar == 'D')	// 오른쪽으로 이동
		{
			inputChar = 0;
			if (xPos != END)
			{
				SwapOnce(pieces + (yPos * MAXSIZE) + xPos, pieces + (yPos * MAXSIZE) + xPos + 1);
				xPos++;
			}
		}
		else if (inputChar == 'q' || inputChar == 'Q')	// 빡종
		{
			cout << endl << "게임을 종료합니다" << endl;
			break;
		}
		else											// 그 외 무시
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
			if (y == yPos_ && x == xPos_)					// 내 위치
			{
				printf("   ");
			}
			else if (*(pieces + (y * MAXSIZE) + x) < 10)
			{
				printf(" %d ", *(pieces + (y * MAXSIZE) + x));
			}
			else												// 나머지는 그냥 출력
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

	cout << "슬라이드 퍼즐 게임" << endl;
	cout << "3 ~ 15 사이의 숫자를 입력해 주세요" << endl;
	cout << "입력 : ";

	cin >> *inputNum;

	cout << endl << *inputNum << " X " << *inputNum << "슬라이드 퍼즐 게임" << endl << endl;

	for (int y = 0; y < *inputNum; y++)				// 퍼즐 생성
	{
		for (int x = 0; x < *inputNum; x++)
		{
			*(pieces + (y * MAXSIZE) + x) = (y * *inputNum) + x + 1;
		}
	}

	*(pieces + (yPos * MAXSIZE) + xPos) = ' ';

	srand((unsigned int)time(NULL));
	int randMove = 0;
	// 퍼즐 셔플
	for (int i = 0; i < 200; i++)
	{
		randMove = (rand() % 4) + 1;

		switch (randMove)
		{
		case 1:		// 위로 이동
			if (yPos != BEGIN)
			{
				SwapOnce(pieces + (yPos * MAXSIZE) + xPos, pieces + ((yPos - 1) * MAXSIZE) + xPos);
				yPos--;
			}
			break;
		case 2:		// 아래로 이동
			if (yPos != END)
			{
				SwapOnce(pieces + (yPos * MAXSIZE) + xPos, pieces + ((yPos + 1) * MAXSIZE) + xPos);
				yPos++;
			}
			break;
		case 3:		// 왼쪽으로 이동
			if (xPos != BEGIN)
			{
				SwapOnce(pieces + (yPos * MAXSIZE) + xPos, pieces + (yPos * MAXSIZE) + xPos - 1);
				xPos--;
			}
			break;
		case 4:		// 오른쪽으로 이동
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

void CreateAnswer(int* pieces, int* inputNum)		// 정답지
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

void Shuffle(int* ptrArr, int arrSize)				// 셔플
{
	int randX1, randX2 = 0;		// 랜덤 x값 두개
	int randY1, randY2 = 0;		// 랜덤 y값 두개 
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
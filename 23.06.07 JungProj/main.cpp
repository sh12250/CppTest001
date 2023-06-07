#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

// 문자열을 입력받아서 대문자 - 소문자 - 대문자 - 소문자 순으로 수정해서 출력하는 프로그램 작성(easy) // 32
// 위의 프로그램을 수정해서 거꾸로 출력하는 프로그램 작성(Hard)
void Change_to_BigSmall();
void Swap2(char* , char* );
void Swap(char , char );
void Shuffle(int* , int* );
// 로또번호 6개 딜레이 함수 활용해서 땅땅땅 나오게 프로그램(중복이 없어야 함)
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

	printf("로또번호는 ");
	Sleep(500);

	for (int i = 0; i < 6; i++)
	{
		printf("%d ", lottoNum[i]);
		Sleep(500);
	}
	printf(" 입니다 \n");
}

// 과제 트럼프 카드 랜덤하게 뽑아서 출력하는 프로그램
// 힌트 int cards[52] = { 0,  };
//	   char cardPatterns[4] = { '♠', '♥', '♣', '◆' } >> 안나옴
//	   A, 2, 3, 4, 5, 6, 7, 8, 9, 10 ,J ,Q ,K
// Spade / 5
//┌───────┐
//│♠      │
//│5      │
//│      5│
//│      ♠│
//└───────┘
void TrumpPick()
{
	const int SHUFFLECOUNT = 400;
	int cards[52] = { 0, };
	char cardPatterns[4][4] = {"♠", "♡", "♣", "◇"};
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

	//randIdx3 = rand() % 4;
	//
	//printf("┌───────┐ \n");
	//printf("│ %s    │ \n", cardPatterns[randIdx3]);

	//if (cards[0] == 65)
	//{
	//	printf("│ %c     │ \n", cards[0]);
	//	printf("│      %c│ \n", cards[0]);
	//}
	//else if(cards[0] > 1 && cards[0] < 10)
	//{
	//	printf("│ %d     │ \n", cards[0]);
	//	printf("│      %d│ \n", cards[0]);
	//}
	//else if (cards[0] == 10)
	//{
	//	printf("│ %d    │ \n", cards[0]);
	//	printf("│     %d│ \n", cards[0]);
	//}
	//else if (cards[0] == 74)
	//{
	//	printf("│ %c     │ \n", cards[0]);
	//	printf("│      %c│ \n", cards[0]);
	//}
	//else if (cards[0] == 75)
	//{
	//	printf("│ %c     │ \n", cards[0]);
	//	printf("│      %c│ \n", cards[0]);
	//}
	//else if (cards[0] == 81)
	//{
	//	printf("│ %c     │ \n", cards[0]);
	//	printf("│      %c│ \n", cards[0]);
	//}

	//printf("│     %s│ \n", cardPatterns[randIdx3]);
	//printf("└───────┘ \n");
	//┌───────┐
	//│♠      │
	//│5      │
	//│      5│
	//│      ♠│
	//└───────┘
}




int main(void)
{
	/*
	// 문자의 배열 string
	// 크기를 잘 봐야한다, 크기는 한번 정하면 바꿀 수 없다
	char string_[15] = "Good morning!\n"; // ' '과 '\n'은 한칸을 차지한다, 
	char stringCopy[16] = { 0, };


	// 선언과 동시에 초기화하면 문자열의 크기를 안 적어도 가능하다
	char string_2[] = "Good morning! \n";  // 마지막에 NULL 문자가 들어간다
	int numbers[10] = { 0, };

	printf("%s", string_);
	printf("문자 배열의 크기 : %d \n", sizeof(string_) * sizeof(char));
	printf("문자 배열2의 크기 : %d \n", sizeof(string_2));
	printf("정수 배열의 크기 : %d \n", sizeof(numbers));
	printf("정수 배열의 길이 : %d \n", sizeof(numbers) / sizeof(int));

	bool isNullSameZero = false;
	if (0 == '\0') // C++에서는 0이다
	{
		isNullSameZero = true;
	}
	
	printf("Null은 0과 같은 값인가? : [%d] \n", isNullSameZero);

	char string3[4];
	string3[0] = 'H';
	string3[1] = 'i';
	string3[2] = '!';
	string3[3] = '\0'; // NULL 문자 없으면 경계할 경 ?가 출력된다

	char string4[4] = "Hi!";

	printf("string3 : %s \n", string3);
	printf("string4 : %s \n", string4);
	// 문자의 배열 string
	

	// 문자열 입력받기
	char str[300] = { 0, };
	printf("문자열을 입력하시오 ( 200자 이내로 ) : ");
	// 서식 지정 문자열
	std::cin >> str;
	// 띄어쓰기 전까지 입력받음

	printf("제대로 입력을 받았는지? >> %s", str);
	// 문자열 입력받기


	// 데이터 스왑
	char str[10] = "Hello";
	char temp = '\0';

	// (str[0], str[4]) = (str[4], str[0]); // C#에서 다시 설명
	// temp = str[0];
	// str[0] = str[4]; // H << o
	// str[4] = temp; // o << o

	// 주솟값을 전달
	Swap2(&str[0], &str[4]);

	// o o
	printf("str의 0번째 : %c, ", str[0]);
	printf("str의 4번째 : %c \n", str[4]);
	printf("str : %s \n", str);
	// 데이터 스왑


	// 포인터
	int number = 100;
	int* ptrNumber = &number;

	printf("number 변수의 주소는 : %p, 할당된 값은 : %d \n", &number, number);
	printf("ptrNumber 변수의 주소는 : %p, 할당된 값은 : %p, 역참조한 값 : %d \n", &ptrNumber, ptrNumber, *ptrNumber);
	printf("ptrNumber 의 크기 : %d \n", sizeof(ptrNumber));
	// 포인터
	

	// 배열의 데이터 스왚
	// 배열 선언
	int number[10] = { 0, };
	for (int i = 0; i < 10; i++)
	{
		number[i] = i + 1;
	}
	// 배열 선언

	// 배열 출력
	printf("셔플 전 \n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", number[i]);
	}
	printf("\n");
	// 배열 출력

	// 셔플 로직
	const int shuffleCount = 100;
	int randomIdx1, randomIdx2 = 0; 
	srand((unsigned int)time(NULL));

	for (int i = 0; i < shuffleCount; i++)
	{
		randomIdx1 = rand() % 10;
		randomIdx2 = rand() % 10;
		Shuffle(&number[randomIdx1], &number[randomIdx2]);
	}
	// 셔플 로직

	// 배열 출력
	printf("셔플 후 \n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", number[i]);
	}
	printf("\n");
	// 배열 출력
	// 배열의 데이터 스왚
	
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
	printf("문자열을 입력하시오 ( 200자 이내 영어로, 띄어쓰기 금지! ) : ");

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

	printf("이렇게 바꿨습니다 : %s \n\n", str);

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
					printf("거꾸로 뒤집었습니다 : %s \n\n", str);

					break;
				}
			}
			break;
		}
	}		// for()
}

void Swap2(char* firstChar, char* secondChar)
{
	// 포인터 변수를 사용하면 전역 변수를 줄일 수 있다
	printf("스왚 전 firstChar 값 : %c, ", *firstChar);
	printf("스왚 전 secondChar 값 : %c \n", *secondChar);
	char temp = '\0';

	temp = (*firstChar);
	(*firstChar) = (*secondChar);
	(*secondChar) = temp;

	printf("스왚 후 firstChar 값 : %c, ", *firstChar);
	printf("스왚 후 secondChar 값 : %c \n", *secondChar);
}

void Swap(char firstChar, char secondChar)
{
	printf("스왚 전 firstChar 값 : %c, ", firstChar);
	printf("스왚 전 secondChar 값 : %c \n", secondChar);
	char temp = '\0';

	temp = (firstChar);
	(firstChar) = (secondChar);
	(secondChar) = temp;

	printf("스왚 후 firstChar 값 : %c, ", firstChar);
	printf("스왚 후 secondChar 값 : %c \n", secondChar);
}

void Shuffle(int* firstNumber, int* secondNumber) 
{
	int temp = 0;
	temp = *firstNumber;
	*firstNumber = *secondNumber;
	*secondNumber = temp;
}
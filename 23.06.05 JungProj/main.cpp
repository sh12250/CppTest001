#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

// 구구단 출력하는 프로그램 만들기
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
// 과제 배열 사용해서 별 5개 찍어보기.(노말)
// * * * * * 
// 배열 사용해서 아래처럼 0을 오른쪽으로 이동하며 찍어보기(하드)(이걸로 제출받음)
// 0 * * * *  >> * 0 * * * >> * * 0 * * >> * * * 0 * 
// ... 
// * * * 0 * >> * * * * 0
// 프로그램 종료
// 위의 프로그램을 수정해서 a로 0이 왼쪽, d로 0이 오른쪽 이동 가능하게 만들기(베리 하드)


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
	// 주솟값과 연산자들
	int number = 1;
	if (0 <= number) {

	}

	Desciption001(10);
	printf("Description001 함수가 끝나면 이 자리로 돌아와 출력해야한다. \n");

	// 오늘 할거 preview
	int mainNumber1 = 0;
	int mainNumber2 = 0;
	AddOne(&mainNumber1, &mainNumber2);											// ( &변수이름 ) 같이 사용, 변수가 저장된 주소값을 입력하겠다는 뜻

	printf("number의 상태 1 : %d, 2 : %d \n\n", &mainNumber1, mainNumber2);
	// 주솟값과 연산자들

	// 캐스팅 테스트
	// ( 자료형_ ) 지역변수인 것이 명확할 때 쓴다
	// ( (자료형) 변수 이름 ) 식으로 사용, 변수를 강제로 ( 자료형 )에 작성한 자료형으로 변환한다
	char char_ = 'A';
	int int_ = (int)char_;
	printf("int형 변수 : %d \n", int_);

	float floatValue = 100.123;
	int_ = floatValue;

	printf("int형 변수 : %f \n", (float)int_);
	// 캐스팅 테스트

	// 배열이란 무엇인지 실습
	// 5개의 변수를 선언
	const int MAX_ARRAY = 5;
	int numbers[MAX_ARRAY];
	//numbers[0] = 11;								2번째로 많이 사용
	//numbers[1] = 12;
	//numbers[2] = 13;
	//numbers[3] = 14;
	//numbers[4] = 15;

	for (int i = 0; i < MAX_ARRAY; i++) //					반복문으로 쉽게 값을 넣을 수 있기 때문
	{
		// 라인 오른쪽에 붉은 점은 브레이크 포인트
		// 실행은 f5, 계속은 f10, 중지는 shift + f5
		// 조사식은 실행후에 볼 수 있다
		numbers[i] = (i + 1) * 100;
		printf("배열의 값 앞은 ( 인덱스 뒤는 값 ) : ( %d, %d ) \n", i, numbers[i]);
	}

	// 배열의 또 다른 초기화 방법
	int numbers2[5] = { 10,20,30,40,50 };

	// 모든 값을 0으로 초기화							제일 많이 사용
	int numbers3[5] = { 0, };

	int number1 = 0;
	int number2 = 1;
	int number3 = 2;
	int number4 = 3;
	int number5 = 4;

	printf("배열의 값 앞은 ( 인덱스 뒤는 값 ) : ( %d, %d ) \n", 0, number1);
	printf("배열의 값 앞은 ( 인덱스 뒤는 값 ) : ( %d, %d ) \n", 1, number2);
	printf("배열의 값 앞은 ( 인덱스 뒤는 값 ) : ( %d, %d ) \n", 2, number3);
	printf("배열의 값 앞은 ( 인덱스 뒤는 값 ) : ( %d, %d ) \n", 3, number4);
	printf("배열의 값 앞은 ( 인덱스 뒤는 값 ) : ( %d, %d ) \n", 4, number5);
	// 배열이란 무엇인지 실습
	*/

	//int inputNum = 0;

	//scanf_s("%d", &inputNum);

	//NineNineTable(inputNum);

	//Homewrk();



	return 0;
}

void AddOne(int* localNumber1, int* localNumber2)								// ( 변수형* ) 같이 사용, 변수의 주소값을 입력받겠다는 뜻
{
	*localNumber1 += 1;															// ( *변수형 ) 같이 사용, 주소값을 아는 변수
	*localNumber2 += 1;
}

void Desciption001(int number) 
{
	printf("Number는 %d \n", number);
}
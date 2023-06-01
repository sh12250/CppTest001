#include <iostream>
#include <stdio.h>

// 1. 정수 3개를 입력받아서 , x + y * z 의 결과를 출력하는 프로그램 작성해보기
// 입력은 scanf_s 사용, 한 라인에서 3개의 입력을 받는다
// 함수를 활용
// 사칙연산 순서에 유의

// x + y * z 를 계산해서 출력하는 함수
void FourArithmeticOperation(int num1, int num2, int num3)
{
	int result = num1 + num2 * num3;

	printf("x + y * z : %d \n", result);
}

// (x - y) * (y + z) * (z % x) 를 계산해서 출력하는 함수
void FourAruthmeticOperationExtention(int num1, int num2, int num3)
{
	int result = (num1 - num2) * (num2 + num3) * (num3 % num1);

	printf("%d * %d * %d : %d \n", (num1 - num2), (num2 + num3), (num3 % num1), result);
}

// 2. 원의 반지름을 입력 받아서 원의 넓이를 출력하는 프로그램 작성
// 함수를 사용할 것, 전방선언 해 볼 것
// 원의 반지름은 정수

// CircleArea함수를 전방선언
void CircleArea(float pi, int radius);

// 3. 캐릭터 하나를 입력받아서 해당 문자가 특수문자인지 아닌지 체크해서 알려주는 프로그램 작성
// 대문자 알파벳 아니고, 소문자 알파벳 아니면 특수문자로 인정(eazy)
// 아무거나 입력해 볼텐데, 오직 특수문자인 경우에만 인정(hard)
// 함수를 활용할 것, 전방선언 활용할 것

void IsSpecialCharacter(char character);
void OnlySpecialCharacter(char character);

// 4. 1 ~ 10까지 while문으로 출력해보기

// 5. 유저에게 정사각형의 사이즈를 입력 받아서
// '*'로 출력하는 프로그램 만들기
// 유저 입력은 3 ~ 10 사이로만 입력한다

void SquareMaker(int squareSize) 
{
	int width = squareSize;
	int length = squareSize;

	while (length > 0) 
	{
		width = squareSize;

		while (width > 0)
		{
			printf("* ");
			width -= 1;

			if (width == 0)
			{
				printf("\n");
			}
		}

		length -= 1;
	}
}

void SpecialSquare(int size) 
{
	if (size % 2 == 0) 
	{
		size -= 1;
	}

	int space = 1;
	int save = 1;

	int widthLeft = (size - space) / 2;
	int widthRight = widthLeft;
	int lengthTop = (size - 1) / 2;
	int lengthBottom = lengthTop;

	while (lengthTop > 0)
	{
		widthLeft = (size - space) / 2;
		widthRight = widthLeft;


		while (widthLeft > 0)
		{
			printf("* ");
			widthLeft -= 1;
		}

		if (widthLeft == 0)
		{
			while (space > 0)
			{
				printf("  ");
				space -= 1;
			}

			if (space == 0) {
				save += 2;
				space = save;
			}
		}

		while (widthRight > 0)
		{
			printf("* ");
			widthRight -= 1;

			if (widthRight == 0) {
				printf("\n");
			}
		}

		lengthTop -= 1;
	}

	printf("\n");

	while (lengthBottom > 0) 
	{
		save -= 2;
		space = save;
		widthLeft = (size - save) / 2;
		widthRight = widthLeft;


		while (widthLeft > 0)
		{
			printf("* ");
			widthLeft -= 1;
		}

		if (widthLeft == 0)
		{
			while (space > 0)
			{
				printf("  ");
				space -= 1;
			}

			if (space == 0) {
				if (save != size)
				{
					space = save;
				}
			}
		}

		while (widthRight > 0)
		{
			printf("* ");
			widthRight -= 1;

			if (widthRight == 0) {
				printf("\n");
			}
		}

		lengthBottom -= 1;
	}
}

int main() 
{

	int loopCount;

	scanf_s("%d", &loopCount);

	//SquareMaker(loopCount);
	SpecialSquare(loopCount);



	/*
	//
	while (loopCount <= 5)
	{
		printf("* * * * * \n");
		loopCount += 1;
	}
	//

	//
	while (loopcount >= 1) 
	{
		printf("hello world! 몇 번째 돌고 있나? : %d \n", loopcount);
		loopcount -= 1;
	}		// loop : 루프 종료
	//
	
	//
	bool isSame = ('A' == 65);

	char someAlphabet = 'a11';
	bool isBigAlphabet = ('A' <= someAlphabet && 'Z' >= someAlphabet);
	bool isSmallAlphabet = ('a' <= someAlphabet && 'z' >= someAlphabet);
	bool isNumber = ('0' <= someAlphabet && '9' >= someAlphabet);

	if (isBigAlphabet) 
	{
		printf("영문 대문자 입니다. \n");
	}	// if문은 조건식이 참이면 스코프 안의 내용을 진행하고, 거짓이면 건너뛴다
	else if (isSmallAlphabet) 
	{
		printf("영문 소문자 입니다. \n");
	}
	else if (isNumber) 
	{ 
		printf("숫자 입니다. \n");
	}
	else 
	{
		printf("잘 모르겠습니다. \n");
	}	// 위의 조건식에서 참이 아닌, 다른 모든 경우 스코프 안의 내용을 진행한다

	// 한 줄일 때, 스코프를 없앨 수 있지만 !절대! 권장하지 않는다
	//

	
	//
	char charValue;
	scanf_s("%c", &charValue);

	//IsSpecialCharacter(charValue);
	OnlySpecialCharacter(charValue);
	//
	
	//
	char charValue = 'A';

	printf("char 출력할 때는 C로 해보자. >> %c \n", 97); 
	// A를 %d로 받아오면 65가 나온다

	bool isSame = ('A' == 65);
	printf("진짜로 같은가? %d \n", isSame);
	// 결과는 1, 진짜로 같다!!

	char someAlphabet = 'a';
	bool isBigAlphabet = ('A' <= someAlphabet);
	printf("SomeAlphabet은 대문자인가? %d \n", isBigAlphabet);
	// 

	// 상수 이름은 대문자로만 작성
	const float PI = 3.141592f;

	int radius;
	printf("원의 반지름 : ");
	scanf_s("%d", &radius);

	CircleArea(PI, radius);
	//
	
	//
	char charvalue = 'A';			// 문자 하나를 저장하기 위한 데이터 타입
	short shortvalue = 10;			// int 보다 작은 수를 저장하기 위한 데이터 타입
	int intvalue = 100;				// 가장 만만한 수를 저장하기 위한 데이터 타입
	long longvalue = 200;			// int가 커져서 이제 잘 안쓰는 데이터 타입
	long long longlongvalue = 1000; // int보다 큰 수를 저장하기 위한 데이터 타입

	float floatvalue = 10.1;				// 가장 만만한 실수를 저장하기 위한 데이터 타입
	double doublevalue = 100.1;				// float 보다 큰 실수를 저장하기 위한 데이터 타입
	long double longdoublevalue = 200.1;	// double 보다 큰 실수를 저장하기 위한 데이터 타입

	printf("char 의 크기는? %d byte. \n", sizeof(charvalue));
	printf("short 의 크기는? %d byte. \n", sizeof(shortvalue));
	printf("int 의 크기는? %d byte. \n", sizeof(intvalue));
	printf("long 의 크기는? %d byte. \n", sizeof(longvalue));
	printf("long long 의 크기는? %d byte. \n\n", sizeof(longlongvalue));

	printf("float 의 크기는? %d byte. \n", sizeof(floatvalue));
	printf("double 의 크기는? %d byte. \n", sizeof(doublevalue));
	printf("long double 의 크기는? %d byte. \n\n", sizeof(longdoublevalue));
	//

	//
	int unknownx, unknowny, unknownz;

	printf("정수 3개를 입력해주세요 : ");
	scanf_s("%d, %d, %d", &unknownx, &unknowny, &unknownz);

	// & 연산자는 메모리 주소를 알려주는 연산자 

	FourArithmeticOperation(unknownx, unknowny, unknownz);
	FourAruthmeticOperationExtention(unknownx, unknowny, unknownz);
	//

	//
	// { 변수 선언부
	int result;
	int num1, num2;
	// } 변수 선언부
	
	// { 사용자 입력받는 로직
	printf("정수 one : ");
	scanf_s("%d", &num1);
	printf("정수 two : ");
	scanf_s("%d", &num2);
	// } 사용자 입력받는 로직

	// { 사용자 입력받는 로직 라인 절약 ver 
	printf("정수 2개를 입력해주세요 : ");
	scanf_s("%d %d", &num1, &num2);
	// } 사용자 입력받는 로직 라인 절약 ver

	// { 실제 연산하는 로직 / 플러스 연산
	result = num1 + num2;
	printf("%d + %d = %d \n", num1, num2, result);
	// } 실제 연산하는 로직 / 플러스 연산
	//
	*/

	// 함수를 여기서 끝내겠다는 의미
	return 0; 
}		// main()		<너무 길면 어디있는지 보이지 않기 때문에 함수의 끝을 함수의 이름으로 표시>

// 원주율 pi와 반지름 radius를 입력받아 소수점 2자릿수까지만 원의 넓이를 출력하는 함수
void CircleArea(float pi, int radius)
{
	printf("원의 넓이 : %.2f \n", pi * radius * radius);
}

void IsSpecialCharacter(char character)
{
	bool testBig = ('A' <= character && 'Z' >= character);
	bool testSmall = ('a' <= character && 'z' >= character);

	printf((testBig == 1) ? "대문자 입니다! \n" : (testSmall == 1 ? "소문자입니다! \n" : "특수문자입니다! \n"));
}

void OnlySpecialCharacter(char character) 
{
	bool testSpChar = ('!' <= character && '~' >= character); 
	bool testNum = ('0' <= character && '9' >= character);
	bool testBig = ('A' <= character && 'Z' >= character); 
	bool testSmall = ('a' <= character && 'z' >= character); 
	
	printf((testSpChar == 1) && (testNum != 1 && testBig != 1 && testSmall != 1) ? "특수문자 입니다! \n" : "특수문자가 아닙니다! \n");
}
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void Desciption001(int ), AddOne(int* , int* );

int main() 
{
	/*

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

	*/


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
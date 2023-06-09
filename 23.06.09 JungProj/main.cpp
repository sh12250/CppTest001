#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** args)		// 된다
{
	int size = 10;
	int userInput = 0;

	cin >> userInput;

	int numbers1[10] = { 0, };
	// new 동적 할당
	int* numbers2 = new int[userInput];
	// 배열의 크기에 변수를 넣어줄 수 있다
	// heap에 할당된다 컴퓨터 끄고 킬 때까지 저장된다


	for (int i = 0; i < userInput; i++)
	{
		numbers2[i] = i + 1;
	}

	for (int i = 0; i < userInput; i++)
	{
		printf("%d \n", numbers2[i]);
	}

	// 프로그램 종료 전에 해준다
	delete[] numbers2;



	return 0;
}
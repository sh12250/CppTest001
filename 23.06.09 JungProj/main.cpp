#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** args)		// �ȴ�
{
	int size = 10;
	int userInput = 0;

	cin >> userInput;

	int numbers1[10] = { 0, };
	// new ���� �Ҵ�
	int* numbers2 = new int[userInput];
	// �迭�� ũ�⿡ ������ �־��� �� �ִ�
	// heap�� �Ҵ�ȴ� ��ǻ�� ���� ų ������ ����ȴ�


	for (int i = 0; i < userInput; i++)
	{
		numbers2[i] = i + 1;
	}

	for (int i = 0; i < userInput; i++)
	{
		printf("%d \n", numbers2[i]);
	}

	// ���α׷� ���� ���� ���ش�
	delete[] numbers2;



	return 0;
}
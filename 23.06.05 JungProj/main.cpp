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
	printf("Description001 �Լ��� ������ �� �ڸ��� ���ƿ� ����ؾ��Ѵ�. \n");

	// ���� �Ұ� preview
	int mainNumber1 = 0;
	int mainNumber2 = 0;
	AddOne(&mainNumber1, &mainNumber2);											// ( &�����̸� ) ���� ���, ������ ����� �ּҰ��� �Է��ϰڴٴ� ��

	printf("number�� ���� 1 : %d, 2 : %d \n\n", &mainNumber1, mainNumber2);

	*/


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
#include <iostream>
#include <stdio.h>

// 1. ���� 3���� �Է¹޾Ƽ� , x + y * z �� ����� ����ϴ� ���α׷� �ۼ��غ���
// �Է��� scanf_s ���, �� ���ο��� 3���� �Է��� �޴´�
// �Լ��� Ȱ��
// ��Ģ���� ������ ����

// x + y * z �� ����ؼ� ����ϴ� �Լ�
void FourArithmeticOperation(int num1, int num2, int num3)
{
	int result = num1 + num2 * num3;

	printf("x + y * z : %d \n", result);
}

// (x - y) * (y + z) * (z % x) �� ����ؼ� ����ϴ� �Լ�
void FourAruthmeticOperationExtention(int num1, int num2, int num3)
{
	int result = (num1 - num2) * (num2 + num3) * (num3 % num1);

	printf("%d * %d * %d : %d \n", (num1 - num2), (num2 + num3), (num3 % num1), result);
}

// 2. ���� �������� �Է� �޾Ƽ� ���� ���̸� ����ϴ� ���α׷� �ۼ�
// �Լ��� ����� ��, ���漱�� �� �� ��
// ���� �������� ����

// CircleArea�Լ��� ���漱��
void CircleArea(float pi, int radius);

// 3. ĳ���� �ϳ��� �Է¹޾Ƽ� �ش� ���ڰ� Ư���������� �ƴ��� üũ�ؼ� �˷��ִ� ���α׷� �ۼ�
// �빮�� ���ĺ� �ƴϰ�, �ҹ��� ���ĺ� �ƴϸ� Ư�����ڷ� ����(eazy)
// �ƹ��ų� �Է��� ���ٵ�, ���� Ư�������� ��쿡�� ����(hard)
// �Լ��� Ȱ���� ��, ���漱�� Ȱ���� ��

void IsSpecialCharacter(char character);
void OnlySpecialCharacter(char character);

// 4. 1 ~ 10���� while������ ����غ���

// 5. �������� ���簢���� ����� �Է� �޾Ƽ�
// '*'�� ����ϴ� ���α׷� �����
// ���� �Է��� 3 ~ 10 ���̷θ� �Է��Ѵ�

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
		printf("hello world! �� ��° ���� �ֳ�? : %d \n", loopcount);
		loopcount -= 1;
	}		// loop : ���� ����
	//
	
	//
	bool isSame = ('A' == 65);

	char someAlphabet = 'a11';
	bool isBigAlphabet = ('A' <= someAlphabet && 'Z' >= someAlphabet);
	bool isSmallAlphabet = ('a' <= someAlphabet && 'z' >= someAlphabet);
	bool isNumber = ('0' <= someAlphabet && '9' >= someAlphabet);

	if (isBigAlphabet) 
	{
		printf("���� �빮�� �Դϴ�. \n");
	}	// if���� ���ǽ��� ���̸� ������ ���� ������ �����ϰ�, �����̸� �ǳʶڴ�
	else if (isSmallAlphabet) 
	{
		printf("���� �ҹ��� �Դϴ�. \n");
	}
	else if (isNumber) 
	{ 
		printf("���� �Դϴ�. \n");
	}
	else 
	{
		printf("�� �𸣰ڽ��ϴ�. \n");
	}	// ���� ���ǽĿ��� ���� �ƴ�, �ٸ� ��� ��� ������ ���� ������ �����Ѵ�

	// �� ���� ��, �������� ���� �� ������ !����! �������� �ʴ´�
	//

	
	//
	char charValue;
	scanf_s("%c", &charValue);

	//IsSpecialCharacter(charValue);
	OnlySpecialCharacter(charValue);
	//
	
	//
	char charValue = 'A';

	printf("char ����� ���� C�� �غ���. >> %c \n", 97); 
	// A�� %d�� �޾ƿ��� 65�� ���´�

	bool isSame = ('A' == 65);
	printf("��¥�� ������? %d \n", isSame);
	// ����� 1, ��¥�� ����!!

	char someAlphabet = 'a';
	bool isBigAlphabet = ('A' <= someAlphabet);
	printf("SomeAlphabet�� �빮���ΰ�? %d \n", isBigAlphabet);
	// 

	// ��� �̸��� �빮�ڷθ� �ۼ�
	const float PI = 3.141592f;

	int radius;
	printf("���� ������ : ");
	scanf_s("%d", &radius);

	CircleArea(PI, radius);
	//
	
	//
	char charvalue = 'A';			// ���� �ϳ��� �����ϱ� ���� ������ Ÿ��
	short shortvalue = 10;			// int ���� ���� ���� �����ϱ� ���� ������ Ÿ��
	int intvalue = 100;				// ���� ������ ���� �����ϱ� ���� ������ Ÿ��
	long longvalue = 200;			// int�� Ŀ���� ���� �� �Ⱦ��� ������ Ÿ��
	long long longlongvalue = 1000; // int���� ū ���� �����ϱ� ���� ������ Ÿ��

	float floatvalue = 10.1;				// ���� ������ �Ǽ��� �����ϱ� ���� ������ Ÿ��
	double doublevalue = 100.1;				// float ���� ū �Ǽ��� �����ϱ� ���� ������ Ÿ��
	long double longdoublevalue = 200.1;	// double ���� ū �Ǽ��� �����ϱ� ���� ������ Ÿ��

	printf("char �� ũ���? %d byte. \n", sizeof(charvalue));
	printf("short �� ũ���? %d byte. \n", sizeof(shortvalue));
	printf("int �� ũ���? %d byte. \n", sizeof(intvalue));
	printf("long �� ũ���? %d byte. \n", sizeof(longvalue));
	printf("long long �� ũ���? %d byte. \n\n", sizeof(longlongvalue));

	printf("float �� ũ���? %d byte. \n", sizeof(floatvalue));
	printf("double �� ũ���? %d byte. \n", sizeof(doublevalue));
	printf("long double �� ũ���? %d byte. \n\n", sizeof(longdoublevalue));
	//

	//
	int unknownx, unknowny, unknownz;

	printf("���� 3���� �Է����ּ��� : ");
	scanf_s("%d, %d, %d", &unknownx, &unknowny, &unknownz);

	// & �����ڴ� �޸� �ּҸ� �˷��ִ� ������ 

	FourArithmeticOperation(unknownx, unknowny, unknownz);
	FourAruthmeticOperationExtention(unknownx, unknowny, unknownz);
	//

	//
	// { ���� �����
	int result;
	int num1, num2;
	// } ���� �����
	
	// { ����� �Է¹޴� ����
	printf("���� one : ");
	scanf_s("%d", &num1);
	printf("���� two : ");
	scanf_s("%d", &num2);
	// } ����� �Է¹޴� ����

	// { ����� �Է¹޴� ���� ���� ���� ver 
	printf("���� 2���� �Է����ּ��� : ");
	scanf_s("%d %d", &num1, &num2);
	// } ����� �Է¹޴� ���� ���� ���� ver

	// { ���� �����ϴ� ���� / �÷��� ����
	result = num1 + num2;
	printf("%d + %d = %d \n", num1, num2, result);
	// } ���� �����ϴ� ���� / �÷��� ����
	//
	*/

	// �Լ��� ���⼭ �����ڴٴ� �ǹ�
	return 0; 
}		// main()		<�ʹ� ��� ����ִ��� ������ �ʱ� ������ �Լ��� ���� �Լ��� �̸����� ǥ��>

// ������ pi�� ������ radius�� �Է¹޾� �Ҽ��� 2�ڸ��������� ���� ���̸� ����ϴ� �Լ�
void CircleArea(float pi, int radius)
{
	printf("���� ���� : %.2f \n", pi * radius * radius);
}

void IsSpecialCharacter(char character)
{
	bool testBig = ('A' <= character && 'Z' >= character);
	bool testSmall = ('a' <= character && 'z' >= character);

	printf((testBig == 1) ? "�빮�� �Դϴ�! \n" : (testSmall == 1 ? "�ҹ����Դϴ�! \n" : "Ư�������Դϴ�! \n"));
}

void OnlySpecialCharacter(char character) 
{
	bool testSpChar = ('!' <= character && '~' >= character); 
	bool testNum = ('0' <= character && '9' >= character);
	bool testBig = ('A' <= character && 'Z' >= character); 
	bool testSmall = ('a' <= character && 'z' >= character); 
	
	printf((testSpChar == 1) && (testNum != 1 && testBig != 1 && testSmall != 1) ? "Ư������ �Դϴ�! \n" : "Ư�����ڰ� �ƴմϴ�! \n");
}
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

// ���ڿ��� �Է¹޾Ƽ� �빮�� - �ҹ��� - �빮�� - �ҹ��� ������ �����ؼ� ����ϴ� ���α׷� �ۼ�(easy) // 32
// ���� ���α׷��� �����ؼ� �Ųٷ� ����ϴ� ���α׷� �ۼ�(easy)

void Change_to_BigSmall() {
	char str[300] = { 0, };
	int change = 0;
	printf("���ڿ��� �Է��Ͻÿ� ( 200�� �̳� �����, ���� ����! ) : ");

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

	printf("�̷��� �ٲ���ϴ� : %s \n\n", str);

	int strLength = 0;

	for (int i = 0; i < sizeof(str); i++) 
	{
		char saveChar = 0;
		if (str[i] != NULL) 
		{
			strLength++;
		}
		else if(str[i] == NULL)
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
					printf("�Ųٷ� ���������ϴ� : %s \n\n", str);

					break;
				}
			}
			break;
		}
	}		// for()
}

int main(void)
{

	/*
	// ������ �迭 string
	// ũ�⸦ �� �����Ѵ�, ũ��� �ѹ� ���ϸ� �ٲ� �� ����
	char string_[15] = "Good morning!\n"; // ' '�� '\n'�� ��ĭ�� �����Ѵ�, 
	char stringCopy[16] = { 0, };


	// ����� ���ÿ� �ʱ�ȭ�ϸ� ���ڿ��� ũ�⸦ �� ��� �����ϴ�
	char string_2[] = "Good morning! \n";  // �������� NULL ���ڰ� ����
	int numbers[10] = { 0, };

	printf("%s", string_);
	printf("���� �迭�� ũ�� : %d \n", sizeof(string_) * sizeof(char));
	printf("���� �迭2�� ũ�� : %d \n", sizeof(string_2));
	printf("���� �迭�� ũ�� : %d \n", sizeof(numbers));
	printf("���� �迭�� ���� : %d \n", sizeof(numbers) / sizeof(int));

	bool isNullSameZero = false;
	if (0 == '\0') // C++������ 0�̴�
	{
		isNullSameZero = true;
	}
	
	printf("Null�� 0�� ���� ���ΰ�? : [%d] \n", isNullSameZero);

	char string3[4];
	string3[0] = 'H';
	string3[1] = 'i';
	string3[2] = '!';
	string3[3] = '\0'; // NULL ���� ������ ����� �� ?�� ��µȴ�

	char string4[4] = "Hi!";

	printf("string3 : %s \n", string3);
	printf("string4 : %s \n", string4);
	// ������ �迭 string
	

	// ���ڿ� �Է¹ޱ�
	char str[300] = { 0, };
	printf("���ڿ��� �Է��Ͻÿ� ( 200�� �̳��� ) : ");
	// ���� ���� ���ڿ�
	std::cin >> str;
	// ���� ������ �Է¹���

	printf("����� �Է��� �޾Ҵ���? >> %s", str);
	// ���ڿ� �Է¹ޱ�
	*/

	Change_to_BigSmall();

	return 0;
}
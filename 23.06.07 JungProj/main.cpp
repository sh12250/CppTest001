#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

// 문자열을 입력받아서 대문자 - 소문자 - 대문자 - 소문자 순으로 수정해서 출력하는 프로그램 작성(easy) // 32
// 위의 프로그램을 수정해서 거꾸로 출력하는 프로그램 작성(easy)

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
					printf("거꾸로 뒤집었습니다 : %s \n\n", str);

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
	*/

	Change_to_BigSmall();

	return 0;
}
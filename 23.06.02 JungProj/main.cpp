//헤더파일 선언부
#include <iostream>
#include <stdio.h>
#include <conio.h> 
#include <time.h>
#include <windows.h>
// #include <stdlib.h>

// 1. 반복문 사용해서 user에게 아무 숫자나 입력받는다.
// 그 숫자가 홀수인지 짝수인지 구별해서 출력하는 프로그램 만들기
// 유저가 종료하기 전까지 반복
void OddEvenProgram(int loop), Description();

// 2. 홀짝 게임
// 컴퓨터가 주사위를 2번 굴린다
// 플레이어는 숫자를 미리 볼 수 있다. 총합이 홀수인지 짝수인지 출력 (easy)
void OddEvenGameEasy() {
	printf("홀짝 게임 \n");
	printf("시작할까요? \npress any key... \n");
	_getch();

	srand(time(NULL));

	int diceNum = 0;
	int totalNum = 0;

	for (int loopCount = 2; loopCount > 0; loopCount--) {
		diceNum = (rand() % 6) + 1;
		totalNum += diceNum;
		printf("%d, ", diceNum);
	}

	printf("\n주사위 합 : %d, ", totalNum);

	if (totalNum % 2 == 0) {
		printf("짝! \n");
	}
	else {
		printf("홀! \n");
	}
}

// 플레이어는 숫자를 미리 볼 수 없다. 플레이어가 홀, 짝을 맞춰야 한다 (normal) + 반복
void OddEvenGameNormal() {
	printf("홀짝 맞추기 게임! \n");
	printf("시작할까요? press any key... \n");
	_getch();

	int diceNum = 0;
	int quitGuide = 1;
	int userInput = 3;
	
	srand(time(NULL));
	while (true) {
		int totalNum = 0;

		if (userInput == 0) {
			printf("게임을 종료합니다. \n");
			break;
		}

		for (int i = 2; i > 0; i--) {
			diceNum = (rand() % 6) + 1;
			totalNum += diceNum;
		}

		printf("\n홀? 짝? \n");
		printf("홀이면 [1] 짝이면 [2] 종료하시려면 [0] 을 입력하세요. \n");

		scanf_s("%d", &userInput);

		if (userInput == 0) {
			printf("게임을 종료합니다... \n\n");
			_getch();
			break;
		}
		else if (userInput == 1){
			if (totalNum % 2 == 1) {
				printf("%d 정답! \n\n", totalNum);
			}
			else {
				printf("%d 오답... \n\n", totalNum);
			}
		}
		else if (userInput == 2){
			if (totalNum % 2 == 0) {
				printf("%d 정답! \n\n", totalNum);
			}
			else {
				printf("%d 오답... \n\n", totalNum);
			}
		}
		else {
			printf("??? 잘 모르겠어요. \n\n");
		}

		printf("계속하시려면 엔터를 눌러주세요. ");
		_getch();
	}		// while()
}

// 3. 크리티컬 데미지 주는 함수
// 60% 확률로 크리티컬 데미지 주는 함수로 만들기
// Loop 사용해서 종료 입력 전까지 반복
// 플레이어가 어떤 상태인지 출력해서 보여줄 것(왜 크리티컬인지, 아닌지 알 수 있어야함)
void CriticalDamage();

int mainNum = 10; // 전역(글로벌) 변수라고 한다 





int main() 
{
	// OddEvenProgram(loopCount);
	
	// OddEvenGameEasy();

	// OddEvenGameNormal();

	// Description();

	CriticalDamage();

	// 파스칼 스타일(최근), 헝가리안 스타일(옛날)

	/*

	//
	int randomNum = 0;
	const int MAX_DICE_VALUE = 6;
	srand(time(NULL));


	printf("주사위 프로그램 \n\n");
	_getch();
	printf("컴퓨터가 뽑은 3개의 주사위 값 -> ");

	for (int i = 0; i < 3; i++) {
		Sleep(1000);
		randomNum = (rand() % MAX_DICE_VALUE) + 1; //	6으로 하면 매직넘버, 나밖에 모른다. 상수로 선언하자
		printf("%d ", randomNum);
	}
	Sleep(1000);
	printf("\n\n");
	printf("프로그램 종료 \n\n");
	//

	//
	// 여기서 키 값을 바꿔볼 예정
	srand(time(NULL));		// 이것이 rand() 함수의 키 값을 바꿔주는 함수
	// NULL은 0이다

	// Ramdom 이해하기
	int randomNumber1, randomNumber2, randomNumber3 = 0;
	randomNumber1 = (rand() % 6) + 1;		// rand() 함수를 사용해서 랜덤값을 받는다
	randomNumber2 = (rand() % 6) + 1;		// 주사위를 만들고 싶으면 6으로 mod 연산한 후 1을 더한다
	randomNumber3 = (rand() % 6) + 1;

	// rand - (rand / 10) * 10

	printf("Random number?? %d \n", randomNumber1);
	printf("Random number?? %d \n", randomNumber2);
	printf("Random number?? %d \n", randomNumber3);

	// 시드 값, 키 값, 아이디 값
	//

	//
	printf("[Main()] number 값은? %d \n", number);
	printf("For문은 반복문이다. 이렇게 돌아간다. \n");

	int loopCount = 1; //	지역(로컬) 변수라고 한다
	for ( 여기는 비어도 실행됨 ; loopCount <= 5; loopCount += 1) { //	(변수 초기화; 조건식; 루프마다 변수 값에 1 더하기)
		printf("어떻게 돌아가고 있는 것이지??? \n");
	}
	printf("\n");
	//

	// Switch / Case 문

	char userInput = 0;
	printf("User Input : ");
	// _getch()함수를 사용하기 위해서는 <conio.h> 헤더파일이 필요하다
	userInput = _getch();
	// 입력받는 중엔 문자가 보이지 않는다

	
	// scanf_s("%d", &userInput);

	switch (userInput) {
	case 'a':
		printf("이것은 가위 \n");
		break;
	case 'b':
		printf("이것은 바위 \n");
		break;
	case 'c':
		printf("이것은 보 \n");
		break;
	default:
		printf("처리되지 않은 예외 입력입니다. \n");
		break;
	}

	printf("Press any key... \n");
	_getch();
	// 이런식으로 사용하면 키입력을 받은 후 프로그램이 종료된다

	
	//
	int userNumber = 0;
	int loopCount = 1;

	while (true) {
		printf("숫자를 입력하시오 : ");
		scanf_s("%d", &userNumber);

		// 탈출 조건
		if (userNumber <= 0) {
			printf("\n프로그램을 종료합니다. \n");
			return 0;
		}	// if : invalid values
		
		if (userNumber % 2 == 0) { 
			printf("[%d]는 짝수 입니다. \n", userNumber);
			continue;
		}
		//탈출 조건을 앞에 작성하면 else가 필요없어진다
		printf("[%d]는 홀수 입니다. \n", userNumber);
	}

	

	
	//
	while (loopCount > 0){
		if (loopCount == 1) {
			printf("[튜토리얼] 만약 게임을 만들려고 한다면 이런식으로 \n\n");
		}

		printf("[sysem] 당신을 플레이어입니다. \n");
		printf("수행할 액션을 입력해주세요 \n");
		scanf_s("%c", &userInput);

		if (userInput == 'q' || userInput == 'Q') {
			printf("[System] 프로그램을 종료합니다. \n");
			break;
		}
		else {
			printf("[Systme] 해당 입력은 정의되어 있지 않습니다. \n");
			loopCount += 1;
			continue;
		}

		loopCount += 1;


		if (loopcount == 7) 
		{ 
			loopcount += 1;
			continue; 
		}

		printf("이것은 무조건 출력되는 문장이다. %d \n", loopcount);
		
	}	// loopCount 만큼 반복
	//
	*/

	return 0;
}

void OddEvenProgram(int loop) {
	int userInputNum;
	int quitGuide = 1;

	while (true)
	{
		printf("숫자를 입력해주세요. : ");

		scanf_s("%d", &userInputNum);

		if (userInputNum < 0) {
			printf("프로그램을 종료합니다. \n");
			break;
		}

		if ((userInputNum % 2) == 0) {
			if (userInputNum == 0) {
				printf("%d : 0 \n", userInputNum);
				printf("다음 ");
				continue;
			}
			printf("%d : 짝수 \n", userInputNum);
		}
		else {
			printf("%d : 홀수 \n", userInputNum);
		}

		if (quitGuide == 1) {
			printf("종료를 원하시면 음수를 입력해주세요. \n");
			quitGuide -= 1;
		}

		printf("다음 ");
	}
}

void CriticalDamage() {
	const int PLAYERATK = 160;
	const int CRITICALRATE = 60;
	const float CRITICALDAMAGERATE = 1.5f;
	float damageGive = PLAYERATK;
	const int ENEMYHP = 2000;
	int enemyCurhp = ENEMYHP;
	int rate = 0;

	srand(time(NULL));

	printf("============================================================\n");
	printf("[info] 치명타 확률이 [%d]이하면 치명타가 터진다. \n", CRITICALRATE);
	Sleep(1000);

	while (true) {
		if (enemyCurhp <= 0) {
			enemyCurhp = 0;

			printf("============================================================\n");
			printf("Enemy ( %d / %d )", enemyCurhp, ENEMYHP);

			for (int i = 5; i > 0; i--) {
				Sleep(300);
				printf("\n");
			}

			printf("적은 쓰러졌다... \n");
			Sleep(500);
			printf("\n전투 승리!!! \n");
			break;
		}


		printf("============================================================\n");
		printf("Enemy ( %d / %d ) \n\n\n\n\n", enemyCurhp, ENEMYHP);

		rate = (rand() % 100) + 1;

		if (rate < CRITICALRATE) {
			printf("치명타 확률 [%d]이 [%d]이하다! \n", rate, CRITICALRATE);

			printf("치명타★ \n%.0f의 데미지를 주었다! \n\n", damageGive * CRITICALDAMAGERATE);
			enemyCurhp -= damageGive * CRITICALDAMAGERATE;
		}
		else {
			printf("치명타 확률 [%d]이 [%d]를 넘었다. \n", rate, CRITICALRATE);

			printf("평타☆ \n%.0f의 데미지를 주었다. \n\n", damageGive);
			enemyCurhp -= damageGive;
		}

		printf("다음 턴을 진행하시겠습니까? \n\n");
		_getch();
		system("cls");
		Sleep(500);
	}		//		while()





}

void Description() {

}
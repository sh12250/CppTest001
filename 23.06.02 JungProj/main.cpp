//������� �����
#include <iostream>
#include <stdio.h>
#include <conio.h> 
#include <time.h>
#include <windows.h>
// #include <stdlib.h>

// 1. �ݺ��� ����ؼ� user���� �ƹ� ���ڳ� �Է¹޴´�.
// �� ���ڰ� Ȧ������ ¦������ �����ؼ� ����ϴ� ���α׷� �����
// ������ �����ϱ� ������ �ݺ�
void OddEvenProgram(int loop), Description();

// 2. Ȧ¦ ����
// ��ǻ�Ͱ� �ֻ����� 2�� ������
// �÷��̾�� ���ڸ� �̸� �� �� �ִ�. ������ Ȧ������ ¦������ ��� (easy)
void OddEvenGameEasy() {
	printf("Ȧ¦ ���� \n");
	printf("�����ұ��? \npress any key... \n");
	_getch();

	srand(time(NULL));

	int diceNum = 0;
	int totalNum = 0;

	for (int loopCount = 2; loopCount > 0; loopCount--) {
		diceNum = (rand() % 6) + 1;
		totalNum += diceNum;
		printf("%d, ", diceNum);
	}

	printf("\n�ֻ��� �� : %d, ", totalNum);

	if (totalNum % 2 == 0) {
		printf("¦! \n");
	}
	else {
		printf("Ȧ! \n");
	}
}

// �÷��̾�� ���ڸ� �̸� �� �� ����. �÷��̾ Ȧ, ¦�� ����� �Ѵ� (normal) + �ݺ�
void OddEvenGameNormal() {
	printf("Ȧ¦ ���߱� ����! \n");
	printf("�����ұ��? press any key... \n");
	_getch();

	int diceNum = 0;
	int quitGuide = 1;
	int userInput = 3;
	
	srand(time(NULL));
	while (true) {
		int totalNum = 0;

		if (userInput == 0) {
			printf("������ �����մϴ�. \n");
			break;
		}

		for (int i = 2; i > 0; i--) {
			diceNum = (rand() % 6) + 1;
			totalNum += diceNum;
		}

		printf("\nȦ? ¦? \n");
		printf("Ȧ�̸� [1] ¦�̸� [2] �����Ͻ÷��� [0] �� �Է��ϼ���. \n");

		scanf_s("%d", &userInput);

		if (userInput == 0) {
			printf("������ �����մϴ�... \n\n");
			_getch();
			break;
		}
		else if (userInput == 1){
			if (totalNum % 2 == 1) {
				printf("%d ����! \n\n", totalNum);
			}
			else {
				printf("%d ����... \n\n", totalNum);
			}
		}
		else if (userInput == 2){
			if (totalNum % 2 == 0) {
				printf("%d ����! \n\n", totalNum);
			}
			else {
				printf("%d ����... \n\n", totalNum);
			}
		}
		else {
			printf("??? �� �𸣰ھ��. \n\n");
		}

		printf("����Ͻ÷��� ���͸� �����ּ���. ");
		_getch();
	}		// while()
}

// 3. ũ��Ƽ�� ������ �ִ� �Լ�
// 60% Ȯ���� ũ��Ƽ�� ������ �ִ� �Լ��� �����
// Loop ����ؼ� ���� �Է� ������ �ݺ�
// �÷��̾ � �������� ����ؼ� ������ ��(�� ũ��Ƽ������, �ƴ��� �� �� �־����)
void CriticalDamage();

int mainNum = 10; // ����(�۷ι�) ������� �Ѵ� 





int main() 
{
	// OddEvenProgram(loopCount);
	
	// OddEvenGameEasy();

	// OddEvenGameNormal();

	// Description();

	CriticalDamage();

	// �Ľ�Į ��Ÿ��(�ֱ�), �밡���� ��Ÿ��(����)

	/*

	//
	int randomNum = 0;
	const int MAX_DICE_VALUE = 6;
	srand(time(NULL));


	printf("�ֻ��� ���α׷� \n\n");
	_getch();
	printf("��ǻ�Ͱ� ���� 3���� �ֻ��� �� -> ");

	for (int i = 0; i < 3; i++) {
		Sleep(1000);
		randomNum = (rand() % MAX_DICE_VALUE) + 1; //	6���� �ϸ� �����ѹ�, ���ۿ� �𸥴�. ����� ��������
		printf("%d ", randomNum);
	}
	Sleep(1000);
	printf("\n\n");
	printf("���α׷� ���� \n\n");
	//

	//
	// ���⼭ Ű ���� �ٲ㺼 ����
	srand(time(NULL));		// �̰��� rand() �Լ��� Ű ���� �ٲ��ִ� �Լ�
	// NULL�� 0�̴�

	// Ramdom �����ϱ�
	int randomNumber1, randomNumber2, randomNumber3 = 0;
	randomNumber1 = (rand() % 6) + 1;		// rand() �Լ��� ����ؼ� �������� �޴´�
	randomNumber2 = (rand() % 6) + 1;		// �ֻ����� ����� ������ 6���� mod ������ �� 1�� ���Ѵ�
	randomNumber3 = (rand() % 6) + 1;

	// rand - (rand / 10) * 10

	printf("Random number?? %d \n", randomNumber1);
	printf("Random number?? %d \n", randomNumber2);
	printf("Random number?? %d \n", randomNumber3);

	// �õ� ��, Ű ��, ���̵� ��
	//

	//
	printf("[Main()] number ����? %d \n", number);
	printf("For���� �ݺ����̴�. �̷��� ���ư���. \n");

	int loopCount = 1; //	����(����) ������� �Ѵ�
	for ( ����� �� ����� ; loopCount <= 5; loopCount += 1) { //	(���� �ʱ�ȭ; ���ǽ�; �������� ���� ���� 1 ���ϱ�)
		printf("��� ���ư��� �ִ� ������??? \n");
	}
	printf("\n");
	//

	// Switch / Case ��

	char userInput = 0;
	printf("User Input : ");
	// _getch()�Լ��� ����ϱ� ���ؼ��� <conio.h> ��������� �ʿ��ϴ�
	userInput = _getch();
	// �Է¹޴� �߿� ���ڰ� ������ �ʴ´�

	
	// scanf_s("%d", &userInput);

	switch (userInput) {
	case 'a':
		printf("�̰��� ���� \n");
		break;
	case 'b':
		printf("�̰��� ���� \n");
		break;
	case 'c':
		printf("�̰��� �� \n");
		break;
	default:
		printf("ó������ ���� ���� �Է��Դϴ�. \n");
		break;
	}

	printf("Press any key... \n");
	_getch();
	// �̷������� ����ϸ� Ű�Է��� ���� �� ���α׷��� ����ȴ�

	
	//
	int userNumber = 0;
	int loopCount = 1;

	while (true) {
		printf("���ڸ� �Է��Ͻÿ� : ");
		scanf_s("%d", &userNumber);

		// Ż�� ����
		if (userNumber <= 0) {
			printf("\n���α׷��� �����մϴ�. \n");
			return 0;
		}	// if : invalid values
		
		if (userNumber % 2 == 0) { 
			printf("[%d]�� ¦�� �Դϴ�. \n", userNumber);
			continue;
		}
		//Ż�� ������ �տ� �ۼ��ϸ� else�� �ʿ��������
		printf("[%d]�� Ȧ�� �Դϴ�. \n", userNumber);
	}

	

	
	//
	while (loopCount > 0){
		if (loopCount == 1) {
			printf("[Ʃ�丮��] ���� ������ ������� �Ѵٸ� �̷������� \n\n");
		}

		printf("[sysem] ����� �÷��̾��Դϴ�. \n");
		printf("������ �׼��� �Է����ּ��� \n");
		scanf_s("%c", &userInput);

		if (userInput == 'q' || userInput == 'Q') {
			printf("[System] ���α׷��� �����մϴ�. \n");
			break;
		}
		else {
			printf("[Systme] �ش� �Է��� ���ǵǾ� ���� �ʽ��ϴ�. \n");
			loopCount += 1;
			continue;
		}

		loopCount += 1;


		if (loopcount == 7) 
		{ 
			loopcount += 1;
			continue; 
		}

		printf("�̰��� ������ ��µǴ� �����̴�. %d \n", loopcount);
		
	}	// loopCount ��ŭ �ݺ�
	//
	*/

	return 0;
}

void OddEvenProgram(int loop) {
	int userInputNum;
	int quitGuide = 1;

	while (true)
	{
		printf("���ڸ� �Է����ּ���. : ");

		scanf_s("%d", &userInputNum);

		if (userInputNum < 0) {
			printf("���α׷��� �����մϴ�. \n");
			break;
		}

		if ((userInputNum % 2) == 0) {
			if (userInputNum == 0) {
				printf("%d : 0 \n", userInputNum);
				printf("���� ");
				continue;
			}
			printf("%d : ¦�� \n", userInputNum);
		}
		else {
			printf("%d : Ȧ�� \n", userInputNum);
		}

		if (quitGuide == 1) {
			printf("���Ḧ ���Ͻø� ������ �Է����ּ���. \n");
			quitGuide -= 1;
		}

		printf("���� ");
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
	printf("[info] ġ��Ÿ Ȯ���� [%d]���ϸ� ġ��Ÿ�� ������. \n", CRITICALRATE);
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

			printf("���� ��������... \n");
			Sleep(500);
			printf("\n���� �¸�!!! \n");
			break;
		}


		printf("============================================================\n");
		printf("Enemy ( %d / %d ) \n\n\n\n\n", enemyCurhp, ENEMYHP);

		rate = (rand() % 100) + 1;

		if (rate < CRITICALRATE) {
			printf("ġ��Ÿ Ȯ�� [%d]�� [%d]���ϴ�! \n", rate, CRITICALRATE);

			printf("ġ��Ÿ�� \n%.0f�� �������� �־���! \n\n", damageGive * CRITICALDAMAGERATE);
			enemyCurhp -= damageGive * CRITICALDAMAGERATE;
		}
		else {
			printf("ġ��Ÿ Ȯ�� [%d]�� [%d]�� �Ѿ���. \n", rate, CRITICALRATE);

			printf("��Ÿ�� \n%.0f�� �������� �־���. \n\n", damageGive);
			enemyCurhp -= damageGive;
		}

		printf("���� ���� �����Ͻðڽ��ϱ�? \n\n");
		_getch();
		system("cls");
		Sleep(500);
	}		//		while()





}

void Description() {

}
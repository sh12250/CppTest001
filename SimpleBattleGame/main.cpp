#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

const int MAXPERCENT = 100;

int monsterKill = 0;
int playerLevel = 0;
int playerAtk = 10;
int playerMaxHp = 50;
int playerCurHp = playerMaxHp;
int roadIncount = 0;

/*

���� ���� Ȱ���ؼ�  ( ��Ʋ �ý��� + �ȱ� �ý��� )
�÷��̾��� �ִ� HP�� 50, �÷��̾ 6�� ���� ������ ���� ����

����� �����ϰ� �����Ѵ� (��, ��, ��)
30�� Ȯ���� ��  -> ������ ����( �༱�� )
20�� Ȯ���� ��  -> ������ ����
50�� Ȯ���� ��  -> ���� �߻� -> ������ ����

������ ���ؼ�   -> ���� ����. ������ �ڵ� ����
			  -> ������ ü��, ���ݷ�, �÷��̾��� ���ݷ��� Ŀ����
			  -> ������ 40�� Ȯ���� �߻�
			  -> 60�� Ȯ���� �÷��̾� ȸ��

*/

// ���� ����
// ������ ���ư��� ��
// ������� �̱ý����� ����
// ���� ã�� ������ �����ϸ� ���� ����
// ������ ������ ��� ����



int RandomPercent(), PlayerHeal(int ), PlayerAtk();
void RandomRoute(), PlayerLevel(), Graphics(int );





int main() {

	return 0;
}

void Battle() {
	int mobMake = 1;
	int mobMaxHp = 0;
	int mobCurHp = 0;
	int mobAtk = 0;

	while (true) {
		// ���Ͱ� �׾��� ���
		if (mobCurHp < 0) {
			mobCurHp = 0;
			monsterKill += 1;
			if (monsterKill == 5) {
				PlayerLevel();
			}

			break;
		}
		// �÷��̾ �׾��� ���
		if (playerCurHp < 0) {
			playerCurHp = 0;
			Graphics(5);

			break;
		}
		// ���� ���� ����
		if(mobMake == 1){
			int mobStat = (RandomPercent() % 16) + 15;
			mobMaxHp = mobStat;
			mobCurHp = mobMaxHp;
			mobStat = (RandomPercent() % 5) + 2;
			mobAtk = mobStat;

			mobMake = 0;
		}

		// �׷��� ���
		Graphics(4);
		// ���� ���� ���

		

		// �÷��̾� ���� ���


		// ���� ����

		mobCurHp -= PlayerAtk();
		playerCurHp -= mobAtk;
		PlayerHeal(playerCurHp);


		_getch();
		system("cls");
		// ���� �� ����
	}
}


void UiPrint() {

}


// �÷��̾��� ����
int PlayerAtk() {
	const int CRIRATE = 30;
	const int CRIATKRATE = 2;
	int isCri = RandomPercent();

	if(isCri > MAXPERCENT- CRIRATE){
		return playerAtk * CRIATKRATE;
	}
	else {
		return playerAtk;
	}
}
// ��

// �÷��̾� ���� ����
void PlayerLevel() {\
	monsterKill = 0;
	playerLevel += 1;
	playerAtk += 2;
	playerMaxHp += 5;
}
// ��

// �׷��� ���
void Graphics(int graphicnum) {
	switch (graphicnum) {
		// ��
	case 1:
		printf("�������������������������������������ܡܡܤ�������\n");
		printf("�����ܡܡܡܤ��������ܡܤ������ܡܡܡܤ�����������\n");
		printf("���������ܡܤ�������������������������������������\n");
		printf("�������������ܡܤ��������������������������ܡܡܡ�\n");
		printf("��������������������������������������������������\n");	
		printf("��������������������������������������������������\n");
		printf("�����������������á��âââââä���������������\n");
		printf("���������ââá���ݢâââââââââä�������\n");
		printf("�����ââá����âââââââââââââä���\n");
		printf("�âââá����ââââââââââââââââ�\n");	
		printf("�ââá�����ââââââââââââââââ�\n");
		printf("�ââá������âââââââââââââââ�\n");
		printf("�ââáݡ������ââââââââââââââ�\n");
		printf("�âââá��������ââââââââââââ�\n");
		printf("�ââââá���������ââââââââââ�\n");	
		printf("�ââââââá����������âââââââ�\n");
		printf("�âââââââá�����������ݢââââ�\n");
		printf("�âââââââá������ݡ������âââ�\n");
		printf("�ââââââá���������������ââ�\n");
		printf("�ââââáݡ�����������������â�\n");	
		printf("�âââá���������������������\n");
		printf("�âá�����������������������\n");
		printf("�á������������������������\n");
		printf("������ݡݡ������������������\n");
		printf("������ݡݡ������������������\n");
		break;
		// ��
	case 2:
		printf("�����������������ܡܤ�����������������������������\n");
		printf("�������������ܡܤ������������������ܡܡܡܤ�������\n");
		printf("���������������������������������������ܤ���������\n");
		printf("�������ܤ��������������ܡܡܡܤ�������������������\n");
		printf("�ܡܡܡܡܤ����������������ܡܡܤ�����������������\n");
		printf("��������������������������������������������������\n");
		printf("�����������������ââââââââä���������������\n");
		printf("���������ââââââââââââââââä�������\n");
		printf("�����ââââââââââââââââââââä���\n");
		printf("�âââââáۡۡۡۡۡۡۡۡۡۢââââââââ�\n");
		printf("�áۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۢââ�\n");
		printf("�ۡۡۡۡۡۡۡۤ����ۡۡۡۡۡۡۡۡۡۡۡۡۡۡ�\n");
		printf("�ۤ����ۡۡۡۡۡۡۡۡۡۡۡۡۡۤ����ۡۡۡۡۡ�\n");
		printf("�ۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۤ����ۡۡ�\n");
		printf("�ۡۡۤ����ۡۡۡۡۡۡۡۡۤ����ۡۡۡۡۡۡۡۡ�\n");
		printf("�ۡۡۡۡۡۡۡۡۡۤ��ۡۡۡۡۡۡۡۡۡۡۡۡۡ�\n");
		printf("�ۡۤ����ۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۡۤ�����\n");
		printf("�ۡۡۡۡۡۢâââââââââââáۡۡۡۡۡۡ�\n");
		printf("�ۢâââââââââââââââââââáۡۡۡ�\n");
		printf("�âââââââââââââââââââââââá�\n");
		printf("�âââââââá����������ââââââ�\n");
		printf("�âá�����������������������\n");
		printf("��������������������������\n");
		printf("��������������������������\n");
		printf("��������������������������\n");
		break;
		// ��
	case 3:
		printf("�ޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡߡ�\n");
		printf("�ޡޡޡޡߡޡޡޡޡޡޡߡޡޡޡޡޡޡޡޡޡޡޡޡ�\n");
		printf("�ޡޡޡޡߡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡ�\n");
		printf("�ޡޡޡޡߡߡߡޡޡߡޡޡޡޡߡޡޡޡޡޡޡޡޡޡ�\n");
		printf("�ޡޡޡߡޡޡޡߡߡޡޡޡޡޡޡߡޡޡޡޡޡޡޡޡ�\n");
		printf("�ߡߡߡޡޡޡߡޡޡޡޡޡޡޡޡޡߡޡߡޡޡޡޡߡ�\n");
		printf("�ߡޡޡޡޡߡߡޢââââââââáߡߡߡߡޡޡߡ�\n");
		printf("�ޡޡޡޢáߡߢá٢ââáݢá��ââáߡߡߡߡߡ�\n");
		printf("�ޡޢââáߡߡ٢ââá�âââââââáߡߡߡߡ�\n");
		printf("�âââá�ߡߢâáݡݡ�âââáݡݢâáߡߡߡߡ�\n");
		printf("�âá���ߡߡߢáݡݡ�ââáݡݡݡݢâáߡߡߡ�\n");
		printf("�âââáߡߡ��ߢá��âáݡݡݡݡݡ�áߡߡߡ�\n");
		printf("�ââá١ߢââââá���áݡݡݡݡ٢ââáߡߡ�\n");
		printf("�âá�áݡݢâââá�������٢âââáߡߡ�\n");
		printf("�âââáݡݢá������âââââââââáߡ�\n");
		printf("�âá���âââá��ݡݡ��âá���ââáߡ�\n");
		printf("�âââââââá�������âââââá١٢á�\n");
		printf("�ââá١٢ââá��������áݢá��ââá�\n");
		printf("�á���á٢á�����������ââââââ�\n");
		printf("�âá��âá��������ݡ����âââââ�\n");
		printf("�á٢âá������������������áݢ�\n");
		printf("�âá����ݡ����������������â�\n");
		printf("�á������������������������\n");
		printf("��������������������������\n");
		printf("��������������������������\n");
		break;
		// �꿡 ��� ����
	case 4:
		break;
		// ��忣��
	case 5:
		break;
		// ����
	case 6:
		break;
		// ���ǿ���
	case 7:
		break;
		// �߰� ����?
	}
}
// �� ��

// ������ �����߳�?
void IsTown() {
	roadIncount += 1;

	if (roadIncount == 6) {
		Graphics(6);
		Graphics(7);
	}
}
// �� ��

// �����ұ�?
void IsBattle() {
	const int BATTLERATE = 40;
	int isBattle = RandomPercent();

	if (isBattle > MAXPERCENT - BATTLERATE) {

	}
}
// �� ��

// ���ұ�?
int PlayerHeal(int curPlayerHP) {
	const int HEALRATE = 60;
	const int HEALPOWER = 10;
	int isHeal = RandomPercent();

	if (isHeal > MAXPERCENT - HEALRATE) {
		return curPlayerHP + HEALPOWER;
	}
	else {
		return curPlayerHP;
	}
}
// ��

// ���� ���� ��
void RandomRoute() {
	const int ROADRATE = 30;
	const int RIVERRATE = 20;
	int myRoute = RandomPercent();

	if (myRoute > MAXPERCENT - ROADRATE) {
		Graphics(1);
		IsTown();
	}
	else if (myRoute > MAXPERCENT - ROADRATE - RIVERRATE) {
		Graphics(2);
	}
	else {
		Graphics(3);
	}
}
// �� ��

// 1 ~ 100������ ���� ��ȯ
int RandomPercent() {
	srand((unsigned int)time(NULL));

	return ((rand() % MAXPERCENT) + 1);
}
// ����
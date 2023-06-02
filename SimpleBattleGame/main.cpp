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

게임 루프 활용해서  ( 배틀 시스템 + 걷기 시스템 )
플레이어의 최대 HP는 50, 플레이어가 6번 길을 걸으면 게임 종료

사용자 랜덤하게 진행한다 (길, 강, 산)
30퍼 확률로 길  -> 랜덤값 리롤( 행선지 )
20퍼 확률로 강  -> 랜덤값 리롤
50퍼 확률로 산  -> 전투 발생 -> 랜덤값 리롤

전투에 대해서   -> 몬스터 등장. 전투는 자동 진행
			  -> 몬스터의 체력, 공격력, 플레이어의 공격력은 커스텀
			  -> 전투는 40퍼 확률로 발생
			  -> 60퍼 확률로 플레이어 회복

*/

// 게임 설정
// 마을로 돌아가는 길
// 세계수의 미궁식으로 진행
// 길을 찾아 마을에 도착하면 해피 엔딩
// 그전에 죽으면 배드 엔딩



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
		// 몬스터가 죽었을 경우
		if (mobCurHp < 0) {
			mobCurHp = 0;
			monsterKill += 1;
			if (monsterKill == 5) {
				PlayerLevel();
			}

			break;
		}
		// 플레이어가 죽었을 경우
		if (playerCurHp < 0) {
			playerCurHp = 0;
			Graphics(5);

			break;
		}
		// 몬스터 스탯 생성
		if(mobMake == 1){
			int mobStat = (RandomPercent() % 16) + 15;
			mobMaxHp = mobStat;
			mobCurHp = mobMaxHp;
			mobStat = (RandomPercent() % 5) + 2;
			mobAtk = mobStat;

			mobMake = 0;
		}

		// 그래픽 출력
		Graphics(4);
		// 몬스터 정보 출력

		

		// 플레이어 정보 출력


		// 전투 진행

		mobCurHp -= PlayerAtk();
		playerCurHp -= mobAtk;
		PlayerHeal(playerCurHp);


		_getch();
		system("cls");
		// 다음 턴 진행
	}
}


void UiPrint() {

}


// 플레이어의 공격
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
// 끝

// 플레이어 스탯 증가
void PlayerLevel() {\
	monsterKill = 0;
	playerLevel += 1;
	playerAtk += 2;
	playerMaxHp += 5;
}
// 끝

// 그래픽 출력
void Graphics(int graphicnum) {
	switch (graphicnum) {
		// 길
	case 1:
		printf("ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ●●●ㅁㅁㅁㅁ\n");
		printf("ㅁㅁ●●●●ㅁㅁㅁㅁ●●ㅁㅁㅁ●●●●ㅁㅁㅁㅁㅁㅁ\n");
		printf("ㅁㅁㅁㅁ●●ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ\n");
		printf("ㅁㅁㅁㅁㅁㅁ●●ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ●●●●\n");
		printf("ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ●\n");	
		printf("ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ\n");
		printf("ㅁㅁㅁㅁㅁㅁㅁㅁ▣□□▣▣▣▣▣▣ㅁㅁㅁㅁㅁㅁㅁㅁ\n");
		printf("ㅁㅁㅁㅁ▣▣▣□□□◎▣▣▣▣▣▣▣▣▣▣ㅁㅁㅁㅁ\n");
		printf("ㅁㅁ▣▣▣□□□□▣▣▣▣▣▣▣▣▣▣▣▣▣▣ㅁㅁ\n");
		printf("▣▣▣▣□□□□▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n");	
		printf("▣▣▣□□□□□▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n");
		printf("▣▣▣□□□□□□▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n");
		printf("▣▣▣◎□□□□□□▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n");
		printf("▣▣▣▣□□□□□□□□▣▣▣▣▣▣▣▣▣▣▣▣▣\n");
		printf("▣▣▣▣▣□□□□□□□□□▣▣▣▣▣▣▣▣▣▣▣\n");	
		printf("▣▣▣▣▣▣▣□□□□□□□□□□▣▣▣▣▣▣▣▣\n");
		printf("▣▣▣▣▣▣▣▣□□□□□□□□□□□◎▣▣▣▣▣\n");
		printf("▣▣▣▣▣▣▣▣□□□□□□◎□□□□□□▣▣▣▣\n");
		printf("▣▣▣▣▣▣▣□□□□□□□□□□□□□□□▣▣▣\n");
		printf("▣▣▣▣▣◎□□□□□□□□□□□□□□□□□▣▣\n");	
		printf("▣▣▣▣□□□□□□□□□□□□□□□□□□□□▣\n");
		printf("▣▣□□□□□□□□□□□□□□□□□□□□□□▣\n");
		printf("▣□□□□□□□□□□□□□□□□□□□□□□□▣\n");
		printf("□□□□□◎◎□□□□□□□□□□□□□□□□□□\n");
		printf("□□□□□◎◎□□□□□□□□□□□□□□□□□□\n");
		break;
		// 강
	case 2:
		printf("ㅁㅁㅁㅁㅁㅁㅁㅁ●●ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ\n");
		printf("ㅁㅁㅁㅁㅁㅁ●●ㅁㅁㅁㅁㅁㅁㅁㅁㅁ●●●●ㅁㅁㅁㅁ\n");
		printf("ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ●ㅁㅁㅁㅁㅁ\n");
		printf("ㅁㅁㅁ●ㅁㅁㅁㅁㅁㅁㅁ●●●●ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ\n");
		printf("●●●●●ㅁㅁㅁㅁㅁㅁㅁㅁ●●●ㅁㅁㅁㅁㅁㅁㅁㅁㅁ\n");
		printf("ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ\n");
		printf("ㅁㅁㅁㅁㅁㅁㅁㅁ▣▣▣▣▣▣▣▣▣ㅁㅁㅁㅁㅁㅁㅁㅁ\n");
		printf("ㅁㅁㅁㅁ▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣ㅁㅁㅁㅁ\n");
		printf("ㅁㅁ▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣ㅁㅁ\n");
		printf("▣▣▣▣▣▣○○○○○○○○○○▣▣▣▣▣▣▣▣▣\n");
		printf("▣○○○○○○○○○○○○○○○○○○○○○▣▣▣\n");
		printf("○○○○○○○○ㅅㅅ○○○○○○○○○○○○○○○\n");
		printf("○ㅅㅅ○○○○○○○○○○○○○○ㅅㅅ○○○○○○\n");
		printf("○○○○○○○○○○○○○○○○○○○○ㅅㅅ○○○\n");
		printf("○○○ㅅㅅ○○○○○○○○○ㅅㅅ○○○○○○○○○\n");
		printf("○○○○○○○○○○ㅅ○○○○○○○○○○○○○○\n");
		printf("○○ㅅㅅ○○○○○○○○○○○○○○○○○○ㅅㅅ○\n");
		printf("○○○○○○▣▣▣▣▣▣▣▣▣▣▣▣○○○○○○○\n");
		printf("○▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣○○○○\n");
		printf("▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣○\n");
		printf("▣▣▣▣▣▣▣▣□□□□□□□□□□▣▣▣▣▣▣▣\n");
		printf("▣▣□□□□□□□□□□□□□□□□□□□□□□□\n");
		printf("□□□□□□□□□□□□□□□□□□□□□□□□□\n");
		printf("□□□□□□□□□□□□□□□□□□□□□□□□□\n");
		printf("□□□□□□□□□□□□□□□□□□□□□□□□□\n");
		break;
		// 산
	case 3:
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◆◇\n");
		printf("◇◇◇◇◆◇◇◇◇◇◇◆◇◇◇◇◇◇◇◇◇◇◇◇◆\n");
		printf("◇◇◇◇◆◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇◇◇◇◆◆◆◇◇◆◇◇◇◇◆◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇◇◇◆◇◇◇◆◆◇◇◇◇◇◇◆◇◇◇◇◇◇◇◇◆\n");
		printf("◆◆◆◇◇◇◆◇◇◇◇◇◇◇◇◇◆◇◆◇◇◇◇◆◆\n");
		printf("◆◇◇◇◇◆◆◇▣▣▣▣▣▣▣▣▣◆◆◆◆◇◇◆◆\n");
		printf("◇◇◇◇▣◆◆▣☆▣▣▣◎▣▲▲▣▣▣◆◆◆◆◆◇\n");
		printf("◇◇▣▣▣◆◆☆▣▣▣□▣▣▣▣▣▣▣▣◆◆◆◆◇\n");
		printf("▣▣▣▣▲◆◆▣▣◎◎□▣▣▣▣◎◎▣▣◆◆◆◆◇\n");
		printf("▣▣▲▲▲◆◆◆▣◎◎□▣▣▣◎◎◎◎▣▣◆◆◆◆\n");
		printf("▣▣▣▣◆◆▲▲◆▣□□▣▣◎◎◎◎◎▲▣◆◆◆◆\n");
		printf("▣▣▣☆◆▣▣▣▣▣□□□▣◎◎◎◎☆▣▣▣◆◆◆\n");
		printf("▣▣▲▣◎◎▣▣▣▣□□□□▲▲▲☆▣▣▣▣◆◆◆\n");
		printf("▣▣▣▣◎◎▣▲▲□□□□▣▣▣▣▣▣▣▣▣▣◆◆\n");
		printf("▣▣▲▲▲▣▣▣▣□□◎◎□□▣▣▲▲▲▣▣▣◆◆\n");
		printf("▣▣▣▣▣▣▣▣▲□□□□□□▣▣▣▣▣▣☆☆▣◆\n");
		printf("▣▣▣☆☆▣▣▣□□□□□□□□▣◎▣▲▲▣▣▣◆\n");
		printf("▣▲▲▲▣☆▣□□□□□□□□□□□▣▣▣▣▣▣▣\n");
		printf("▣▣▲▲▣▣□□□□□□□□◎□□□□▣▣▣▣▣▣\n");
		printf("▣☆▣▣□□□□□□□□□□□□□□□□□▲▣◎▣\n");
		printf("▣▣□□□□◎□□□□□□□□□□□□□□□□▣▣\n");
		printf("▣□□□□□□□□□□□□□□□□□□□□□□□▣\n");
		printf("□□□□□□□□□□□□□□□□□□□□□□□□□\n");
		printf("□□□□□□□□□□□□□□□□□□□□□□□□□\n");
		break;
		// 산에 사는 몬스터
	case 4:
		break;
		// 배드엔딩
	case 5:
		break;
		// 마을
	case 6:
		break;
		// 해피엔딩
	case 7:
		break;
		// 추가 사항?
	}
}
// 안 끝

// 마을에 도착했나?
void IsTown() {
	roadIncount += 1;

	if (roadIncount == 6) {
		Graphics(6);
		Graphics(7);
	}
}
// 안 끝

// 전투할까?
void IsBattle() {
	const int BATTLERATE = 40;
	int isBattle = RandomPercent();

	if (isBattle > MAXPERCENT - BATTLERATE) {

	}
}
// 안 끝

// 힐할까?
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
// 끝

// 내가 가는 길
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
// 안 끝

// 1 ~ 100까지의 난수 반환
int RandomPercent() {
	srand((unsigned int)time(NULL));

	return ((rand() % MAXPERCENT) + 1);
}
// 끝남
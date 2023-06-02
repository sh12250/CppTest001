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

惟績 欠覗 醗遂背辞  ( 壕堂 獣什奴 + 鞍奄 獣什奴 )
巴傾戚嬢税 置企 HP澗 50, 巴傾戚嬢亜 6腰 掩聖 杏生檎 惟績 曽戟

紫遂切 沓棋馬惟 遭楳廃陥 (掩, 悪, 至)
30遁 溌懸稽 掩  -> 沓棋葵 軒継( 楳識走 )
20遁 溌懸稽 悪  -> 沓棋葵 軒継
50遁 溌懸稽 至  -> 穿燈 降持 -> 沓棋葵 軒継

穿燈拭 企背辞   -> 佼什斗 去舌. 穿燈澗 切疑 遭楳
			  -> 佼什斗税 端径, 因維径, 巴傾戚嬢税 因維径精 朕什賭
			  -> 穿燈澗 40遁 溌懸稽 降持
			  -> 60遁 溌懸稽 巴傾戚嬢 噺差

*/

// 惟績 竺舛
// 原聖稽 宜焼亜澗 掩
// 室域呪税 耕叡縦生稽 遭楳
// 掩聖 達焼 原聖拭 亀鐸馬檎 背杷 殖漁
// 益穿拭 宋生檎 壕球 殖漁



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
		// 佼什斗亜 宋醸聖 井酔
		if (mobCurHp < 0) {
			mobCurHp = 0;
			monsterKill += 1;
			if (monsterKill == 5) {
				PlayerLevel();
			}

			break;
		}
		// 巴傾戚嬢亜 宋醸聖 井酔
		if (playerCurHp < 0) {
			playerCurHp = 0;
			Graphics(5);

			break;
		}
		// 佼什斗 什堵 持失
		if(mobMake == 1){
			int mobStat = (RandomPercent() % 16) + 15;
			mobMaxHp = mobStat;
			mobCurHp = mobMaxHp;
			mobStat = (RandomPercent() % 5) + 2;
			mobAtk = mobStat;

			mobMake = 0;
		}

		// 益掘波 窒径
		Graphics(4);
		// 佼什斗 舛左 窒径

		

		// 巴傾戚嬢 舛左 窒径


		// 穿燈 遭楳

		mobCurHp -= PlayerAtk();
		playerCurHp -= mobAtk;
		PlayerHeal(playerCurHp);


		_getch();
		system("cls");
		// 陥製 渡 遭楳
	}
}


void UiPrint() {

}


// 巴傾戚嬢税 因維
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
// 魁

// 巴傾戚嬢 什堵 装亜
void PlayerLevel() {\
	monsterKill = 0;
	playerLevel += 1;
	playerAtk += 2;
	playerMaxHp += 5;
}
// 魁

// 益掘波 窒径
void Graphics(int graphicnum) {
	switch (graphicnum) {
		// 掩
	case 1:
		printf("けけけけけけけけけけけけけけけけけけ＋＋＋けけけけ\n");
		printf("けけ＋＋＋＋けけけけ＋＋けけけ＋＋＋＋けけけけけけ\n");
		printf("けけけけ＋＋けけけけけけけけけけけけけけけけけけけ\n");
		printf("けけけけけけ＋＋けけけけけけけけけけけけけ＋＋＋＋\n");
		printf("けけけけけけけけけけけけけけけけけけけけけけけけ＋\n");	
		printf("けけけけけけけけけけけけけけけけけけけけけけけけけ\n");
		printf("けけけけけけけけ�叩燹燿但但但但但辰韻韻韻韻韻韻韻�\n");
		printf("けけけけ�但但叩燹燹燹蘗但但但但但但但但但辰韻韻韻�\n");
		printf("けけ�但但叩燹燹燹燿但但但但但但但但但但但但但辰韻�\n");
		printf("�但但但叩燹燹燹燿但但但但但但但但但但但但但但但但�\n");	
		printf("�但但叩燹燹燹燹燿但但但但但但但但但但但但但但但但�\n");
		printf("�但但叩燹燹燹燹燹燿但但但但但但但但但但但但但但但�\n");
		printf("�但但叩檗燹燹燹燹燹燿但但但但但但但但但但但但但但�\n");
		printf("�但但但叩燹燹燹燹燹燹燹燿但但但但但但但但但但但但�\n");
		printf("�但但但但叩燹燹燹燹燹燹燹燹燿但但但但但但但但但但�\n");	
		printf("�但但但但但但叩燹燹燹燹燹燹燹燹燹燿但但但但但但但�\n");
		printf("�但但但但但但但叩燹燹燹燹燹燹燹燹燹燹燹蘗但但但但�\n");
		printf("�但但但但但但但叩燹燹燹燹燹燹檗燹燹燹燹燹燿但但但�\n");
		printf("�但但但但但但叩燹燹燹燹燹燹燹燹燹燹燹燹燹燹燿但但�\n");
		printf("�但但但但叩檗燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燿但�\n");	
		printf("�但但但叩燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燿�\n");
		printf("�但叩燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燿�\n");
		printf("�叩燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燿�\n");
		printf("÷÷÷÷÷−−÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷\n");
		printf("÷÷÷÷÷−−÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷\n");
		break;
		// 悪
	case 2:
		printf("けけけけけけけけ＋＋けけけけけけけけけけけけけけけ\n");
		printf("けけけけけけ＋＋けけけけけけけけけ＋＋＋＋けけけけ\n");
		printf("けけけけけけけけけけけけけけけけけけけ＋けけけけけ\n");
		printf("けけけ＋けけけけけけけ＋＋＋＋けけけけけけけけけけ\n");
		printf("＋＋＋＋＋けけけけけけけけ＋＋＋けけけけけけけけけ\n");
		printf("けけけけけけけけけけけけけけけけけけけけけけけけけ\n");
		printf("けけけけけけけけ�但但但但但但但但辰韻韻韻韻韻韻韻�\n");
		printf("けけけけ�但但但但但但但但但但但但但但但但辰韻韻韻�\n");
		printf("けけ�但但但但但但但但但但但但但但但但但但但但辰韻�\n");
		printf("�但但但但但叩曄曄曄曄曄曄曄曄曄暸但但但但但但但但�\n");
		printf("�叩曄曄曄曄曄曄曄曄曄曄曄曄曄曄曄曄曄曄曄曄暸但但�\n");
		printf("】】】】】】】】ささ】】】】】】】】】】】】】】】\n");
		printf("】ささ】】】】】】】】】】】】】】ささ】】】】】】\n");
		printf("】】】】】】】】】】】】】】】】】】】】ささ】】】\n");
		printf("】】】ささ】】】】】】】】】ささ】】】】】】】】】\n");
		printf("】】】】】】】】】】さ】】】】】】】】】】】】】】\n");
		printf("】】ささ】】】】】】】】】】】】】】】】】】ささ】\n");
		printf("】】】】】】�但但但但但但但但但但但叩曄曄曄曄曄曄�\n");
		printf("】�但但但但但但但但但但但但但但但但但但但叩曄曄曄�\n");
		printf("�但但但但但但但但但但但但但但但但但但但但但但但叩�\n");
		printf("�但但但但但但但叩燹燹燹燹燹燹燹燹燹燿但但但但但但�\n");
		printf("�但叩燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹�\n");
		printf("÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷\n");
		printf("÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷\n");
		printf("÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷\n");
		break;
		// 至
	case 3:
		printf("±±±±±±±±±±±±±±±±±±±±±±±×±\n");
		printf("±±±±×±±±±±±×±±±±±±±±±±±±×\n");
		printf("±±±±×±±±±±±±±±±±±±±±±±±±±\n");
		printf("±±±±×××±±×±±±±×±±±±±±±±±±\n");
		printf("±±±×±±±××±±±±±±×±±±±±±±±×\n");
		printf("×××±±±×±±±±±±±±±×±×±±±±××\n");
		printf("×±±±±××±�但但但但但但但但叩漾漾漾漾沺沺漾�\n");
		printf("±±±±�叩漾漓叩戡但但叩蘗叩磧磚但但叩漾漾漾漾漾�\n");
		printf("±±�但但叩漾漾戡但但叩燿但但但但但但但叩漾漾漾漾�\n");
		printf("�但但但叩磧漾漓但叩檗檗燿但但但叩檗蘗但叩漾漾漾漾�\n");
		printf("�但叩磧磧磧漾漾漓叩檗檗燿但但叩檗檗檗蘗但叩漾漾漾�\n");
		printf("�但但但叩漾漾磧磧漓叩燹燿但叩檗檗檗檗檗磚叩漾漾漾�\n");
		printf("�但但叩戞漓但但但但叩燹燹燿叩檗檗檗檗戡但但叩漾漾�\n");
		printf("�但叩磚叩檗蘗但但但叩燹燹燹燹磧磧磧戡但但但叩漾漾�\n");
		printf("�但但但叩檗蘗叩磧磧燹燹燹燿但但但但但但但但但叩漾�\n");
		printf("�但叩磧磧磚但但但叩燹燹檗檗燹燿但叩磧磧磚但但叩漾�\n");
		printf("�但但但但但但但叩磧燹燹燹燹燹燿但但但但但叩戞戡叩�\n");
		printf("�但但叩戞戡但但叩燹燹燹燹燹燹燹燿叩蘗叩磧磚但但叩�\n");
		printf("�叩磧磧磚叩戡叩燹燹燹燹燹燹燹燹燹燹燿但但但但但但�\n");
		printf("�但叩磧磚但叩燹燹燹燹燹燹燹燹檗燹燹燹燿但但但但但�\n");
		printf("�叩戡但叩燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹磚叩蘗�\n");
		printf("�但叩燹燹燹燹檗燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燿但�\n");
		printf("�叩燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燹燿�\n");
		printf("÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷\n");
		printf("÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷\n");
		break;
		// 至拭 紫澗 佼什斗
	case 4:
		break;
		// 壕球殖漁
	case 5:
		break;
		// 原聖
	case 6:
		break;
		// 背杷殖漁
	case 7:
		break;
		// 蓄亜 紫牌?
	}
}
// 照 魁

// 原聖拭 亀鐸梅蟹?
void IsTown() {
	roadIncount += 1;

	if (roadIncount == 6) {
		Graphics(6);
		Graphics(7);
	}
}
// 照 魁

// 穿燈拝猿?
void IsBattle() {
	const int BATTLERATE = 40;
	int isBattle = RandomPercent();

	if (isBattle > MAXPERCENT - BATTLERATE) {

	}
}
// 照 魁

// 枇拝猿?
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
// 魁

// 鎧亜 亜澗 掩
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
// 照 魁

// 1 ~ 100猿走税 貝呪 鋼発
int RandomPercent() {
	srand((unsigned int)time(NULL));

	return ((rand() % MAXPERCENT) + 1);
}
// 魁害
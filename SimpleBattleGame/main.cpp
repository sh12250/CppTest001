#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

using namespace std;

const int MAXPERCENT = 100;

int dayCount = 0;
int killCount = 0;
int roadIncount = 0;

int playerLevel = 0;
int playerAtk = 10;
int playerMaxHp = 50;
int playerCurHp = playerMaxHp;

int mobMaxHp = 0;
int mobCurHp = 0;
int mobAtk = 0;

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
// 길을 찾아 마을에 도착하면 해피 엔딩
// 그전에 죽으면 배드 엔딩

// 마을에 도착한 이후 플레이?

// 마을밖은 위험해
// 자경단의 되어 하루하루를 살아간다

int RandomPercent(), BattlePrint(int, int);
void IntroPrint(), RandomRoute(), Graphics(int ), IsTown(), IsBattle(), Battle(), MonsterStat(), PlayerAtk(), PlayerHeal(), PlayerLevelUP(), InfoPrint(int), TurnWait(int);

int main() {
	int playMore = 0;

	Graphics(7);
	printf("Press any key... \n");

	_getch();
	system("cls");

	IntroPrint();
	// 맛보기
	while (true) {
		if (roadIncount != 0 && roadIncount % 6 == 0) {
			break;
		}

		if (playerCurHp == 0) {
			break;
		}

		RandomRoute();
	}

	Graphics(7);
	printf("플레이해주셔서 감사합니다 \n");

	Sleep(1000);
	system("cls");
	// 2회차 이상
	while (playerCurHp != 0) {
		Graphics(7);
		printf("다음 날을 시작할까요? \n");
		printf("1. 예       2. 아니오 \n");

		playMore = _getch();;
		system("cls");

		if (playMore == '2') {
			Graphics(7);
			printf("게임을 종료합니다. \n");
			printf("Press any key... \n");

			_getch();
			system("cls");

			break;
		}
		else if (playMore == '1') {
			dayCount += 1;
			playMore = 0;
			roadIncount = 0;
			playerCurHp = playerMaxHp;

			Graphics(7);
			printf("마을 자경단 %d일차... \n", dayCount);
			printf("Press any key... \n");

			_getch();
			system("cls");

			while (true) {
				if (roadIncount != 0 && roadIncount % 6 == 0) {
					break;
				}

				RandomRoute();
			}
		}
		else {
			playMore = 0;

			Graphics(7);
			printf("잘못된 입력입니다. \n");

			Sleep(1000);
			system("cls");

			continue;
		}
	}		//	while()


	return 0;
}

// 전투 출력
void Battle() {
	MonsterStat();
	// 정보 출력
	InfoPrint(mobMaxHp);

	while (true) {
		// 플레이어가 죽었을 경우
		if (playerCurHp == 0) {
			Graphics(5);
			printf("당신은 객사했습니다... \n");

			break;
		}
		// 몬스터가 죽었을 경우
		if (mobCurHp == 0) {
			killCount += 1;

			break;
		}
		// 전투 진행
		BattlePrint(mobMaxHp, mobAtk);
		// 다음 턴 진행 전 정보 출력
		TurnWait(mobMaxHp);
	}
}


// 몬스터 스탯 생성
void MonsterStat() {
	int mobStat = (RandomPercent() % 16 + 15);
	mobMaxHp = mobStat;
	mobCurHp = mobMaxHp;
	mobStat = (RandomPercent() % 6  + 5);
	mobAtk = mobStat;

	if (dayCount > 0) {
		mobMaxHp += dayCount;
		mobCurHp = mobMaxHp;
		mobAtk += 1;
	}
}

// 다음 턴 진행 전 출력
void TurnWait(int maxhp) {
	Graphics(4);
	printf("늑대 ( %d / %d ) ", mobCurHp, maxhp);
	printf("\n============================================================\n");

	if (dayCount > 0) {
		if (mobCurHp <= 0) {
			printf("\n늑대를 퇴치했다 ");
			PlayerLevelUP();
		}
		else if (playerCurHp < (playerMaxHp / 2)) {
			printf("\n슬슬 위험한데... \n");
		}
		else {
			printf("\n방심하지 말자 \n");
		}
	}
	else {
		if (mobCurHp <= 0) {
			printf("\n늑대와의 전투에서 승리했다. ");
			PlayerLevelUP();
		}
		else if (playerCurHp < (playerMaxHp / 2)) {
			printf("\n힘든 싸움이 될 것 같다... \n");
		}
		else {
			printf("\n할만한데? \n");
		}
	}

	printf("\n============================================================\n");
	printf("나 ( %d / %d ) \n", playerCurHp, playerMaxHp);

	Sleep(1000);
	printf("\n다음 턴을 진행... \n");

	_getch();
	system("cls");
}

// 전투 출력
int BattlePrint(int maxhp, int atk) {
	Graphics(4);
	printf("늑대 ( %d / %d ) ", mobCurHp, maxhp);
	printf("\n============================================================\n");

	PlayerAtk();
	printf("\n============================================================\n");
	printf("나 ( %d / %d ) \n", playerCurHp, playerMaxHp);

	Sleep(1500);
	system("cls");

	if (mobCurHp <= 0) {
		mobCurHp = 0;

		return 0;
	}

	Graphics(4);
	printf("늑대 ( %d / %d ) ", mobCurHp, maxhp);
	printf("\n============================================================\n");
	printf("늑대의 공격! %d의 데미지를 입었다\n\n", atk);

	printf("\n============================================================\n");
	printf("나 ( %d / %d ) \n", playerCurHp, playerMaxHp);
	playerCurHp -= atk;

	if (playerCurHp <= 0) {
		playerCurHp = 0;

		return 0;
	}

	Sleep(1500);
	system("cls");
}

// 싸우기 전 정보 출력
void InfoPrint(int maxhp) {
	Graphics(4);
	printf("늑대 ( %d / %d ) ", mobCurHp, maxhp);
	printf("\n============================================================\n");

	if (dayCount > 0) {
		printf("\n일할 시간이다 \n");
	}
	else {
		printf("\n싸울 수 밖에 없는 것 같다... \n");
	}

	printf("\n============================================================\n");
	printf("나 ( %d / %d ) \n", playerCurHp, playerMaxHp);

	_getch();
	system("cls");
}


// 플레이어의 공격
void PlayerAtk() {
	const int CRIRATE = 30;
	const int CRIATKRATE = 2;
	int isCri = RandomPercent() + playerLevel;
	int damage = playerAtk;

	if(isCri > MAXPERCENT- CRIRATE){
		damage *= CRIATKRATE;
		printf("\n\n치명타※ %d의 데미지를 입혔다 ", damage);

		mobCurHp -= damage;

		if (mobCurHp < 0) {
			mobCurHp = 0;
		}
	}
	else {
		printf("\n\n공격＃ %d의 데미지를 입혔다 ", damage);

		mobCurHp -= damage;

		if (mobCurHp < 0) {
			mobCurHp = 0;
		}
	}
}

// 플레이어 스탯 증가
void PlayerLevelUP() {
	if (killCount != 0 && killCount % 5 == 0) {
		playerLevel += 1;
		playerAtk += 2;
		playerMaxHp += 5;

		printf("\n강해진 기분이 든다 ");
	}
	else {
		printf("\n");
	}
}

// 그래픽 출력
void Graphics(int graphicnum) {
	switch (graphicnum) {
		// 길
	case 1:
		printf("============================================================\n");
		cout 
		<< "@@@@@@@@@@@@#######$##$!..;############$########=##@#@@@@@@@" << endl
		<< "@@@@@@@@@@#@###$=#$$$$=:.:$###########@############@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@###==#$$$$$!.;#########$##$######$#####@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@#$$###$$$#$$$$$#####$##$#####$$###$#=#@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@##$=###$#$$$$$$#######$$$######$#$$$######@@@@@@@" << endl
		<< "@#@@@@@$@@##==$@####$$#$=$$########$$$$#####$##@#$#$@@@@@#@@" << endl
		<< "##@#@@@@@###$#$#==$#$$#==$$######$$$$$$####$$#######@@@@#@@@" << endl
		<< "#@##@@@@@$#$#=$@#$$=$$$*=$$$$$$$$$$$$$$$#$$$$###@@@@#@@###@@" << endl
		<< "##@$#@@##=$$#*$@####$$$==$$$###$$$$$$$####$$$=###@@##@@*=@@@" << endl
		<< "#@@$$$@=##$=@#@###$#$$#$=$$#$$$$$###$$##$$$$=$$$#@#$=$@;*#@@" << endl
		<< "#@@$@=@##$*#@@#########$$$$$$###$###$$##$$=$##*$##$##=@#@@@@" << endl
		<< "###$@#####$#@##$##@###$$$$$$$$##$##$$$#######@@##=$###@@#@#@" << endl
		<< "###$@@#=##$####$$$@@#$$$$##$$$##$$$$$$#####@#@@##=#@@#@#@@#@" << endl
		<< "##@####$#######$#$###$$######$####$$####$##@@@###$##@@#$###@" << endl
		<< "####$##$###$##$$$=$#==$$==#$$$$$$$==$==$===$###$$$$$$$$=$=##" << endl
		<< "=$$$$##$##$##$==**$=!*=$*!========****!==**!**==*=*!**!$!;#=" << endl
		<< "$===$$#$$$=$$=**;!==!*=$**=======$=!!!!=***!!!!**=*!!!!$;;#*" << endl
		<< "======#===**$=****==!;;;!*=*===$$$=*!!!==*****!!*=!!;!!$;;#=" << endl
		<< "=====$#$****$===**==!;:-~:;!**=$===****$==****!**=*!;*!#!!#$" << endl
		<< "====*=#=*=**$===!!****;----~:;*==**====#$==*=***=$*!*==#*=#$" << endl
		<< "===*!!$*!**==**=:::::::---~;;:!*****===$#$=$=*==$$===$$$=$@#" << endl
		<< "==**!!$!;;***!**~-,-------:!!!!!!*****=$$==$====#$$$$###$$@$" << endl
		<< "$$=*!!#!;;!*!;!*;;::~-----~~~~~:;!!!!**==**===**#$==$###$#@#" << endl
		<< "$*$*!*#=;;!!!;!*!!!!!;:------,,-~~~~:;!!!!!!***======#####@#" << endl
		<< "==*!*!#=!!;;!!!!*!****!:~-----,,,,---~~~:;;!;!**===*=$##$$@#" << endl
		<< "*=*!*!=!!!;;!!!********!:~---------------~:;!****=**==$$$$#@" << endl
		<< "==*!;;;!!!!!!!!!!!***!;:~-----------------~:!****=*===$$$$$@" << endl
		<< "==!!!!;!!!!!!!!!!!:::~~--------------------~;*****=====$$$$@" << endl
		<< "$***!!!!**!!!**!;~-----------------------~~~;*****======$=$#" << endl
		<< "=*=**!!!******;:~-----------------------~~~:!*****=====$=$$$" << endl
		<< "===****!;::~~~--------------------------~~~;****=*==$==$$$$$" << endl
		<< "=====***;:~------------------------------~:!*=======$=$=$$$$" << endl
		<< "$==*$;:~~--------------------------------~;**=======$$$=$$$$" << endl
		<< "#==;:~~---------------------------------~:**==========$$=$$$" << endl
		<< "=;:~~~---------------------------------~~;**==============$$" << endl
		<< ";::~~---~~-----------------------------~:!**=======*=*===$$#" << endl
		<< "::~~~~~~~~~-~~------------------------~~~;*======*======$$##" << endl
		<< ":::~~~~~~~~~~~~----------------------~~~;!**======*=$=$=$#$#" << endl
		<< ";::~~~~~~~~~~~~~----------------------~~~:!=========$$$$####" << endl
		<< ";;::~~~~~~~~~~~~~~~~------------------~~:;!**==$$$=*===$$$$#" << endl;
		printf("============================================================\n");
		printf("나 ( %d / %d ) \n", playerCurHp, playerMaxHp);

		break;
		// 강
	case 2:
		printf("============================================================\n");
		cout 
		<< ",,,,,,,,,,,,,,,,,,,,,,,,,,.,,...,,,.,..............  ...,:;;" << endl
		<< ".,.,,,,,,,,,,,,,,,,,,............................,~--;!;~!;!" << endl
		<< "~....,,,,,,,,,,,,,..............................~!!!!!;;:!;!" << endl
		<< "~:....,,,,,,,,,,,............................:.-;!*;-:!!!!*!" << endl
		<< "!!::,...,,,,,,,,...........................,-;;;;**!!!;!;!;;" << endl
		<< "!!!~:,..,,,,,,............................:!;*!:!!!!!!!;;!;;" << endl
		<< "===~~:-...,..............................~!**!*;*==*!=;;:*!;" << endl
		<< "$$$-~~::...,,....................  ....,:;!*=!!!=$*!!!=;;!:*" << endl
		<< "$$=$~:::;- .......................,,...!;;!=*!!===$===*!;;;;" << endl
		<< "!#$$**:~;:~  .........................,;;;*=*!*!=**==$!:*;**" << endl
		<< "$$$$==~:!~:~     .............,,~-~::;:!*;!=!;==$#*$;;*;!**!" << endl
		<< "$$#$**!*$;*:-. .. ..........,::::~:-~~*!=!!=*!**:;*==*=**!=*" << endl
		<< "####**$!!!*::;-.  .........,::::~~~*:;**!*!=*!***!*=*!*!**=*" << endl
		<< "####**$*!=*!!*:-.........-~::::~:::**;**!***!;*=*;=*===$!===" << endl
		<< "=@#@=!=*!$#;;!:;;.......~~::*~;!;!;!*=;;**==*=!*!=!*$$$*!$==" << endl
		<< "@@#@$*$*=$$*;;:::;:-::~::;*;=;!!;*!!***;!*;;=*!;!!*$##$=*$$=" << endl
		<< "=$#@$$#$$#$=!!;!!!*;:~;;;!==!!**;!*=;!$!!*=!=*!=!*==###$$$==" << endl
		<< ":~*::*!:*$$$*$;=$$*=;:******!***!*==;;*=!====$=$!!=$#####$!=" << endl
		<< "*~:!;:;~:**$=$;*=$$#$******!!***;=$***==$*==*!$$$=!$$$**;;;!" << endl
		<< ":;~~;;:;:;=*!=;;==$#$;!!*!!!;;!;!*!*;!;;;;;!!!*!;!;;;;!!!*=!" << endl
		<< "!::!:;**!~;*;*:;!!!!;:;;**!:~~::*!:*;**!*!!!;!!***!**!*=*!!!" << endl
		<< "*=*====:!*-;;:~~~-----~~:;!!;-,.-....-:::::;;!!;;*!;!!*!;**=" << endl
		<< "**=~--:::~-;=~:---------~~::;!!!!:--,,,,,....,,,,--~-~~::!;!" << endl
		<< "=**;,~*#==;=*;*:-----~~~~~~:;;;;;!;!!;:;!::---,--~--,~--,-,-" << endl
		<< "$;;;!!!:~::==*:;~-~~~~-~~~~:::;:;;:;!!***!*!!;!;~:;~:-:~ :~." << endl
		<< "--,!*!-!!:==!$#=:~--~-~~~~~;!;::;:;;!;;:!*$$=****;!~:,:=~;!*" << endl
		<< ",~;=*==-:~~~~:---~~~~~~~~~:~::::!;;!;!**!=**=*=**==$$!~;*!~:" << endl
		<< "~-!==#*;:::~~-~:**;::::~~~:~:::;;;;!!!***=*****=**===$**==!!" << endl
		<< ":--!$@=*;~-~!;;=$=;~:~~-~~~~:::::;:!!;!=*=**==*===!=$===*$==" << endl
		<< ":-~,:#*!$;~**$*==,=;;!-~--~:~:::::;!;;;!!**=********=***====" << endl
		<< ";;!;~;*=#=!!*=$=*--!!*~~~::;:;;:~;;:!;;*!;!**!!****==**===*=" << endl
		<< "!~;;;*#$##==$=#==~~*!::~:;;:;:;:~:;:;::;****==*!!:;*=*!*;***" << endl
		<< "*=*$$*$$@#=#;~~~:*$=:*;:;:!:;;;;!!;~;*;!!=$=*!==*!*===*;!!*=" << endl
		<< "=**=$#*#*!;;~-~~--~*;;!!:;;;;!;!;:;!!!!=*!!!*=**;:*=*===**==" << endl
		<< "=**==$$=!;;;~--~~--,--,~;*;;:;;!!;!;;!*=*!;!;***!!***$=====*" << endl
		<< "#$**$*==!;;;;,~--,,---;=**!!:;!!!!;;;;;!!*!*!!*!!!*===**!==!" << endl
		<< "==$!**$$*;!*,,---*:-~$$$$=!;!=***;;;::*;*!*****!;**;!**=:*==" << endl
		<< "$$$$##$!!$*;---~*=~!$$=!;~!:-;*!!!!;!!;*!**=*=**!***!*=**==*" << endl
		<< "#$$##$=*=$=---~!$!::;:::~-;!!=***;!!*!**=****==*=$=**=======" << endl
		<< "@@@#$****$=~~:;;;~--~~~!--;=#$==$***!*$=**;!*=**=========!;=" << endl;
		printf("============================================================\n");
		printf("나 ( %d / %d ) \n", playerCurHp, playerMaxHp);

		break;
		// 산
	case 3:
		printf("============================================================\n");
		cout 
		<< ";~!!;:~:!:;;;!-:;;;~!;::;;-;~;~;:::;~~-:-;,~*,~,,.-.,;:~~:-~" << endl
		<< "*!!;:!*:~~;--:;**;:.!,!:;;;;:-~:~:!;~-.~,~.!!:*~:::--~-,-~.." << endl
		<< ";::;;;~;!:~!***!;;=!:!;;;:!:;;~-;:-::;,:;*~~;:;;:,-.~~:!~;--" << endl
		<< "=*;=****=~~~*=*=;=$=!!;!~~;;:~-~~::~.,.;:;!~~-~~!~,~-~!:~,-." << endl
		<< ";$!$$$*!*=:;-!=*$!=:=!!;:~!::*;:!;*-~!~:,!::!-~;~~,,..;:;~--" << endl
		<< "=!#!=***!*!;:!!===**==*;;;:::;:-;;:~!;;;!:~~!,-,~--:-.,-*::;" << endl
		<< "=#*!!!==********!!*~=!=*;:*!;;!*-:::**:-;!~:!-:,~~,,,--~:---" << endl
		<< "!==*!:!**=!;**=*=!**===!*;!!*!!!!~!:;:~-!;--;,-:-,,--:~-~,-~" << endl
		<< "$=#=*$==**==:;:.-$!=*=====*!!!:!*,,!:;.::-,~!.,*~,,.- -.;,-;" << endl
		<< "##===$!*=*=!!:!*=!;=!=*!**!!*!;:!;-;!,-:;-;~--~:~,~:-.,-:~~-" << endl
		<< "$*!$*#-;!**~:*!$=!;*=*$**!**::*~;:.~~!~!:,--~:~:,. .,,..*:-," << endl
		<< "=$##*****:!**$=!!=*!*=!;*!;!;!****:~*!::~,,,..~,,~,,----:--:" << endl
		<< "!=$!!;$;;!===#$==$**=**=*#*$*=*;;$=:;!!~;.,, ,,-,,.- ~-!-;;;" << endl
		<< "=**!!!*;:*;!=*==$#=$$#$*#;=$!*!~~~::~::-~:-,,-~:~-~-::;:;;;!" << endl
		<< "$=#!==*!=$*$$$=*!#**##$=!!$$!;;!;*,!!;::~:;--~:~:~;;:*!!:!!:" << endl
		<< "=*$=$$$$$*=$$=*===*=!**;*$$!;*=$==:*;:;:;:,~;:~:~~:;*!***==!" << endl
		<< "$**!!*$$=$$=$=*$****=$$*==**!*=#$=:;:;!*:-:;!!*;;!!,;$*~!===" << endl
		<< "!*===$$=*$$*=*!#=***!=*=***=*==!*$:!;:~-~!*:;;:**!;**=;!;*!;" << endl
		<< "!!!:==**!*$$=!:=****=!!!;!;!!**;;!:!!!--,~!=*;=**=***;::**=*" << endl
		<< "*=!;;!!!:=$$**=***==**!!!;;::!~~:*!!#==!!!=*!==***!!****====" << endl
		<< "=*!$;;==$*$$====*!=*!!~:;!~~----;!;*$!$==!!;!!*:!*!:!;=$$*$#" << endl
		<< "!**!:!!!!$=**!**!!**=*!-~~~-----;:!!$$=$$***!!!;*;*!!!$=~:*=" << endl
		<< "=*!!;;:!!$!!==**!!!*!;;:~:~~~~-~~:*=*#==$**=!;!=;!;;~;;~::;:" << endl
		<< "*!;!*!*;$$=*!*=!**;!!;;:::~~~---~:*!*=*$$;=*;:*;~:;*;*;!!!*!" << endl
		<< "*!*;*!!!===***=!!*;;~,~~::~~~~~~~~-!:;!**!#=**===$;=!**#~=#*" << endl
		<< "*=$!;;!*$=**!!!;;!!;:~~::~~~~:::~~-:~;*!===$$@@###@#*@$*$==*" << endl
		<< "*=$!!*=*=*=*!;!!;!;:;:~::~~~-~:~~~~::!;*=*=*=$#$$@@##$##$#$*" << endl
		<< "$$==*$=!:*!;;$:!!;:~;::~~~~~~~:~~:::-!*!#*#~::*#$##$$$#=**==" << endl
		<< "===*;**=;!;:;*!!;:::~~~~:~~~~::::;;;;*==##$$$#=**=#$=*=#@@##" << endl
		<< "$=$*!;$!=;*;*;**!;~-~~-~:::;;:~:~:;;;!=##$$###;##;$###==@##$" << endl
		<< "$$==*=**!!!:;;!;;;~:~-:~:;:~;:;:~::;;;!==$$#$####@#$$#####$=" << endl
		<< "$===*=!!!*=;;;!!!~::-~~;:::~::~~::~;:;;!*==$####$$$$$$#$####" << endl
		<< "===*=**!***!*!!;!!;:~-~::~:~~~~::;~~:~:;!!==$#$#=#=$$$$$####" << endl
		<< "=$=*!==**!**:;;!*;:::~~~:::~~~~:::~~:~;~:;;*=*$$##$$##=#####" << endl
		<< "$$=*****=*!*!;!;!!;;::~~~~~~~~~:~~~::~~:*::;;!!;===*=;=#$$=$" << endl
		<< "**$***=*:!!***!!**;;:~~~~~~~~-!~,-:~;:;:,::;:;;;****:=***$$$" << endl
		<< "$#=!==!=**;*!!*!!;!;~~:~::~~~~~~~~:~;::~-;!-:;:;;~:;=*=!!$*!" << endl
		<< "=$#*$*=!=$*;:!*!!:;::::~~~~~~~:~~~~~~~~~~~::::;!::;*!*=!=*==" << endl
		<< "=!==*===***!!;!;!;:~::~~-~~~~~-~,~::::~:~;~::~:::;;!!;!=*=*=" << endl
		<< "$***==***!!;-;:;;!:::;::::~~~~~~~:~--:::::~~:::;:;:;!!*!!!=!" << endl;
		printf("============================================================\n");
		printf("나 ( %d / %d ) \n", playerCurHp, playerMaxHp);

		break;
		// 산에 사는 몬스터 늑대
	case 4:
		printf("============================================================\n");
		cout
		<< "                             . . .,~~::.                    " << endl 
		<< "                        . .~~~.,;*;;!*:#.                   " << endl 
		<< "                     . -.*----~:;$=!!!!$-.                  " << endl 
		<< "                      .,-----~~:*,**!!!:~*:                 " << endl 
		<< "                     ..------~:!#;;!*!!*: ,.                " << endl 
		<< "                    ..---.--- ;!! *#:~:~ =; .               " << endl 
		<< "                   ..--#---~-::!;  :!=!::~-. .              " << endl 
		<< "                  . =:$#~:::,.!!!:!!**!!. , .               " << endl 
		<< "                 . .~:-:::::~::!;$*,!!-!=~,.                " << endl 
		<< "                  . !:-~::::~:=;==-~-;.,$!~ .               " << endl 
		<< "                 . -:::**:::~:;-::~ *; -!*;.                " << endl 
		<< "                  .@:::;::::::*-  ~;!~*~ ;~-.               " << endl 
		<< "                 .-!:::$!::::~=..  ~!!.   :! .              " << endl 
		<< "                  $*:::$;::::,;;.., ,.   .!,                " << endl 
		<< "               . ;*=;::=;;:::~:$, ,~@=-..-:.                " << endl 
		<< "                .:**#::$~,::::::@-.;--..~$.                 " << endl 
		<< "               . $**#:::.. $:::::: ...:!,.                  " << endl 
		<< "              . .#!*=:::-..~~!!:,=~ ..:$- .                 " << endl 
		<< "               . =:*#*:, ~$ ,:!!;!:=.:@.                    " << endl 
		<< "              . !=*!~ :, ,,:!.:;:;;;:$.                     " << endl 
		<< "               .~#$* .*. ;, .....,;,;~ .                    " << endl 
		<< "              . ~@@~. ,..,, .:..  ,,, .                     " << endl 
		<< "                ~!.   ; -,~    :. :,,                       " << endl 
		<< "                      , .,:     - ~,;                       " << endl 
		<< "                      , !.      *. -                        " << endl 
		<< "                    . ~ *..     ;. $.                       " << endl 
		<< "                     . ..,     .-. , .                      " << endl 
		<< "                    . .- -!     .. ~.                       " << endl 
		<< "                     . , !;#     :   .                      " << endl 
		<< "                      .  :,,=    ,  ~ .                     " << endl 
		<< "                       .  -*,.   !:; .                      " << endl 
		<< "                        -,~:     !~.~=                      " << endl 
		<< "                         ,        ;-::                      " << endl;
		printf("============================================================\n");

		break;
		// 배드엔딩
	case 5:
		printf("============================================================\n");
		cout
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@$;=@@$!#@*##*@@;*#@#!$@@@@@@@=;===@@@#=;=#@$;====$$;==*$@@@" << endl
		<< "@@=$@@#@@=@@@@=@!$@@@$@@@@@@@@@!@@@!@@@@;@@@@*@@@@#@!@@@*=@@" << endl
		<< "@@@;@@=@@*@@@@*@!$@@@#@@@@@@@@@!@@@=*@@@;@@@@=@@@@@@!@@@@!@@" << endl
		<< "@@@$$$#@=*@@@@*=!$@@@#@@@@@@@@@!@@@@*@@@;@@@@=@@@#@@!@@@@!@@" << endl
		<< "@@@@;$@@*=@@@@=*!$@@@#@@@@@@@@@!@@@@!@@@;@@@@=$$$;@@!@@@@=@@" << endl
		<< "@@@@=$@@*=@@@@==!$@@@#@@@@@@@@@!@@@@!@@@;@@@@=@@@*@@!@@@@=@@" << endl
		<< "@@@@=$@@=*@@@@*$!$@@@#@@@@@@@@@!@@@@*@@@;@@@@=@@@@@@!@@@@*@@" << endl
		<< "@@@@=$@@@*@@@@*@=$@@@$@@@@@@@@@!@@@==@@@;@@@@=@@@@@@!@@@@!@@" << endl
		<< "@@@@=$@@@*@@@@=@@=@@@=@@@@@@@@@!@@#*@@@@;@@@@*@@@@=@!@@@*=@@" << endl
		<< "@@@#;!@@@@!$$!@@@**#=@@@@@@@@@*;!!*@@@@=:*#@$;;!!;!$;!!;#@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl
		<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		printf("============================================================\n");
		printf("나 ( %d / %d ) \n", playerCurHp, playerMaxHp);

		break;
		// 마을
	case 6:
		printf("============================================================\n");
		cout
		<< "***!*!-:;:;~:;:*=*!;**;!**!!:!;!!;!*-;!:::!::;;;..         ." << endl
		<< "**!!!!-:;;:~~:~;!!;!;*=*!**!!;;;!!*!;!!;-,~!:;;::-       .-." << endl
		<< "*;=*:;;:!;;:~~~-;;;;:;!!**:;:;;;!:*!:;-:-,-~-!:;;:-      ,-;" << endl
		<< "**!!!!::~;;!::;;::-::-::;*!;:;!;!!;;;:~~~~:--~~;;;,   ..-:-:" << endl
		<< "=!**!;!!::;:;:;;:::-~;!;;;!!:~!;!*!;;~-:;;::~--;;;~. ,.-:!;*" << endl
		<< "*!*:;:$!!-::~~:!;;~:;##$;;;!:;!!!!;;;,-~:-,~~~-*$*!~-;,~:*;!" << endl
		<< "!**!*!*;;:;:!~!~!::;*###*;::*****!!=!~:::~-:~~~:!-~~:::;!!!;" << endl
		<< "!=***!;!;;;;::-~:~:;!@#$*;;:!;!*!~~!*-~-~:~~~~:;*-~-~~~~=*!*" << endl
		<< "!;$;*:****!!;;~~:;;;;=@=**;!*==!!~-!!~~~~~--~~~!=:*;!:,,,;!*" << endl
		<< "*!*;$==!;!*!;;~**;~:!=#$$#$$$=*!;;:*!:::~~~:;!!!*=====*;-;;*" << endl
		<< "!*!*$#!****;;::;:;;!;;;=$$#==$======****!!!*=**$!**!*;*!;;;*" << endl
		<< "!*=*=@$*=$**!;~::;;;;;;!!$=$***$$;;$*;::::~:;!=@!::;!!!!:;!*" << endl
		<< "!!*!=$$*$#=*!;::;~!:;;;;;==******==$;;::;:;!;!!$*;::;::!!!*=" << endl
		<< ";!!!!**!****:!;:::;!;:;;*=$=*!*;*==#;::;!=$*:;;!$;;;;::;!===" << endl
		<< "**;;**!*=!!!!;~~;:!!!!!;!#$=$$*;;!!$;;:=;!;!;;;:!:~:!;:;*;!;" << endl
		<< "!*:;!=****!;*!;=;!!:!;=;*=*!###;!!**:;=;;!!;***;*!!!*!;!!***" << endl
		<< "!!;***$=*!;:;*!=:!*;!=!!==*!###!*=*!;=!*!;**!*!**;!;*=!*!!*=" << endl
		<< "!****==!!:!!;!;~;!!;;*!;=#!*###**==!;;!;!;*!;*;!;:!;!=!=!=;=" << endl
		<< ";!!=***!;~~!:::;;!;!!**!$=!=$#$!!*!*$*!!!;***!;;!:;;=$!==*!*" << endl
		<< "*!*=!**!;:::*!:;~*:!!!**===*##$!!*!!@#*;***!!!**!~~**=!!;;;:" << endl
		<< "**=*!;::~::;!;~;:!:*:!*=$===$#$~~~:~=**;=!**!**!;~!*=$=$$*==" << endl
		<< "!!!*=!*;;~:;*;:=;;~;*!***===$=$~:;;:==***!**;;**!:!*=$$**!*!" << endl
		<< "-!!!*!*;:;;!;:;;:;::=;!;!$#$!=$;!!::*!=***::~*!*;~;====;;;!!" << endl
		<< "*;****!!:::*;;*!-:;;*;!;!=$**$=!!*:=***:;;**;**$*!;*=$==;*=!" << endl
		<< "!*!**!*!;!;!;!::~~~::****==*!=*!!!:!;*;!*!=!!;;**=*=****$=*=" << endl
		<< "$;***=!!;:;=;!::~;:::=$$@##=*!!~!;~;*!**!;=@:~-;;;!;;;;=@@@@" << endl
		<< "!!*!!=*!!!!*=:~;:~:~:*=$#=***!!:!!!!*!;~~~:#:---;;;!!;!==;==" << endl
		<< "*!!!!!!!!!!!*;;:;:;::**=$*;!!;;:!*:!*::~~--!~,,-;;:;!!!*===*" << endl
		<< ";;!!!!***!**;;::::!;*=**$*!;!;;;!!**:~~-~--!:,,.**!*==!-===*" << endl
		<< ";!!!!!;;*!!!;;;;*;;;;*:;;!:-:-.,,,,,,,,,,,,,,-!**!*=*$$=!;;;" << endl
		<< ":;!!!!;;;!**;:~:*~-,,*,,--,,,,,,,,,,,,,,,,,,,,:;;:*~~-;=!;!;" << endl
		<< ":;;$!;!;:-;~,,,-*-,--,.,,,,-,,,,,,,,,,,,,,,,,-~~:!*==***;~;$" << endl
		<< "*;:$;---,-;-,,,-;-,.,,,,,~-,,--,,,,,,,,,,,,,,,,~::!***;;;=$=" << endl
		<< "--,$;,,,-,--,.,,,,,,,,,,~~--,,-,,,,,,,,,,,,,,,,,-~~*====*===" << endl
		<< ",,,*:--,, ,,,,,,,,,,,,,--,,,,,,,,,,,,,,,,,,,,,,,,-,~!*~~~~:!" << endl
		<< "~----,,,,,,,,,,,,,,,,,,,,,,,,---,,,,,,,,,,,,,,,,,,--~:*=====" << endl
		<< ",,---,,-,,,,,,,,,,,,,,.,,,,,,,,,,.,,,,,,,,,,,,,,,,-,--:;==;~" << endl
		<< ",,,----,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,~-:=$" << endl
		<< ",,,,,,,,,,,,,,,,..,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,--:;!" << endl
		<< ",,,,,,,,,,,,,,,,,.,,.,,,,,,-,,,,,,,,,,,,,,,,,.,,,,,--,,,----" << endl;
		printf("============================================================\n");
		printf("나 ( %d / %d ) \n", playerCurHp, playerMaxHp);

		break;
		// 게임 시작 화면?
	case 7:
		printf("========================================================================================\n");
		cout
		<< ">=>        >=>                                                                          " << endl
		<< ">=>        >=>                                                                          " << endl
		<< ">=>   >>   >=>    >=> >=>  >=>   >=>                                                    " << endl
		<< ">=>  >=>   >=>  >=>   >=>   >=> >=>                                                     " << endl
		<< ">=> >> >=> >=> >=>    >=>     >==>                                                      " << endl
		<< ">> >>    >===>  >=>   >=>      >=>                                                      " << endl
		<< ">=>        >=>   >==>>>==>    >=>                                                       " << endl
		<< "                            >=>                                                         " << endl
		<< "                          >=>                                                           " << endl
		<< "                          >=>                                                           " << endl
		<< "                        >=>>==>    >=>                                                  " << endl
		<< "                          >=>    >=>  >=>                                               " << endl
		<< "                          >=>   >=>    >=>                                              " << endl
		<< "                          >=>    >=>  >=>                                               " << endl
		<< "                           >=>     >=>                                                  " << endl
		<< "                                                                                        " << endl
		<< "                                          >=>    >=>                                    " << endl
		<< "                                          >=>    >=>                                    " << endl
		<< "                                          >=>    >=>    >=>     >===>>=>>==>    >==>    " << endl
		<< "                                          >=====>>=>  >=>  >=>   >=>  >>  >=> >>   >=>  " << endl
		<< "                                          >=>    >=> >=>    >=>  >=>  >>  >=> >>===>>=> " << endl
		<< "                                          >=>    >=>  >=>  >=>   >=>  >>  >=> >>        " << endl
		<< "                                          >=>    >=>    >=>     >==>  >>  >=>  >====>   " << endl
		<< "                                                                                        " << endl;
		printf("========================================================================================\n");

		break;
		// 추가 사항?
	}
}

// 마을에 도착했나?
void IsTown() {
	if (roadIncount != 0 && roadIncount % 6 == 0) {
		if (dayCount > 0) {
			Graphics(6);
			Sleep(300);

			printf("근무 시간이 끝난 당신은 귀가했다 \n");

			_getch();
			system("cls");
		}
		else {
			Graphics(6);
			printf("길 끝에 마을이 보인다... \n");

			Sleep(1500);
			system("cls");

			Graphics(6);
			printf("당신은 무사히 마을에 도착했습니다 \n");

			_getch();
			system("cls");
		}
	}
}

// 전투할까?
void IsBattle() {
	const int BATTLERATE = 70;
	int isBattle = RandomPercent();

	if (isBattle > MAXPERCENT - BATTLERATE) {
		Graphics(3);
		Sleep(300);

		if (dayCount > 0) {
			printf("늑대를 발견했다 \n");
		}
		else {
			printf("옆 수풀에서 늑대가 나타났다!!! \n");
		}

		Sleep(1000);
		system("cls");

		Battle();
	}
	else {
		Graphics(3);
		Sleep(300);
			
		printf("신비한 힘이 나를 감싼다 \n");

		_getch();
		system("cls");

		PlayerHeal();
	}
}

// 힐할까?
void PlayerHeal() {
	const int HEALRATE = 60;
	const int HEALPOWER = 10;
	int isHeal = RandomPercent();

	if (isHeal > MAXPERCENT - HEALRATE) {
		playerCurHp += HEALPOWER;

		if (playerCurHp > playerMaxHp) {
			playerCurHp = playerMaxHp;
		}
	}
}

// 내가 가는 길
void RandomRoute() {
	const int ROADRATE = 30;
	const int RIVERRATE = 20;
	int myRoute = RandomPercent();

	if (myRoute > MAXPERCENT - ROADRATE) {
		Graphics(1);
		Sleep(300);

		if (dayCount > 0) {
			printf("당신은 길가를 정비했다 \n");

		}
		else {
			printf("잘 정비된 길이다 \n");
		}

		_getch();
		system("cls");

		roadIncount += 1;
		IsTown();
	}
	else if (myRoute > MAXPERCENT - ROADRATE - RIVERRATE) {
		Graphics(2);
		Sleep(300);

		if (dayCount > 0) {
			printf("당신은 강가를 순찰했다 \n");

		}
		else {
			printf("강을 따라 걸었다 \n");
		}

		_getch();
		system("cls");
	}
	else {
		Graphics(3);
		Sleep(300);

		if (dayCount > 0) {
			printf("당신은 늑대 퇴치를 나섰다 \n");

		}
		else {
			printf("뭐가 나올지 모른다 빨리 지나가자 \n");
		}

		Sleep(1500);
		system("cls");

		IsBattle();
	}
}

// 1 ~ 100까지의 난수 반환
int RandomPercent() {
	srand((unsigned int)time(NULL));

	return (((rand() * 3) % MAXPERCENT) + 1);
}

void IntroPrint() {
	printf("\n============================================================\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	Sleep(100);
	printf("모");
	Sleep(100);
	printf("험");
	Sleep(100);
	printf("가");
	Sleep(100);
	printf("인");
	Sleep(100);
	printf(" ");
	printf("당");
	Sleep(100);
	printf("신");
	Sleep(100);
	printf("은");
	Sleep(100);
	printf("\n");
	Sleep(100);
	printf("모");
	Sleep(100);
	printf("험");
	Sleep(100);
	printf("을");
	Sleep(100);
	printf(" ");
	Sleep(100);
	printf("끝");
	Sleep(100);
	printf("내");
	Sleep(100);
	printf("고");
	Sleep(100);
	printf(" ");
	Sleep(100);
	printf("마");
	Sleep(100);
	printf("을");
	Sleep(100);
	printf("로");
	Sleep(100);
	printf(" ");
	Sleep(100);
	printf("돌");
	Sleep(100);
	printf("아");
	Sleep(100);
	printf("가");
	Sleep(100);
	printf("는");
	Sleep(100);
	printf(" ");
	Sleep(100);
	printf("길");
	Sleep(100);
	printf("입");
	Sleep(100);
	printf("니");
	Sleep(100);
	printf("다");
	Sleep(100);
	printf("\n");
	Sleep(100);
	printf("\n");
	Sleep(100);
	printf("무");
	Sleep(100);
	printf("사");
	Sleep(100);
	printf("히");
	Sleep(100);
	printf(" ");
	Sleep(100);
	printf("도");
	Sleep(100);
	printf("착");
	Sleep(100);
	printf("할");
	Sleep(100);
	printf(" ");
	Sleep(100);
	printf("수");
	Sleep(100);
	printf(" ");
	Sleep(100);
	printf("있");
	Sleep(100);
	printf("을");
	Sleep(100);
	printf("까");
	Sleep(100);
	printf("요");
	Sleep(100);
	printf("?");
	Sleep(100);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n============================================================\n");

	Sleep(2000);
	system("cls");
}


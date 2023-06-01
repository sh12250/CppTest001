#include<stdio.h>

void RockScissorsPaper(int npc, int player)
{
	printf("%s", (player < npc) ? "플레이어 승리!" : "플레이어 패배!");
}

int main() 
{
	int npc = 2;
	int player;

	scanf_s("%d", &player);
	RockScissorsPaper(npc, player);


}

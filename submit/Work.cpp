#include<stdio.h>

void RockScissorsPaper(int npc, int player)
{
	printf("%s", (player < npc) ? "�÷��̾� �¸�!" : "�÷��̾� �й�!");
}

int main() 
{
	int npc = 2;
	int player;

	scanf_s("%d", &player);
	RockScissorsPaper(npc, player);


}

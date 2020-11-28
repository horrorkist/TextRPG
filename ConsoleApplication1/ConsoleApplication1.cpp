#include "SystemManager.h"
#include "BattleManager.h"
#include "Character.h"
#include "Monster.h"
#include <vector>
#include <iostream>

using namespace std;

SystemManager systemManager;
BattleManager battleManager;

//************************* Monster List *************************
//(이름, 맥댐, 민댐, 방어, 골드, 경험치, 체력)
Monster Orc("오크", 120, 80, 25, 500, 250, 400);
Monster Slime("슬라임", 15, 5, 1, 30, 10, 100);
Monster Mouse("생쥐", 5, 1, 0, 10, 5, 30);
Monster Wolf("늑대", 30, 15, 0, 75, 45, 150);
//Monster Bear;
//Monster Goblin;
//Monster Cobolt;
//Monster Dragon;
//Monster Spider;
//Monster Bet;
//Monster Skeleton;
//Monster Wisp;
//Monster Snake;
//Monster Wildboar;
//Monster Bandit;

//************************* Item List *************************

//************************* Battle Field List *************************
vector<vector<Monster>> BattleFields = { {Orc}, {Slime}, {Mouse} };


//************************* Player *************************
Character cPlayer;

int main()
{

	cPlayer.CreateNewChar();
	systemManager.ShowMainMenu();


	return 0;
}



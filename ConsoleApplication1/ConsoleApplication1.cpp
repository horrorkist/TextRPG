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

Monster Mouse("생쥐", 5, 1, 0, 10, 5, 30);
Monster Spider("거미", 7, 3, 0, 14, 7, 40);
Monster Bet("박쥐", 15, 8, 0, 15, 10, 25);
Monster Bandit("산적", 30, 20, 3, 70, 40, 80);
Monster Snake("뱀", 10, 5, 0, 40, 15, 40);

Monster Wolf("늑대", 30, 15, 0, 75, 45, 150);
Monster Bear("갈색 곰", 40, 20, 0, 100, 50, 200);
Monster Wildboar("멧돼지", 25, 10, 0, 60, 30, 100);

//Monster Wisp;
//Monster Kobold;
//Monster Skeleton;
Monster Goblin("고블린", 60, 40, 3, 200, 80, 250);
Monster Orc("오크", 120, 80, 5, 350, 100, 400);
Monster Ogre("오우거", 150, 100, 10, 500, 150, 1000);

Monster Dragon("오닉시아", 1000, 700, 50, 20000, 5000, 10000);
Monster Hatchling("새끼 용", 300, 200, 30, 2500, 300, 500);
Monster Slime("슬라임", 15, 5, 1, 30, 10, 100);
//************************* Item List *************************

//************************* Battle Field List *************************
vector<vector<Monster>> BattleFields = { {Mouse, Spider, Bet, Snake, Bandit}, {Wolf, Bear, Wildboar}, {Goblin, Orc, Ogre}, {Hatchling, Dragon} };


//************************* Player *************************
Character cPlayer;

int main()
{
	
	cPlayer.CreateNewChar();
	systemManager.ShowMainMenu();


	return 0;
}



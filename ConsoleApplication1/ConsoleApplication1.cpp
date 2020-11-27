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
Monster Orc("오크", 30, 10, 2, 100, 20, 200, 200);
Monster Slime("슬라임", 15, 5, 1, 30, 10, 100, 100);
Monster Mouse("생쥐", 5, 1, 0, 10, 5, 30, 30);

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



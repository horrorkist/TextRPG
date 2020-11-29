#include "SystemManager.h"
#include "BattleManager.h"
#include "StoreManager.h"
#include "Character.h"
#include "MonsterDB.h"
#include "ItemDB.h"
#include <vector>
#include <iostream>

using namespace std;

//************************* Player *************************
Character cPlayer;

//************************* DB *************************
ItemDB itemDB;
MonsterDB monsterDB;

//************************* Manager *************************
SystemManager	 systemManager;
BattleManager	 battleManager;
StoreManager	 storeManager;
int main()
{
	
	cPlayer.CreateNewChar();
	systemManager.ShowMainMenu();


	return 0;
}



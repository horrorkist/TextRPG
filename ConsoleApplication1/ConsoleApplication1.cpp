#include "SystemManager.h"
#include "BattleManager.h"
#include "StoreManager.h"
#include "Character.h"
#include "MonsterDB.h"
#include "ItemDB.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


ifstream inputStream;
ofstream outputStream;


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
	inputStream.open("data.txt");
	if (inputStream.is_open()) {
		string str;
		getline(inputStream, str);
		cPlayer.SetUsingData(str);
		inputStream.close();
	}
	else
		cPlayer.CreateNewChar();
	systemManager.ShowMainMenu();


	return 0;
}



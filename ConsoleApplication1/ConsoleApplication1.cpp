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
#include <Windows.h>

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
		cout << "데이터를 자동으로 불러옵니다." << endl;
		Sleep(600);
		system("cls");
		cout << "데이터를 자동으로 불러옵니다.." << endl;
		Sleep(600);
		system("cls");
		cout << "데이터를 자동으로 불러옵니다..." << endl;
		Sleep(600);
	}
	else
		cPlayer.CreateNewChar();
	systemManager.ShowMainMenu();


	return 0;
}



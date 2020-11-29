#include "SystemManager.h"
#include "BattleManager.h"
#include "StoreManager.h"
#include <vector>

using namespace std;

extern Character cPlayer;
extern BattleManager battleManager;
extern StoreManager storeManager;

void SystemManager::ShowMainMenu() {


	enum MM_Choice {MM_ZERO, MM_BATTLE, MM_STORE, MM_INN, MM_STATS, MM_SAVE, MM_QUIT};

	while (true) {
		system("cls");
		cout << "-------------------------------------------------" << endl;
		cout << "1. 전투" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 여관" << endl;
		cout << "4. 내 정보" << endl;
		cout << "5. 저장" << endl;
		cout << "6. 종료" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "행동을 선택하세요 : ";

		int iChoice;

		cin >> iChoice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}


		if (iChoice == MM_QUIT) {
			cout << "게임을 종료할까요?(y/n)" << endl;
			char cConfirm = 0;
			cin.ignore();
			cin >> cConfirm;
			switch (cConfirm) {
			case 'y': {
				cout << "게임을 종료합니다." << endl;
				return;
			}
					  break;
			case 'n':
				continue;
			default:
				continue;
			}
		}

		switch (iChoice) {
		case MM_BATTLE:  
			battleManager.ShowBattleMenu();
			break;
		case MM_STORE:
			storeManager.ShowStoreMenu();
			break;
		case MM_INN:
			Heal();
			break;
		case MM_STATS:
			ShowMyInfo();
			break;
		case MM_SAVE: {
			cout << "정보를 저장합니다. " << endl;
			ofstream outputStream;
			outputStream.open("data.txt");
			string save = cPlayer.GetDataString();
			outputStream.write(save.c_str(), save.size());
			outputStream.close();
			break; 
		}
		default:
			cout << "잘못된 입력입니다. 다시 선택하세요." << endl;
			break;
		}
	}
}

void SystemManager::Heal() {
	system("cls");
	cPlayer.iHp = cPlayer.iMaxHp;
	cPlayer.iMp = cPlayer.iMaxMp;
	cout << "체력을 회복했습니다." << endl;
	system("PAUSE");
}

void SystemManager::ShowMyInfo() const {
	system("cls");
	cPlayer.ShowCharStats();
	cout << "1. 내 장비 확인  2. 돌아가기" << endl;

	enum INFO { INFO_NONE, INFO_EQUIPMENT, INFO_RETURN };

	int iChoice;

	while (true) {
		cout << endl << "선택하세요 : "; cin >> iChoice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iChoice == INFO_RETURN) break;

		if (iChoice == INFO_EQUIPMENT) {
			cPlayer.ShowCharEquipments();
			system("PAUSE");
			break;
		}
	}
}


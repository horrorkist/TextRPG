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
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. ����" << endl;
		cout << "4. �� ����" << endl;
		cout << "5. ����" << endl;
		cout << "6. ����" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "�ൿ�� �����ϼ��� : ";

		int iChoice;

		cin >> iChoice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}


		if (iChoice == MM_QUIT) {
			cout << "������ �����ұ��?(y/n)" << endl;
			char cConfirm = 0;
			cin.ignore();
			cin >> cConfirm;
			switch (cConfirm) {
			case 'y': {
				cout << "������ �����մϴ�." << endl;
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
			cout << "������ �����մϴ�. " << endl;
			ofstream outputStream;
			outputStream.open("data.txt");
			string save = cPlayer.GetDataString();
			outputStream.write(save.c_str(), save.size());
			outputStream.close();
			break; 
		}
		default:
			cout << "�߸��� �Է��Դϴ�. �ٽ� �����ϼ���." << endl;
			break;
		}
	}
}

void SystemManager::Heal() {
	system("cls");
	cPlayer.iHp = cPlayer.iMaxHp;
	cPlayer.iMp = cPlayer.iMaxMp;
	cout << "ü���� ȸ���߽��ϴ�." << endl;
	system("PAUSE");
}

void SystemManager::ShowMyInfo() const {
	system("cls");
	cPlayer.ShowCharStats();
	cout << "1. �� ��� Ȯ��  2. ���ư���" << endl;

	enum INFO { INFO_NONE, INFO_EQUIPMENT, INFO_RETURN };

	int iChoice;

	while (true) {
		cout << endl << "�����ϼ��� : "; cin >> iChoice;

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


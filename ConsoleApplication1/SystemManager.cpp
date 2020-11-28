#include "SystemManager.h"
#include "BattleManager.h"
#include "StoreManager.h"
#include "Monster.h"
#include <vector>
//#include "ConsoleApplication1.cpp"

using namespace std;

extern Character cPlayer;
extern vector<vector<Monster>> BattleFields;
extern BattleManager battleManager;
extern StoreManager storeManager;

void SystemManager::ShowMainMenu() const {

	enum MM_Choice {MM_ZERO, MM_BATTLE, MM_STORE, MM_INN, MM_STATS, MM_SAVE, MM_LOAD, MM_QUIT};

	while (true) {
		system("cls");
		cout << "-------------------------------------------------" << endl;
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. ����" << endl;
		cout << "4. �� ����" << endl;
		cout << "5. ����" << endl;
		cout << "6. �ҷ�����" << endl;
		cout << "7. ����" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "�ൿ�� �����ϼ��� : ";

		int iChoice;

		cin >> iChoice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		switch (iChoice) {
		case MM_BATTLE:  //�Լ��� ó��
			ShowBattleMenu();
			/*while (true) {
				system("cls");
				cout << "************************ ����͸� �����ϼ���. ************************" << endl;
				cout << "1. �޻�" << endl;
				cout << "2. ����" << endl;
				cout << "3. ���� ��" << endl;
				cout << "4. ���ư���" << endl;
				cout << "************************************************" << endl;
				cout << "�����ϼ���. : ";
				
				cin >> iChoice;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (ichoice == 4) break;

				if (ichoice < 1 || ichoice > 4) continue;

				battlemanager.battle(ichoice);

			}*/
			break;
		case MM_STORE:
			storeManager.ShowStoreMenu();
			break;
		case MM_INN:
			system("cls");
			cPlayer.iHp = cPlayer.iMaxHp;
			cPlayer.iMp = cPlayer.iMaxMp;
			cout << "ü���� ȸ���߽��ϴ�." << endl;
			system("PAUSE");
			break;
		case MM_STATS: {
			system("cls");
			cPlayer.ShowCharStats();
			cout << "1. �� ��� Ȯ��  2. ���ư���" << endl;

			//int iChoice = 0;
			enum INFO {INFO_NONE, INFO_EQUIPMENT, INFO_RETURN};

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
			break;
		case MM_SAVE:
			break;
		case MM_LOAD:
			break;
		case MM_QUIT: {
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
				break;
			default:
				break;
			}
			break;
		}
		default:
			cout << "�߸��� �Է��Դϴ�. �ٽ� �����ϼ���." << endl;
			break;
		}
	}
}

void SystemManager::ShowBattleMenu() const {
	int iChoice;
	while (true) {
		system("cls");
		cout << "************************ ����͸� �����ϼ���. ************************" << endl;
		cout << "1. �޻�" << endl;
		cout << "2. ����" << endl;
		cout << "3. ���� ��" << endl;
		cout << "4. ���нþ��� ����" << endl;
		cout << "5. ���ư���" << endl;
		cout << "************************************************" << endl;
		cout << "�����ϼ���. : ";

		cin >> iChoice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iChoice == 5) break;

		if (iChoice < 1 || iChoice > 5) continue;

		battleManager.Battle(iChoice);

	}
}
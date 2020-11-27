#include "SystemManager.h"
#include "BattleManager.h"
#include "Monster.h"
#include <vector>
//#include "ConsoleApplication1.cpp"

using namespace std;

extern Character cPlayer;
extern vector<vector<Monster>> BattleFields;
extern BattleManager battleManager;

void SystemManager::ShowMainMenu() const {

	enum MM_Choice {MM_ZERO, MM_BATTLE, MM_STORE, MM_INN, MM_STATS, MM_SAVE, MM_LOAD, MM_QUIT};

	while (true) {
		system("cls");
		cout << "-------------------------------------------------" << endl;
		cout << "1. 전투" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 여관" << endl;
		cout << "4. 내 정보" << endl;
		cout << "5. 저장" << endl;
		cout << "6. 불러오기" << endl;
		cout << "7. 종료" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "행동을 선택하세요 : " << endl;

		int iChoice;

		cin >> iChoice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		switch (iChoice) {
		case MM_BATTLE:
			while (true) {
				system("cls");
				cout << "************************ 사냥터를 선택하세요. ************************" << endl;
				cout << "1. 뒷산" << endl;
				cout << "2. 들판" << endl;
				cout << "3. 깊은 숲" << endl;
				cout << "4. 돌아가기" << endl;
				cout << "************************************************" << endl;
				cout << "선택하세요. : ";
				
				cin >> iChoice;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (iChoice == 4) break;

				if (iChoice < 1 || iChoice > 4) continue;

				battleManager.Battle(iChoice);

			}
			break;
		case MM_STORE:
			break;
		case MM_INN:
			break;
		case MM_STATS: {
			for (int i = 0; i < BattleFields.size(); i++) {
				for (int j = 0; j < BattleFields[i].size(); j++) BattleFields[i][j].ShowCharStats();
			}
			cPlayer.ShowCharStats();
			cout << "1. 장비창 보기  2. 돌아가기" << endl;

			int iChoice = 0;

			while (iChoice != 1 && iChoice != 2) {
				cout << endl << "선택하세요 : ";
				
				cin >> iChoice;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
			}
		}
			break;
		case MM_SAVE:
			break;
		case MM_LOAD:
			break;
		case MM_QUIT: {
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
				break;
			default:
				break;
			}
			break;
		}
		default:
			cout << "잘못된 입력입니다. 다시 선택하세요." << endl;
			break;
		}
	}
}
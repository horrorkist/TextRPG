#include "SystemManager.h"
#include "BattleManager.h"
//#include "ConsoleApplication1.cpp"

using namespace std;


BattleManager bm; //전투 매니저 생성

extern Character cPlayer;

void SystemManager::ShowMainMenu() const {

	enum MMChoice {MM_ZERO, MM_BATTLE, MM_STORE, MM_INN, MM_STATS, MM_SAVE, MM_LOAD, MM_QUIT};
	enum BFChoice { BF_ZERO, BF_MOUNTAIN, BF_FIELD, BF_FOREST, BF_QUIT };

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

		switch (iChoice) {
		case MM_BATTLE:
			system("cls");
			cout << "-------------------------------------------------" << endl;
			cout << "1. 뒷산" << endl;
			cout << "2. 들판" << endl;
			cout << "3. 깊은 숲" << endl;
			cout << "4. 돌아가기" << endl;
			cout << "-------------------------------------------------" << endl;
			cout << "행동을 선택하세요 : " << endl;

			cin >> iChoice;

			if (iChoice == BF_QUIT) break;

			bm.Battle(iChoice);
			
			break;
		case MM_STORE:
			break;
		case MM_INN:
			break;
		case MM_STATS:
			cPlayer.ShowCharStats();
			break;
		case MM_SAVE:
			break;
		case MM_LOAD:
			break;
		case MM_QUIT: {
			cout << "게임을 종료할까요?(y/n)" << endl;
			char cConfirm = 0;
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
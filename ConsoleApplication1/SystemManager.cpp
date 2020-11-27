#include "SystemManager.h"
//#include "ConsoleApplication1.cpp"

using namespace std;

extern Character cPlayer;

void SystemManager::ShowMainMenu() const {

	enum MMChoice {MM_ZERO, MM_BATTLE, MM_STORE, MM_INN, MM_STATS, MM_SAVE, MM_LOAD, MM_QUIT};

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
		cout << "�ൿ�� �����ϼ��� : " << endl;

		int iChoice;

		cin >> iChoice;

		switch (iChoice) {
		case MM_BATTLE:
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
			cout << "������ �����ұ��?(y/n)" << endl;
			char cConfirm = 0;
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
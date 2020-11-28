#include "StoreManager.h"
#include "SystemManager.h"
#include "Item.h"

enum SMChoice { SM_ZERO, SM_BUY, SM_RESET, SM_UPGRADE, SM_QUIT };

void StoreManager::StoreMenu() const
{
	while (true)
	{
		int iChoice = 0;

		//�÷��̾� ����
		system("cls");
		cout << "-------------------------------------------------" << endl;
		cout << "1. ������ ����" << endl;
		cout << "2. ���� ���ΰ�ħ" << endl;
		cout << "3. ���� ���׷��̵�" << endl;
		cout << "4. ���θ޴� ���ư���" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "�ൿ�� �����ϼ��� : " << endl;

		cin >> iChoice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		switch (iChoice) {

		case SM_BUY:

			//������ ������
			break;

		case SM_RESET:
			cout << "������ ����� ���ΰ�ħ�մϴ�. ( ��� : 00G )" << endl;
			//������ ����
			break;

		case SM_UPGRADE:
			cout << "���� ������ ���׷��̵� �մϴ�. ( ��� : 00G )" << endl;
			//���� ������
			break;

		case SM_QUIT:
			cout << "���� �޴��� ���ư��ϴ�." << endl;
			//ShowMainMenu();
			break;

		default:
			cout << "�߸��� �Է��Դϴ�. �ٽ� �����ϼ���." << endl;
			break;

		}
	}

}
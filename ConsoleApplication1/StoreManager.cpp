#include "StoreManager.h"
#include "SystemManager.h"
#include "Item.h"


//************************* Member Functions *************************

enum SMChoice { SM_ZERO, SM_BUY, SM_RESET, SM_UPGRADE, SM_QUIT };

void StoreManager::ShowStoreMenu()
{
	while (true)
	{
		system("cls");

		if (StoreManager::isAllSlotsEmpty()) {  // ���� �� ��� ������ ��������� ��� ���� ä���
			for (int i = 0; i < iMaxSlots; i++) {
				FillSlot(i);
			}
		}

		ShowStoreList();

		int iChoice = 0;

		//�÷��̾� ����
		cout << "-------------------------------------------------" << endl;
		cout << "1. ������ ����" << endl;
		cout << "2. ���� ���ΰ�ħ" << endl;
		cout << "3. ���� ���׷��̵�" << endl;
		cout << "4. ���ư���" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "�����ϼ���. : " << endl;

		cin >> iChoice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iChoice == SM_QUIT) return;

		switch (iChoice) {

		case SM_BUY:

			while (true) {
				system("cls");

				ShowStoreList();

				cout << "�� �� ������ �������� �����ұ��?(1 ~ " << iMaxSlots << ", ���ư��� : 0)" << endl; cin >> iChoice;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (iChoice == 0) break;

				if (1 <= iChoice && iChoice <= iMaxSlots) {
					system("cls");

					Slot[iChoice].ShowItemInfo();

					if (cPlayer.iGold < Slot[iChoice].GetItemPrice()) {
						cout << "�������� �����Ͽ� ������ �� �����ϴ�. ���� ������ : " << cPlayer.iGold << "G" << endl;
						system("PAUSE");
						break;
					}
					cout << "��" << Slot[iChoice].GetItemName() << "�� ��(��) �����ұ��? ���� ���� �������� �������ϴ�. \n ���� ������ : " << cPlayer.iGold << "G (y/n)" << endl;

					char cConfirm;

					cin >> cConfirm;

					if (cin.fail()) {
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}

				}
				else {
					cout << "�߸��� ���� �����Դϴ�. �ٽ� �������ּ���." << endl;
					system("PAUSE");
					continue;
				}
			}

			break;

		case SM_RESET:
			cout << "������ ����� ���ΰ�ħ�մϴ�. ( ��� : 00G )" << endl;
			//������ ����
			break;

		case SM_UPGRADE:
			cout << "���� ������ ���׷��̵� �մϴ�. ( ��� : 00G )" << endl;
			//���� ������
			break;

		default:
			cout << "�߸��� �Է��Դϴ�. �ٽ� �����ϼ���." << endl;
			break;

		}
	}

}

void StoreManager::ShowStoreList() const {
	for (int i = 0; i < iMaxSlots; i++) {
		cout << i+1 << "�� ����" << endl;
		Slot[i].ShowItemInfo();
	}
	return;
}

bool StoreManager::isAllSlotsEmpty() const {
	for (int i = 0; i < iMaxSlots; i++) {
		if (Slot[i].GetItemType()) return false;
	}
	return true;
}

void StoreManager::FillSlot(int toFill) {
	srand((unsigned int)time(NULL));

	int iDice = (rand() % 100) + 1;
	
	for (int i = 1; i <= 6; i++) {
		if (iDice <= Odds[iStoreLevel][i]) {
			iDice = rand() % ItemList[i].size();
			Slot[toFill] = ItemList[i][iDice];
			return;
		}
	}
	
	cout << "������ ä��⿡ �����߽��ϴ�." << endl;
	system("PAUSE");

	return;
}
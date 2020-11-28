#include "StoreManager.h"
#include "SystemManager.h"
#include "Item.h"


//************************* Member Functions *************************

enum SM_Choice { SM_ZERO, SM_BUY, SM_REFRESH, SM_UPGRADE, SM_INFO, SM_QUIT };

void StoreManager::ShowStoreMenu()
{
	srand((unsigned int)time(NULL));

	while (true)
	{
		system("cls");

		
		if (StoreManager::isAllSlotsEmpty()) {  // ���� �� ��� ������ ��������� ��� ���� ä���
			//cout << "��� ������ ����ֽ��ϴ�." << endl;
			for (int i = 1; i <= iMaxSlots; i++) {
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
		cout << "4. ���� ���� Ȯ��" << endl;
		cout << "5. ���ư���" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "�����ϼ���. : ";

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
				cout << "****************** ������ ���� ******************" << endl;
				cout << "�� �� ������ �������� �����ұ��?(1 ~ " << iMaxSlots << ", ���ư��� : 0)" << endl; cin >> iChoice;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (iChoice == 0) break;

				if (1 <= iChoice && iChoice <= iMaxSlots) {

					if (!Slot[iChoice].GetItemType()) {
						cout << "����ִ� ������ ������ �� �����ϴ�." << endl;
						system("PAUSE");
						continue;
					}

					while (true) {

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

						if (cConfirm == 'y') {
							cout << "��" << Slot[iChoice].GetItemName() << "����(��) �����߽��ϴ�. ���� ������ : ";
							cPlayer.iGold -= Slot[iChoice].GetItemPrice();
							cout << cPlayer.iGold << "G" << endl;
							Slot[iChoice].Equip(cPlayer);
							Slot[iChoice] = None;

							if (isAllSlotsEmpty()) {
								cout << endl << "��� ������ �������� �����Ͽ� ����� ���ΰ�ħ �˴ϴ�." << endl;
								for (int i = 1; i <= iMaxSlots; i++) FillSlot(i);
							}
							system("PAUSE");
							break;
						}

						if (cConfirm == 'n') break;
					}
				}
				else {
					cout << "�߸��� ���� �����Դϴ�. �ٽ� �������ּ���." << endl;
					system("PAUSE");
					continue;
				}
			}

			break;

		case SM_REFRESH:
			system("cls");

			ShowStoreList();
			cout << "****************** ���� ���ΰ�ħ ******************" << endl;
			cout << "������ ���ΰ�ħ �ұ��? ��� ������ ���ΰ�ħ �˴ϴ�. ����� : " << iRefCost << "G �Դϴ�.(y/n)" << endl;
			
			char cConfirm;

			while (true) {

				cin >> cConfirm;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (cConfirm == 'y') {
					if (cPlayer.iGold < iRefCost) {
						cout << "�������� �����մϴ�. ���� ������ : " << cPlayer.iGold << "G" << endl;
						system("PAUSE");
						break;
					}
					cPlayer.iGold -= iRefCost;
					for (int i = 1; i <= iMaxSlots; i++) {
						FillSlot(i);
					}
					cout << "��� ������ ���ΰ�ħ �Ǿ����ϴ�." << endl;
					system("PAUSE");
					break;
				}

				if (cConfirm == 'n') break;
			}

			break;

		case SM_UPGRADE:
			enum UPG_CHOICE {UP_NONE, UP_LVUP, UP_ADDSLOT, UP_QUIT};

			while (true) {
				system("cls");
				cout << "****************** ���� ���׷��̵� ******************" << endl;
				cout << "1. ���� ���� ��" << endl;
				cout << "2. ���� ���� �ø���" << endl;
				cout << "3. ���ư���" << endl;
				cout << "******************************************" << endl;
				cout << "�����ϼ���. : "; cin >> iChoice;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (iChoice == UP_QUIT) break;

				switch(iChoice) {
				case UP_LVUP: {
					if (iStoreLevel == iStoreLevelLimit) {
						cout << "�� �̻� ���� ������ �ø� �� �����ϴ�." << endl;
						system("PAUSE");
						break;
					}

					cout << "���� ������ �ø����? ����� : " << iStoreLevelUpCost << "G �Դϴ�.(y/n)" << endl;

					char cConfirm;

					while (true) {

						cin >> cConfirm;

						if (cin.fail()) {
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						if (cConfirm == 'y') {
							if (cPlayer.iGold < iStoreLevelUpCost) {
								cout << "�������� �����մϴ�. ���� ������ : " << cPlayer.iGold << "G" << endl;
								system("PAUSE");
								break;
							}
							cPlayer.iGold -= iStoreLevelUpCost;
							iStoreLevel++;
							cout << "������ ������ �ö����ϴ�. ���� ���� ���� : " << iStoreLevel << endl;
							system("PAUSE");
							break;
						}

						if (cConfirm == 'n') break;
					}
				}
					
					break;
				case UP_ADDSLOT: {
					if (iMaxSlots == iSlotLimit) {
						cout << "�� �̻� ������ �ø� �� �����ϴ�." << endl;
						system("PAUSE");
						break;
					}

					cout << "���� ������ �߰��ұ��? ����� : " << iAddSlotCost << "G �Դϴ�.(y/n)" << endl;

					char cConfirm;

					while (true) {

						cin >> cConfirm;

						if (cin.fail()) {
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						if (cConfirm == 'y') {
							if (cPlayer.iGold < iAddSlotCost) {
								cout << "�������� �����մϴ�. ���� ������ : " << cPlayer.iGold << "G" << endl;
								system("PAUSE");
								break;
							}
							cPlayer.iGold -= iAddSlotCost;
							iMaxSlots++;
							Slot[iMaxSlots] = None;
							cout << "���� ������ �þ���ϴ�. ���� ���� �� : " << iMaxSlots << endl;
							system("PAUSE");
							break;
						}

						if (cConfirm == 'n') break;
					}
				}
					break;
				default:
					cout << "�߸��� �����Դϴ�. �ٽ� �����ϼ���." << endl;
					system("PAUSE");
					break;
				}
			}
			break;
		case SM_INFO:
			system("cls");
			cout << "****************** ���� ���� ******************" << endl;
			cout << "���� ���� ���� : " << iStoreLevel << endl;
			cout << "���� ������ ���� Ȯ�� " << endl;
			cout << "�Ϲ� : " << Odds[iStoreLevel][1] << "%" << endl;
			cout << "���� : " << Odds[iStoreLevel][2] << "%" << endl;
			cout << "��� : " << Odds[iStoreLevel][3] << "%" << endl;
			cout << "���� : " << Odds[iStoreLevel][4] << "%" << endl;
			cout << "����ũ : " << Odds[iStoreLevel][5] << "%" << endl << endl;
			if (iStoreLevel < iStoreLevelLimit) cout << "���� ���� ��� : " << iStoreLevelUpCost << "G" << endl;
			else cout << "���� ���� ������ �ִ��Դϴ�." << endl << endl;
			cout << "���� ���� ���� �� : " << iMaxSlots << endl;
			if (iMaxSlots < iSlotLimit) cout << "���� ���� ��� : " << iAddSlotCost << "G" << endl;
			else cout << "���� ���� ���� ���� �ִ��Դϴ�." << endl << endl;
			system("PAUSE");
			break;
		default:
			cout << "�߸��� �Է��Դϴ�. �ٽ� �����ϼ���." << endl;
			system("PAUSE");
			break;

		}
	}

}

void StoreManager::ShowStoreList() const {
	for (int i = 1; i <= iMaxSlots; i++) {
		cout << i << "�� ����" << endl;
		Slot[i].ShowItemInfo();
		cout << endl;
	}
	return;
}

bool StoreManager::isAllSlotsEmpty() const {
	for (int i = 1; i <= iMaxSlots; i++) {
		if (Slot[i].GetItemType()) return false;
	}
	return true;
}

void StoreManager::FillSlot(int toFill) {
	//srand((unsigned int)time(NULL));

	int iDice = (rand() % 100) + 1;
	int iChanceBar = 0;
	for (int i = 1; i <= 5; i++) {
		iChanceBar += Odds[iStoreLevel][i];
		if (iDice <= iChanceBar) {
			iDice = (rand() % ItemList[i].size());
			Slot[toFill] = ItemList[i][iDice];
			return;
		}
	}
	
	cout << "������ ä��⿡ �����߽��ϴ�." << endl;
	system("PAUSE");

	return;
}
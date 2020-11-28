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

		
		if (StoreManager::isAllSlotsEmpty()) {  // 진입 시 모든 슬롯이 비어있으면 모든 슬롯 채우기
			//cout << "모든 슬롯이 비어있습니다." << endl;
			for (int i = 1; i <= iMaxSlots; i++) {
				FillSlot(i);
			}
		}

		ShowStoreList();

		int iChoice = 0;

		//플레이어 선택
		cout << "-------------------------------------------------" << endl;
		cout << "1. 아이템 구매" << endl;
		cout << "2. 상점 새로고침" << endl;
		cout << "3. 상점 업그레이드" << endl;
		cout << "4. 상점 정보 확인" << endl;
		cout << "5. 돌아가기" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "선택하세요. : ";

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
				cout << "****************** 아이템 구매 ******************" << endl;
				cout << "몇 번 슬롯의 아이템을 구매할까요?(1 ~ " << iMaxSlots << ", 돌아가기 : 0)" << endl; cin >> iChoice;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (iChoice == 0) break;

				if (1 <= iChoice && iChoice <= iMaxSlots) {

					if (!Slot[iChoice].GetItemType()) {
						cout << "비어있는 슬롯은 구매할 수 없습니다." << endl;
						system("PAUSE");
						continue;
					}

					while (true) {

						system("cls");

						Slot[iChoice].ShowItemInfo();

						if (cPlayer.iGold < Slot[iChoice].GetItemPrice()) {
							cout << "소지금이 부족하여 구매할 수 없습니다. 현재 소지금 : " << cPlayer.iGold << "G" << endl;
							system("PAUSE");
							break;
						}
						cout << "『" << Slot[iChoice].GetItemName() << "』 을(를) 구매할까요? 장착 중인 아이템은 버려집니다. \n 현재 소지금 : " << cPlayer.iGold << "G (y/n)" << endl;

						char cConfirm;

						cin >> cConfirm;

						if (cin.fail()) {
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						if (cConfirm == 'y') {
							cout << "『" << Slot[iChoice].GetItemName() << "』을(를) 구매했습니다. 남은 소지금 : ";
							cPlayer.iGold -= Slot[iChoice].GetItemPrice();
							cout << cPlayer.iGold << "G" << endl;
							Slot[iChoice].Equip(cPlayer);
							Slot[iChoice] = None;

							if (isAllSlotsEmpty()) {
								cout << endl << "모든 슬롯의 아이템을 구매하여 목록이 새로고침 됩니다." << endl;
								for (int i = 1; i <= iMaxSlots; i++) FillSlot(i);
							}
							system("PAUSE");
							break;
						}

						if (cConfirm == 'n') break;
					}
				}
				else {
					cout << "잘못된 슬롯 선택입니다. 다시 선택해주세요." << endl;
					system("PAUSE");
					continue;
				}
			}

			break;

		case SM_REFRESH:
			system("cls");

			ShowStoreList();
			cout << "****************** 상점 새로고침 ******************" << endl;
			cout << "상점을 새로고침 할까요? 모든 슬롯이 새로고침 됩니다. 비용은 : " << iRefCost << "G 입니다.(y/n)" << endl;
			
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
						cout << "소지금이 부족합니다. 현재 소지금 : " << cPlayer.iGold << "G" << endl;
						system("PAUSE");
						break;
					}
					cPlayer.iGold -= iRefCost;
					for (int i = 1; i <= iMaxSlots; i++) {
						FillSlot(i);
					}
					cout << "모든 슬롯이 새로고침 되었습니다." << endl;
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
				cout << "****************** 상점 업그레이드 ******************" << endl;
				cout << "1. 상점 레벨 업" << endl;
				cout << "2. 상점 슬롯 늘리기" << endl;
				cout << "3. 돌아가기" << endl;
				cout << "******************************************" << endl;
				cout << "선택하세요. : "; cin >> iChoice;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (iChoice == UP_QUIT) break;

				switch(iChoice) {
				case UP_LVUP: {
					if (iStoreLevel == iStoreLevelLimit) {
						cout << "더 이상 상점 레벨을 올릴 수 없습니다." << endl;
						system("PAUSE");
						break;
					}

					cout << "상점 레벨을 올릴까요? 비용은 : " << iStoreLevelUpCost << "G 입니다.(y/n)" << endl;

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
								cout << "소지금이 부족합니다. 현재 소지금 : " << cPlayer.iGold << "G" << endl;
								system("PAUSE");
								break;
							}
							cPlayer.iGold -= iStoreLevelUpCost;
							iStoreLevel++;
							cout << "상점의 레벨이 올랐습니다. 현재 상점 레벨 : " << iStoreLevel << endl;
							system("PAUSE");
							break;
						}

						if (cConfirm == 'n') break;
					}
				}
					
					break;
				case UP_ADDSLOT: {
					if (iMaxSlots == iSlotLimit) {
						cout << "더 이상 슬롯을 늘릴 수 없습니다." << endl;
						system("PAUSE");
						break;
					}

					cout << "상점 슬롯을 추가할까요? 비용은 : " << iAddSlotCost << "G 입니다.(y/n)" << endl;

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
								cout << "소지금이 부족합니다. 현재 소지금 : " << cPlayer.iGold << "G" << endl;
								system("PAUSE");
								break;
							}
							cPlayer.iGold -= iAddSlotCost;
							iMaxSlots++;
							Slot[iMaxSlots] = None;
							cout << "상점 슬롯이 늘어났습니다. 현재 슬롯 수 : " << iMaxSlots << endl;
							system("PAUSE");
							break;
						}

						if (cConfirm == 'n') break;
					}
				}
					break;
				default:
					cout << "잘못된 선택입니다. 다시 선택하세요." << endl;
					system("PAUSE");
					break;
				}
			}
			break;
		case SM_INFO:
			system("cls");
			cout << "****************** 상점 정보 ******************" << endl;
			cout << "현재 상점 레벨 : " << iStoreLevel << endl;
			cout << "현재 아이템 등장 확률 " << endl;
			cout << "일반 : " << Odds[iStoreLevel][1] << "%" << endl;
			cout << "마법 : " << Odds[iStoreLevel][2] << "%" << endl;
			cout << "희귀 : " << Odds[iStoreLevel][3] << "%" << endl;
			cout << "레어 : " << Odds[iStoreLevel][4] << "%" << endl;
			cout << "유니크 : " << Odds[iStoreLevel][5] << "%" << endl << endl;
			if (iStoreLevel < iStoreLevelLimit) cout << "다음 레벨 비용 : " << iStoreLevelUpCost << "G" << endl;
			else cout << "현재 상점 레벨이 최대입니다." << endl << endl;
			cout << "현재 상점 슬롯 수 : " << iMaxSlots << endl;
			if (iMaxSlots < iSlotLimit) cout << "다음 슬롯 비용 : " << iAddSlotCost << "G" << endl;
			else cout << "현재 상점 슬롯 수가 최대입니다." << endl << endl;
			system("PAUSE");
			break;
		default:
			cout << "잘못된 입력입니다. 다시 선택하세요." << endl;
			system("PAUSE");
			break;

		}
	}

}

void StoreManager::ShowStoreList() const {
	for (int i = 1; i <= iMaxSlots; i++) {
		cout << i << "번 슬롯" << endl;
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
	
	cout << "아이템 채우기에 실패했습니다." << endl;
	system("PAUSE");

	return;
}
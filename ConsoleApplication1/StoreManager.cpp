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

		if (StoreManager::isAllSlotsEmpty()) {  // 진입 시 모든 슬롯이 비어있으면 모든 슬롯 채우기
			for (int i = 0; i < iMaxSlots; i++) {
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
		cout << "4. 돌아가기" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "선택하세요. : " << endl;

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

				cout << "몇 번 슬롯의 아이템을 구매할까요?(1 ~ " << iMaxSlots << ", 돌아가기 : 0)" << endl; cin >> iChoice;

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

				}
				else {
					cout << "잘못된 슬롯 선택입니다. 다시 선택해주세요." << endl;
					system("PAUSE");
					continue;
				}
			}

			break;

		case SM_RESET:
			cout << "상점의 목록을 새로고침합니다. ( 골드 : 00G )" << endl;
			//아이템 리셋
			break;

		case SM_UPGRADE:
			cout << "상점 레벨을 업그레이드 합니다. ( 골드 : 00G )" << endl;
			//상점 레벨업
			break;

		default:
			cout << "잘못된 입력입니다. 다시 선택하세요." << endl;
			break;

		}
	}

}

void StoreManager::ShowStoreList() const {
	for (int i = 0; i < iMaxSlots; i++) {
		cout << i+1 << "번 슬롯" << endl;
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
	
	cout << "아이템 채우기에 실패했습니다." << endl;
	system("PAUSE");

	return;
}
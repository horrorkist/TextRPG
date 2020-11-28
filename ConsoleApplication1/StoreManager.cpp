#include "StoreManager.h"
#include "SystemManager.h"
#include "Item.h"

enum SMChoice { SM_ZERO, SM_BUY, SM_RESET, SM_UPGRADE, SM_QUIT };

void StoreManager::StoreMenu() const
{
	while (true)
	{
		int iChoice = 0;

		//플레이어 선택
		system("cls");
		cout << "-------------------------------------------------" << endl;
		cout << "1. 아이템 구매" << endl;
		cout << "2. 상점 새로고침" << endl;
		cout << "3. 상점 업그레이드" << endl;
		cout << "4. 메인메뉴 돌아가기" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "행동을 선택하세요 : " << endl;

		cin >> iChoice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		switch (iChoice) {

		case SM_BUY:

			//랜덤한 아이템
			break;

		case SM_RESET:
			cout << "상점의 목록을 새로고침합니다. ( 골드 : 00G )" << endl;
			//아이템 리셋
			break;

		case SM_UPGRADE:
			cout << "상점 레벨을 업그레이드 합니다. ( 골드 : 00G )" << endl;
			//상점 레벨업
			break;

		case SM_QUIT:
			cout << "메인 메뉴로 돌아갑니다." << endl;
			//ShowMainMenu();
			break;

		default:
			cout << "잘못된 입력입니다. 다시 선택하세요." << endl;
			break;

		}
	}

}
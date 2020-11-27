#include "BattleManager.h"
#include "Monster.h"
#include <cstdlib>
#include <ctime>

extern Character cPlayer;
extern vector<vector<Monster>> BattleFields;

enum ACTChoice {ACT_ZERO, ACT_ATTACK, ACT_ITEM, ACT_RUN };

void BattleManager::Battle(int field) {
	srand((unsigned int)time(NULL));

 //파라미터로 사냥터를 받아오고, 랜덤으로 사냥터에 속하는 몬스터를 정한다.

	//정한 몬스터를 생성한다.

	int index = rand() % BattleFields[field-1].size();

	Monster mEnemy = BattleFields[field-1][index];

	//몬스터나 플레이어 중 하나가 죽을 때 까지

	bool isBattleEnded = false;

	while (true) {

		int iChoice = 0;

		//플레이어 선택
		system("cls");
		
		mEnemy.ShowCharStats();
		cout << endl << endl << endl;
		cPlayer.ShowCharStats();

		if (isBattleEnded) {
			if (mEnemy.iHp == 0) {
				cout << mEnemy.sName << "을(를) 처치했습니다! " << mEnemy.iGold << "G 획득, 경험치 " << mEnemy.iExp << " 획득." << endl;
				cPlayer.iGold += mEnemy.iGold;
				cPlayer.iExp += mEnemy.iExp;
				if (cPlayer.iRqExp <= cPlayer.iExp) {	//레벨업 하는 경우
					cPlayer.iExp -= cPlayer.iRqExp;
					cPlayer.iLevel++;
					cPlayer.iRqExp *= 1.05;
					cPlayer.iMaxHp += 50;	cPlayer.iHp = cPlayer.iMaxHp;
					cPlayer.iMinAtt += 2;	cPlayer.iMaxAtt += 5;
					cPlayer.iMaxMp += 30;	cPlayer.iMp = cPlayer.iMaxMp;
					cout << "레벨이 올랐습니다!" << endl;
				}
			}
			else {
				cout << "당신은 죽었습니다... (소지금 -50%)" << endl;
				cPlayer.iGold /= 2;
				cPlayer.iHp = cPlayer.iMaxHp / 2;
			}
			/*while (true) {
				char cTemp;
				cout << "아무 키나 눌러 계속하세요." << endl;
				cin >> cTemp;
				cin.ignore();
				return;
			}*/
			system("PAUSE");
			return;
		}

		cout << endl << "1. 공격  2. 아이템  3. 도망친다." << endl;
		cout << "행동을 선택하세요 : ";

		cin >> iChoice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		switch (iChoice) {
		case ACT_ATTACK: {

			int iDealt = (cPlayer.iMinAtt + (rand() % (cPlayer.iMaxAtt - cPlayer.iMinAtt))) - mEnemy.iDef;
			int iHurt = (mEnemy.iMinAtt + (rand() % (mEnemy.iMaxAtt - mEnemy.iMinAtt))) - cPlayer.iDef;

			mEnemy.iHp -= iDealt;
			//cout << mEnemy.sName << "에게 대미지를 " << iDealt << " 가했습니다!" << endl;
			if (mEnemy.iHp <= 0) {
				mEnemy.iHp = 0;
				isBattleEnded = true;
				break;
			}
			cPlayer.iHp -= iHurt;
			//cout << mEnemy.sName << "가 대미지를 " << iHurt << " 가했습니다!" << endl;
			if (cPlayer.iHp <= 0) {
				cPlayer.iHp = 0;
				isBattleEnded = true;
				break;
			}
			break;

		}
		case ACT_RUN:
			return;
		default:
			continue;
		}

		//몬스터 공격

	}
	//{ 플레이어 선택 -> 몬스터 공격 -> 몬스터 Afterattack() } 반복.
	//
	//플레이어가 죽었다면: 패널티 부여 후 반환
	//몬스터가 죽었다면: 
}

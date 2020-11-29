#include "BattleManager.h"
#include "MonsterDB.h"
#include "Monster.h"
#include "ItemDB.h"
#include <cstdlib>
#include <ctime>

extern Character cPlayer;
extern MonsterDB monsterDB;
extern ItemDB itemDB;

enum ACTChoice {ACT_ZERO, ACT_ATTACK, ACT_ITEM, ACT_RUN };

void BattleManager::ShowBattleMenu() {

	int iChoice;

	while (true) {
		system("cls");
		cout << "************************ 사냥터를 선택하세요. ************************" << endl;
		cout << "1. 뒷산" << endl;
		cout << "2. 들판" << endl;
		cout << "3. 깊은 숲" << endl;
		cout << "4. 오닉시아의 둥지" << endl;
		cout << "5. 돌아가기" << endl;
		cout << "************************************************" << endl;
		cout << "선택하세요. : ";

		cin >> iChoice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iChoice == 5) break;

		if (iChoice < 1 || iChoice > 5) continue;

		BattleManager::Battle(iChoice);

	}
}

void BattleManager::Battle(int field) {

	string dealt = "";
	string hit = "";

	srand((unsigned int)time(NULL));

 //파라미터로 사냥터를 받아오고, 랜덤으로 사냥터에 속하는 몬스터를 정한다.

	//정한 몬스터를 생성한다.

	int index = rand() % monsterDB.BattleFields2D[field-1].size();

	Monster mEnemy = monsterDB.BattleFields2D[field-1][index];

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
				while (cPlayer.iRqExp <= cPlayer.iExp) {
					cPlayer.iExp -= cPlayer.iRqExp;
					cPlayer.iLevel++;
					cPlayer.iRqExp *= 1.05;
					cPlayer.iMaxHp += 50;	cPlayer.iHp = cPlayer.iMaxHp;
					cPlayer.iMinAtt += 2;	cPlayer.iMaxAtt += 5;
					cPlayer.iMaxMp += 30;	cPlayer.iMp = cPlayer.iMaxMp;
					cout << "레벨이 올랐습니다!" << endl;
				}
				int iDice = (rand() % 100) + 1;
				if (iDice <= mEnemy.iDropChance) {
					iDice = (rand() % 100) + 1;
					int iDropItemTier, iChanceBar = 0;
					for (int i = 1; i <= 5; i++) {
						iChanceBar += mEnemy.vDropChance2D[mEnemy.iMonsterRank][i];
						if (iDice <= iChanceBar) {
							iDropItemTier = i;
							break;
						}
					}
					iDice = rand() % mEnemy.vDropTableCode2D[iDropItemTier].size();

					hash_map<int, Item>::iterator FindIter = itemDB.Item_Hash.find(mEnemy.vDropTableCode2D[iDropItemTier][iDice]);

					Item itemDropItem = FindIter->second;

					cout << "떨어진 아이템이 있습니다! 확인하시겠습니까?(y/n)" << endl;

					bool bCheckDropItem = false;

					while (true) {
						if (bCheckDropItem) break;

						char cConfirm;

						cin >> cConfirm;

						if (cin.fail()) {
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						if (cConfirm == 'y') {
							system("cls");
							itemDropItem.ShowItemInfo();
							cout << endl;
							cout << "이 아이템을 착용할까요? 착용 중인 아이템은 버려집니다.(y/n)";
							while (true) {
								char cConfirm;

								cin >> cConfirm;

								if (cin.fail()) {
									cin.clear();
									cin.ignore(1024, '\n');
									continue;
								}

								if (cConfirm == 'y') {
									bCheckDropItem = true;
									itemDropItem.Equip(cPlayer);
									cout << "『" << itemDropItem.GetItemName() << "』을(를) 착용했습니다." << endl;
									break;
								}
								if (cConfirm == 'n') {
									bCheckDropItem = true;
									break;
								}
							}
						}
						if (cConfirm == 'n') break;
					}
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

		cout << dealt;
		cout << hit;
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

			int iDealt = (cPlayer.iMinAtt + (rand() % (cPlayer.iMaxAtt - cPlayer.iMinAtt))) - mEnemy.iDef; if (iDealt < 0) iDealt = 0;
			int iHurt = (mEnemy.iMinAtt + (rand() % (mEnemy.iMaxAtt - mEnemy.iMinAtt))) - cPlayer.iDef; if (iHurt < 0) iHurt = 0;

			mEnemy.iHp -= iDealt;
			dealt = mEnemy.sName + "에게 데미지를 " + to_string(iDealt) + " 가했습니다!\n";
			if (mEnemy.iHp <= 0) {
				mEnemy.iHp = 0;
				isBattleEnded = true;
				break;
			}
			cPlayer.iHp -= iHurt;
			hit = mEnemy.sName + "에게서 데미지를 " + to_string(iHurt) + " 받았습니다!\n";
			//cout << mEnemy.sName << "가 대미지를 " << iHurt << " 가했습니다!" << endl;
			if (cPlayer.iHp <= 0) {
				cPlayer.iHp = 0;
				isBattleEnded = true;
				break;
			}
			break;
		}
		case ACT_ITEM:
			break;
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

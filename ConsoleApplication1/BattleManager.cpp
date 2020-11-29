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
		cout << "************************ ����͸� �����ϼ���. ************************" << endl;
		cout << "1. �޻�" << endl;
		cout << "2. ����" << endl;
		cout << "3. ���� ��" << endl;
		cout << "4. ���нþ��� ����" << endl;
		cout << "5. ���ư���" << endl;
		cout << "************************************************" << endl;
		cout << "�����ϼ���. : ";

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

 //�Ķ���ͷ� ����͸� �޾ƿ���, �������� ����Ϳ� ���ϴ� ���͸� ���Ѵ�.

	//���� ���͸� �����Ѵ�.

	int index = rand() % monsterDB.BattleFields2D[field-1].size();

	Monster mEnemy = monsterDB.BattleFields2D[field-1][index];

	//���ͳ� �÷��̾� �� �ϳ��� ���� �� ����

	bool isBattleEnded = false;

	while (true) {

		int iChoice = 0;

		//�÷��̾� ����
		system("cls");
		
		mEnemy.ShowCharStats();
		cout << endl << endl << endl;
		cPlayer.ShowCharStats();

		if (isBattleEnded) {
			if (mEnemy.iHp == 0) {
				cout << mEnemy.sName << "��(��) óġ�߽��ϴ�! " << mEnemy.iGold << "G ȹ��, ����ġ " << mEnemy.iExp << " ȹ��." << endl;
				cPlayer.iGold += mEnemy.iGold;
				cPlayer.iExp += mEnemy.iExp;
				while (cPlayer.iRqExp <= cPlayer.iExp) {
					cPlayer.iExp -= cPlayer.iRqExp;
					cPlayer.iLevel++;
					cPlayer.iRqExp *= 1.05;
					cPlayer.iMaxHp += 50;	cPlayer.iHp = cPlayer.iMaxHp;
					cPlayer.iMinAtt += 2;	cPlayer.iMaxAtt += 5;
					cPlayer.iMaxMp += 30;	cPlayer.iMp = cPlayer.iMaxMp;
					cout << "������ �ö����ϴ�!" << endl;
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

					cout << "������ �������� �ֽ��ϴ�! Ȯ���Ͻðڽ��ϱ�?(y/n)" << endl;

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
							cout << "�� �������� �����ұ��? ���� ���� �������� �������ϴ�.(y/n)";
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
									cout << "��" << itemDropItem.GetItemName() << "����(��) �����߽��ϴ�." << endl;
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
				cout << "����� �׾����ϴ�... (������ -50%)" << endl;
				cPlayer.iGold /= 2;
				cPlayer.iHp = cPlayer.iMaxHp / 2;
			}
			/*while (true) {
				char cTemp;
				cout << "�ƹ� Ű�� ���� ����ϼ���." << endl;
				cin >> cTemp;
				cin.ignore();
				return;
			}*/
			system("PAUSE");
			return;
		}

		cout << dealt;
		cout << hit;
		cout << endl << "1. ����  2. ������  3. ����ģ��." << endl;
		cout << "�ൿ�� �����ϼ��� : ";

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
			dealt = mEnemy.sName + "���� �������� " + to_string(iDealt) + " ���߽��ϴ�!\n";
			if (mEnemy.iHp <= 0) {
				mEnemy.iHp = 0;
				isBattleEnded = true;
				break;
			}
			cPlayer.iHp -= iHurt;
			hit = mEnemy.sName + "���Լ� �������� " + to_string(iHurt) + " �޾ҽ��ϴ�!\n";
			//cout << mEnemy.sName << "�� ������� " << iHurt << " ���߽��ϴ�!" << endl;
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

		//���� ����

	}
	//{ �÷��̾� ���� -> ���� ���� -> ���� Afterattack() } �ݺ�.
	//
	//�÷��̾ �׾��ٸ�: �г�Ƽ �ο� �� ��ȯ
	//���Ͱ� �׾��ٸ�: 
}

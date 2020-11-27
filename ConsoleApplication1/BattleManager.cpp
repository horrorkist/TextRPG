#include "BattleManager.h"
#include "Monster.h"
#include <cstdlib>
#include <ctime>

extern Character cPlayer;
extern vector<vector<Monster>> BattleFields;

enum ACTChoice {ACT_ZERO, ACT_ATTACK, ACT_ITEM, ACT_RUN };

void BattleManager::Battle(int field) {
	srand((unsigned int)time(NULL));

 //�Ķ���ͷ� ����͸� �޾ƿ���, �������� ����Ϳ� ���ϴ� ���͸� ���Ѵ�.

	//���� ���͸� �����Ѵ�.

	int index = rand() % BattleFields[field-1].size();

	Monster mEnemy = BattleFields[field-1][index];

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
				if (cPlayer.iRqExp <= cPlayer.iExp) {	//������ �ϴ� ���
					cPlayer.iExp -= cPlayer.iRqExp;
					cPlayer.iLevel++;
					cPlayer.iRqExp *= 1.05;
					cPlayer.iMaxHp += 50;	cPlayer.iHp = cPlayer.iMaxHp;
					cPlayer.iMinAtt += 2;	cPlayer.iMaxAtt += 5;
					cPlayer.iMaxMp += 30;	cPlayer.iMp = cPlayer.iMaxMp;
					cout << "������ �ö����ϴ�!" << endl;
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

			int iDealt = (cPlayer.iMinAtt + (rand() % (cPlayer.iMaxAtt - cPlayer.iMinAtt))) - mEnemy.iDef;
			int iHurt = (mEnemy.iMinAtt + (rand() % (mEnemy.iMaxAtt - mEnemy.iMinAtt))) - cPlayer.iDef;

			mEnemy.iHp -= iDealt;
			//cout << mEnemy.sName << "���� ������� " << iDealt << " ���߽��ϴ�!" << endl;
			if (mEnemy.iHp <= 0) {
				mEnemy.iHp = 0;
				isBattleEnded = true;
				break;
			}
			cPlayer.iHp -= iHurt;
			//cout << mEnemy.sName << "�� ������� " << iHurt << " ���߽��ϴ�!" << endl;
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

		//���� ����

	}
	//{ �÷��̾� ���� -> ���� ���� -> ���� Afterattack() } �ݺ�.
	//
	//�÷��̾ �׾��ٸ�: �г�Ƽ �ο� �� ��ȯ
	//���Ͱ� �׾��ٸ�: 
}

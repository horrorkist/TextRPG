#include "BattleManager.h"
#include "Monster.h"

extern Character cPlayer;

enum ACTChoice {ACT_ZERO, ACT_ATTACK, ACT_POTION, ACT_RUN };

void BattleManager::Battle(int field) {
 //�Ķ���ͷ� ����͸� �޾ƿ���, �������� ����Ϳ� ���ϴ� ���͸� ���Ѵ�.

	//���� ���͸� �����Ѵ�.

	//Monster enemy = BF[field][index];

	//���ͳ� �÷��̾� �� �ϳ��� ���� �� ����

	while (!cPlayer.isDead && !enemy.isDead) {
		
		int iChoice = 0;

		//�÷��̾� ����
		system("cls");
		cout << "-------------------------------------------------" << endl;
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. ����" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "�ൿ�� �����ϼ��� : " << endl;

		cin >> iChoice;
		switch (iChoice) {
		case ACT_ATTACK:
			int Attack = rand() % (cPlayer.iMaxAtt - cPlayer.iMinAtt) + (cPlayer.iMinAtt + 1);
			int dmg = Attack - enemy.iDef;
			break;
		case ACT_POTION:
			break;
		case ACT_RUN:
			break;
		default:
			break;
		}
		

		//���� ����

	}
	//{ �÷��̾� ���� -> ���� ���� -> ���� Afterattack() } �ݺ�.
	//
	//�÷��̾ �׾��ٸ�: �г�Ƽ �ο� �� ��ȯ
	//���Ͱ� �׾��ٸ�: 
}

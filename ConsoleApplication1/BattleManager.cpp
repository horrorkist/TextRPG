#include "BattleManager.h"
#include "Monster.h"

extern Character cPlayer;

enum ACTChoice {ACT_ZERO, ACT_ATTACK, ACT_POTION, ACT_RUN };

void BattleManager::Battle(int field) {
 //파라미터로 사냥터를 받아오고, 랜덤으로 사냥터에 속하는 몬스터를 정한다.

	//정한 몬스터를 생성한다.

	//Monster enemy = BF[field][index];

	//몬스터나 플레이어 중 하나가 죽을 때 까지

	while (!cPlayer.isDead && !enemy.isDead) {
		
		int iChoice = 0;

		//플레이어 선택
		system("cls");
		cout << "-------------------------------------------------" << endl;
		cout << "1. 공격" << endl;
		cout << "2. 물약" << endl;
		cout << "3. 도망" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "행동을 선택하세요 : " << endl;

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
		

		//몬스터 공격

	}
	//{ 플레이어 선택 -> 몬스터 공격 -> 몬스터 Afterattack() } 반복.
	//
	//플레이어가 죽었다면: 패널티 부여 후 반환
	//몬스터가 죽었다면: 
}

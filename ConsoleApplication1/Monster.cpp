#include "Monster.h"
//���� üũ
//���� üũ 2
//Babamvirus �ּ� �� �� �߰�
//Babamvirus �ּ� �� �� �߰�
//Babamvirus �ּ� �� �� �߰�
void Monster::ShowCharStats() const {
	cout << "---------------------------------" << endl;
	cout << "��� : " << this->sName << endl;
	cout << "HP : " << this->iHp << " / " << this->iMaxHp << endl;
	cout << "���ݷ� : " << this->iMinAtt << " - " << this->iMaxAtt << endl;
	cout << "���� : " << this->iDef << endl;
	cout << "---------------------------------" << endl;
}
Monster::Monster(string strName, int maxAtt, int minAtt, int def, int gold, int exp, int maxHp, int hp) {
	this->sName = strName;
	this->iMaxAtt = maxAtt;
	this->iMinAtt = minAtt;
	this->iDef = def;
	this->iGold = gold;
	this->iExp = exp;
	this->iMaxHp = maxHp;
	this->iHp = hp;
}

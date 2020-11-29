#include "Monster.h"
//주석 추가


void Monster::ShowCharStats() const {
	cout << "---------------------------------" << endl;
	cout << "상대 : " << this->sName << endl;
	cout << "HP : " << this->iHp << " / " << this->iMaxHp << endl;
	cout << "공격력 : " << this->iMinAtt << " - " << this->iMaxAtt << endl;
	cout << "방어력 : " << this->iDef << endl;
	cout << "---------------------------------" << endl;
}
Monster::Monster(string strName, int maxAtt, int minAtt, int def, int gold, int exp, int maxHp, int rank) {
	this->sName = strName;
	this->iMaxAtt = maxAtt;
	this->iMinAtt = minAtt;
	this->iDef = def;
	this->iGold = gold;
	this->iExp = exp;
	this->iMaxHp = maxHp;
	this->iHp = maxHp;
	this->iMonsterRank = rank;
}
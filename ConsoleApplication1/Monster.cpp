#include "Monster.h"
//병합 체크
//병합 체크 2
//Babamvirus 주석 초기화
void Monster::ShowCharStats() const {
	cout << "---------------------------------" << endl;
	cout << "상대 : " << this->sName << endl;
	cout << "HP : " << this->iHp << " / " << this->iMaxHp << endl;
	cout << "공격력 : " << this->iMinAtt << " - " << this->iMaxAtt << endl;
	cout << "방어력 : " << this->iDef << endl;
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
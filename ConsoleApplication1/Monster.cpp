#include "Monster.h"

void Monster::ShowCharStats() const {
	cout << "---------------------------------" << endl;
	cout << "이름 : " << this->sName << endl;
	cout << "HP : " << this->iHp << " / " << this->iMaxHp << endl;
	cout << "공격력 : " << this->iMinAtt << " - " << this->iMaxAtt << endl;
	cout << "방어력 : " << this->iDef << endl;
	cout << "---------------------------------" << endl;
}
#include "Monster.h"

void Monster::ShowCharStats() const {
	cout << "---------------------------------" << endl;
	cout << "�̸� : " << this->sName << endl;
	cout << "HP : " << this->iHp << " / " << this->iMaxHp << endl;
	cout << "���ݷ� : " << this->iMinAtt << " - " << this->iMaxAtt << endl;
	cout << "���� : " << this->iDef << endl;
	cout << "---------------------------------" << endl;
}
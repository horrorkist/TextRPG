#include "Character.h"

void Character::CreateNewChar() {

	string sTempName;

	while (true) {
		system("cls");
		cout << "ĳ������ �̸��� �Է����ּ���. : ";

		cin >> sTempName;

		if (sTempName.length() < 2 || sTempName.length() > 10) {
			cout << "�̸��� �ʹ� ª�ų� ��ϴ�. 2�ڿ��� 10�� �̳��� �Է����ּ���." << endl;
		}
		else {
			cout << "ĳ������ �̸��� " << sTempName << " ���� ���Ͻðڽ��ϱ�?(y/n)" << endl;
			char cConfirm = 0;
			cin >> cConfirm;
			switch (cConfirm) {
			case 'y': {
				this->iMaxHp = 500;
				this->sName = sTempName;
				this->iHp = 500;
				this->iMaxMp = 100;
				this->iMp = 100;
				this->iLevel = 1;
				this->iRqExp = 100;
				this->iExp = 0;
				this->iGold = 0;
				this->iMaxAtt = 20;
				this->iMinAtt = 5;
				this->iStr = 5;
				this->iDex = 5;
				this->iInt = 5;
				this->iDef = 0;
				this->iDodge = 0;
				cout << "ĳ���� ������ �Ϸ�Ǿ����ϴ�." << endl;
				return;
			}
				break;
			case 'n':
				break;
			default:
				break;
			}
		}
	}
}

void Character::ShowCharStats() const {
	cout << "---------------------------------" << endl;
	cout << "�̸� : " << this->sName << endl;
	cout << "HP : " << this->iHp << " / " << this->iMaxHp << endl;
	cout << "MP : " << this->iMp << " / " << this->iMaxMp << endl;
	cout << "���ݷ� : " << this->iMinAtt << " - " << this->iMaxAtt << endl;
	cout << "���� : " << this->iDef << endl;
	cout << "����ġ : " << this->iExp << " / " << this->iRqExp << endl;
	cout << "������ : " << this->iGold << "G" << endl;
	cout << "�� : " << this->iStr << endl << "��ø : " << this->iDex << endl << "���� : " << this->iInt << endl;
	cout << "---------------------------------" << endl;
	cout << "1. ���â ����" << endl << "2. ���ư���" << endl;

	int iChoice = 0;

	while (iChoice != 1 && iChoice != 2) {
		cout << endl << "�����ϼ��� : "; cin >> iChoice;
	}

	//if (iChoice == 1) /*Character::ShowEquipment()*/;

	return;
}
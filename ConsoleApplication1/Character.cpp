#include "Character.h"
#include <sstream>

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
	cout << "���� : " << this->iLevel << endl;
	cout << "HP : " << this->iHp << " / " << this->iMaxHp << endl;
	cout << "MP : " << this->iMp << " / " << this->iMaxMp << endl;
	cout << "���ݷ� : " << this->iMinAtt << " - " << this->iMaxAtt << endl;
	cout << "���� : " << this->iDef << endl;
	cout << "����ġ : " << this->iExp << " / " << this->iRqExp << endl;
	cout << "������ : " << this->iGold << "G" << endl;
	cout << "�� : " << this->iStr << endl << "��ø : " << this->iDex << endl << "���� : " << this->iInt << endl;
	cout << "---------------------------------" << endl;
	return;
}

void Character::SetUsingData(string str) {
	istringstream ss(str);
	vector<string> data;
	data.clear();
	while (getline(ss, str, ' ')) {
		data.push_back(str);
	}
	this->sName = data[0];
	this->iMaxHp = stoi(data[1]);
	this->iHp = stoi(data[2]);
	this->iMaxAtt = stoi(data[3]);
	this->iMinAtt = stoi(data[4]);
	this->iDef = stoi(data[5]);
	this->iGold = stoi(data[6]);
	this->iExp = stoi(data[7]);
	this->iMaxMp = stoi(data[8]);
	this->iMp = stoi(data[9]);
	this->iLevel = stoi(data[10]);
	this->iRqExp = stoi(data[11]);
	this->iDodge = stoi(data[12]);
	this->iStr = stoi(data[13]);
	this->iDex = stoi(data[14]);
	this->iInt = stoi(data[15]);
}

string Character::GetDataString() {
	string data;
	data.append(this->sName); data.append(" ");
	data.append(to_string(this->iMaxHp)); data.append(" ");
	data.append(to_string(this->iHp)); data.append(" ");
	data.append(to_string(this->iMaxAtt)); data.append(" ");
	data.append(to_string(this->iMinAtt)); data.append(" ");
	data.append(to_string(this->iDef)); data.append(" ");
	data.append(to_string(this->iGold)); data.append(" ");
	data.append(to_string(this->iExp)); data.append(" ");
	data.append(to_string(this->iMaxMp)); data.append(" ");
	data.append(to_string(this->iMp)); data.append(" ");
	data.append(to_string(this->iLevel)); data.append(" ");
	data.append(to_string(this->iRqExp)); data.append(" ");
	data.append(to_string(this->iDodge)); data.append(" ");
	data.append(to_string(this->iStr)); data.append(" ");
	data.append(to_string(this->iDex)); data.append(" ");
	data.append(to_string(this->iInt));
	return data;
}

Character NPC;

#pragma once
#include <string>
#include <iostream>

using namespace std;

class Character
{
public:

	string	sName;
	int		iMaxHp;
	int		iHp;
	int		iMaxAtt;
	int		iMinAtt;
	int		iDef;

private:

	int		iMaxMp;
	int		iMp;
	int		iGold;
	int		iExp;
	int		iLevel;
	int		iRqExp;
	int		iDodge;
	int		iStr;
	int		iDex;
	int		iInt;

public:
	void CreateNewChar();
	void ShowCharStats() const;

	friend class SystemManager;
};


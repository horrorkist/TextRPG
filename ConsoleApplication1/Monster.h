#pragma once
#include "Character.h"

class Monster : public Character
{
private:
	string strRace;
public:
	Monster(string , int , int , int , int , int, int);
	void ShowCharStats() const;
};

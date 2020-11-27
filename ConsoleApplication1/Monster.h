#pragma once
#include "Character.h"

class Monster : public Character
{
private:
	string strRace;
public:
	void ShowCharStats() const;
};


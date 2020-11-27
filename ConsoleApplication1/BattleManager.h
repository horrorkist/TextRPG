#pragma once
#include <iostream>
#include <vector>
#include <string.h>



using namespace std;

class BattleManager
{
private:
	vector<string> sBattleField = { "µﬁªÍ", "µÈ∆«", "Ω£" };

public:
	void ShowBattleFields() const;
	void Battle(int field);
};


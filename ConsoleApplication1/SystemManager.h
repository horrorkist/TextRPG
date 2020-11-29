#pragma once
#include <iostream>
#include <fstream>
#include "Character.h"
//#include "Character.h"

using namespace std;

class SystemManager
{
private:

	//Character Player;
	

public:

	void Heal();

	void ShowMainMenu();

	void ShowMyInfo() const;

	bool QuitGame() const;
};


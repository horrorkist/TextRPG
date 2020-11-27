#include "SystemManager.h"
#include "Character.h"
#include <iostream>

using namespace std;

SystemManager Manager;
Character cPlayer;

int main()
{
	cout << "Hello wordls";
	cPlayer.CreateNewChar();
	Manager.ShowMainMenu();

	return 0;
}



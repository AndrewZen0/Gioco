#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <fstream>
#include <string>
#include"Game_Logic.cpp"
using namespace std;

int main()
{
	int intro_scelta;

	intro_scelta = Game_Intro();

	if (intro_scelta == 2)
	{
		std::ifstream MyplayerData("PlayerData.dat");
		if (MyplayerData.is_open())
		{
			std::string line;
			while (std::getline(MyplayerData, line))
			{
				MyplayerData >> Player.VitaAtt;
				MyplayerData >> Player.VitaMax;

				MyplayerData >> Player.Forza;
				MyplayerData >> Player.Destrezza;
				MyplayerData >> Player.Intelligenza;
				MyplayerData >> Player.Fortuna;

				MyplayerData >> Player.Monete;

				MyplayerData >> Player.Inventario[0];
				MyplayerData >> Player.Inventario[1];
				MyplayerData >> Player.Inventario[2];
			}
			MyplayerData.close();
		}
	}
	Castle();
}






#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <fstream>
using namespace std;

class Giocatore
{
public:
	int VitaAtt = 100;
	int VitaMax = 100;

	int Forza = 10;
	int Destrezza = 10;
	int Intelligenza = 10;
	int Fortuna = 10;

	int Monete = 100;

	int Inventario[3] = { 0,0,0 };
};

Giocatore Player;
char decisione[50];
int scelta;

void Chiusura_gioco()//chiusura gioco
{
	exit(0);
}

void Save_Game()//salvataggio del gioco
{
	ofstream playerData("PlayerData.dat");

	playerData << Player.VitaAtt << endl;
	playerData << Player.VitaMax << endl;

	playerData << Player.Forza << endl;
	playerData << Player.Destrezza << endl;
	playerData << Player.Intelligenza << endl;
	playerData << Player.Fortuna << endl;

	playerData << Player.Monete << endl;

	playerData << Player.Inventario[0] << endl;
	playerData << Player.Inventario[1] << endl;
	playerData << Player.Inventario[2] << endl;

	playerData.close();

	cout << "\nPartita salvata\n";
}

int Game_Intro()//intro del gioco
{

	system("cls");
	cout << "\nBenvenuto in Holgar.\nIn questa avventura prenderai i panni di un demone, che dopo essere resuscitato dopo una enorme guerra territoriale tra le varie forze del male, ha deciso di prendere in possesso del castello di suo padre e cercare fortuna per se stesso\n";

	cout << "\n1--New Game\n2--Load Game\n";
	cout << endl;
	cin >> scelta;
	system("cls");

	switch (scelta)
	{
	case 1:
	{
		return(1);
	}break;

	case  2:
	{
		return(2);
	}break;
	}
}

bool Limite_Movimento(int PlayerX, int PlayerY, char *spostamento)//test se il giocatore uscira' o meno dalla mappa
{
	if (strcmp(spostamento, "w") == 0)
	{
		if ((PlayerX - 1) >= 0)
		{
			return(true);
		}
		else
		{
			return(false);
		}
	}
	else
	{
		if (strcmp(spostamento, "s") == 0)
		{
			if ((PlayerX + 1) <= 9)
			{
				return(true);
			}
			else
			{
				return(false);
			}
		}
		else
		{
			if (strcmp(spostamento, "a") == 0)
			{
				if ((PlayerY - 1) >= 0)
				{
					return(true);
				}
				else
				{
					return(false);
				}
			}
			else
			{
				if (strcmp(spostamento, "d") == 0)
				{
					if ((PlayerY + 1) <= 9)
					{
						return(true);
					}
					else
					{
						return(false);
					}
				}
			}
		}
	}
}

void Movimento(int &PlayerX, int &PlayerY, int Map[][50], int &MaxPlayer, int &MaxEnemis)//movimento del personaggio
{
	char spostamento;
	bool is_valid;

	cin >> spostamento;

	is_valid = Limite_Movimento(PlayerX, PlayerY,&spostamento);

	if (is_valid == true && spostamento == 'w')
	{
		if (Map[PlayerX - 1][PlayerY] == 2)
		{
			MaxEnemis = MaxEnemis - 1;
			Map[PlayerX][PlayerY] = 0;
			Map[PlayerX - 1][PlayerY] = 3;
			PlayerX = PlayerX - 1;
			Player.VitaAtt = Player.VitaAtt - 10;
			Player.Monete = Player.Monete + 10;
		}
		if (Map[PlayerX - 1][PlayerY] == 1)
		{
			
		}
		else
		{
			Map[PlayerX][PlayerY] = 0;
			Map[PlayerX - 1][PlayerY] = 3;
			PlayerX = PlayerX - 1;
		}
	}
	else
	{
		if (is_valid == true && spostamento == 's')
		{
			if (Map[PlayerX + 1][PlayerY] == 2)
			{
				MaxEnemis = MaxEnemis - 1;
				Map[PlayerX][PlayerY] = 0;
				Map[PlayerX + 1][PlayerY] = 3;
				PlayerX = PlayerX + 1;
				Player.VitaAtt = Player.VitaAtt - 10;
				Player.Monete = Player.Monete + 10;
			}
			if (Map[PlayerX + 1][PlayerY] == 1)
			{
				
			}
			else
			{
				Map[PlayerX][PlayerY] = 0;
				Map[PlayerX + 1][PlayerY] = 3;
				PlayerX = PlayerX + 1;
			}
		}
		else
		{
			if (is_valid == true && spostamento == 'a')
			{
				if (Map[PlayerX][PlayerY - 1] == 2)
				{
					MaxEnemis = MaxEnemis - 1;
					Map[PlayerX][PlayerY] = 0;
					Map[PlayerX][PlayerY - 1] = 3;
					PlayerY = PlayerY - 1;
					Player.VitaAtt = Player.VitaAtt - 10;
					Player.Monete = Player.Monete + 10;
				}
				if (Map[PlayerX][PlayerY - 1] == 1)
				{
					
				}
				else
				{
					Map[PlayerX][PlayerY] = 0;
					Map[PlayerX][PlayerY - 1] = 3;
					PlayerY = PlayerY - 1;
				}
			}
			else
			{
				if (is_valid == true && spostamento == 'd')
				{
					if (Map[PlayerX - 1][PlayerY + 1] == 2)
					{
						MaxEnemis = MaxEnemis - 1;
						Map[PlayerX][PlayerY] = 0;
						Map[PlayerX][PlayerY + 1] = 3;
						PlayerY = PlayerY + 1;
						Player.VitaAtt = Player.VitaAtt - 10;
						Player.Monete = Player.Monete + 10;
					}
					if (Map[PlayerX - 1][PlayerY + 1] == 1)
					{
						
					}
					else
					{
						Map[PlayerX][PlayerY] = 0;
						Map[PlayerX][PlayerY + 1] = 3;
						PlayerY = PlayerY + 1;
					}
				}
			}
		}
	}
	if (Player.VitaAtt <= 0)
	{
		MaxPlayer = MaxPlayer - 1;
	}
	cout << endl << Player.VitaAtt << "/" << Player.VitaMax << endl;
}

void Dungeon()//interazioni nel dungeon
{
	cout << "\nTi ritrovi nella parte piu' bassa del tuo castello, dove e' presente una porta che blocca l'accesso ad un dungeon pieno di ricchezze ancora da ottenere ma allo stesso momento anche grandi avversita'\n";
	cout << endl;
	cin >> decisione;

	if (strcmp(decisione, "entra") == 0)//inizio creazione dungeon
	{
		int MaxROW = 10;
		int MaxCOL = 10;
		int MaxPlayer = 0;
		int MaxEnemies = 0;
		int Map[50][50];
		int temp;
		int Block_Save = 0;
		int PlayerX;
		int PlayerY;

		srand(time(0));
		for (int i = 0; i < MaxROW; i++)
		{
			for (int j = 0; j < MaxCOL; j++)
			{
				temp = rand() % 4;

				if (temp == 1)
				{
					if (Block_Save < 10)
					{
						Map[i][j] = 1;
						Block_Save++;
					}
					else
					{
						Map[i][j] = 0;
					}
				}
				else
				{
					if (temp == 2)
					{
						if (MaxEnemies < 5)
						{
							Map[i][j] = 2;
							MaxEnemies++;
						}
						else
						{
							Map[i][j] = 0;
						}
					}
					else
					{
						if (temp == 3)
						{
							if (MaxPlayer < 1)
							{
								Map[i][j] = 3;
								MaxPlayer++;
							}
							else
							{
								Map[i][j] = 0;
							}
						}
						else
						{
							Map[i][j] = 0;
						}
					}
				}
			}
		}//fine creazione dungeon

		for (int i = 0; i < MaxROW; i++)//troviamo la posizione del giocatore
		{
			for (int j = 0; j < MaxCOL; j++)
			{
				if (Map[i][j] == 3)
				{
					PlayerX = i;
					PlayerY = j;
				}
			}
		}

		do
		{
			for (int i = 0; i < MaxROW; i++)
			{
				for (int j = 0; j < MaxCOL; j++)
				{
					switch (Map[i][j])
					{
					case 0:
					{
						cout << ". ";
					}break;

					case 1:
					{
						cout << "# ";
					}break;

					case 2:
					{
						cout << "E ";
					}break;

					case 3:
					{
						cout << "P ";
					}
					}
				}
				cout << endl;
			}
			cout << endl;
			Movimento(PlayerX, PlayerY, Map, MaxPlayer, MaxEnemies);
			cout << endl;
		} while (MaxPlayer > 0 || MaxEnemies > 0);
		if (MaxPlayer <= 0)
		{
			cout << "\nGame Over\n";			
		}
		else
		{
			if (MaxEnemies <= 0)
			{
				cout << "\nDungeon completato\n";
				Save_Game();
			}
		}
	}
	else
	{
		if (strcmp(decisione, "salva") == 0)
		{
			Save_Game();
		}
		else
		{
			if (strcmp(decisione, "pozione") == 0)
			{
				if (Player.Inventario[2] > 0)
				{
					Player.VitaAtt = Player.VitaAtt + 50;
					Player.Inventario[2] = Player.Inventario[2] - 1;
				}
			}
		}
	}
}

void NPC_Area()//interazione con npc del secondo piano
{

	do
	{
		cout << "\nTi trovi in una stanza in cui si ritrovano tutti i tuoi consiglieri e vari mercanti\n";
		cout << endl;
		cin >> decisione;

		if (strcmp(decisione, "mercante") == 0)//inizio interazione mercante
		{
			cout << "\nBenvenuto nel mio umile negozio, come la posso aiutare padrone\n";
			cout << endl;
			cin >> decisione;

			do
			{
				if (strcmp(decisione, "compra") == 0)
				{

					cout << "\nPreogo osservi\n1--Spada di ferro\n2--Scudo di cuoio\n3--Pozione curativa\n";
					cout << endl;
					cin >> scelta;
					switch (scelta)
					{
						case 1:
						{
							if (Player.Monete >= 100)
							{
								Player.Inventario[0] = Player.Inventario[0] + 1;
								Player.Monete = Player.Monete - 100;
								cout << "\nhai comprato una spada\n";
							}
							else
							{
								cout << "\nnon hai abbastanza denaro\n";
							}
						}break;

						case 2:
						{
							if (Player.Monete >= 50)
							{
								Player.Inventario[1] = Player.Inventario[1] + 1;
								Player.Monete = Player.Monete - 50;
								cout << "\nhai comprato uno scudo\n";
							}
							else
							{
								cout << "\nnon hai abbastanza denaro\n";
							}
						}break;

						case 3:
						{
							if (Player.Monete >= 10)
							{
								Player.Inventario[2] = Player.Inventario[2] + 1;
								Player.Monete = Player.Monete - 10;
								cout << "\nhai comprato una pozione\n";
							}
							else
							{
								cout << "\nnon hai abbastanza denaro\n";
							}
						}break;
					}					
				}
				cout << "\nvuole qualcosa d'altro mio signore\n";
				cin >> decisione;
			} while (strcmp(decisione, "fine") != 0);
		}//fine interazione mercante
		else
		{
			if (strcmp(decisione, "scendi1") == 0)
			{
				Dungeon();
			}
			else
			{
				if (strcmp(decisione, "salva") == 0)
				{
					Save_Game();
				}
				else
				{
					if (strcmp(decisione, "pozione") == 0)
					{
						if (Player.Inventario[2] > 0)
						{
							Player.VitaAtt = Player.VitaAtt + 50;
							Player.Inventario[2] = Player.Inventario[2] - 1;
						}
					}
				}
			}
		}
		cout << endl;
		cin >> decisione;
	} while (strcmp(decisione, "exit") != 0);

	if (strcmp(decisione, "exit") == 0)
	{
		Chiusura_gioco();
	}
}

void Castle()//area di inizio gioco e scelta di dove andare
{
	do
	{
		cout << "\nTi trovi nella sala del trono, il piano piu' alto del castello, il tempo e la mal manutenzione ha effetti evidenti sull'aspetto estetico\n";
		cout << endl;
		cin >> decisione;

		if (strcmp(decisione, "ispeziona") == 0)
		{
			cout << "\nla sala del trono si trova in una situazione deprorevole dopo i vari assedi che ha subito e la mal manutenzione del forte in generale\n";
		}
		else
		{
			if (strcmp(decisione, "scendi1") == 0)
			{
				NPC_Area();
			}
			else
			{
				if (strcmp(decisione, "scendi2") == 0)
				{
					Dungeon();
				}
				else
				{
					if (strcmp(decisione, "salva") == 0)
					{
						Save_Game();
					}
					else
					{
						if (strcmp(decisione, "pozione") == 0)
						{
							if (Player.Inventario[2] > 0)
							{
								Player.VitaAtt = Player.VitaAtt + 50;
								Player.Inventario[2] = Player.Inventario[2] - 1;
							}
						}
					}
				}
			}
		}
	} while (strcmp(decisione, "exit") != 0);

	if (strcmp(decisione, "exit") == 0)
	{
		Chiusura_gioco();
	}
}
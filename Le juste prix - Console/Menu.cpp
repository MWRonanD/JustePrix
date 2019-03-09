#include "pch.h"
#include <array>
#include <iostream>
#include <list>
#include <iterator> 

using namespace std;
#include "Menu.h"
#include "game.h"
#include "Scores.h"

list<Scores> scoresList;

void LunchMsg() {

	cout << "Bonjour"
		<< endl
		<< "Bienvenue au juste prix !!"
		<< endl
		<< endl
		<< "Voulez vous faire une partie ? (" << static_cast<char>(Inputs::Play) << "/" << static_cast<char>(Inputs::Quit) << ") ou voir les scores ? (S)"
		<< endl;
}

void Menu() {
	bool quit = false;
	do
	{
		LunchMsg();
		char choise;
		cin >> choise;
		Inputs converChoise = static_cast<Inputs>(toupper(choise));

		switch (converChoise)
		{
		case Inputs::Play:
			PlayGame(scoresList);
			break;
		case Inputs::Quit:
			cout << "Bye.";
			quit = true;
			break;
		case Inputs::Scores:
			ScoresMenu();
			break;
		default:
			cout << static_cast<char>(Inputs::Play) << " / " << static_cast<char>(Inputs::Quit) << " ??"
				<< endl;
			Menu();
			break;
		}
	} while (!quit);
}

void ScoresMenu() {
	char choise = 'R';
	cout << "Voicis les scores : " << endl << endl;
	list<Scores>::iterator it;
	int count = 1;
	for (it = scoresList.begin(); it != scoresList.end(); ++it)
	{

		cout << count << " : ";
		static_cast<Scores>(*it).ShowMessage();
		count++;
	}
	cout << "R pour retourner au menu" << endl;
	cin >> choise;
	Menu();
}
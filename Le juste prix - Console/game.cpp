#include "pch.h"
#include<list>
#include <random>
#include <iostream>
using namespace std;

#include "Menu.h"
#include "Scores.h"
#include "game.h"


int GetRand(random_device &seed) {
	auto generateur = mt19937{ seed() };
	auto distrib = uniform_int_distribution<int>{ 0,1000 };
	return distrib(generateur);
}

void PlayGame(list<Scores> &scores) {
	random_device seed{};

	int userProposition;
	int nbPartie;
	cout << "Pour jouer il vous suffit de proposer un prix la console vous répondra \"+\" ou \"-\" afin de trouver le prix coresspondant"
		<< endl
		<< "Combien de partie ?"
		<< endl;
	cin >> nbPartie;
	for (size_t i = 0; i < nbPartie; i++)
	{
		int nbTry{ 0 };
		int toFind = GetRand(seed);
		Scores score;
		score.SetGoodAnswer(toFind);
		//cout << endl << toFind << endl;

		do
		{
			nbTry++;
			cout << "Quel est votre proposition ?" << endl;
			cin >> userProposition;
			if (userProposition < toFind)
			{
				cout << "Bu bu! Plus grand que ça !" << endl;
			}
			else if (userProposition > toFind)
			{
				cout << "Bu bu! Moins que ça !" << endl;
			}
			else if (userProposition == toFind)
			{
				cout << "Congratulation le prix etait bien : "
					<< toFind
					<< endl
					<< "En " << nbTry << "essais";
				score.SetNbTry(nbTry);
				scores.push_back(score);
			}
			else
			{
				cout << "J'ai pas tout compris ... tu veux bien ressayer un truc ? ^^\"" << endl;
			}

		} while (toFind != userProposition);
	}

}

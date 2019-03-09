#pragma once
#include <iostream>
using namespace std;

enum  class Inputs
{
	Play = 'Y',
	Quit = 'N',
	Scores = 'S',
	Return = 'R'
};

void Menu();
void ScoresMenu();
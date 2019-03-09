#pragma once
#include <iostream>
#include <chrono>
class Scores
{
private :
	void StartGme() {
		startGame = std::chrono::system_clock::now();
	}
	void EndGame() {
		endGame = std::chrono::system_clock::now();

	}

protected:
	int nbTry{ 0 };
	int goodAnswer{ 0 };
	std::chrono::system_clock::time_point startGame;
	std::chrono::system_clock::time_point endGame;

public:
	Scores();
	~Scores();
	void ShowMessage() {
		std::cout << "Vous avez fait "
			<< nbTry
			<< "essaie pour trouver la bonne réponse ("
			<< goodAnswer
			<< ")"
			<< std::endl
			<< "Vous avez mit :" << std::chrono::duration_cast<std::chrono::duration<double>>(endGame -startGame ).count() << "secondes." << std::endl;
	}

	int GetNbTry() {
		return nbTry;
	}

	void SetNbTry(int value) {
		nbTry = value;
		EndGame();
	}

	int GetGoodAnswer() {
		return goodAnswer;
	}
	void SetGoodAnswer(int value) {
		goodAnswer = value;
	}


};


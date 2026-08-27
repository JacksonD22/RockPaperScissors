#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

const int quit = 0;
const int rock = 1,
const int paper = 2;
const int scissors = 3;

const int playerWin = 0;
const int computerWin = 1;
const int tie = 2;

void displayChoices();
void getChoice();
int getComputerChoice();
void chooseWinner();
void displayWinner();
void displayResults();
void displayFinalResults();
void displayError();


int main() {
	 
	displayChoices();
	getChoice();
	if (userChoice < 4 && userChoice > 0) {
		getComputerChoice();
		chooseWinner();
		displayWinner();
		displayResults();
	}
	else if (userchoice = 0) {
		displayFinalResults();
	}
	else
		displayError();
	return 0;
}
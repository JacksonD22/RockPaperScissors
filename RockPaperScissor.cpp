#include <iostream>
#include <iomanip>
#include <random>
#include <string>

using namespace std;

const int quit = 0;
const int rock = 1;
const int paper = 2;
const int scissors = 3;

const int draw = 0;
const int win = 1;
const int loss = 2;

int& wins;
int& losses;
int& draws;

void displayChoices(const int, const int, const int, const int);
int getChoice();
int getComputerChoice();
int chooseWinner(int, int, const int, const int, const int, int&, int&, int&, const int, const int, const int);
void displayWinner(int, int&, int&, int&, const int, const int, const int);
void displayResults(int&, int&, int&);
void displayFinalResults(int&, int&, int&);
void displayError();


int main() {
	 
	void displayChoices(const int scissors, const int rock, const int paper, const int quit);
	int getChoice();
	if (userChoice < 4 && userChoice > 0) {
		int getComputerChoice();
		int chooseWinner(int, int, const int, const int, const int, int&, int&, int&, const int, const int, const int);
		void displayWinner(int, int&, int&, int&, const int, const int, const int);
		void displayResults(int&, int&, int&);
	}
	else if (userchoice = 0) {
		void displayFinalResults(int&, int&, int&);
	}
	else
		void displayError();
	return 0;
}

void displayChoices(const int scissors, const int rock, const int paper, const int quit) {
	cout << "Welcome to the rock, paper, scissors tournament!\n";
	cout << "You can choose one of the following actions.\n";
	cout << scissors, ": Scissors\n ", rock, ": Paper\n ", paper, ": Rock\n ", quit, ": Quit(end your tournament)\n";
}

int getChoice() {
	int userChoice;
	cout << "Enter the cooresponding number below to make your move.\n";
		cin >> userChoice;
		return userChoice;
}

int getComputerChoice() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> distrib(1, 3);
	int computerChoice = distrib(gen);
	return computerChoice;
}

int chooseWinner(int userChoice, int computerChoice, const int scissors, const int rock, const int paper, int &wins, int &losses, int &draws, const int draw, const int loss, const int win) {
	int result;
	
	if (computerChoice = userChoice) {
		result = draw;
		draws++;
	}
	while (userChoice = scissors) {
		if (computerChoice = rock) {
			result = loss;
			losses++;
		}
		else if (computerChoice = paper) {
			result = win;
			wins++;
		}
	}

	while (userChoice = rock) {
		if (computerChoice = scissors) {
			result = win;
			wins++;
		}
		else if (computerChoice = paper) {
			result = loss;
			losses++;
		}
	}

	while (userChoice = paper)
		if (computerChoice = scissors) {
			result = loss;
			losses++;
		}
		else if (computerChoice = rock) {
			result = win;
			wins++;
		}

	return result;
}

void displayWinner(int result, int& wins, int& losses, int& draws, const int win, const int loss, const int draw) {
	if (result = win) {
		cout << "Congratulations, you won!\n";
	}

	else if (result = loss) {
		cout << "Sorry, you lost, try again.\n";
	}

	else if (result = draw) {
		cout << "Not exactly a win, but you didn't lose, keep going!\n";
	}


}

void displayResults(int& wins, int& losses, int& draws) {
	cout << "Your total score is...\n Wins: ", wins, "\n Losses: ", losses, "\n Draws: ", draws; cout << endl;
}

void displayFinalResults(int& wins, int& losses, int& draws) {
	cout << "Thanks for playing!\n";
	cout << "Your final score is...\n Wins: ", wins, "\n Losses: ", losses, "\n Draws: ", draws; cout << endl;
	if (wins > losses) {
		cout << "You beat the computer!\n";
	}
	else if (losses > wins) {
		cout << "Computer got the best of you this time.\n";
	}
}

void displayError() {
	cout << "You have selected an invalid number, try again\n";
	cout << "You can choose one of the following actions.\n 3: Scissors\n 2: Paper\n 1: Rock\n 0: Quit (end your tournament)\n"; 
	getChoice();
}
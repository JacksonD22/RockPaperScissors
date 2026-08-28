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

void displayChoices(const int, const int, const int, const int);
int getChoice(int);
int getComputerChoice();
int chooseWinner(int, int, const int, const int, const int, const int, const int, const int, int&, int&, int&);
void displayWinner(int, int&, int&, int&, const int, const int, const int);
void displayResults(int&, int&, int&);
void displayFinalResults(int&, int&, int&);
void displayError(int);


int main() {
	int wins = 0;
	int losses = 0;
	int draws = 0; 
	int userChoice = 5; 

	while (userChoice != quit) {
		displayChoices(scissors, rock, paper, quit);
		userChoice = getChoice(userChoice);
		if (userChoice < 4 && userChoice > 0) {
			int computerChoice = getComputerChoice();
			int result = chooseWinner(userChoice, computerChoice, scissors, rock, paper, draw, loss, win, draws, wins, losses);
			displayWinner(result, wins, losses, draws, win, loss, draw);
			displayResults(wins, losses, draws);
		}

		else if (userChoice == quit) {
			displayFinalResults(wins, losses, draws);
		}
		else
			displayError(userChoice);
	}
	return 0;
}

void displayChoices(const int scissors, const int rock, const int paper, const int quit) {
	cout << "Welcome to the rock, paper, scissors tournament!\n";
	cout << "You can choose one of the following actions.\n";
	cout << " " << scissors << ": Scissors\n " << rock << ": Paper\n " << paper << ": Rock\n " << quit << ": Quit(end your tournament)\n";
}

int getChoice(int userChoice) {
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

int chooseWinner(int userChoice, int computerChoice, const int scissors, const int rock, const int paper, const int draw, const int loss, const int win, int& draws, int& wins, int& losses) {
	int result;

	if (computerChoice == userChoice) {
		result = draw;
		draws++;
	}

	else if (userChoice == scissors) {
		if (computerChoice == rock) {
			result = loss;
			losses++;
			return result;
		}
		else {
			result = win;
			wins++;
			return result;
		}
	}
	else if (userChoice == rock) {
		if (computerChoice == scissors) {
			result = win;
			wins++;
			return result;
		}
		else {
			result = loss;
			losses++;
			return result;
		}
	}
	else if (userChoice == paper) {
		if (computerChoice == scissors) {
			result = loss;
			losses++;
			return result;
		}
		else {
			result = win;
			wins++;
			return result;
		}
	}
}

void displayWinner(int result, int& wins, int& losses, int& draws, const int win, const int loss, const int draw) {
	if (result == win) {
		cout << "Congratulations, you won!\n";
	}

	else if (result == loss) {
		cout << "Sorry, you lost, try again.\n";
	}

	else  {
		cout << "Not exactly a win, but you didn't lose, keep going!\n";
	}


}

void displayResults(int& wins, int& losses, int& draws) {
	cout << "Your total score is...\n Wins: " << wins << "\n Losses: " << losses << "\n Draws: " << draws << endl; cout << endl;
}

void displayFinalResults(int& wins, int& losses, int& draws) {
	cout << "Thanks for playing!\n";
	cout << "Your final score is...\n Wins: " << wins << "\n Losses: " << losses << "\n Draws: " << draws << endl; cout << endl;
	if (wins > losses) {
		cout << "You beat the computer!\n";
	}
	else if (losses > wins) {
		cout << "Computer got the best of you this time.\n";
	}
}

void displayError(int userChoice) {
	cout << "You have selected an invalid number, try again\n";
	cout << "You can choose one of the following actions.\n 3: Scissors\n 2: Paper\n 1: Rock\n 0: Quit (end your tournament)\n"; 
	getChoice(userChoice);
}
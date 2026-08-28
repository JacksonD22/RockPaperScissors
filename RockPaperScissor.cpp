#include <iostream>
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

void intro();
void displayChoices(const int, const int, const int, const int);
int getChoice(int);
int getComputerChoice();
void displayUserChoice(int, const int, const int, const int);
void displayComputerChoice(int, const int, const int, const int);
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

	intro();
	while (userChoice != quit) {
		displayChoices(scissors, rock, paper, quit);
		userChoice = getChoice(userChoice);
		if (userChoice <= scissors && userChoice >= rock) {
			int computerChoice = getComputerChoice();
			displayComputerChoice(computerChoice, scissors, rock, paper);
			displayUserChoice(userChoice, scissors, rock, paper);
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

void intro() {
	cout << "Welcome to the rock, paper, scissors tournament!\n";
}

void displayChoices(const int scissors, const int rock, const int paper, const int quit) {
	cout << "You can choose one of the following actions.\n";
	cout << " " << scissors << ": Scissors\n " << paper << ": Paper\n " << rock << ": Rock\n " << quit << ": Quit(end your tournament)\n";
}

int getChoice(int userChoice) {
	cout << "Enter the cooresponding number above to make your move.\n";
	cin >> userChoice; cout << endl;
		return userChoice;
}

int getComputerChoice() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> distrib(1, 3);
	int computerChoice = distrib(gen);
	return computerChoice;
}

void displayComputerChoice(int computerChoice, const int scissors, const int rock, const int paper) {
	if (computerChoice == scissors) {
		cout << "The computer chooses scissors." << endl;
	}
	else if (computerChoice == rock) {
		cout << "The computer chooses rock." << endl;
	}
	else
		cout << "The computer chooses paper." << endl;
}

void displayUserChoice(int userChoice, const int scissors, const int rock, const int paper) {
	if (userChoice == scissors) {
		cout << "You chose scissors." << endl;
	}
	else if (userChoice == rock) {
		cout << "You chose rock." << endl;
	}
	else
		cout << "You chose paper." << endl;
}

int chooseWinner(int userChoice, int computerChoice, const int scissors, const int rock, const int paper, const int draw, const int loss, const int win, int& draws, int& wins, int& losses) {
	int result = draw;;


	if (computerChoice == userChoice) {
		result = draw;
		draws++;
		
	}

	else if (computerChoice != userChoice) {
		if (userChoice == scissors && computerChoice == rock) {
			result = loss;
			losses++;
		}
		else if (userChoice == scissors && computerChoice == paper) {
			result = win;
			wins++;
		}

		else if (userChoice == rock && computerChoice == scissors) {
			result = win;
			wins++;
		}
		else if (userChoice == rock && computerChoice == paper) {
			result = loss;
			losses++;	
		}

		else if (userChoice == paper && computerChoice == scissors) {
			result = loss;
			losses++;
		}
		else if (userChoice == paper && computerChoice == rock) {
			result = win;
			wins++;	
		}
		
	}
	return result;
}

void displayWinner(int result, int& wins, int& losses, int& draws, const int win, const int loss, const int draw) {
	if (result == draw) {
		cout << "Not exactly a win, but at least you didn't lose. \n";
	}
	else {
		if (result == win) {
			cout << "Congrats, you won! \n";
		}
		else {
			cout << "Sorry, you lost, keep going. \n";
		}
	}

}	

void displayResults(int& wins, int& losses, int& draws) {
	cout << "Your currrent score is...\n Wins: " << wins << "\n Losses: " << losses << "\n Draws: " << draws << endl; cout << endl;
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
	cout << userChoice << " Is not a valid response, try again\n";
}
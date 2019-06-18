#include "Problem.h"
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cassert>
using namespace std;

void polyProblem(ProblemLevelOne *);

int main() {

	srand((unsigned)time(0));

	char retest;
	int difficulty;

	cout << "Enter a difficulty level (1 = easy, 2 = moderate, 3 = hard, 4 = very hard): ";
	cin >> difficulty;

	while (difficulty < 1 || difficulty > 4 || cin.fail())
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Invalid input. Re-enter (1 = easy, 2 = moderate, 3 = hard, 4 = very hard): ";
		cin >> difficulty;
	}
	cin.ignore(80, '\n');
	cout << endl;

	do {

		polyProblem(difficulty < 4 ? new ProblemLevelOne(difficulty) : new ProblemLevelTwo(difficulty));

		cout << "Give 'er another go? (y/n) ";
		cin >> retest;
		retest = toupper(retest);

		while (retest != 'Y' && retest != 'N')
		{
			cin.ignore(80, '\n');
			cout << "It's a yes or no question damn it! (y/n) ";
			cin >> retest;
			retest = toupper(retest);
		}
		cin.ignore(80, '\n');
		cout << endl;

	} while (retest != 'N');

} // end main


void polyProblem(ProblemLevelOne * prob) {

	assert(prob);
	prob->show();

	int guess, answer = prob->calcSolution();
	cout << "\nGuess the number printed onto the screen (or 666 if it is an infinite loop): ";
	cin >> guess;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Enter a number, not a letter stupid... ";
		cin >> guess;
	}
	cin.ignore(80, '\n');

	cout << endl;
	if (guess == answer)
	{
		cout << "Correct! Well done!";
	}
	else
	{
		cout << "Incorrect. ";
		if (answer == 666)
		{
			cout << "It is an infinite loop.";
		}
		else
		{
			cout << "The answer is " << answer << ".";
		}
	}
	cout << endl << endl;

	delete prob;

} // end polyProblem
#include "Problem.h"
#include <iomanip>
#include <ctime>
#include <cassert>


// LEVEL ONE

ProblemLevelOne::ProblemLevelOne(int difficulty) {

	letterList = new LetterList;
	assert(letterList);

	loopParent = new LoopHeader(letterList, difficulty);
	assert(loopParent);

	modifyX = new ModifyVariable(letterList, difficulty);
	assert(modifyX);

	int modifier = difficulty < 3 ? 5 : 1;
	X.num = rand() % (100 / modifier) - (50 / modifier);
	X.letter = letterList->grabLetter();

} // end constructor


ProblemLevelOne::~ProblemLevelOne() {

	delete letterList;
	delete loopParent;
	delete modifyX;

} // end destructor


// displays all variables listed at the top of the question
void ProblemLevelOne::showVariables() const {

	cout << "int " << X.letter << " = " << X.num;

	loopParent->showVariables();
	modifyX->showVariables();

} // end showVariables


// determines the value of the X variable to be guessed
int ProblemLevelOne::calcSolution() {
	
	if (loopParent->isInfinite())
		X.num = 666;
	else
		while (loopParent->iterate())
			X.num = modifyX->calc(X.num);
	
	return X.num;

} // end calcSolution


// displays the entire problem
void ProblemLevelOne::show() const {

	showVariables();

	cout << ";\n\n";

	loopParent->showLine();

	cout << "\n{\n    ";

	modifyX->showLine(X.letter);

	cout << "\n}\n\ncout << " << X.letter << ";\n";

} // end show


// LEVEL TWO

ProblemLevelTwo::ProblemLevelTwo(int difficulty) : ProblemLevelOne(difficulty) {

	ifParent = new IfHeader(loopParent, letterList);
	assert(ifParent);

} // end constructor


ProblemLevelTwo::~ProblemLevelTwo() {

	delete ifParent;

} // end destructor


// displays all variables listed at the top of the question, including the added variable for the nested if statement
void ProblemLevelTwo::showVariables() const {

	ProblemLevelOne::showVariables();
	ifParent->showVariables();

} // end showVariables


// displays the entire problem
void ProblemLevelTwo::show() const {

	showVariables();

	cout << ";\n\n";

	loopParent->showLine();

	cout << "\n{\n    ";

	ifParent->showLine();

	cout << "\n    {\n        ";

	modifyX->showLine(X.letter);

	cout << "\n    }";

	cout << "\n}\n\ncout << " << X.letter << ";\n";

} // end show


// determines the value of the X variable to be guessed
int ProblemLevelTwo::calcSolution() {

	if (loopParent->isInfinite())
		X.num = 666;
	else
		while (loopParent->iterate())
			if (ifParent->isTrue())
				X.num = modifyX->calc(X.num);

	return X.num;

} // end calcSolution
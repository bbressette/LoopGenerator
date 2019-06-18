#include "ModifyVariable.h"
#include <ctime>
#include <iostream>


ModifyVariable::ModifyVariable(LetterList * letterList, int difficulty) {

	D.num = difficulty < 3 ? 1 : rand() % 4 + 2;
	D.letter = letterList->grabLetter();

	solutionOperator = rand() % 2;

} // end constructor


int ModifyVariable::calc(int num) const {

	return (solutionOperator == 0 ? num - D.num : num + D.num);

} // end calc


void ModifyVariable::showVariables() const {

	if (D.num > 1)
		cout << ", " << D.letter << " = " << D.num;

} // end showVariables


void ModifyVariable::showLine(char letter) const {

	cout << letter;

	if (solutionOperator == 1)
		if (D.num == 1)
			cout << "++";
		else
			cout << " += " << D.letter;
	else
		if (D.num == 1)
			cout << "--";
		else
			cout << " -= " << D.letter;

	cout << ";";

} // end showLine
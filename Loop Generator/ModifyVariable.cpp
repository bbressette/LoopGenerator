#include "ModifyVariable.h"
#include <ctime>
#include <iostream>


// this class is used for incrementing/decrementing the X value to be guessed
ModifyVariable::ModifyVariable(LetterList * letterList, int difficulty) {

	// randomly generate ++ or -- and the value to be added, subtracted from X
	D.num = difficulty < 3 ? 1 : rand() % 4 + 2;
	D.letter = letterList->grabLetter();

	solutionOperator = rand() % 2;

} // end constructor


// increment/decrement X
int ModifyVariable::calc(int num) const {

	return (solutionOperator == 0 ? num - D.num : num + D.num);

} // end calc


// display the value of the increment/decrement integer at the top of the question
void ModifyVariable::showVariables() const {

	if (D.num > 1)
		cout << ", " << D.letter << " = " << D.num;

} // end showVariables


// display the increment/decrement code in the question
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
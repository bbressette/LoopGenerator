#include "IfHeader.h"
#include <iostream>
#include <ctime>


IfHeader::IfHeader(LoopHeader * newLoopParent, LetterList * letterList) {

	loopParent = newLoopParent;
	conditionOperator = rand() % 4 + 1;

	E.letter = letterList->grabLetter();
	E.num = loopParent->A.num >= loopParent->B.num ? 
		    rand() % ((loopParent->A.num + 10) - loopParent->B.num) + (loopParent->B.num - 5) : 
		    rand() % ((loopParent->B.num + 10) - loopParent->A.num) + (loopParent->A.num - 5);

} // end constructor that uses A


void IfHeader::showVariables() const {

	cout << ", " << E.letter << " = " << E.num;

} // end showVariables


void IfHeader::showLine() const {

	cout << "if (";

	cout << loopParent->A.letter;
	
	switch (conditionOperator)
	{
	case 1:
		cout << " < ";
		break;
	case 2:
		cout << " > ";
		break;
	case 3:
		cout << " <= ";
		break;
	default:
		cout << " >= ";
	}

	cout << E.letter << ")";

} // end showLine


bool IfHeader::isTrue() const {

	return (

		(conditionOperator == 1 && loopParent->A.num < E.num) ||
		(conditionOperator == 2 && loopParent->A.num > E.num) ||
		(conditionOperator == 3 && loopParent->A.num <= E.num) ||
		(conditionOperator == 4 && loopParent->A.num >= E.num)

	); // end return
	
} // end isTrue
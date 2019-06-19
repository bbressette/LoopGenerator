#pragma once
#include "LetterList.h"
#include "LetterNum.h"
using namespace std;

class ModifyVariable {

public:
	ModifyVariable(LetterList * /* letterList */, int /* difficulty */);
	int calc(int /* num */) const;
	void showVariables() const;
	void showLine(char /* letter */) const;

private:
	LetterNum D;
	int solutionOperator;

};
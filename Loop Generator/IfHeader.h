#include <iostream>
#include "ModifyVariable.h"
#include "LoopHeader.h"
#include "LetterList.h"
#include "LetterNum.h"
using namespace std;

class IfHeader {

public:
	IfHeader(LoopHeader * /* loopParent */, LetterList * /* letterList */);
	void showVariables() const;
	void showLine() const;
	bool isTrue() const;

private:
	LoopHeader * loopParent;
	LetterNum E;
	int conditionOperator;

};
#pragma once
#include "LetterList.h"
#include "LetterNum.h"
using namespace std;

class LoopHeader {

	friend class IfHeader;

public:
	LoopHeader(LetterList * /* letterList */, int /* difficulty */);
	bool isInfinite() const;
	void showVariables() const;
	void showLine() const;
	bool iterate();

private:
	LetterNum A, B, C;
	int conditionOperator, counterOperator;
	bool firstIteration;

};
#include <iostream>
#include "LoopHeader.h"
#include "IfHeader.h"
#include "ModifyVariable.h"
#include "LetterList.h"
#include "LetterNum.h"
using namespace std;


/* LEVEL ONE:

int X = ?, B = ?, C = ?, D = ?;

for (A = ?; A ? B; A ? C)
{
	X ? D;
}

cout << X;

*/

class ProblemLevelOne {

public:
	ProblemLevelOne(int /* difficulty */);
	virtual ~ProblemLevelOne();
	virtual int calcSolution();
	virtual void show() const;

protected:
	virtual void showVariables() const;
	LetterList * letterList;
	LetterNum X;
	LoopHeader * loopParent;
	ModifyVariable * modifyX;

}; // end ProblemLevelOne


/* LEVEL TWO:

int X = ?, B = ?, C = ?, D = ?, E = ?;

for (A = ?; A ? B; A ? C)
{
    if (A ? E)
	{
		X ? D;
	}
}

cout << X;

*/

class ProblemLevelTwo : public ProblemLevelOne {

public:
	ProblemLevelTwo(int /* difficulty */);
	~ProblemLevelTwo();
	void show() const;
	int calcSolution();

protected:
	void showVariables() const;
	IfHeader * ifParent;

}; // end ProblemLevelTwo
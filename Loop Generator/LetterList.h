#pragma once
using namespace std;

struct Letter {

	char letter;
	Letter * link;

}; // end Letter

class LetterList {

public:
	LetterList();
	~LetterList();
	char grabLetter();
	int getNoLetters() const { return noLetters; }

private:
	Letter * firstLink;
	int noLetters;

}; // end LetterList
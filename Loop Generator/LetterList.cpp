#include <cassert>
#include <ctime>
#include <iostream>
#include "LetterList.h"


LetterList::LetterList() {

	noLetters = 1;
	firstLink = new Letter;
	assert(firstLink);

	firstLink->letter = 'A';
	firstLink->link = NULL;

	Letter * walker = firstLink;

	while (noLetters < 26)
	{
		walker->link = new Letter;
		assert(walker->link);
		walker->link->letter = (char) 65 + noLetters;
		walker->link->link = NULL;
		noLetters++;
		walker = walker->link;
	}

} // end constructor


LetterList::~LetterList() {

	Letter * walker = firstLink;

	while (walker != NULL)
	{
		walker = walker->link;
		delete firstLink;
		firstLink = walker;
	}

} // end destructor


char LetterList::grabLetter() {
	
	int letterIndex = rand() % noLetters, ctr = 0;
	char letter;
	Letter * walker = firstLink, * stalker = NULL;

	while (walker != NULL)
	{
		if (letterIndex == ctr)
		{
			letter = walker->letter;
			break;
		}
		stalker = walker;
		walker = walker->link;
		ctr++;
	}

	if (stalker == NULL)
		firstLink = walker->link;
	else
		stalker->link = walker->link;
	
	noLetters--;
	delete walker;

	return letter;

} // end grabLetter
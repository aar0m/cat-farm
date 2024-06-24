///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// File for epicCats
///
/// @file    epicCats.cpp
/// @author  Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "ArrayDB.h"
#include "Cat.h"
#include <iostream>

using namespace std;

/// Program for generating a Cat database
int main() {
	const int catsAdded = 10;

	srand(time(nullptr));

	/*
	for (int index = 0; index < 10; index++){
		printCat(generateCat());
	}
	*/

	Cat catDB[MAX_CATS];
	initDB();

	for (int index = 0; index < catsAdded; index++) {
		AddCat(generateCat(), catDB);
	}

	for (int index = 0; index < numCats; index++) {
		printCat(catDB[index]);
	}


	return 0;
}
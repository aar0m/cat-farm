///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Functions for validating, generating, and printing structures for Cats
///
/// @file    Cat.cpp
/// @author  Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Cat.h"
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>

/// List of potential cat names
const char* catNames[NUM_OF_NAMES] = { "Whiskey", "Oreo", "Cappuccino", "Wasabi", "Mango", "Mocha", "Kiwi", "Cookie",
									"Tito", "Mochi", "Clementine", "Ginger", "Maple", "Pepper", "Pickle", "Waffle",
									"Chip", "Miso", "Peanut", "Brownie", "Honey", "Jameson", "Butterscotch",
									"Cheerio", "Godiva", "Kit Kat", "Nilla", "Truffle", "Cheeto", "Java", "Olive",
									"Sushi", "Cheddar", "Meatball"
};

using namespace std;

/// Validate Cat based on member information
extern bool validateCat(struct Cat catStructure) {
	if ( (strlen(catStructure.name) > MAX_CAT_NAME) || (strcmp(catStructure.name, "") == 0) ) {
		return false;
	}

	if ( catStructure.weightInPounds <= 0 || catStructure.weightInPounds >= MAX_CAT_WEIGHT ) {
		return false;
	}

	return true;
}

/// Generate a valid, random cat
///
/// @return A cat
struct Cat generateCat() {
	struct Cat aCat;

	static int numCatNames = 0;

	if( numCatNames == 0 ) {
		// Find the number of names in #catNames (it ends with an empty name)
		while( catNames[numCatNames++][0] != '\0' ) {}
	}

	do {
		memset( &aCat, 0, sizeof( aCat ));

		// strncpy( aCat.name, catNames[ rand() % numCatNames ], MAX_CAT_NAME );

		aCat.gender = (enum Gender) ( rand() % (int) GENDER_LAST );

		aCat.weightInPounds = (float) drand48() * MAX_CAT_WEIGHT;

		aCat.chipId = lrand48();

		aCat.isFixed = rand() % 2;
	} while( !validateCat( aCat ) );  /// If the randomly generated cat is invalid, generate another cat

	return aCat;
}
/// Prints Cat structure
extern void printCat(Cat catStruct) {
	if ( validateCat(catStruct) ) {
		cout << catStruct.name << endl;
		cout << "Gender:  " << catStruct.gender << endl;
		cout << "Weight:  " << setprecision(4) << catStruct.weightInPounds << " lbs" << endl;
		cout << "Chip ID: 0x" << hex << catStruct.chipId << endl;
		cout << "IsFixed: " << boolalpha << catStruct.isFixed << endl;
		cout << endl;
	}
}

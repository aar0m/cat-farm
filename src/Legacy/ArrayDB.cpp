///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// All functions pertaining to Cat array database.
///
/// @file    ArrayDB.cpp
/// @author  Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "ArrayDB.h"
#include "Cat.h"
#include <cstring>
#include <iostream>

/// Initialize number of Cats in catArray
int numCats = 0;

/// Initialize a Cat array
struct Cat catArray[MAX_CATS];

/// Initialize #catArray
///
/// Danger: This function will zero out and destroy the contents of #catArray
///
/// @return `true` if the database was successfully initialized.
///          `false` if there was a problem.
extern bool initDB(){
	memset(catArray, 0, sizeof(catArray));

	numCats = 0;

	return true;
}

/// If newCat is valid, return `true`
extern bool AddCat(struct Cat catStructure, struct Cat catArray[MAX_CATS]) {
	if ( (numCats >= 0) && (numCats < MAX_CATS) && validateCat(catStructure) ) {
		catArray[numCats] = catStructure;
		numCats += 1;
		return true;
	}

	return false;
}

/// Validate the Cat database based on preexisting checks
extern bool validateCatDB(struct Cat catArray[MAX_CATS]) {
	if ( (numCats >= 0) && (numCats <= MAX_CATS) ) {
		for( int index = 0; index <= numCats; index++ ) {
			if ( !validateCat(catArray[index]) ) {
				return false;
			}
		}
	} else {
		return false;
	}

	return true;
}


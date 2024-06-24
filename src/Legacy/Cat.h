///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Header file for Cat
///
/// @file    Cat.h
/// @author  Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <stdint.h>  // For uint32_t
#include <stdlib.h>  // For size_t

#ifndef EE205_ANIMAL_FARM_CAT_H

/// Defines Cat header for file if not already present
#define EE205_ANIMAL_FARM_CAT_H

#endif //EE205_ANIMAL_FARM_CAT_H

#define MAX_CAT_NAME 		(35)   ///< The maximum size of the cat's name
#define MAX_CAT_WEIGHT 		(100)  ///< The maximum weight of a cat in pounds
#define NUM_OF_NAMES		(34)   ///< The maximum amount of names in name array

/// Gender enumeration
enum Gender { GENDER_UNKNOWN = 0
	,GENDER_MALE         ///< A male cat
	,GENDER_FEMALE       ///< A female cat
	,GENDER_LAST         ///< A marker for the last gender -- do **_not_** use
};

/// A database record for a cat
struct Cat {
	enum Gender gender;                ///< The cat's gender
	float       weightInPounds;        ///< The cat's weight in pounds.  Must be >0 and < 100
	uint32_t    chipId;                ///< The chip ID
	bool        isFixed;               ///< Has the cat been neutered or spayed
	char        name[ MAX_CAT_NAME ];  ///< The name of the cat
};

extern bool validateCat(struct Cat catStructure);

extern Cat generateCat();

extern void printCat(Cat catStruct);



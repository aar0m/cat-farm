///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Header file for Animal Farm configuration.
///
/// @file    config.h
/// @author  Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_CONFIG_H
#define EE205_ANIMAL_FARM_CONFIG_H

#define PROGRAM_TITLE 	"Animal Farm"  ///< Grammatically correct title for the program
#define PROGRAM_NAME 	"animalFarm"   ///< Short-tile for the program (used for console messages)

#include <iomanip> ///< For setfill()
#include <random> ///< For random_device & mt19937

/// Format a line for dumping the members of a class to the console.
/// Setup the fields for printing (space pad, left justify, etc.)
#define FORMAT_LINE_FOR_DUMP( className, member ) \
	std::cout << std::setfill( ' ' ) 			/* Space pad */    \
			  << std::left 						/* Left justify */ \
			  << std::boolalpha 				/* Print `true` or `false` for `bool`s */ \
			  << std::setw(20) << (className) \
			  << std::setw(20) << (member) \
			  << std::setw(40) 					/* (data) */

/// Format a heading to print before FORMAT_LINE_FOR_DUMP.
/// Does not take any input and prints '=' 80 times.
#define FORMAT_HEADING_FOR_DUMP \
	std::cout << std::setfill( '=' )	/* fills with '=' */ \
			  << std::setw( 80 )    	/* pads 80 spaces */ \
			  << "" << std::endl		/* space printed */

/// Establish the RNG used by Animal Farm
///
/// The C++ standard library has some great built-in random number features.
/// @see https://en.cppreference.com/w/cpp/header/random
///
/// If you want the same pseudorandom sequence each time you run the program,
/// use `std::mt19937`.
///
/// If you want a truly unique random sequence each time you run the program,
/// use `std::random_device`.
// #define ANIMAL_FARM_RNG std::random_device
#define ANIMAL_FARM_RNG std::mt19937

#endif //EE205_ANIMAL_FARM_CONFIG_H

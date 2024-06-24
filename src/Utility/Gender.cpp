///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Methods to generate and validate Genders
///
/// @file    Gender.cpp
/// @author  Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Gender.h"

extern Gender newRandomGender() {
	return (Gender ( rand() % int( Gender::LAST_GENDER ) ) );
}

extern bool validateGender( Gender gender ) {
	return ( gender < Gender::LAST_GENDER );
}

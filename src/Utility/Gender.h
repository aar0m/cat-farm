///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Gender class to be used for Mammals
///
/// @file    Gender.h
/// @author  Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "../config.h"
#include <cstdlib>
#include <stdexcept>

// ////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_GENDER_H
#define EE205_ANIMAL_FARM_GENDER_H

// Gender Class ///////////////////////////////////////////////////////////////

/// A #Gender for education purposes (not indicative of all current genders)
enum class Gender {
	UNKNOWN_GENDER = 0, ///< Used when Gender is unknown
	GENDER_MALE,        ///< Indicates "male"
	GENDER_FEMALE,      ///< Indicates "female"
	LAST_GENDER         ///< Marker for last Gender (NOT TO BE USED)
};

// Methods ////////////////////////////////////////////////////////////////////

extern Gender newRandomGender();                ///< Generates a random Gender from the enumeration
extern bool validateGender( Gender gender );	///< Validates a Gender class given via input

// Class-to-string function ///////////////////////////////////////////////////
/// Output Gender as a formatted string
///
/// @param lhs_stream The output stream to write to (usually `cout`).
/// `lhs` stands for Left Hand Side and means the left side
/// of the `<<` operator.
/// @param rhs_Gender The Gender to output.
/// `rhs` stands for Right Hand Side and means the right
/// side of the `<<` operator.
/// @return `Unknown gender`, `Female` or `Male`.
inline std::ostream& operator<<( std::ostream& lhs_stream, const Gender& rhs_Gender )
{
	switch( rhs_Gender ) {
		case Gender::UNKNOWN_GENDER:
			lhs_stream << "Unknown gender";
			break;
		case Gender::GENDER_MALE:
			lhs_stream << "Male";
			break;
		case Gender::GENDER_FEMALE:
			lhs_stream << "Female";
			break;
		default:
			/// @throw out_of_range If the enum is not mapped to a string.
			throw std::out_of_range( PROGRAM_NAME ": Gender not mapped to a string." );
	}
	return lhs_stream;
}

#endif //EE205_ANIMAL_FARM_GENDER_H

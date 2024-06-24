///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Mammals? More like "ma pals!"
///
/// @file    Mammal.cpp
/// @author  Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Mammal.h"

using namespace std;

/// Generates Mammal with specified 'weight', 'color', and Gender
///
/// @param newWeight The new 'weight' of the Mammal
/// @param newColor  The new 'color' of the Mammal
/// @param newGender The new Gender of the Mammal
Mammal::Mammal( const float newWeight, const string_view newColor, const Gender newGender) : Animal( newWeight ) {
	if( !validateWeight( newWeight ) ){
		/// @throw invalid_argument If 'newWeight' is not valid
		throw invalid_argument( PROGRAM_NAME ": newWeight is not valid, please enter a valid weight." );
	}

	if( newGender == Gender::LAST_GENDER ){
		/// @throw invalid_argument If 'newGender' is not valid
		throw invalid_argument( PROGRAM_NAME ": newGender is not valid, please enter a valid gender." );
	}

	weight = newWeight;
	setColor( newColor );
	gender = newGender;
}

/// Generates Mammal with a specified 'weight' and 'color'
///
/// @param newWeight The new 'weight' of the Mammal
/// @param newColor  The new 'color' of the Mammal
Mammal::Mammal( const float newWeight, const string_view newColor ) {
	if( !validateWeight( newWeight ) ){
		/// @throw invalid_argument If 'newWeight' is not valid
		throw invalid_argument( PROGRAM_NAME ": newWeight is not valid, please enter a valid weight." );
	}

	weight = newWeight;
	setColor( newColor );
	gender = Gender::UNKNOWN_GENDER;
}

/// Generates Mammal with a specified 'weight' and Gender
///
/// @param newWeight  The new 'weight' of the Mammal
/// @param newGender The new Gender of the Mammal
Mammal::Mammal( const float newWeight, const Gender newGender ) {
	if( !validateWeight( newWeight ) ){
		/// @throw invalid_argument If 'newWeight' is not valid
		throw invalid_argument( PROGRAM_NAME ": newWeight is not valid, please enter a valid weight." );
	}

	if( newGender == Gender::LAST_GENDER ){
		/// @throw invalid_argument If 'newGender' is not valid
		throw invalid_argument( PROGRAM_NAME ": newGender is not valid, please enter a valid gender." );
	}

	weight = newWeight;
	color = "Unknown color";
	gender = newGender;
}

/// Generates Mammal with a specified 'color' and Gender
///
/// @param newColor  The new 'color' of the Mammal
/// @param newGender The new Gender of the Mammal
Mammal::Mammal( const Gender newGender, const string_view newColor ) {
	if( newGender == Gender::LAST_GENDER ){
		/// @throw invalid_argument If 'newGender' is not valid
		throw invalid_argument( PROGRAM_NAME ": newGender is not valid, please enter a valid gender." );
	}

	setColor( newColor );
	gender= newGender;
}

/// Generates a Mammal with a specified 'weight'
///
/// @param newWeight  The new 'weight' of the Mammal
Mammal::Mammal( float newWeight ) {
	if( !validateWeight( newWeight ) ){
		/// @throw invalid_argument If 'newWeight' is not valid
		throw invalid_argument( PROGRAM_NAME ": newWeight is not valid, please enter a valid weight." );
	}

	color = "Unknown color";
	gender = Gender::UNKNOWN_GENDER;
}

/// Generates a Mammal with a specified Gender
///
/// @param newGender  The new Gender of the Mammal
Mammal::Mammal( const Gender newGender ) {
	if( newGender == Gender::LAST_GENDER ){
		/// @throw invalid_argument If 'newGender' is not valid
		throw invalid_argument( PROGRAM_NAME ": newGender is not valid, please enter a valid gender." );
	}

	weight = generatePounds();
	color = "Unknown color";
	gender = newGender;
}

/*
/// Generates a Mammal with a specified 'color'
///
/// @param newColor  The new 'color' of the Mammal
Mammal::Mammal( const string_view newColor ) {
	setColor( newColor );
	gender = Gender::UNKNOWN_GENDER;
}
*/

/// Generates a Mammal with unknown 'weight', 'color', and Gender
Mammal::Mammal() {
	weight = generatePounds();
	color = "Unknown color";
	gender = Gender::UNKNOWN_GENDER;
}

Mammal::~Mammal() {}

void Mammal::setColor( string_view newColor ) {
	if( color == "Unknown color" ) {
		color = newColor;
	} else if( !color.empty() ) {
		/// @throw logic_error If the Mammal already has a set 'color'.
		throw logic_error( PROGRAM_NAME ": Mammal already has a set color!");
	}

	color = newColor;
}

string_view Mammal::getColor() const noexcept {
	return color;
}

/// Sets Gender of an Animal
/// @param  newGender The new Gender being set
void Mammal::setGender( const Gender newGender ) {
	if( ( newGender == Gender::LAST_GENDER ) ) {
		/// @throw invalid_argument If 'newGender' is not valid.
		throw invalid_argument(PROGRAM_NAME ": newGender must be valid!");
	}

	if(gender != Gender::UNKNOWN_GENDER) {
		/// @throw logic_error If the Mammal already has a set Gender.
		throw logic_error(PROGRAM_NAME ": Gender is already set!");
	}

	gender = newGender;
}

Gender Mammal::getGender() const noexcept {
	return gender;
}

string_view Mammal::getClassification() noexcept {
	const string_view classification = "Mammalia";
	return classification;
}

/// Validates that Mammal follows a specified ruleset.
///
///    - getClassification() must not be empty.
///    - getColor() must not be empty.
///    - 'gender' must be valid
///    - Is a valid Animal
///
/// @return 'true' if Mammal passes ruleset. 'false' otherwise.
bool Mammal::validate() const noexcept{
	if( ( color.empty() ) ) {
		cout << PROGRAM_NAME <<  ": Please set a color for the mammal manually or use generateColor()" << endl;
		return false;
	}

	if( getClassification().empty() ) {
		cout << PROGRAM_NAME << ": Please set a classification for the mammal" << endl;
		return false;
	}

	if( !validateGender( gender ) ) {
		cout << PROGRAM_NAME << ": This animal has an invalid gender." << endl;
		return false;
	}

	return Animal::validate();
}

/// Prints information of an Animal, including 'kingdom' and Gender.
///
/// #### Sample Output
///
///    Object              class               Mammal
///    Object              this                0x7ffc8f7605d0
///    Node                next                0
///    Animal			   weight			   0.1
///    Animal			   kingdom			   Animalia
///    Mammal			   classification	   Mammalia
///    Mammal			   gender			   Unknown gender
///    Mammal			   color			   Orange
///
void Mammal::dump() const noexcept {
	Animal::dump();
	FORMAT_LINE_FOR_DUMP( "Mammal", "classification" ) << getClassification() << endl;
	FORMAT_LINE_FOR_DUMP( "Mammal", "gender" ) << getGender() << endl;
	FORMAT_LINE_FOR_DUMP( "Mammal", "color" ) << getColor() << endl;
}

/// Total count of 'color' for the list
const int NUM_COLORS = 40;

/// A list of potential colors for a Mammal
const string_view randColors[ NUM_COLORS ] = {
		"Red",      "Orange",    "Yellow",     "Green",  "Blue",   "Violet",  "Brown",  "Pink",     "Black",     "White",
		"Crimson",  "Mahogany",  "Mustard",    "Lime",   "Cyan",   "Indigo",  "Beige",  "Fuchsia",  "Gray",      "Platinum",
		"Scarlet",  "Peach",     "Dandelion",  "Olive",  "Azure",  "Mauve",   "Tan",    "Magenta",  "Taupe",     "Cream",
		"Ruby",     "Rust",      "Gold",       "Jade",   "Navy",   "Lilac",   "Sepia",  "Cerise",   "Charcoal",  "Silver"
};

string_view Mammal::generateColor() noexcept {
	const int newColor = rand() % NUM_COLORS;
	return randColors[ newColor ];
}



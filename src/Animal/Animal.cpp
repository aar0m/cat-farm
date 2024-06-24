///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Are there any malls for animals?
///
/// @file    Animal.cpp
/// @author  Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "../Mammal/Cat/Cat.h"
#include "Animal.h"

using namespace std;

Animal::Animal( float newWeight ) {
	if( !validateWeight( newWeight ) ) {
		/// @throw invalid_argument If 'newWeight' is not valid
		throw invalid_argument( PROGRAM_NAME ": newWeight is not valid, please enter a valid weight." );
	}

	weight = newWeight;
}

Animal::Animal() {
	float const newWeight = generatePounds();

	if( !validateWeight( newWeight ) ) {
		weight = generatePounds();
	}

	weight = newWeight;
}

string_view Animal::getKingdom() noexcept {
	string_view const kingdom = "Animalia";
	return kingdom;
}

/// Validates that the 'weight' of an Animal follows a specified ruleset.
///
///    - 'weight' is greater than '0'
///
/// @return 'true' if 'weight' follows the ruleset. 'false' otherwise.
bool Animal::validateWeight( float aWeight ) {
	bool result = false;

	if( aWeight > 0 ) {
		result = true;
	}

	return result;
}

/// Validates that Animal follows a specified ruleset, then validates Animal as a Node.
///
///    - getKingdom() must not be empty
///    - info() must not be empty
///    - 'weight' is greater than '0'
///    - Is a valid Node
///
/// @return 'true' if Animal passes ruleset and is a valid Node. 'false' otherwise.
bool Animal::validate() const noexcept {
	if( getKingdom().empty() ) {
		cout << PROGRAM_NAME << ": This animal must have a kingdom." << endl;
		return false;
	}

	/* if( info().empty() ) {
		cout << PROGRAM_NAME << "ERROR: This animal must have info." << endl;
		return false;
	} */

	if( weight <= 0 ) {
		return false;
	}

	return Node::validate();

}

/// Prints information of an Animal, including 'kingdom' and Gender.
///
/// #### Sample Output
///
///    Object              class               Node
///    Object              this                0x7ffc8f7605d0
///    Node                next                0
///    Animal			   weight			   0.1
///    Animal			   kingdom			   Animalia
///
void Animal::dump() const noexcept {
	assert( validate() );

	Node::dump();
	FORMAT_LINE_FOR_DUMP( "Animal", "weight" ) << weight << endl;
	FORMAT_LINE_FOR_DUMP( "Animal", "kingdom" ) << getKingdom() << endl;
}

float Animal::generatePounds() noexcept {
	float const decimalVal  = 100;
	float const randWeight  = float( drand48() * decimalVal);

	return randWeight;
}

/// Print a unique one-line string representing this object
///
/// #### Sample Output
///
/// The Node at 0x7ffff375ba90
///
void Animal::info() const noexcept {
	// Put the address of this object into a string
	std::stringstream stringStream;
	stringStream << this;
	const std::string theAddressOfThis = stringStream.str();

	string infoString {};

	// Print the class
	infoString += "The ";
	infoString += boost::core::demangled_name( BOOST_CORE_TYPEID( *this ));
	infoString += " named ";
	infoString += getName();
	infoString += " at ";
	infoString += theAddressOfThis;
	infoString += " says ";
	infoString += speak();

	cout << infoString << endl;
}

Animal* Animal::getRandomAnimal() {
	Name catColors( "./data/catColors.txt" );
	return new Cat( Cat::names.getNextName(), generatePounds(), catColors.getNextName(), newRandomGender() );
}







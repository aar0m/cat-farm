///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Meow meow meow? Meow meow meow meow meow meow!
///
/// @file    Cat.cpp
/// @author  Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Cat.h"

using namespace std;

/// Data file that holds a list of cat names
#define CAT_NAMES_FILE "./data/catNames.txt"

/// This is static, so the list will be available for any and all Cat instances
/// to use.
///
/// #### Internal
/// The scope of this **member** variable is `public:`. This is to facilitate
/// testing. It's difficult to friend some of the Boost test fixtures.
Name Cat::names( CAT_NAMES_FILE ); // NOLINT: Professor provided code

/// This constructor is declared to be `explicit`, so you can't do silly
/// things like `Cat newCat = "Bella";` ... instead, you need to construct
/// a Cat properly like `Cat newCat( "Bella" );`
///
/// @param newName Must be a valid name per Name::validateName
Cat::Cat( const std::string_view newName )
		: Mammal( Mammal::generatePounds(), "Unknown color", Gender::UNKNOWN_GENDER ) { // Delegating constructor
			Cat::setName( newName ) ;
	Cat::validate();
}

string_view Cat::getName() const noexcept {
	return name;
}

/// @param newName The Cat's new name. It must be valid per Name::validateName.
void Cat::setName( const string_view newName ) {
	/* Unable to implement trim due to trim taking character arrays as arguments
	if( !Name::validateTrimmed( newName ) || !Name::validateInteriorWhitespaceTrimmed( newName ) ) {
		name = trim( newName );
	}
	*/

	if( !Name::validateName( newName ) ) {
		/// @throws invalid_argument If the Cat's name is invalid
		throw invalid_argument( "The cat's name [" + string(newName) + "] is invalid" );
	}

	name = newName;
}

/// Validates that Cat follows a specified ruleset.
///
///    - Name must be valid
///    - Is a valid Mammal
///
/// @return 'true' if Mammal passes ruleset. 'false' otherwise.
bool Cat::validate() const noexcept {
	if( !Name::validateName( name ) ) {
		return false;
	}

	return Mammal::validate();
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
///    Cat                 name                Chili
///
void Cat::dump() const noexcept {
	Mammal::dump();
	FORMAT_LINE_FOR_DUMP( "Cat", "name" ) << getName() << endl;
};

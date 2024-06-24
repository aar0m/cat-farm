///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Meow meow meow? Meow meow meow meow meow meow!
///
/// @file    Cat.h
/// @author  Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "../../Utility/Name.h"
#include "../../Utility/Trim.h"
#include "../Mammal.h"

// ////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_CAT_H
#define EE205_ANIMAL_FARM_CAT_H

// Cat class //////////////////////////////////////////////////////////////////

/// Cat class
class Cat : public Mammal {

// Protected members //////////////////////////////////////////////////////////
protected:
	std::string name;       ///< The name of the Cat

// Public members /////////////////////////////////////////////////////////////
public:
	static Name names;    ///< A list of potential Cat names

// Constructor/destructor methods /////////////////////////////////////////////
// 4-argument constructors ////////////////////////////////////////////////////
public:
	/// Generates a Cat with a specified Name, 'color', 'weight', and Gender
	Cat( const std::string_view newName, const float newWeight, const std::string_view newColor, const Gender newGender )
		: Mammal( newWeight, newColor, newGender ) {
		Cat::setName( newName );
	};


// 3-argument constructors ////////////////////////////////////////////////////
	/// Generates a Cat with a specified Name, 'weight' and 'color'
	Cat( const std::string_view newName, const float newWeight, std::string_view newColor )
			: Mammal( newWeight, newColor ) {
		Cat::setName( newName );
	};

	/// Generates a Cat with a specified Name, 'weight' and Gender
	Cat( const std::string_view newName, const float newWeight, const Gender newGender )
			: Mammal( newWeight, newGender ) {
		Cat::setName( newName );
	};

	/// Generates a Cat with a specified Name, Gender, and 'color'
	Cat( const std::string_view newName, const Gender newGender, const std::string_view newColor )
			: Mammal( newGender, newColor ) {
		Cat::setName( newName );
	};


// 2-argument constructors ////////////////////////////////////////////////////
	/// Generates a Cat with a specified Name and 'weight'
	Cat( const std::string_view newName, const float newWeight )
		: Mammal( newWeight ) {
		Cat::setName( newName );
	};

	/// Generates a Cat with a specified Name and Gender
	Cat( const std::string_view newName, const Gender newGender )
			: Mammal( newGender ) {
		Cat::setName( newName );
	};

// 1-argument constructors ////////////////////////////////////////////////////
	/// Generates a Cat with an unknown 'color', Gender, random 'weight', and specified 'newName'
	explicit Cat( std::string_view newName );

// Methods ////////////////////////////////////////////////////////////////////
	std::string_view getName() const noexcept;      ///< Get the Cat name
	void setName( std::string_view newName );       ///< Set the Cat name

	/// Causes Cat to speak via humane methods :3
	std::string_view speak() const noexcept { return "Meow"; };

	/// Validates Cat based on specified ruleset
	virtual bool validate() const noexcept;

	/// Prints information about Cat (Node, Animal, Mammal, Name)
	virtual void dump() const noexcept;

};

#endif //EE205_ANIMAL_FARM_CAT_H

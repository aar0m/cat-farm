///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Mammals? More like "ma pals!"
///
/// @file    Mammal.h
/// @author  Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "../Animal/Animal.h"
#include "../Utility/Gender.h"

// ////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_MAMMAL_H
#define EE205_ANIMAL_FARM_MAMMAL_H

// Mammal class ///////////////////////////////////////////////////////////////

/// Mammals? More like "ma pals!"
class Mammal : public Animal {

// Protected members //////////////////////////////////////////////////////////
protected:
	std::string_view color;		            ///< Specified 'color' of the Mammal
	Gender gender;                      ///< Specified Gender of the Mammal

// Constructor/destructor methods /////////////////////////////////////////////
public:
	/// Generates a Mammal with a specified 'color', 'weight', and Gender
	Mammal( float newWeight, std::string_view newColor, Gender newGender );

	Mammal( float newWeight, std::string_view newColor );    ///< Generates a Mammal with a specified 'weight' and 'color'
	Mammal( float newWeight, Gender newGender );             ///< Generates a Mammal with a specified 'weight' and Gender
	Mammal( Gender newGender, std::string_view newColor );   ///< Generates a Mammal with a specified 'color' and Gender and random 'weight'

	Mammal( float newWeight );                               ///< Generates a Mammal with a specified 'weight'
	Mammal( Gender newGender );                              ///< Generates a Mammal with a specified Gender and random 'weight'

	/* Removing constructors for convenience of implementing Cat class D:
	Mammal( string_view newColor );  ///< Generates a Mammal with a specified 'color' and random 'weight'
	*/

	Mammal();			 ///< Generates a Mammal with unknown 'color' and Gender but a random 'weight'
	virtual ~Mammal(); 	 ///< Destroys Mammal

// Methods ////////////////////////////////////////////////////////////////////
	void setColor( std::string_view newColor );  ///< Sets color of Mammal
	std::string_view getColor() const noexcept;  ///< Returns color of Mammal

	void setGender( Gender newGender );          ///< Sets Gender of Animal if "unknown"
	Gender getGender() const noexcept;           ///< Returns Gender of Animal

	/// Returns classification of Mammal
	static std::string_view getClassification() noexcept;

	/// Validates Animal based on specified ruleset
	virtual bool validate() const noexcept;

	/// Prints information about Mammal (Node, Animal, 'classification', 'color')
	virtual void dump() const noexcept;

	/// Generates a random 'color' for a Mammal (because "Unknown color" does not exist in the real world >:3)
	static std::string_view generateColor() noexcept;

	// Compares Mammals based on color: ASCII values of the strings are compared
	// int compare( Mammal* rhs_mammal );
};


#endif //EE205_ANIMAL_FARM_MAMMAL_H

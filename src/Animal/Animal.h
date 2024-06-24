///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Are there any malls for animals?
///
/// @file    Animal.h
/// @author  Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "../Container/Node.h"
#include "../config.h"
#include <cassert>
#include <cstring>
#include <iostream>
#include <string_view>

// ////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_ANIMAL_H
#define EE205_ANIMAL_FARM_ANIMAL_H

// Animal Class ///////////////////////////////////////////////////////////////

/// Are there any malls for animals?
class Animal : public Node {

// Protected members //////////////////////////////////////////////////////////
protected:
	float weight;                               ///< The specified 'weight' (in pounds) of the Animal

// Constructor/destructor methods /////////////////////////////////////////////
public:
	Animal( float newWeight );                  ///< Generates an Animal with a specified 'weight'
	Animal();                                   ///< Generates an Animal with a random valid 'weight'

// Methods ////////////////////////////////////////////////////////////////////
	static std::string_view getKingdom() noexcept;   ///< Returns 'kingdom' of Animal

	static bool validateWeight( float weight );      ///< Validates 'weight' based on specified ruleset
	virtual bool validate() const noexcept;          ///< Validates Animal based on specified ruleset

	/// Prints information of Animal (Node properties, 'kingdom', Gender)
	virtual void dump() const noexcept;

	/// Generates a random 'weight' in pounds for an Animal
	static float generatePounds() noexcept;

	/// Makes the Animal speak! (because who would let the dogs out if they won't woof)
	virtual std::string_view speak() const noexcept = 0;

	/// Gets the Name of the Animal
	virtual std::string_view getName() const noexcept = 0;

	/// Print a unique one-line string representing this object
	virtual void info() const noexcept;

	/// Generates a random Animal with random specifications (in this case, a Cat)
	static Animal* getRandomAnimal();

	// Compares Animals based on name, weight, color
	// int compare( Animal* rhs_animal );
};


#endif //EE205_ANIMAL_FARM_ANIMAL_H

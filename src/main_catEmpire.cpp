///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// This empire was definitely not built in a day.
///
/// @file    main.cpp
/// @author  Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "config.h"
#include "Container/SingleLinkedList.h"
#include "Mammal/Cat/Cat.h"
#include <iostream>

// ////////////////////////////////////////////////////////////////////////////

#define ALL_MY_ANIMALS 100 ///< Number of animals
#define ANIMAL_SAMPLE_SIZE 10 ///< Number of animals to sample

using namespace std;

/// The Cat Empire test program
///
/// @return The exit value for the program
int main() { /// @NOLINT( bugprone-exception-escape ): main() may throw an exception
	cout << "catEmpire" << endl ;

	SingleLinkedList myAnimals ;
	for( int counter = 0 ; counter < ALL_MY_ANIMALS ; counter++ ) {
		myAnimals.add( Animal::getRandomAnimal() );
	}
	for( int counter = 0 ; counter < ANIMAL_SAMPLE_SIZE ; counter++ ) {
		Node* aRandomNode = myAnimals.getRandomNode();
		Animal* aRandomAnimal = dynamic_cast<Animal*>( aRandomNode );
		aRandomAnimal->info();
	}
}
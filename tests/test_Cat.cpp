///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          Animal Farm - EE 205 - Spring 2023
//
/// Comprehensive test of Cat class methods
///
/// @file   test_Cat.cpp
/// @author Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
/// @cond Suppress Doxygen warnings

#include <boost/test/tools/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>

using namespace std;

#include "../src/Container/SingleLinkedList.h"
#include "../src/Mammal/Cat/Cat.h"

BOOST_AUTO_TEST_SUITE( test_Cat )

	BOOST_AUTO_TEST_CASE( test_setName ) {
	// Testing via constructors (each uses setName)
		BOOST_CHECK_NO_THROW( const Cat getName0( "Meowser" ) );
		BOOST_CHECK_NO_THROW( const Cat getName1( "Meow-ser" ) );
		BOOST_CHECK_NO_THROW( const Cat getName2( "M30w53r" ) );
		BOOST_CHECK_NO_THROW( const Cat getName3( "M30w-53r" ) );

		BOOST_CHECK_THROW( const Cat getName4( "" ), invalid_argument );
		BOOST_CHECK_THROW( const Cat getName5( "  Meowser  " ), invalid_argument );
		BOOST_CHECK_THROW( const Cat getName6( "1Meowser" ), invalid_argument );
		BOOST_CHECK_THROW( const Cat getName7( "-Meowser" ), invalid_argument );
		BOOST_CHECK_THROW( const Cat getName8( "Meowser!" ), invalid_argument );
		BOOST_CHECK_THROW( const Cat getName9( "Meow  ser!" ), invalid_argument );
		BOOST_CHECK_THROW( const Cat getName10( "Meow	ser!" ), invalid_argument );

		// Repeatedly tests since getRandomAnimal() uses setName()
		const int ALL_MY_ANIMALS = 100;
		for( int counter = 0 ; counter < ALL_MY_ANIMALS ; counter++ ) {
			BOOST_CHECK_NO_THROW( Animal::getRandomAnimal() );
		}
	}

	BOOST_AUTO_TEST_CASE( test_getName ) {
		const int ALL_MY_ANIMALS = 100;
		SingleLinkedList myAnimals ;

		for( int counter = 0 ; counter < ALL_MY_ANIMALS ; counter++ ) {
			myAnimals.add( Animal::getRandomAnimal() );
		}

		for( int counter = 0 ; counter < ALL_MY_ANIMALS ; counter++ ) {
			Node* aRandomNode = myAnimals.getRandomNode();
			Animal* aRandomAnimal = dynamic_cast<Cat*>( aRandomNode );
			BOOST_CHECK_NO_THROW( aRandomAnimal->getName() );
		}

		const Cat getName0( "Meowser" );          BOOST_CHECK( getName0.getName() == "Meowser");
		const Cat getName1( "Meowrio" );          BOOST_CHECK( getName1.getName() == "Meowrio");
		const Cat getName2( "Purrincess Peach" ); BOOST_CHECK( getName2.getName() == "Purrincess Peach" );
	}

	BOOST_AUTO_TEST_CASE( test_speak ) {
		const int ALL_MY_ANIMALS = 100;
		SingleLinkedList myAnimals ;

		for( int counter = 0 ; counter < ALL_MY_ANIMALS ; counter++ ) {
			myAnimals.add( Animal::getRandomAnimal() );
		}

		for( int counter = 0 ; counter < ALL_MY_ANIMALS ; counter++ ) {
			Node* aRandomNode = myAnimals.getRandomNode();
			Animal* aRandomAnimal = dynamic_cast<Animal*>( aRandomNode );
			BOOST_CHECK( aRandomAnimal->speak() == "Meow" );
		}
	}

	BOOST_AUTO_TEST_CASE( test_validate ) {
		const Cat validateTest0( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor(), Gender::UNKNOWN_GENDER);

		BOOST_CHECK( validateTest0.validate() == true );

		const Cat validateTest1( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() );
		const Cat validateTest2( Cat::names.getNextName(), Mammal::generatePounds(), Gender::GENDER_MALE );
		const Cat validateTest3( Cat::names.getNextName(), Gender::GENDER_FEMALE, Mammal::generateColor() );

		BOOST_CHECK( validateTest1.validate() == true );
		BOOST_CHECK( validateTest2.validate() == true );
		BOOST_CHECK( validateTest3.validate() == true );

		const Cat validateTest4( Cat::names.getNextName(), Mammal::generatePounds() );
		const Cat validateTest5( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() );
		const Cat validateTest6( Cat::names.getNextName(), Gender::GENDER_FEMALE );

		BOOST_CHECK( validateTest4.validate() == true );
		BOOST_CHECK( validateTest5.validate() == true );
		BOOST_CHECK( validateTest6.validate() == true );

		const Cat validateTest7( Cat::names.getNextName() );

		BOOST_CHECK( validateTest7.validate() == true );

		Cat validateTest8( Cat::names.getNextName() ); validateTest8.setColor( "" );

		BOOST_CHECK( validateTest8.validate() == false );
	}

	BOOST_AUTO_TEST_CASE( test_dump ) {
		const Cat dumpTest0( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() );
		const Cat dumpTest1( Cat::names.getNextName(), Gender::GENDER_MALE, Mammal::generateColor() );
		const Cat dumpTest2( Cat::names.getNextName(), Gender::GENDER_FEMALE, Mammal::generateColor() );

		BOOST_CHECK_NO_THROW( dumpTest0.dump() );
		BOOST_CHECK_NO_THROW( dumpTest1.dump() );
		BOOST_CHECK_NO_THROW( dumpTest2.dump() );

		Cat dumpTest3( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() ); dumpTest3.setGender( Gender::UNKNOWN_GENDER );
		Cat dumpTest4( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() ); dumpTest4.setGender( Gender::GENDER_MALE );
		Cat dumpTest5( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() ); dumpTest5.setGender( Gender::GENDER_FEMALE );

		BOOST_CHECK_NO_THROW( dumpTest3.dump() );
		BOOST_CHECK_NO_THROW( dumpTest4.dump() );
		BOOST_CHECK_NO_THROW( dumpTest5.dump() );

		Cat dumpTest6( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() ); dumpTest6.setGender( newRandomGender() );
		Cat dumpTest7( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() ); dumpTest7.setGender( newRandomGender() );
		Cat dumpTest8( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() ); dumpTest8.setGender( newRandomGender() );

		BOOST_CHECK_NO_THROW( dumpTest6.dump() );
		BOOST_CHECK_NO_THROW( dumpTest7.dump() );
		BOOST_CHECK_NO_THROW( dumpTest8.dump() );

		const Cat dumpTest9( Cat::names.getNextName(), Gender::GENDER_MALE, Mammal::generateColor() );
		const Cat dumpTest10( Cat::names.getNextName(), Gender::GENDER_FEMALE, Mammal::generateColor() );
		const Cat dumpTest11( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() );

		BOOST_CHECK_NO_THROW( dumpTest9.dump() );
		BOOST_CHECK_NO_THROW( dumpTest10.dump() );
		BOOST_CHECK_NO_THROW( dumpTest11.dump() );
	}

BOOST_AUTO_TEST_SUITE_END()
///@endcond

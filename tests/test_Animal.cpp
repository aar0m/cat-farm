///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          Animal Farm - EE 205 - Spring 2023
//
/// Comprehensive test of Animal class methods
///
/// @file   test_Animal.cpp
/// @author Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
/// @cond Suppress Doxygen warnings

#include <boost/test/tools/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>

using namespace std;

#include "../src/Animal/Animal.h"
#include "../src/Container/SingleLinkedList.h"
#include "../src/Mammal/Cat/Cat.h"

BOOST_AUTO_TEST_SUITE( test_Animal )

	BOOST_AUTO_TEST_CASE( test_getKingdom ) {
		const Cat kingdomTest0( Cat::names.getNextName() ); BOOST_CHECK_EQUAL( kingdomTest0.getKingdom(), "Animalia");	///< Tests for "kingdom" output
		const Cat kingdomTest1( Cat::names.getNextName() ) ; BOOST_CHECK_EQUAL( kingdomTest1.getKingdom(), "Animalia");   	///< Tests for "kingdom" output
		const Cat kingdomTest2( Cat::names.getNextName() ) ; BOOST_CHECK_EQUAL( kingdomTest2.getKingdom(), "Animalia");   	///< Tests for "kingdom" output
	}

	BOOST_AUTO_TEST_CASE( test_info ) {
		const Cat infoTest0( Cat::names.getNextName() ) ; BOOST_CHECK_NO_THROW( infoTest0.info() );
		const Cat infoTest1( Cat::names.getNextName() ) ; BOOST_CHECK_NO_THROW( infoTest1.info() );
		const Cat infoTest2( Cat::names.getNextName() ) ; BOOST_CHECK_NO_THROW( infoTest2.info() );
	}

	BOOST_AUTO_TEST_CASE( test_validateWeight ) {
		BOOST_CHECK( Animal::validateWeight( -0.1 ) == false ) ;
		BOOST_CHECK( Animal::validateWeight( -100 ) == false ) ;
		BOOST_CHECK( Animal::validateWeight( +0.1 ) == true ) ;
		BOOST_CHECK( Animal::validateWeight( 100 ) == true ) ;
	}

	BOOST_AUTO_TEST_CASE( test_validate ) {
		const Cat validateKingdomTest0( Cat::names.getNextName() ); BOOST_CHECK(validateKingdomTest0.validate() == true);  ///< Default case
		const Cat validateKingdomTest1( Cat::names.getNextName() ); BOOST_CHECK(validateKingdomTest1.validate() == true);  ///< Default case (kingdom can't change)
		const Cat validateKingdomTest2( Cat::names.getNextName() ); BOOST_CHECK(validateKingdomTest2.validate() == true);  ///< Default case (REALLY sure kingdom can't change)

		const Cat validateInfoTest0( Cat::names.getNextName() ); BOOST_CHECK(validateInfoTest0.validate() == true);        ///< Default case
		const Cat validateInfoTest1( Cat::names.getNextName() ); BOOST_CHECK(validateInfoTest1.validate() == true);        ///< Default case (info can't change)
		const Cat validateInfoTest2( Cat::names.getNextName() ); BOOST_CHECK(validateInfoTest2.validate() == true);        ///< Default case (REALLY sure info can't change)

		const Cat validateWeightTest0( Cat::names.getNextName() ); BOOST_CHECK(validateWeightTest0.validate() == true);
		const Cat validateWeightTest1( Cat::names.getNextName() ); BOOST_CHECK(validateWeightTest1.validate() == true);
		const Cat validateWeightTest2( Cat::names.getNextName() ); BOOST_CHECK(validateWeightTest2.validate() == true);

		const Cat validateWeightTest3( Cat::names.getNextName(), Animal::generatePounds() ); BOOST_CHECK(validateWeightTest3.validate() == true);
		const Cat validateWeightTest4( Cat::names.getNextName(), Animal::generatePounds() ); BOOST_CHECK(validateWeightTest4.validate() == true);
		const Cat validateWeightTest5( Cat::names.getNextName(), Animal::generatePounds() ); BOOST_CHECK(validateWeightTest5.validate() == true);

		const Cat validateWeightTest6( Cat::names.getNextName(), 0.1 );    BOOST_CHECK(validateWeightTest6.validate() == true);
		const Cat validateWeightTest7( Cat::names.getNextName(), 72.1 );   BOOST_CHECK(validateWeightTest7.validate() == true);
		const Cat validateWeightTest8( Cat::names.getNextName(), 999.99 ); BOOST_CHECK(validateWeightTest8.validate() == true);

		const Cat validateWeightTest9( Cat::names.getNextName(), 1 );     BOOST_CHECK(validateWeightTest9.validate() == true);
		const Cat validateWeightTest10( Cat::names.getNextName(), 400 );  BOOST_CHECK(validateWeightTest10.validate() == true);
		const Cat validateWeightTest11( Cat::names.getNextName(), 1600 ); BOOST_CHECK(validateWeightTest11.validate() == true);

		BOOST_CHECK_THROW(const Cat validateWeightTest12( Cat::names.getNextName(), -69.420 ), invalid_argument);
		BOOST_CHECK_THROW(const Cat validateWeightTest13( Cat::names.getNextName(), -999.99 ), invalid_argument);
		BOOST_CHECK_THROW(const Cat validateWeightTest14( Cat::names.getNextName(), -1616.16 ), invalid_argument);

		BOOST_CHECK_THROW(const Cat validateWeightTest15( Cat::names.getNextName(), -69420 ), invalid_argument);
		BOOST_CHECK_THROW(const Cat validateWeightTest16( Cat::names.getNextName(), -99999 ), invalid_argument);
		BOOST_CHECK_THROW(const Cat validateWeightTest17( Cat::names.getNextName(), -161616 ), invalid_argument);

		const int MAX_TESTS = 50;
		for (int count = 0; count <= MAX_TESTS; count++) {
			BOOST_CHECK_NO_THROW(new Cat( Cat::names.getNextName() ) );
		};

		for (int count = 0; count <= MAX_TESTS; count++) {
			BOOST_CHECK_NO_THROW( new Cat( Cat::names.getNextName(), Animal::generatePounds() ) );
		};
	}

	BOOST_AUTO_TEST_CASE( test_dump ) {
		const Cat dumpTest0( Cat::names.getNextName() ); BOOST_CHECK_NO_THROW( dumpTest0.dump() );
		const Cat dumpTest1( Cat::names.getNextName() ); BOOST_CHECK_NO_THROW( dumpTest1.dump() );
		const Cat dumpTest2( Cat::names.getNextName() ); BOOST_CHECK_NO_THROW( dumpTest2.dump() );

		const Cat dumpTest3( Cat::names.getNextName(), Animal::generatePounds() ); BOOST_CHECK_NO_THROW( dumpTest3.dump() );
		const Cat dumpTest4( Cat::names.getNextName(), Animal::generatePounds() ); BOOST_CHECK_NO_THROW( dumpTest4.dump() );
		const Cat dumpTest5( Cat::names.getNextName(), Animal::generatePounds() ); BOOST_CHECK_NO_THROW( dumpTest5.dump() );

		const Cat dumpTest6( Cat::names.getNextName(), 14 );     BOOST_CHECK_NO_THROW( dumpTest6.dump() );
		const Cat dumpTest7( Cat::names.getNextName(), 587143 ); BOOST_CHECK_NO_THROW( dumpTest7.dump() );
		const Cat dumpTest8( Cat::names.getNextName(), 467 );    BOOST_CHECK_NO_THROW( dumpTest8.dump() );

		const Cat dumpTest9( Cat::names.getNextName(), 1.4 );      BOOST_CHECK_NO_THROW( dumpTest9.dump() );
		const Cat dumpTest10( Cat::names.getNextName(), 587.143 ); BOOST_CHECK_NO_THROW( dumpTest10.dump() );
		const Cat dumpTest11( Cat::names.getNextName(), 4.67 );    BOOST_CHECK_NO_THROW( dumpTest11.dump() );
	}

	BOOST_AUTO_TEST_CASE( test_generatePounds ) {
		const int MAX_TESTS = 100;
		for (int count = 0; count <= MAX_TESTS; count++) {
			BOOST_CHECK_NO_THROW( new Cat( Cat::names.getNextName(), Animal::generatePounds() ) );
		};
	}

	BOOST_AUTO_TEST_CASE( test_AnimalSLL ) {
		SingleLinkedList firstSLL;
		int const NUM_ANIMALS = 50;

		BOOST_CHECK( firstSLL.isEmpty() == true );

		for( int count = 1; count <= NUM_ANIMALS; count++ ) {
			firstSLL.add( new Cat( Cat::names.getNextName() ) );
			BOOST_CHECK( firstSLL.isEmpty() == false );			///< Tests if Animals are present in SLL
			BOOST_CHECK_EQUAL( firstSLL.size(), count );		///< Verifies correct number of Animals are in SLL
		}

		// BOOST_CHECK( firstSLL.isIn( pNodeTest8 ) == true );		///< Verifies isIn function

		BOOST_CHECK_NO_THROW( firstSLL.dump() );				///< Prints Animals present in SLL

		BOOST_CHECK_NO_THROW( firstSLL.removeAll() );			///< Makes SLL empty

		BOOST_CHECK( firstSLL.isEmpty() == true );				///< Tests if SLL is empty

		BOOST_CHECK( firstSLL.size() == 0 );					///< Verifies SLL is empty
	}

	BOOST_AUTO_TEST_CASE( test_getRandomAnimal ) {
		const int ALL_MY_ANIMALS = 100;
		const int ANIMAL_SAMPLE_SIZE = 20;
		SingleLinkedList myAnimals ;

		for( int i = 0 ; i < ALL_MY_ANIMALS ; i++ ) {
			BOOST_CHECK_NO_THROW( Animal::getRandomAnimal() );
			myAnimals.add( Animal::getRandomAnimal() );
		}

		for( int i = 0 ; i < ANIMAL_SAMPLE_SIZE ; i++ ) {
			Node* aRandomNode = myAnimals.getRandomNode();
			Animal* aRandomAnimal = dynamic_cast<Animal*>( aRandomNode );
			aRandomAnimal->info();
		}
	}

BOOST_AUTO_TEST_SUITE_END()
///@endcond

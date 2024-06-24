///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          Animal Farm - EE 205 - Spring 2023
//
/// Comprehensive test of Mammal class methods
///
/// @file   test_Mammal.cpp
/// @author Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
/// @cond Suppress Doxygen warnings

#include <boost/test/tools/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>

using namespace std;

#include "../src/Animal/Animal.h"
#include "../src/Container/SingleLinkedList.h"
#include "../src/Mammal/Cat/Cat.h"

BOOST_AUTO_TEST_SUITE( test_Mammal )

	BOOST_AUTO_TEST_CASE( test_Constructors ) {
		BOOST_CHECK_NO_THROW( const Cat constructorTest0( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor(), Gender::GENDER_FEMALE ) );
		BOOST_CHECK_NO_THROW( const Cat constructorTest1( Cat::names.getNextName(), 587143, "black", Gender::GENDER_MALE ) );
		BOOST_CHECK_NO_THROW( const Cat constructorTest2( Cat::names.getNextName(), 11.11, "white", Gender::UNKNOWN_GENDER ) );

		BOOST_CHECK_THROW( const Cat constructorTest3( Cat::names.getNextName(), -1, Mammal::generateColor(), Gender::GENDER_FEMALE ), invalid_argument );
		BOOST_CHECK_THROW( const Cat constructorTest4( Cat::names.getNextName(), -587143, "black", Gender::GENDER_MALE ), invalid_argument );
		BOOST_CHECK_THROW( const Cat constructorTest5( Cat::names.getNextName(), -11.11, "white", Gender::UNKNOWN_GENDER ), invalid_argument );

		BOOST_CHECK_NO_THROW( const Cat constructorTest6( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() ) );
		BOOST_CHECK_NO_THROW( const Cat constructorTest7( Cat::names.getNextName(), 44, "myColor" ) );

		BOOST_CHECK_THROW( const Cat constructorTest8( Cat::names.getNextName(), 0.0, Mammal::generateColor() ), invalid_argument );
		BOOST_CHECK_THROW( const Cat constructorTest9( Cat::names.getNextName(), -44, "myColor" ), invalid_argument );

		BOOST_CHECK_NO_THROW( const Cat constructorTest10( Cat::names.getNextName(), Mammal::generatePounds(), Gender::GENDER_MALE) );
		BOOST_CHECK_NO_THROW( const Cat constructorTest11( Cat::names.getNextName(), 80, Gender::GENDER_MALE) );

		BOOST_CHECK_THROW( const Cat constructorTest12( Cat::names.getNextName(), -3, Gender::GENDER_MALE), invalid_argument );
		BOOST_CHECK_THROW( const Cat constructorTest13( Cat::names.getNextName(), -80, Gender::GENDER_MALE), invalid_argument );

		BOOST_CHECK_NO_THROW( const Cat constructorTest14( Cat::names.getNextName(), Gender::GENDER_FEMALE, Mammal::generateColor() ) );
		BOOST_CHECK_NO_THROW( const Cat constructorTest15( Cat::names.getNextName(), Gender::GENDER_FEMALE, "myColor" ) );

		BOOST_CHECK_NO_THROW( const Cat constructorTest16( Cat::names.getNextName(), Mammal::generatePounds() ) );
		BOOST_CHECK_NO_THROW( const Cat constructorTest17( Cat::names.getNextName(), 120 ) );

		BOOST_CHECK_THROW( const Cat constructorTest18( Cat::names.getNextName(), -4.1 ), invalid_argument );
		BOOST_CHECK_THROW( const Cat constructorTest19( Cat::names.getNextName(), -120 ), invalid_argument );

		/*
		BOOST_CHECK_NO_THROW( const Cat constructorTest20( Mammal::generateColor() ) );
		BOOST_CHECK_NO_THROW( const Cat constructorTest21( "myColor" ) );
		*/

		BOOST_CHECK_NO_THROW( const Cat constructorTest22( Cat::names.getNextName(), Gender::GENDER_MALE ) );
		BOOST_CHECK_NO_THROW( const Cat constructorTest23( Cat::names.getNextName(), Gender::GENDER_FEMALE ) );
		BOOST_CHECK_NO_THROW( const Cat constructorTest24( Cat::names.getNextName(), Gender::UNKNOWN_GENDER ) );
		BOOST_CHECK_THROW( const Cat constructorTest24( Cat::names.getNextName(), Gender::LAST_GENDER ), invalid_argument );

		BOOST_CHECK_NO_THROW( const Cat constructorTest25( Cat::names.getNextName() ) );
	}

	BOOST_AUTO_TEST_CASE( test_setColor ) {
		const string_view aColor = "newColor";

		Cat colorTest0( Cat::names.getNextName() );
		Cat colorTest1( Cat::names.getNextName() );
		Cat colorTest2( Cat::names.getNextName() );

		BOOST_CHECK_NO_THROW( colorTest0.setColor( Mammal::generateColor() ) );
		BOOST_CHECK_NO_THROW( colorTest1.setColor( "myColor" ) );
		BOOST_CHECK_NO_THROW( colorTest2.setColor( aColor ) );

		Cat colorTest3( Cat::names.getNextName(), Mammal::generatePounds(), "Unknown color" );
		Cat colorTest4( Cat::names.getNextName(), Mammal::generatePounds(), "Unknown color" );
		Cat colorTest5( Cat::names.getNextName(), Mammal::generatePounds(), "Unknown color" );

		BOOST_CHECK_NO_THROW( colorTest3.setColor( Mammal::generateColor() ) );
		BOOST_CHECK_NO_THROW( colorTest4.setColor( "myColor" ) );
		BOOST_CHECK_NO_THROW( colorTest5.setColor( aColor ) );

		Cat colorTest6( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() );
		Cat colorTest7( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() );
		Cat colorTest8( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() );

		BOOST_CHECK_THROW( colorTest6.setColor( Mammal::generateColor() ), logic_error  );
		BOOST_CHECK_THROW( colorTest7.setColor( "myColor" ), logic_error  );
		BOOST_CHECK_THROW( colorTest8.setColor( aColor ), logic_error  );

		Cat colorTest9( Cat::names.getNextName(), Mammal::generatePounds(), "myColor" );
		Cat colorTest10( Cat::names.getNextName(), Mammal::generatePounds(), "myColor" );
		Cat colorTest11( Cat::names.getNextName(), Mammal::generatePounds(), "myColor" );

		BOOST_CHECK_THROW( colorTest9.setColor( Mammal::generateColor() ), logic_error );
		BOOST_CHECK_THROW( colorTest10.setColor( "myColor" ), logic_error );
		BOOST_CHECK_THROW( colorTest11.setColor( aColor ), logic_error );

		Cat colorTest12( Cat::names.getNextName(), Mammal::generatePounds(), aColor );
		Cat colorTest13( Cat::names.getNextName(), Mammal::generatePounds(), aColor );
		Cat colorTest14( Cat::names.getNextName(), Mammal::generatePounds(), aColor );

		BOOST_CHECK_THROW( colorTest12.setColor( Mammal::generateColor() ), logic_error );
		BOOST_CHECK_THROW( colorTest13.setColor( "myColor" ), logic_error );
		BOOST_CHECK_THROW( colorTest14.setColor( aColor ), logic_error );

	}

	BOOST_AUTO_TEST_CASE( test_getColor ) {
		const string_view aColor = "newColor";

		const Cat classificationTest0( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor(), Gender::UNKNOWN_GENDER);

		BOOST_CHECK_NO_THROW( classificationTest0.getColor() );

		const Cat colorTest1( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() );
		const Cat colorTest2( Cat::names.getNextName(), Mammal::generatePounds(), Gender::UNKNOWN_GENDER );
		const Cat colorTest3( Cat::names.getNextName(), Gender::UNKNOWN_GENDER, Mammal::generateColor() );

		BOOST_CHECK_NO_THROW( colorTest1.getColor() );
		BOOST_CHECK( colorTest2.getColor() == "Unknown color" );
		BOOST_CHECK_NO_THROW( colorTest3.getColor() );

		const Cat colorTest4( Cat::names.getNextName(), Mammal::generatePounds() );
		const Cat colorTest5( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() );
		const Cat colorTest6( Cat::names.getNextName(), Gender::UNKNOWN_GENDER );

		BOOST_CHECK( colorTest4.getColor() == "Unknown color" );
		BOOST_CHECK_NO_THROW( colorTest5.getColor() );
		BOOST_CHECK( colorTest6.getColor() == "Unknown color" );

		const Cat colorTest7( Cat::names.getNextName() );

		BOOST_CHECK( colorTest7.getColor() == "Unknown color" );

		const Cat colorTest8( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() );
		const Cat colorTest9( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() );
		const Cat colorTest10( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() );

		BOOST_CHECK_NO_THROW( colorTest8.getColor() );
		BOOST_CHECK_NO_THROW( colorTest9.getColor() );
		BOOST_CHECK_NO_THROW( colorTest10.getColor() );

		const Cat colorTest11( Cat::names.getNextName(), Mammal::generatePounds(), "Unknown color" );
		const Cat colorTest12( Cat::names.getNextName(), Mammal::generatePounds(), "myColor" );
		const Cat colorTest13( Cat::names.getNextName(), Mammal::generatePounds(), "123456789" );
		const Cat colorTest14( Cat::names.getNextName(), Mammal::generatePounds(), "!@#$%^&*()-+" );

		BOOST_CHECK( colorTest11.getColor() == "Unknown color" );
		BOOST_CHECK( colorTest12.getColor() == "myColor" );
		BOOST_CHECK( colorTest13.getColor() == "123456789" );
		BOOST_CHECK( colorTest14.getColor() == "!@#$%^&*()-+" );

		const Cat colorTest15( Cat::names.getNextName(), Mammal::generatePounds(), aColor );
		const Cat colorTest16( Cat::names.getNextName(), Mammal::generatePounds(), aColor );

		BOOST_CHECK( colorTest15.getColor() == aColor );
		BOOST_CHECK( colorTest16.getColor() == "newColor" );

	}

	BOOST_AUTO_TEST_CASE( test_setGender ) {
		Cat genderTest0( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor(), Gender::UNKNOWN_GENDER);

		BOOST_CHECK_NO_THROW( genderTest0.setGender( Gender::GENDER_MALE ) );
		BOOST_CHECK_THROW( genderTest0.setGender( Gender::UNKNOWN_GENDER ), logic_error );
		BOOST_CHECK_THROW( genderTest0.setGender( Gender::LAST_GENDER ), invalid_argument );

		Cat genderTest1( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() );
		Cat genderTest2( Cat::names.getNextName(), Mammal::generatePounds(), Gender::GENDER_MALE );
		Cat genderTest3( Cat::names.getNextName(), Gender::GENDER_FEMALE, Mammal::generateColor() );

		BOOST_CHECK_NO_THROW( genderTest1.setGender( Gender::GENDER_MALE ) );
		BOOST_CHECK_THROW( genderTest1.setGender( Gender::UNKNOWN_GENDER ), logic_error );
		BOOST_CHECK_THROW( genderTest1.setGender( Gender::LAST_GENDER ), invalid_argument );

		BOOST_CHECK_THROW( genderTest2.setGender( Gender::UNKNOWN_GENDER ), logic_error );
		BOOST_CHECK_THROW( genderTest2.setGender( Gender::LAST_GENDER ), invalid_argument );

		BOOST_CHECK_THROW( genderTest3.setGender( Gender::UNKNOWN_GENDER ), logic_error );
		BOOST_CHECK_THROW( genderTest3.setGender( Gender::LAST_GENDER ), invalid_argument );

		Cat genderTest4( Cat::names.getNextName(), Mammal::generatePounds() );
		Cat genderTest5( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() );
		Cat genderTest6( Cat::names.getNextName(), Gender::GENDER_FEMALE );

		BOOST_CHECK_NO_THROW( genderTest4.setGender( Gender::GENDER_MALE ) );
		BOOST_CHECK_THROW( genderTest4.setGender( Gender::UNKNOWN_GENDER ), logic_error );
		BOOST_CHECK_THROW( genderTest4.setGender( Gender::LAST_GENDER ), invalid_argument );

		BOOST_CHECK_NO_THROW( genderTest5.setGender( Gender::GENDER_MALE ) );
		BOOST_CHECK_THROW( genderTest5.setGender( Gender::UNKNOWN_GENDER ), logic_error );
		BOOST_CHECK_THROW( genderTest5.setGender( Gender::LAST_GENDER ), invalid_argument );

		BOOST_CHECK_THROW( genderTest6.setGender( Gender::UNKNOWN_GENDER ), logic_error );
		BOOST_CHECK_THROW( genderTest6.setGender( Gender::LAST_GENDER ), invalid_argument );

		Cat genderTest7( Cat::names.getNextName() );

		BOOST_CHECK_NO_THROW( genderTest7.setGender( Gender::GENDER_MALE ) );
		BOOST_CHECK_THROW( genderTest7.setGender( Gender::UNKNOWN_GENDER ), logic_error );
		BOOST_CHECK_THROW( genderTest7.setGender( Gender::LAST_GENDER ), invalid_argument );

		Cat genderTest8( Cat::names.getNextName() );
		Cat genderTest9( Cat::names.getNextName(), Gender::UNKNOWN_GENDER );
		Cat genderTest10( Cat::names.getNextName(), Gender::GENDER_MALE );
		Cat genderTest11( Cat::names.getNextName(), Gender::GENDER_FEMALE );

		BOOST_CHECK_NO_THROW( genderTest8.setGender( Gender::GENDER_MALE ) );
		BOOST_CHECK_NO_THROW( genderTest9.setGender( Gender::GENDER_FEMALE ) );
		BOOST_CHECK_THROW( genderTest10.setGender( Gender::GENDER_FEMALE ), logic_error );
		BOOST_CHECK_THROW( genderTest11.setGender( Gender::GENDER_MALE ), logic_error );

		BOOST_CHECK_THROW( genderTest8.setGender( Gender::GENDER_MALE ), logic_error );
		BOOST_CHECK_THROW( genderTest8.setGender( Gender::GENDER_FEMALE ), logic_error );

		BOOST_CHECK_THROW( genderTest8.setGender( Gender::LAST_GENDER ), invalid_argument );
		BOOST_CHECK_THROW( genderTest9.setGender( Gender::LAST_GENDER ), invalid_argument );
		BOOST_CHECK_THROW( genderTest10.setGender( Gender::LAST_GENDER ), invalid_argument );
		BOOST_CHECK_THROW( genderTest1.setGender( Gender::LAST_GENDER ), invalid_argument );
	}

	BOOST_AUTO_TEST_CASE( test_getGender ) {
		const Cat genderTest0( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor(), Gender::UNKNOWN_GENDER);

		BOOST_CHECK( genderTest0.getGender() == Gender::UNKNOWN_GENDER );

		const Cat genderTest1( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() );
		const Cat genderTest2( Cat::names.getNextName(), Mammal::generatePounds(), Gender::GENDER_MALE );
		const Cat genderTest3( Cat::names.getNextName(), Gender::GENDER_FEMALE, Mammal::generateColor() );

		BOOST_CHECK( genderTest1.getGender() == Gender::UNKNOWN_GENDER );
		BOOST_CHECK( genderTest2.getGender() == Gender::GENDER_MALE );
		BOOST_CHECK( genderTest3.getGender() == Gender::GENDER_FEMALE );

		const Cat genderTest4( Cat::names.getNextName(), Mammal::generatePounds() );
		const Cat genderTest5( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() );
		const Cat genderTest6( Cat::names.getNextName(), Gender::GENDER_FEMALE );

		BOOST_CHECK( genderTest4.getGender() == Gender::UNKNOWN_GENDER );
		BOOST_CHECK( genderTest5.getGender() == Gender::UNKNOWN_GENDER );
		BOOST_CHECK( genderTest6.getGender() == Gender::GENDER_FEMALE );

		const Cat genderTest7( Cat::names.getNextName() );

		BOOST_CHECK( genderTest7.getGender() == Gender::UNKNOWN_GENDER );

		const Cat genderTest8( Cat::names.getNextName() );
		const Cat genderTest9( Cat::names.getNextName(), Gender::UNKNOWN_GENDER );
		const Cat genderTest10( Cat::names.getNextName(), Gender::GENDER_MALE );
		const Cat genderTest11( Cat::names.getNextName(), Gender::GENDER_FEMALE );

		BOOST_CHECK( genderTest8.getGender() == Gender::UNKNOWN_GENDER );		///< Default case
		BOOST_CHECK( genderTest9.getGender() == Gender::UNKNOWN_GENDER );   	///< Tests when gender is set to unknown
		BOOST_CHECK( genderTest10.getGender() == Gender::GENDER_MALE );   		///< Tests when gender is set to male
		BOOST_CHECK( genderTest11.getGender() == Gender::GENDER_FEMALE );   	///< Tests when gender is set to female
	}

	BOOST_AUTO_TEST_CASE( test_getClassification ) {
		const Cat classificationTest0( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor(), Gender::UNKNOWN_GENDER);

		BOOST_CHECK( classificationTest0.getClassification() == "Mammalia" );

		const Cat classificationTest1( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() );
		const Cat classificationTest2( Cat::names.getNextName(), Mammal::generatePounds(), Gender::UNKNOWN_GENDER );
		const Cat classificationTest3( Cat::names.getNextName(), Gender::UNKNOWN_GENDER, Mammal::generateColor() );

		BOOST_CHECK( classificationTest1.getClassification() == "Mammalia" );
		BOOST_CHECK( classificationTest2.getClassification() == "Mammalia" );
		BOOST_CHECK( classificationTest3.getClassification() == "Mammalia" );

		const Cat classificationTest4( Cat::names.getNextName(), Mammal::generatePounds() );
		const Cat classificationTest5( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() );
		const Cat classificationTest6( Cat::names.getNextName(), Gender::UNKNOWN_GENDER );

		BOOST_CHECK( classificationTest4.getClassification() == "Mammalia" );
		BOOST_CHECK( classificationTest5.getClassification() == "Mammalia" );
		BOOST_CHECK( classificationTest6.getClassification() == "Mammalia" );

		const Cat classificationTest7( Cat::names.getNextName() );

		BOOST_CHECK( classificationTest7.getClassification() == "Mammalia" );
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

		// Not a lot of ways to make an invalid Animal :)
	}

	BOOST_AUTO_TEST_CASE( test_dump ) {
		const Cat dumpTest0( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() );
		const Cat dumpTest1( Cat::names.getNextName(), Gender::GENDER_MALE, Mammal::generateColor() );
		const Cat dumpTest2( Cat::names.getNextName(), Gender::GENDER_FEMALE, Mammal::generateColor() );

		BOOST_CHECK_NO_THROW( dumpTest0.dump() );		///< Prints default Animal
		BOOST_CHECK_NO_THROW( dumpTest1.dump() );		///< Prints implicitly MALE Animal
		BOOST_CHECK_NO_THROW( dumpTest2.dump() );		///< Prints implicitly FEMALE Animal

		Cat dumpTest3( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() ); dumpTest3.setGender( Gender::UNKNOWN_GENDER );
		Cat dumpTest4( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() ); dumpTest4.setGender( Gender::GENDER_MALE );
		Cat dumpTest5( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() ); dumpTest5.setGender( Gender::GENDER_FEMALE );

		BOOST_CHECK_NO_THROW( dumpTest3.dump() );		///< Prints EXPLICITLY UNKNOWN Animal
		BOOST_CHECK_NO_THROW( dumpTest4.dump() );		///< Prints EXPLICITLY MALE Animal
		BOOST_CHECK_NO_THROW( dumpTest5.dump() );		///< Prints EXPLICITLY FEMALE Animal

		Cat dumpTest6( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() ); dumpTest6.setGender( newRandomGender() );
		Cat dumpTest7( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() ); dumpTest7.setGender( newRandomGender() );
		Cat dumpTest8( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() ); dumpTest8.setGender( newRandomGender() );

		BOOST_CHECK_NO_THROW( dumpTest6.dump() );		///< Prints Animal with randomly generated Gender
		BOOST_CHECK_NO_THROW( dumpTest7.dump() );
		BOOST_CHECK_NO_THROW( dumpTest8.dump() );

		const Cat dumpTest9( Cat::names.getNextName(), Gender::GENDER_MALE, Mammal::generateColor() );
		const Cat dumpTest10( Cat::names.getNextName(), Gender::GENDER_FEMALE, Mammal::generateColor() );
		const Cat dumpTest11( Cat::names.getNextName(), Mammal::generatePounds(), Mammal::generateColor() );

		BOOST_CHECK_NO_THROW( dumpTest9.dump() );		///< Should print original Gender
		BOOST_CHECK_NO_THROW( dumpTest10.dump() );		///< Should print original Gender
		BOOST_CHECK_NO_THROW( dumpTest11.dump() );
	}

BOOST_AUTO_TEST_SUITE_END()
///@endcond

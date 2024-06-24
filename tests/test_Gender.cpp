///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          Animal Farm - EE 205 - Spring 2023
//
/// Comprehensive test of Gender class
///
/// @file   test_Gender.cpp
/// @author Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_DYN_LINK

#include <boost/test/tools/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>

#include "../src/Utility/Gender.h"

BOOST_AUTO_TEST_SUITE( test_Gender )

 	BOOST_AUTO_TEST_CASE( test_validateGender ) {
		BOOST_CHECK_EQUAL( validateGender( Gender::UNKNOWN_GENDER ), true );   	///< Tests unknown Gender
		BOOST_CHECK_EQUAL( validateGender( Gender::GENDER_MALE ), true );   	///< Tests male Gender
		BOOST_CHECK_EQUAL( validateGender( Gender::GENDER_FEMALE ), true );   	///< Tests female Gender
		BOOST_CHECK_EQUAL( validateGender( Gender::LAST_GENDER ), false );   	///< Tests gender marker (not to be used)
		BOOST_CHECK_EQUAL( validateGender( newRandomGender() ), true );			///< Tests generated Gender

		/// Validates a randomly generated gender class multiple times
		for( int times = 0; times < 100; times++) {
			BOOST_CHECK_EQUAL( validateGender( newRandomGender() ), true );
		}
	}

BOOST_AUTO_TEST_SUITE_END()

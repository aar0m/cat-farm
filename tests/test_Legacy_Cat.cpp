///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          Animal Farm - EE 205 - Spring 2023
//
/// Comprehensive test of general Cat structures
///
/// @file   test_Legacy_ArrayDB.cpp
/// @author Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#define BOOST_TEST_DYN_LINK

#include <boost/test/tools/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>

#include "../src/Legacy/Cat.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_Legacy_Cat )

	BOOST_AUTO_TEST_CASE( test_validateCat ) {
		/* BOOST_CHECK_EQUAL(validateCat(generateCat()), true); /// Test randomly curated cat

		struct Cat testCat; strcpy(testCat.name, "Aaron Jr.");
		/// BOOST_CHECK_EQUAL(validateCat(testCat), true); /// Test custom name

		strcpy(testCat.name, "");
		BOOST_CHECK_EQUAL(validateCat(testCat), false); /// Test NULL or "empty" name

		strcpy(testCat.name, "Hubert Blaine Wolfeschlegelsteinhausenbergerdorff Sr.");
		BOOST_CHECK_EQUAL(validateCat(testCat), false); /// Test name exceeding MAX_CAT_NAME

		strcpy(testCat.name, "Mr. Miyagi"); testCat.weightInPounds = -1;
		BOOST_CHECK_EQUAL(validateCat(testCat), false); /// Test negative weight

		strcpy(testCat.name, "Obese"); testCat.weightInPounds = 500;
		BOOST_CHECK_EQUAL(validateCat(testCat), false); /// Test overflow weight
		*/
		}

BOOST_AUTO_TEST_SUITE_END()
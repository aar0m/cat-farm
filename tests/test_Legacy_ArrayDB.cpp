///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          Animal Farm - EE 205 - Spring 2023
//
/// Comprehensive test of general static array-based #Cat database
///
/// @file   test_Legacy_ArrayDB.cpp
/// @author Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#define BOOST_TEST_DYN_LINK

#include <boost/test/tools/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>

#include "../src/Legacy/ArrayDB.h"
#include "../src/Legacy/Cat.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_Legacy_ArrayDB )

	BOOST_AUTO_TEST_CASE( test_initDB ) {
		BOOST_CHECK_EQUAL( initDB(), true );
	}

	BOOST_AUTO_TEST_CASE( test_AddCat ) { /// MAX_CATS is defined as 10
		/// struct Cat testCat; strcpy(testCat.name, "Hubert Blaine Wolfeschlegelsteinhausenbergerdorff Sr.");
		/// BOOST_CHECK_EQUAL( AddCat(testCat, catArray), false ); /// Test adding cat with invalid name
	}

	BOOST_AUTO_TEST_CASE( test_validateCatDB ) {
		numCats = 11;
		BOOST_CHECK_EQUAL( validateCatDB(catArray), false ); /// Test overflowing array

		numCats = -1;
		BOOST_CHECK_EQUAL( validateCatDB(catArray), false ); /// Test negative array value
	}

BOOST_AUTO_TEST_SUITE_END()
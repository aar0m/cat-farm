///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          Cat Farm - EE 205 - Spring 2023
//
/// Comprehensive test of SLL class methods
///
/// @file   test_SingleLinkedList.cpp
/// @author Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
///@cond Suppress Doxygen warnings

#define BOOST_TEST_DYN_LINK

#include <boost/test/tools/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>

#include "../src/Container/SingleLinkedList.h"
#include "../src/Mammal/Cat/Cat.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_SingleLinkedList )

	BOOST_AUTO_TEST_CASE( test_Add ) {
		SingleLinkedList firstSLL;

		BOOST_CHECK( firstSLL.validate() == true );

		Cat nodeTest0( "Aaron" );   BOOST_CHECK_NO_THROW( firstSLL.add( &nodeTest0 ) );
		Cat nodeTest1( "Nicolas" ); BOOST_CHECK_NO_THROW( firstSLL.add( &nodeTest1 ) );
		Cat nodeTest2( "Bryant" );  BOOST_CHECK_NO_THROW( firstSLL.add( &nodeTest2 ) );
		Cat nodeTest3( "Lowy" );    BOOST_CHECK_NO_THROW( firstSLL.add( &nodeTest3 ) );
		Cat nodeTest4( "Bella" );   BOOST_CHECK_NO_THROW( firstSLL.add( &nodeTest4 ) );
		Cat nodeTest5( "Mikky" );   BOOST_CHECK_NO_THROW( firstSLL.add( &nodeTest5 ) );
		Cat nodeTest6( "Axel" );    BOOST_CHECK_NO_THROW( firstSLL.add( &nodeTest6 ) );
		Cat nodeTest7( "Amanda" );  BOOST_CHECK_NO_THROW( firstSLL.add( &nodeTest7 ) );
		Cat nodeTest8( "Mansai" );  BOOST_CHECK_NO_THROW( firstSLL.add( &nodeTest8 ) );
		Cat nodeTest9( "Kiara" );   BOOST_CHECK_NO_THROW( firstSLL.add( &nodeTest9 ) );

		BOOST_CHECK_THROW( firstSLL.add( nullptr ), invalid_argument );

		BOOST_CHECK_THROW( firstSLL.add( &nodeTest0 ), logic_error );
		BOOST_CHECK_THROW( firstSLL.add( &nodeTest1 ), logic_error );
		BOOST_CHECK_THROW( firstSLL.add( &nodeTest2 ), logic_error );

		BOOST_CHECK( firstSLL.validate() == true );
	}

	BOOST_AUTO_TEST_CASE( test_isEmpty ) {
		SingleLinkedList firstSLL;

		BOOST_CHECK( firstSLL.isEmpty() == true );

		Cat nodeTest0( "Neutral" );   firstSLL.add( &nodeTest0 );
		Cat nodeTest1( "Bad" );       firstSLL.add( &nodeTest1 );
		Cat nodeTest2( "Horrible" );  firstSLL.add( &nodeTest2 );
		Cat nodeTest3( "Malicious" ); firstSLL.add( &nodeTest3 );
		Cat nodeTest4( "Evil" );      firstSLL.add( &nodeTest4 );
		BOOST_CHECK( firstSLL.isEmpty() == false );

		firstSLL.removeAll();
		BOOST_CHECK( firstSLL.isEmpty() == true );
	}

	BOOST_AUTO_TEST_CASE( test_size ) {
		SingleLinkedList firstSLL;

		BOOST_CHECK( firstSLL.size() == 0 );

		Cat nodeTest0( Cat::names.getNextName() ); firstSLL.add( &nodeTest0 );
		BOOST_CHECK( firstSLL.size() == 1 );

		Cat nodeTest1( Cat::names.getNextName() ); firstSLL.add( &nodeTest1 );
		Cat nodeTest2( Cat::names.getNextName() ); firstSLL.add( &nodeTest2 );
		Cat nodeTest3( Cat::names.getNextName() ); firstSLL.add( &nodeTest3 );
		Cat nodeTest4( Cat::names.getNextName() ); firstSLL.add( &nodeTest4 );
		BOOST_CHECK( firstSLL.size() == 5 );

		Cat nodeTest5( Cat::names.getNextName() ); firstSLL.add( &nodeTest5 );
		Cat nodeTest6( Cat::names.getNextName() ); firstSLL.add( &nodeTest6 );
		Cat nodeTest7( Cat::names.getNextName() ); firstSLL.add( &nodeTest7 );
		Cat nodeTest8( Cat::names.getNextName() ); firstSLL.add( &nodeTest8 );
		Cat nodeTest9( Cat::names.getNextName() ); firstSLL.add( &nodeTest9 );
		BOOST_CHECK( firstSLL.size() == 10 );

		SingleLinkedList secondSLL;
		const int NUM_CatS = 50;
		for( int counter = 1 ; counter < NUM_CatS ; counter++ ) {
			secondSLL.add( new Cat( Cat::names.getNextName() ) );
			BOOST_CHECK( secondSLL.size() == size_t ( counter ) );
		}

	}

	BOOST_AUTO_TEST_CASE( test_getNode ) {
		SingleLinkedList firstSLL;

		BOOST_CHECK_NO_THROW( firstSLL.getRandomNode() );
		BOOST_CHECK_NO_THROW( firstSLL.getLargestNode() );
		BOOST_CHECK_NO_THROW( firstSLL.getSmallestNode() );

		Cat nodeTest0( Cat::names.getNextName() ); firstSLL.add( &nodeTest0 );
		Cat nodeTest1( Cat::names.getNextName() ); firstSLL.add( &nodeTest1 );
		Cat nodeTest2( Cat::names.getNextName() ); firstSLL.add( &nodeTest2 );
		Cat nodeTest3( Cat::names.getNextName() ); firstSLL.add( &nodeTest3 );
		Cat nodeTest4( Cat::names.getNextName() ); firstSLL.add( &nodeTest4 );
		Cat nodeTest5( Cat::names.getNextName() ); firstSLL.add( &nodeTest5 );
		Cat nodeTest6( Cat::names.getNextName() ); firstSLL.add( &nodeTest6 );
		Cat nodeTest7( Cat::names.getNextName() ); firstSLL.add( &nodeTest7 );
		Cat nodeTest8( Cat::names.getNextName() ); firstSLL.add( &nodeTest8 );
		Cat nodeTest9( Cat::names.getNextName() ); firstSLL.add( &nodeTest9 );

		const int MAX_TESTS = 50;
		for( int count = 0 ; count < MAX_TESTS ; count++ ) {
			BOOST_CHECK_NO_THROW( firstSLL.getRandomNode() );
		}

		BOOST_CHECK_NO_THROW( firstSLL.getLargestNode() );
		BOOST_CHECK_NO_THROW( firstSLL.getSmallestNode() );
	}

	BOOST_AUTO_TEST_CASE( test_Dump ) {
		const int NUM_CatS = 50;
		SingleLinkedList testList;

		for( int counter = 0 ; counter < NUM_CatS ; counter++ ) {
			testList.add( new Cat( Cat::names.getNextName() ) );
			BOOST_CHECK( testList.validate() == true );
		}

		BOOST_CHECK_NO_THROW( testList.dump() );
	}

	BOOST_AUTO_TEST_CASE( test_Remove ) {
		SingleLinkedList testList;

		Cat fakeCat( Cat::names.getNextName() );

		BOOST_CHECK_THROW( testList.remove( nullptr ), invalid_argument );
		BOOST_CHECK_THROW( testList.remove( &fakeCat ), domain_error );

		Cat testNode0( Cat::names.getNextName() ); testList.add( &testNode0 );
		Cat testNode1( Cat::names.getNextName() ); testList.add( &testNode1 );
		Cat testNode2( Cat::names.getNextName() ); testList.add( &testNode2 );
		Cat testNode3( Cat::names.getNextName() ); testList.add( &testNode3 );
		Cat testNode4( Cat::names.getNextName() ); testList.add( &testNode4 );
		Cat testNode5( Cat::names.getNextName() ); testList.add( &testNode5 );
		Cat testNode6( Cat::names.getNextName() ); testList.add( &testNode6 );
		Cat testNode7( Cat::names.getNextName() ); testList.add( &testNode7 );
		Cat testNode8( Cat::names.getNextName() ); testList.add( &testNode8 );
		Cat testNode9( Cat::names.getNextName() ); testList.add( &testNode9 );

		BOOST_CHECK_NO_THROW( testList.remove( &testNode9 ); );
		BOOST_CHECK_THROW( testList.remove( &testNode9 ), domain_error );
		BOOST_CHECK_THROW( testList.remove( nullptr ), invalid_argument );

		BOOST_CHECK_NO_THROW( testList.remove( &testNode0 ) );
		BOOST_CHECK_NO_THROW( testList.remove( &testNode1 ) );
		BOOST_CHECK_NO_THROW( testList.remove( &testNode2 ) );
		BOOST_CHECK_NO_THROW( testList.remove( &testNode3 ) );
		BOOST_CHECK_NO_THROW( testList.remove( &testNode4 ) );
		BOOST_CHECK_NO_THROW( testList.remove( &testNode5 ) );
		BOOST_CHECK_NO_THROW( testList.remove( &testNode6 ) );
		BOOST_CHECK_NO_THROW( testList.remove( &testNode7 ) );
		BOOST_CHECK_NO_THROW( testList.remove( &testNode8 ) );

		BOOST_CHECK_THROW( testList.remove( &testNode8 ), domain_error );

		testList.dump();

		BOOST_CHECK_NO_THROW( testList.removeAll() );

		testList.add( &testNode0 );
		testList.add( &testNode1 );
		testList.add( &testNode2 );
		testList.add( &testNode3 );
		testList.add( &testNode4 );
		testList.add( &testNode5 );
		testList.add( &testNode6 );
		testList.add( &testNode7 );
		testList.add( &testNode8 );
		testList.add( &testNode9 );

		BOOST_CHECK_NO_THROW( testList.removeAll() );
		BOOST_CHECK( testList.isEmpty() == true );

		testList.dump();

	}

	BOOST_AUTO_TEST_CASE( test_Sort ) {
		SingleLinkedList testList;		///< Create empty SLL
		BOOST_CHECK( testList.isSorted() == true );

		Cat testNode0( Cat::names.getNextName() ); testList.add( &testNode0 );			///< Create and add generic nodes to SLL
		// BOOST_CHECK( testList.isSorted() == true );
		BOOST_CHECK_NO_THROW( testList.sort() );

		Cat testNode1( Cat::names.getNextName() ); testList.add( &testNode1 );
		Cat testNode2( Cat::names.getNextName() ); testList.add( &testNode2 );
		Cat testNode3( Cat::names.getNextName() ); testList.add( &testNode3 );
		Cat testNode4( Cat::names.getNextName() ); testList.add( &testNode4 );
		Cat testNode5( Cat::names.getNextName() ); testList.add( &testNode5 );
		Cat testNode6( Cat::names.getNextName() ); testList.add( &testNode6 );
		Cat testNode7( Cat::names.getNextName() ); testList.add( &testNode7 );
		Cat testNode8( Cat::names.getNextName() ); testList.add( &testNode8 );
		Cat testNode9( Cat::names.getNextName() ); testList.add( &testNode9 );

		BOOST_CHECK( testList.isSorted() == false );

		FORMAT_HEADING_FOR_DUMP;
		cout << "UNSORTED LIST BELOW" << endl;
		FORMAT_HEADING_FOR_DUMP;
		testList.dump();

		FORMAT_HEADING_FOR_DUMP;
		cout << "SORTED LIST BELOW" << endl;
		FORMAT_HEADING_FOR_DUMP;

		BOOST_CHECK_NO_THROW( testList.sort() );
		testList.dump();

		// *****MANUALLY VERIFIED ADDRESSES BY CONVERTING FROM HEXADECIMAL TO DECIMAL
		// BOOST_CHECK( testList.isSorted() == true );

	}

BOOST_AUTO_TEST_SUITE_END()
///@endcond
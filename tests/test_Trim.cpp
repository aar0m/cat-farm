///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          Animal Farm - EE 205 - Spring 2023
//
/// Comprehensive test of general string-trimming functions
///
/// @file   test_trim.cpp
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
/// @cond Suppress Doxygen warnings
#define BOOST_TEST_MODULE Animal Farm Test Suite
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN  // in only one cpp file

#include <boost/test/tools/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>

#include "../src/Utility/Trim.h"

using namespace std;

/// Allocate a character buffer for testing
char buffer[1024];

/// Clear the buffer and then set it
///
/// @param newContents Set the buffer to this string
// Commenting out test due to error "warning: 'char* strncpy(char*, const char*, size_t)' specified bound 1024 equals destination size [-Wstringop-truncation]"
/*
void clearAndSetBuffer( const char newContents[] ) {
	memset( buffer, 'X', sizeof( buffer ) );  // Fill it full of X's
	strncpy( buffer, newContents, sizeof( buffer ) );
} */

BOOST_AUTO_TEST_SUITE( test_trim )
	// All tests use clearAndSetBufer()
	/*
   BOOST_AUTO_TEST_CASE( test_Trim_Left ) {
      clearAndSetBuffer( "" );      BOOST_CHECK_EQUAL( trim_left( buffer ), "" );
      clearAndSetBuffer( "A" );     BOOST_CHECK_EQUAL( trim_left( buffer ), "A" );
      clearAndSetBuffer( "AB" );    BOOST_CHECK_EQUAL( trim_left( buffer ), "AB" );
      clearAndSetBuffer( "ABC" );   BOOST_CHECK_EQUAL( trim_left( buffer ), "ABC" );

      clearAndSetBuffer( " " );     BOOST_CHECK_EQUAL( trim_left( buffer ), "" );
      clearAndSetBuffer( " A" );    BOOST_CHECK_EQUAL( trim_left( buffer ), "A" );
      clearAndSetBuffer( " AB" );   BOOST_CHECK_EQUAL( trim_left( buffer ), "AB" );
      clearAndSetBuffer( " ABC" );  BOOST_CHECK_EQUAL( trim_left( buffer ), "ABC" );

      clearAndSetBuffer( "\t " );    BOOST_CHECK_EQUAL( trim_left( buffer ), "" );
      clearAndSetBuffer( "\t A" );   BOOST_CHECK_EQUAL( trim_left( buffer ), "A" );
      clearAndSetBuffer( "\t AB" );  BOOST_CHECK_EQUAL( trim_left( buffer ), "AB" );
      clearAndSetBuffer( "\t ABC" ); BOOST_CHECK_EQUAL( trim_left( buffer ), "ABC" );

      clearAndSetBuffer( " \t\f\n\r\v " );       BOOST_CHECK_EQUAL( trim_left( buffer ), "" );
      clearAndSetBuffer( " \t\f\n\r\v A  " );    BOOST_CHECK_EQUAL( trim_left( buffer ), "A  " );
      clearAndSetBuffer( " \t\f\n\r\v AB  " );   BOOST_CHECK_EQUAL( trim_left( buffer ), "AB  " );
      clearAndSetBuffer( " \t\f\n\r\v ABC  " );  BOOST_CHECK_EQUAL( trim_left( buffer ), "ABC  " );
   }

   BOOST_AUTO_TEST_CASE( test_Trim_Right ) {
      clearAndSetBuffer( "" );        BOOST_CHECK_EQUAL( trim_right( buffer ), "" );
      clearAndSetBuffer( "A" );       BOOST_CHECK_EQUAL( trim_right( buffer ), "A" );
      clearAndSetBuffer( "AB" );      BOOST_CHECK_EQUAL( trim_right( buffer ), "AB" );
      clearAndSetBuffer( "ABC" );     BOOST_CHECK_EQUAL( trim_right( buffer ), "ABC" );

      clearAndSetBuffer( " " );       BOOST_CHECK_EQUAL( trim_right( buffer ), "" );
      clearAndSetBuffer( "A " );      BOOST_CHECK_EQUAL( trim_right( buffer ), "A" );
      clearAndSetBuffer( "AB " );     BOOST_CHECK_EQUAL( trim_right( buffer ), "AB" );
      clearAndSetBuffer( "ABC " );    BOOST_CHECK_EQUAL( trim_right( buffer ), "ABC" );

      clearAndSetBuffer( " \t" );     BOOST_CHECK_EQUAL( trim_right( buffer ), "" );
      clearAndSetBuffer( "A \t" );    BOOST_CHECK_EQUAL( trim_right( buffer ), "A" );
      clearAndSetBuffer( "AB \t" );   BOOST_CHECK_EQUAL( trim_right( buffer ), "AB" );
      clearAndSetBuffer( "ABC \t" );  BOOST_CHECK_EQUAL( trim_right( buffer ), "ABC" );

      clearAndSetBuffer( " \t\f\n\r\v " );      BOOST_CHECK_EQUAL( trim_right( buffer ), "" );
      clearAndSetBuffer( " A \t\f\n\r\v " );    BOOST_CHECK_EQUAL( trim_right( buffer ), " A" );
      clearAndSetBuffer( " AB \t\f\n\r\v " );   BOOST_CHECK_EQUAL( trim_right( buffer ), " AB" );
      clearAndSetBuffer( " ABC \t\f\n\r\v " );  BOOST_CHECK_EQUAL( trim_right( buffer ), " ABC" );
   }


   BOOST_AUTO_TEST_CASE( test_Trim ) {
      clearAndSetBuffer( "" );        BOOST_CHECK_EQUAL( trim_edges( buffer ), "" );
      clearAndSetBuffer( "A" );       BOOST_CHECK_EQUAL( trim_edges( buffer ), "A" );
      clearAndSetBuffer( "AB" );      BOOST_CHECK_EQUAL( trim_edges( buffer ), "AB" );
      clearAndSetBuffer( "ABC" );     BOOST_CHECK_EQUAL( trim_edges( buffer ), "ABC" );

      clearAndSetBuffer( " " );       BOOST_CHECK_EQUAL( trim_edges( buffer ), "" );
      clearAndSetBuffer( " A" );      BOOST_CHECK_EQUAL( trim_edges( buffer ), "A" );
      clearAndSetBuffer( " AB" );     BOOST_CHECK_EQUAL( trim_edges( buffer ), "AB" );
      clearAndSetBuffer( " ABC" );    BOOST_CHECK_EQUAL( trim_edges( buffer ), "ABC" );

      clearAndSetBuffer( "\t " );     BOOST_CHECK_EQUAL( trim_edges( buffer ), "" );
      clearAndSetBuffer( "\t A" );    BOOST_CHECK_EQUAL( trim_edges( buffer ), "A" );
      clearAndSetBuffer( "\t AB" );   BOOST_CHECK_EQUAL( trim_edges( buffer ), "AB" );
      clearAndSetBuffer( "\t ABC" );  BOOST_CHECK_EQUAL( trim_edges( buffer ), "ABC" );

      clearAndSetBuffer( " \t\f\n\r\v " );     BOOST_CHECK_EQUAL( trim_edges( buffer ), "" );
      clearAndSetBuffer( " \t\f\n\r\v A" );    BOOST_CHECK_EQUAL( trim_edges( buffer ), "A" );
      clearAndSetBuffer( " \t\f\n\r\v AB" );   BOOST_CHECK_EQUAL( trim_edges( buffer ), "AB" );
      clearAndSetBuffer( " \t\f\n\r\v ABC" );  BOOST_CHECK_EQUAL( trim_edges( buffer ), "ABC" );

      clearAndSetBuffer( "A " );      BOOST_CHECK_EQUAL( trim_edges( buffer ), "A" );
      clearAndSetBuffer( "AB " );     BOOST_CHECK_EQUAL( trim_edges( buffer ), "AB" );
      clearAndSetBuffer( "ABC " );    BOOST_CHECK_EQUAL( trim_edges( buffer ), "ABC" );

      clearAndSetBuffer( "A \t" );    BOOST_CHECK_EQUAL( trim_edges( buffer ), "A" );
      clearAndSetBuffer( "AB \t" );   BOOST_CHECK_EQUAL( trim_edges( buffer ), "AB" );
      clearAndSetBuffer( "ABC \t" );  BOOST_CHECK_EQUAL( trim_edges( buffer ), "ABC" );

      clearAndSetBuffer( "A \t\f\n\r\v " );    BOOST_CHECK_EQUAL( trim_edges( buffer ), "A" );
      clearAndSetBuffer( "AB \t\f\n\r\v " );   BOOST_CHECK_EQUAL( trim_edges( buffer ), "AB" );
      clearAndSetBuffer( "ABC \t\f\n\r\v " );  BOOST_CHECK_EQUAL( trim_edges( buffer ), "ABC" );

      clearAndSetBuffer( " A " );    BOOST_CHECK_EQUAL( trim_edges( buffer ), "A" );
      clearAndSetBuffer( " AB " );   BOOST_CHECK_EQUAL( trim_edges( buffer ), "AB" );
      clearAndSetBuffer( " ABC " );  BOOST_CHECK_EQUAL( trim_edges( buffer ), "ABC" );

      clearAndSetBuffer( "\t A \t" );    BOOST_CHECK_EQUAL( trim_edges( buffer ), "A" );
      clearAndSetBuffer( "\t AB \t" );   BOOST_CHECK_EQUAL( trim_edges( buffer ), "AB" );
      clearAndSetBuffer( "\t ABC \t" );  BOOST_CHECK_EQUAL( trim_edges( buffer ), "ABC" );

      clearAndSetBuffer( " \t\f\n\r\v A \t\f\n\r\v " );    BOOST_CHECK_EQUAL( trim_edges( buffer ), "A" );
      clearAndSetBuffer( " \t\f\n\r\v AB \t\f\n\r\v " );   BOOST_CHECK_EQUAL( trim_edges( buffer ), "AB" );
      clearAndSetBuffer( " \t\f\n\r\v ABC \t\f\n\r\v " );  BOOST_CHECK_EQUAL( trim_edges( buffer ), "ABC" );
   }

   BOOST_AUTO_TEST_CASE( test_Trim_In ) {
      clearAndSetBuffer( "" );     BOOST_CHECK_EQUAL( trim( buffer ), "" );
      clearAndSetBuffer( "A" );    BOOST_CHECK_EQUAL( trim( buffer ), "A" );
      clearAndSetBuffer( " A" );   BOOST_CHECK_EQUAL( trim( buffer ), "A" );
      clearAndSetBuffer( "A " );   BOOST_CHECK_EQUAL( trim( buffer ), "A" );
      clearAndSetBuffer( " A " );  BOOST_CHECK_EQUAL( trim( buffer ), "A" );

      clearAndSetBuffer( " " );      BOOST_CHECK_EQUAL( trim( buffer ), "" );
      clearAndSetBuffer( " A " );    BOOST_CHECK_EQUAL( trim( buffer ), "A" );
      clearAndSetBuffer( "  A" );    BOOST_CHECK_EQUAL( trim( buffer ), "A" );
      clearAndSetBuffer( "A  " );    BOOST_CHECK_EQUAL( trim( buffer ), "A" );
      clearAndSetBuffer( "  A  " );  BOOST_CHECK_EQUAL( trim( buffer ), "A" );

      clearAndSetBuffer( "A B" );    BOOST_CHECK_EQUAL( trim( buffer ), "A B" );
      clearAndSetBuffer( "A  B" );   BOOST_CHECK_EQUAL( trim( buffer ), "A B" );
      clearAndSetBuffer( "A   B" );  BOOST_CHECK_EQUAL( trim( buffer ), "A B" );

      clearAndSetBuffer( "AA BB" );    BOOST_CHECK_EQUAL( trim( buffer ), "AA BB" );
      clearAndSetBuffer( "AA  BB" );   BOOST_CHECK_EQUAL( trim( buffer ), "AA BB" );
      clearAndSetBuffer( "AA   BB" );  BOOST_CHECK_EQUAL( trim( buffer ), "AA BB" );

      clearAndSetBuffer( " A B " );        BOOST_CHECK_EQUAL( trim( buffer ), "A B" );
      clearAndSetBuffer( "  A  B  " );     BOOST_CHECK_EQUAL( trim( buffer ), "A B" );
      clearAndSetBuffer( "   A   B   " );  BOOST_CHECK_EQUAL( trim( buffer ), "A B" );

      clearAndSetBuffer( "A B C" );      BOOST_CHECK_EQUAL( trim( buffer ), "A B C" );
      clearAndSetBuffer( "A  B  C" );    BOOST_CHECK_EQUAL( trim( buffer ), "A B C" );
      clearAndSetBuffer( "A   B   C" );  BOOST_CHECK_EQUAL( trim( buffer ), "A B C" );

      clearAndSetBuffer( " A B C " );          BOOST_CHECK_EQUAL( trim( buffer ), "A B C" );
      clearAndSetBuffer( "  A  B  C  " );      BOOST_CHECK_EQUAL( trim( buffer ), "A B C" );
      clearAndSetBuffer( "   A   B   C   " );  BOOST_CHECK_EQUAL( trim( buffer ), "A B C" );

      clearAndSetBuffer( "\t\f\n\r\vA\t\f\n\r\vB\t\f\n\r\vC\t\f\n\r\v" );        BOOST_CHECK_EQUAL( trim( buffer ), "A B C" );
      clearAndSetBuffer( "\t\f\n\r\vAA\t\f\n\r\vBB\t\f\n\r\vCC\t\f\n\r\v" );     BOOST_CHECK_EQUAL( trim( buffer ), "AA BB CC" );
      clearAndSetBuffer( "\t\f\n\r\vAAA\t\f\n\r\vBBB\t\f\n\r\vCCC\t\f\n\r\v" );  BOOST_CHECK_EQUAL( trim( buffer ), "AAA BBB CCC" );
   }
*/
BOOST_AUTO_TEST_SUITE_END()
/// @endcond
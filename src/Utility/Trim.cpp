///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// General string-trimming functions
///
/// There are *so many ways* to implement string trimming...
///
///   - Maximize clarity and understandability
///   - Maximize efficiency
///
/// This implementation is designed to try to balance both requirements.
///
/// @file    Trim.cpp
/// @author  Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "../config.h"
#include "Trim.h"
#include <ctype.h>
#include <stdexcept>
#include <stdio.h>
#include <string.h>

using namespace std;

// Forward declaration
char* shift_left( char* string_base, size_t current_position, size_t distance );

/// @see https://en.cppreference.com/w/c/string/byte/isspace
extern char* trim_left( char inString[] ) {
	int const strLength = int(strlen(inString) - 1 );
	int const lastChar = int(strlen(inString) - 1 );
	int firstChar = 0;

	/// Isolate string
	for (int count = 0; count <= strLength; count++) {
		if (isspace(inString[count]) == 0 ) {
			firstChar = count;
			break;
		}
	}

	/// Shift and trim
	for (int count = 0; count <= lastChar; count++, firstChar++) {
		inString[count] = inString[firstChar];
	}

	/// End string
	if ( int(isspace(*inString)) == 0) {
		inString[lastChar + 1] = '\0';
	} else {
		inString[0] = '\0';
	}

	return inString;
}


/// @see https://en.cppreference.com/w/c/string/byte/isspace
extern char* trim_right( char inString[] ) {
	int const strLength = int(strlen(inString) - 1 );
	int lastChar = 0;

	/// Isolate string
	for (int count = strLength; count >= 0; count--) {
		if (isspace(inString[count]) == 0 ) {
			lastChar = count;
			break;
		}
	}

	/// Trim
	for (int count = strLength; count >= lastChar; count--) {
		if (isspace(inString[count]) != 0 ) {
			inString[count] = '\0';
		}
	}
	return inString;
}


/// This trim function does not modify the interior of the string
///
/// @see https://en.cppreference.com/w/c/string/byte/isspace
extern char* trim_edges( char inString[] ) {
	trim_left(inString);
	trim_right(inString);
	return inString;
}

/// The nature of a given character
enum CharClass {
	ASCII       ///< The character is a graphical ASCII character
	,WHITESPACE  ///< The character is neither an ASCII nor END character
	,END         ///< The character is the null terminator `'\0'`
};


/// Classify a character into a CharClass
///
/// @see https://en.cppreference.com/w/inChar/string/byte/isspace
///
/// @param inChar The character to classify
/// @return       The #CharClass of `inChar`
CharClass classifyChar( const char inChar ) {
	if( inChar == '\0' ) {
		return END;
	}

	if( isspace( inChar ) ) {
		return WHITESPACE;
	}

	return ASCII;
}


/// Shift characters in a string to the left.
///
/// @param string_base      The base address of a null-terminated string
/// @param current_position The index into `string_base` where it will start moving characters
/// @param distance         The number of characters to shift left.  Distance must be `<= current_position`
/// @return                 The final string
char* shift_left( char* string_base, size_t current_position, size_t distance ) {

	// printf( "Shifting c=%ld   d=%ld\n", current_position, distance );

	/// Don't do anything if distance == 0
	if( distance == 0 ) {
		throw logic_error( PROGRAM_NAME ": Distance traveled cannot be 0.");
	}

	/// Don't do anything if distance > current_position.
	if( distance > current_position ) {
		throw logic_error( PROGRAM_NAME ": Distance cannot be greater than current position.");
	}

	do {
		string_base [current_position - distance] = string_base[ current_position ];
	} while( string_base[ current_position++ ] != '\0' );

	return string_base;
}

/// This function does the following:
///
///    - Trim the leading whitespace
///    - Trim trailing whitespace
///    - Replace consecutive whitespace characters inside the string with
///      a single `" "`
char* trim( char inString[] ) {
	enum State { START, IN_WORD, ON_NOTICE, WORK_TO_DO, SHIFT, DONE } state = START;
	size_t index = 0;  // The current position
	size_t distance = 0;  // The distance

#ifdef DEBUG
	printf( "Before=[%s]\n", inString);
#endif

	while( state != DONE ) {
#ifdef DEBUG
		switch( state ) {
			case START:      printf( "State=START   " );      break;
			case IN_WORD:    printf( "State=IN_WORD   " );     break;
			case ON_NOTICE:  printf( "State=ON_NOTICE   " );   break;
			case WORK_TO_DO: printf( "State=WORK_TO_DO   " );  break;
			case SHIFT:      printf( "State=SHIFT   " );       break;
			case DONE:       printf( "State=DONE   " );        break;
		}

		printf( "index=%lu   distance=%lu  inString=[%s]\n", index, distance, inString );
#endif

		switch( state ) {
			case START:
				switch( classifyChar( inString[index] )) {
					case END:
						state = DONE;
						continue;
					case ASCII:
						state = IN_WORD;
						index++;
						continue;
					case WHITESPACE:
						index++;
						distance++;
						state = WORK_TO_DO;
						continue;
				}
				break;
			case IN_WORD:
				switch( classifyChar( inString[index] )) {
					case END:
						state = DONE;
						continue;
					case ASCII:
						state = IN_WORD;
						index++;
						continue;
					case WHITESPACE:
						inString[ index ] = ' ';  // Jam a space into this position
						index++;
						state = ON_NOTICE;
						continue;
				}
				break;
			case ON_NOTICE:
				switch( classifyChar( inString[index] )) {
					case END:
						state = SHIFT;
						distance++;
						continue;
					case ASCII:
						state = IN_WORD;
						index++;
						continue;
					case WHITESPACE:
						index++;
						distance=2;
						state = WORK_TO_DO;
						continue;
				}
				break;
			case WORK_TO_DO:
				switch( classifyChar( inString[index] )) {
					case ASCII:
					case END:
						state = SHIFT;
						continue;
					case WHITESPACE:
						index++;
						distance++;
						continue;
				}
				break;
			case SHIFT:
				switch( classifyChar( inString[index] )) {
					case END:
						shift_left( inString, index, distance );
						index = index - distance;
						distance = 0;
						state = DONE;
						continue;
					case ASCII:
						if( index - distance > 0 ) {  // If not the first character...
							distance--;          // then make room for a space
						}
						shift_left( inString, index, distance );
						index = index - distance;
						distance = 0;
						state = IN_WORD;
						continue;
					case WHITESPACE:
						continue;
				}
				break;
			case DONE:
				continue;
		}
	}

#ifdef DEBUG
	printf( "State=DONE   index=%lu   distance=%lu  inString=[%s]\n", index, distance, inString );
#endif

	return inString;
}
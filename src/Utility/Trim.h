///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// General string-trimming functions
///
/// @file   Trim.h
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#pragma once

/// Remove all leading whitespace from `inString`
extern char* trim_left( char inString[] ) ;

/// Remove all trailing whitespace from `inString`
extern char* trim_right( char inString[] ) ;

/// Remove all leading and trailing whitespace from `inString`
extern char* trim_edges( char inString[] ) ;

///< Trim leading & trailing whitespace and collapse consecutive interior whitespace into `" "`
extern char* trim( char inString[] ) ;

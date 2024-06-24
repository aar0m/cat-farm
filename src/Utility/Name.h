///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// A utility class for managing names of things
///
/// @file   Name.h
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>  // For string & string_view
#include <vector>  // For vector<>

/// A utility class for managing Animal names
///
/// Names can come from several sources:
///
///    - #FROM_FILE:  A list of names in a file
///    - #FROM_SERIAL:  Monotonically generated names with an optional prefix
///                     and/or suffix
///
/// This class does not have setters as once it's instantiated, nothing needs
/// to change.
class Name {
public:  // //////////////////////// Type Definitions //////////////////////////

   /// The type of name the Name class will serve
   enum NameType {
       FROM_FILE    ///< Name is randomly selected from a list in a file
      ,FROM_SERIAL  ///< Name is monotonically generated from a serial number
   } ;
   typedef unsigned long serial_t;  ///< The datatype of the serial number


public:  // /////////////////////////// Constants //////////////////////////////

   static serial_t maxSerial;   ///< The largest possible serial number


protected:  // //////////////////// Protected Members //////////////////////////

   enum NameType nameType;  ///< Enum that determines how names are generated

   std::string fileName;            ///< If #FROM_FILE, the source filename
   std::vector<std::string> names;  ///< If #FROM_FILE, the collection of names
                                    ///< read from the file

   std::string serialPrefix;  ///< If #FROM_SERIAL, print this before the serial number
   std::string serialSuffix;  ///< If #FROM_SERIAL, print this after the serial number
   serial_t serial = 0;       ///< If #FROM_SERIAL, then this is the serial number

public:  // /////////////////// Constructors & Destructors /////////////////////
   /// Construct a #FROM_FILE Name class
   Name( std::string_view newFilename ); // NOLINT: Professor provided code

   /// Construct a #FROM_SERIAL Name class
   Name( std::string_view newSerialPrefix, std::string_view newSerialSuffix );


public:  // ///////////////////////// Public Methods ///////////////////////////

   /// Get the next name
   std::string getNextName();

   /// Erase and then re-load the names database or set the serial number to 0
   void reset();

   /// Return the number of unique names left
   serial_t remainingNames() noexcept;

public:  // ///////////////////// Static Public Methods ////////////////////////
   /// Check if `newName` is valid
   static bool validateName( std::string_view newName );

   /// Return `true` if `newName` is not empty
   static bool validateNotEmpty( std::string_view newName );

   /// Return `true` if `newName` is left and right trimmed for whitespace
   static bool validateTrimmed( std::string_view newName );

   /// Return `true` if `newName` starts with an alphabetic character (`A` - `Z` or `a` - `z`)
   static bool validateStartsWithAlpha( std::string_view newName );

   /// Return `true` if `newName` only contains `A` - `Z`, `a` - `z`, `0`-`9`, space and `-`
   static bool validateNoSpecialChars( std::string_view newName );

   /// Return `true` if `newName`'s interior whitespace is trimmed
   static bool validateInteriorWhitespaceTrimmed( std::string_view newName );
};

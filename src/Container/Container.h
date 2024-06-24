///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Container class for objects to be storage and use
///
/// @file    Container.h
/// @author  Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Node.h"

// ////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_CONTAINER_H
#define EE205_ANIMAL_FARM_CONTAINER_H

// Container class ////////////////////////////////////////////////////////////

/// What CAN'T this container class contain?
class Container {

// Protected members //////////////////////////////////////////////////////////
protected:
	size_t count = 0;   ///< Variable to count objects within a Container

// Constructor method /////////////////////////////////////////////////////////
public:
	Container() {};     ///< Generates a Container to place objects into

// Methods ////////////////////////////////////////////////////////////////////
	/// Indicates if Container is empty or not
	/// @return  'true' if the Container is empty. 'false' if populated.
	virtual bool isEmpty() const noexcept {
		bool result = false;

		if( count == 0 ) {
			result = true;
		}

		return result;
	}

	/// Returns number of objects in Container
	virtual size_t size() const noexcept {
		return count;
	}

	/// Checks if Node (aNode) is present in the Container
	virtual bool isIn( const Node* aNode ) const = 0;

	virtual void add( Node* newNode ) = 0;              ///< Adds a new Node to Container
	virtual void removeAll() noexcept = 0;              ///< Removes every Node from Container

	virtual Node* getRandomNode() const noexcept = 0;   ///< Retrieves a random Node

	/// Prints information of a Container, including class, address, and 'count'
	///
	/// #### Sample Output
	///
	///    Object              class               SingleLinkedList
	///    Object              this                0x7ffc8f7605d0
	///    Container           count               0
	///
	virtual void dump() const noexcept {
		FORMAT_LINE_FOR_DUMP( "Object", "class" ) << boost::core::demangled_name( BOOST_CORE_TYPEID( *this )) << std::endl ;
		FORMAT_LINE_FOR_DUMP( "Object", "this" ) << this << std::endl ;
		FORMAT_LINE_FOR_DUMP( "Container", "count" ) << count << std::endl;
	}

	/// Validates that Node and Container follow a specified ruleset.
	///
	///    - If 'count' is equal to 0, then isEmpty() must be true.
	///    - If 'count' is not equal to 0, then isEmpty() must be false.
	///
	/// @return  'true' if Container passes ruleset. 'false' otherwise.
	virtual bool validate() const noexcept {
		bool result = false;

		if( ( count == 0 ) && isEmpty() ) {
			result = true;
		}

		if( ( count != 0 ) && !isEmpty() ) {
			result = true;
		}

		return result;
	}

};

#endif //EE205_ANIMAL_FARM_CONTAINER_H

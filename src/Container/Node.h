///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Node class for objects to inherit
///
/// @file    Node.h
/// @author  Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "../config.h"
#include <boost/core/typeinfo.hpp>
#include <iostream>

// ////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_NODE_H
#define EE205_ANIMAL_FARM_NODE_H

// Node Class /////////////////////////////////////////////////////////////////

/// Do no new nodes know known nodes!?
class Node {


// Friend Classes /////////////////////////////////////////////////////////////
	/// Allows class SingleLinkedList to access members
	friend class SingleLinkedList;

// Protected members //////////////////////////////////////////////////////////

protected:
	Node* next;               ///< Points to next Node
	Node* left  = nullptr;    ///< Points to the 'left' Node
	Node* right = nullptr;    ///< Points to the 'right' Node

// Constructor/destructor methods /////////////////////////////////////////////

public:
	Node() = default;   ///< Generates an instance of a Node

	virtual ~Node() {   ///< Resets a Node and destroys the instance
		Node::reset();
	}

// Public methods /////////////////////////////////////////////////////////////
	/// Sets next pointer of Node to nullptr
	virtual void reset() {
		next = nullptr;
	};

	/// Prints information of a Node, including class, address, and next Node.
	///
	/// #### Sample Output
	///
	///    Object              class               Node
	///    Object              this                0x7ffc8f7605d0
	///    Node                next                0
	///    Node                left                0
	///    Node                right               0
	///
	virtual void dump() const noexcept {
		FORMAT_HEADING_FOR_DUMP;
		FORMAT_LINE_FOR_DUMP( "Object", "class" ) << boost::core::demangled_name( BOOST_CORE_TYPEID( *this )) << std::endl ;
		FORMAT_LINE_FOR_DUMP( "Object", "this" ) << this << std::endl ;
		FORMAT_LINE_FOR_DUMP( "Node", "next" ) << next << std::endl;
		FORMAT_LINE_FOR_DUMP( "Node", "left" ) << left << std::endl;
		FORMAT_LINE_FOR_DUMP( "Node", "right" ) << right << std::endl;
	};

	/// Ensures Node and all its members are healthy (presumably)
	/// @return 'true' if the Node follows the specified ruleset.
	virtual bool validate() const {
		return true;
	};


	/// Prints unique line representing this object
	///
	/// #### Sample Output
	/**@verbatim
	The Node at 0x7ffff375ba90
	@endverbatim */
	virtual void info() const noexcept {
		// Put the address of this object into a string
		std::stringstream stringStream;
		stringStream << this;
		std::string theAddressOfThis = stringStream.str();

		std::string infoString{};

		// Print the class
		infoString += "The ";
		infoString += boost::core::demangled_name(BOOST_CORE_TYPEID(*this));
		infoString += " at ";
		infoString += theAddressOfThis;

		std::cout << infoString << std::endl;
	}

	/// Compares Node based by numerically comparing addresses
	/// @param  rhs_node The Node that the current object is being compared
	/// @return 'true' if the current object is less than 'rhs_node'. 'false' if the current object is greater than 'rhs_node'.
	bool isLessThan( const Node* rhs_node ) {
		return this < rhs_node;
	}
};

#endif //EE205_ANIMAL_FARM_NODE_H

///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Singly Linked List (SLL) class to store Nodes
///
/// @file    SingleLinkedList.h
/// @author  Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "../Mammal/Mammal.h"
#include "Container.h"
#include <cassert>

// ////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_SINGLELINKEDLIST_H
#define EE205_ANIMAL_FARM_SINGLELINKEDLIST_H

// Singly Linked List (SLL) class /////////////////////////////////////////////

/// A one way trip to the nullptr :)
class SingleLinkedList : public Container {

// Protected members //////////////////////////////////////////////////////////
protected:
	/// Head pointer that anchors a SingleLinkedList and facilitates methods
	Node* head = nullptr;

// Public methods /////////////////////////////////////////////////////////////
public:
	/// Indicates if a specific object is present in the SingleLinkedList
	virtual bool isIn( const Node* aNode ) const;

	virtual void add( Node* newNode );                          ///< Adds a new Node, 'newNode', to SingleLinkedList

	virtual void remove( Node* oldNode );                       ///< Removes a Node, 'thisNode', from SingleLinkedList
	virtual void removeAll() noexcept;                          ///< Unlinks all objects from SingleLinkedList

	virtual Node* getRandomNode() const noexcept;               ///< Returns a random object from the SingleLinkedList
	virtual Node* getParentOf( const Node* thisNode ) const;    ///< Returns "parent" Node (previous) of thisNode

	virtual Node* getSmallestNode() const noexcept;             ///< Returns smallest Node in SingleLinkedList
	virtual Node* getLargestNode() const noexcept;              ///< Returns largest Node in SingleLinkedList

	virtual void sort();                                        ///< Sorts SingleLinkedList via selection sort
	virtual bool isSorted() const noexcept;                     ///< Checks if SingleLinkedList is sorted from least to greatest

	/// Iterates and prints information for every object in a SingleLinkedList
	virtual void dump() const noexcept;

	/// Iterates and validates every object in a SingleLinkedList based on specified ruleset
	virtual bool validate() const noexcept;

	// Super secret method to view how loop iterates over SingleLinkedList
	// void traversal() const noexcept;
};


#endif //EE205_ANIMAL_FARM_SINGLELINKEDLIST_H

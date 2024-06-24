///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Singly Linked List (SLL) class to store Nodes
///
/// @file    SingleLinkedList.cpp
/// @author  Aaron Ramos <ramosab@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "SingleLinkedList.h"

// ////////////////////////////////////////////////////////////////////////////

using namespace std;

// Public methods /////////////////////////////////////////////////////////////
/// Indicates if Node, 'aNode', is in the Container
/// @return 'true' if 'aNode' is present. 'false' if 'aNode' is absent.
bool SingleLinkedList::isIn( const Node* aNode ) const {
	Node* current = head;
	bool result = false;

	while( current != nullptr ) {
		if( current == aNode ) {
			result = true;
		}

		current = current->next;
	}

	return result;
}

void SingleLinkedList::add( Node* newNode ) {
	if( newNode == nullptr ) {
		/// @throw invalid_argument If 'newNode' is 'nullptr'
		throw invalid_argument( PROGRAM_NAME ": newNode can't be nullptr.");
	}

	if( !newNode->validate() ) {
		/// @throw domain_error If the 'newNode' is not valid.
		throw domain_error( PROGRAM_NAME ": newNode is not a valid node." );
	}

	if( isIn( newNode ) ) {
		/// @throw logic_error If 'newNode' already exists in the SingleLinkedList.
		throw logic_error( PROGRAM_NAME ": newNode is already in the Singly Linked List.");
	}

	if( !validate() ) {
		/// @throw domain_error If the SingleLinkedList is not valid before the insert.
		throw domain_error(PROGRAM_NAME ": Singly Linked List not valid before the insert.");
	}

	newNode->next = head;
	head = newNode;

	count += 1;

	if( !validate() ) {
		/// @throw domain_error If the SingleLinkedList is not valid after the insert.
		throw domain_error(PROGRAM_NAME ": Singly Linked List not valid after the insert");
	}

}

void SingleLinkedList::remove( Node* oldNode ) {
	if( oldNode == nullptr ) {
		/// @throw invalid_argument If 'oldNode' is 'nullptr'.
		throw invalid_argument( PROGRAM_NAME ": oldNode cannot be nullptr" );
	}

	if( !isIn( oldNode ) ) {
		/// @throw domain_error If 'oldNode' does not exist in the SingleLinkedList.
		throw domain_error( PROGRAM_NAME ": oldNode is not in the Singly Linked List!" );
	}

	assert( validate() );

	if( !validate() ) {
		/// @throw domain_error If the SingleLinkedList is not valid before the removal.
		throw domain_error( PROGRAM_NAME ": Singly Linked List not valid before the removal." );
	}

	Node* parent = getParentOf( oldNode );
	if( parent == nullptr ) {
		head = oldNode->next ;
	} else {
		parent->next = oldNode->next;
	}
	oldNode->next = nullptr ;
	count -= 1 ;

	if( !validate() ) {
		/// @throw domain_error If the SingleLinkedList is not valid after the removal.
		throw domain_error( PROGRAM_NAME ": SLL not valid after the removal." );
	}

}

void SingleLinkedList::removeAll() noexcept {
	head = nullptr;
	count = 0;
}

Node* SingleLinkedList::getRandomNode() const noexcept{
	if( head == nullptr ) {
		return nullptr;
	}

	size_t randomNodeNumber = rand() % count;

	Node* currentNode = head;

	while( currentNode != nullptr && randomNodeNumber-- != 0 ) {
		currentNode = currentNode->next;
	}

	return currentNode;
}

/// Returns "parent" Node (the Node previous of 'thisNode')
///	@param thisNode The Node that the parent Node points to.
Node* SingleLinkedList::getParentOf( const Node* thisNode ) const{
	if( thisNode == nullptr ) {
		/// @throw invalid_argument If 'thisNode' is 'nullptr'.
		throw invalid_argument( PROGRAM_NAME ": thisNode can't be nullptr" );
	}

	if( !thisNode->validate() ) {
		/// @throw domain_error If 'thisNode' is not valid.
		throw domain_error( PROGRAM_NAME ": thisNode is not valid" );
	}

	if( !isIn( thisNode ) ) {
		/// @throw invalid_argument If 'thisNode' does not exist in the SingleLinkedList.
		throw invalid_argument( PROGRAM_NAME ": thisNode is not in container!" );
	}

	assert( validate() );

	if( head == thisNode ) {
		return nullptr ;
	}

	for( Node* counter = head ; counter != nullptr ; counter = counter->next ) {
		if( counter->next == thisNode ) {
			return counter ;  // Found it!
		}
	}

	assert( false ) ; // We should never get here.
	return nullptr;
}

Node* SingleLinkedList::getSmallestNode() const noexcept {
	Node* smallestNode = head;

	if( head == nullptr ) {
		smallestNode = nullptr;
	}

	for( Node* current = head; current != nullptr ; current = current->next ) {
		if( !current->next->isLessThan( smallestNode ) ) {
			smallestNode = current->next;
		}
	}

	return smallestNode;
}

Node* SingleLinkedList::getLargestNode() const noexcept {
	Node* largestNode = head;

	if( head == nullptr ) {
		largestNode = nullptr;
	}

	for( Node* current = head; current != nullptr ; current = current->next ) {
		if( largestNode->isLessThan( current->next ) ) {
			largestNode = current->next;
		}
	}

	return largestNode;

}

void SingleLinkedList::sort() {
	assert( validate() );

	if( count <= 1 ) {  // If the list is empty or only has 1 node, then it's
		return ;         // already sorted
	}

	if( isSorted() ) {  // If the list is already sorted, then we're done
		return ;         // This is important to do with Selection Sorts
	}

	SingleLinkedList sortedList;
	while( count > 0 ) {
		// Find the largest Node
		Node* outerNode = getSmallestNode();
		remove( outerNode );
		sortedList.add( outerNode );
	}
	head = sortedList.head;
	count = sortedList.count;

	/* if( !isSorted() ) { ****NOT INCLUDING UNTIL isSorted() PASSES TESTS
		dump() ;
	}

	assert( isSorted() ) ; */
	assert( validate() );
}

bool SingleLinkedList::isSorted() const noexcept {
	assert( validate() );
	bool result = true;

	if ( count <= 1 ) {
		result = true;
	}

	for( Node* current = head ; current != nullptr ; current = current->next ) {
		if( ! current->isLessThan( current->next ) ) {
			return false;
		}
	}

	return result;
}

/// Prints information of a SingleLinkedList and objects in Container, including address, 'head', and 'count'.
///
/// #### Sample Output
///
///    Object              class               SingleLinkedList
///    Object              this                0x7ffc8f7605d0
///    Container           count               10
///    SingleLinkedList    head                0x7ffc8f7605d0
///    ================================================================================
///    ================================================================================
///    Object              class               Node
///    Object              this                0x7ffc8f7605d0
///    Node                next                0x55622ab40fe0
///    Animal			   kingdom			   Animalia
///    Animal			   gender			   Unknown gender
///    ================================================================================
///    Object              class               Node
///    Object              this                0x55622ab40fe0
///    Node                next                0
///    Animal			   kingdom			   Animalia
///    Animal			   gender			   Unknown gender
///
void SingleLinkedList::dump() const noexcept {
	Node* current = head;

	Container::dump();
	FORMAT_LINE_FOR_DUMP( "SingleLinkedList", "head" ) << head << std::endl;
	FORMAT_HEADING_FOR_DUMP;

	while( current != nullptr ) {
		current->dump();
		current = current->next;
	}
}

/// Validates that SingleLinkedList follows a specified ruleset.
///
///    - Is a valid Container
///    - If 'head == nullptr', then 'count' must be '0' and isEmpty() must be true.
///    - If 'head != nullptr', then 'count' must NOT be '0' and isEmpty() must be false.
///    - Amount of objects in a SingleLinkedList is equal to 'count'
///
/// @return 'true' if SingleLinkedList passes ruleset. 'false' otherwise.
bool SingleLinkedList::validate() const noexcept {
	assert( Container::validate() );
	Node* current = head;
	size_t finalCount = 0;
	bool result = true;

	if( !Container::validate() ) {
		result = false;
	}

	if( head == nullptr ) {
		if( ( count != 0 ) || !isEmpty() ) {
			result = false;
		}
	} else {
		if( ( count == 0 ) || isEmpty() ) {
			result = false;
		}
	}

	while( current != nullptr ) {
		if( !current->validate() ) {
			result = false;
		}

		finalCount += 1;
		current = current->next;
	}

	if( finalCount != count ) {
		result = false;
	}

	return result;
}

// Super secret method to view how loop iterates over SingleLinkedList
// This is mostly because I got lost in traversal logic
/* void SingleLinkedList::traversal() const noexcept{
	int counter = 0;

	for( Node* current = head ; current != nullptr ; current = current->next, counter++ ) {
		cout << counter << endl;
		current->dump();
	}
} */


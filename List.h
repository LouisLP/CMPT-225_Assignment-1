/*
 * List.h
 *
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - (For you to fill: Add the other invariant(s) of this List class.)
 *
 * Author: Louis Lascelles-Palys
 * Date: January 29th, 2022 (latest modification)
 */

#pragma once

// You can add #include statements if you wish.
#include <string>
#include "Patient.h"

using namespace std;


class List  {

private:

/*
 * You can add more attributes to this class,
 * but you cannot remove the attributes below
 * nor can you change them.
 */

	// Data structure's initial capacity
	int const INITIAL_CAPACITY = 10;
	// Data structure
	Patient * elements = new Patient[INITIAL_CAPACITY];
	// Number of elements in the data structure
	int elementCount;
	// Full capacity (n) that can be held
	int capacity;

public:

/*
 * You can add more private methods to this class,
 * but you cannot remove the methods below
 * nor can you change their prototype.
 * Bottom line: you cannot change the public interface of this List class.
 *
 */

	// UNMODIFIED (provided) METHODS

	// Default constructor
	List();

	// Destructor
	// Description: Destruct a List object, releasing heap-allocated memory.
	~List();

	// Description: Returns the total element count currently stored in List.
	int getElementCount() const;

	// Description: Insert an element.
	// Precondition: newElement must not already be in data collection.
	// Postcondition: newElement inserted and elementCount has been incremented.
	bool insert(const Patient& newElement);

	// Description: Remove an element.
	// Postcondition: toBeRemoved is removed and elementCount has been decremented.
	bool remove(const Patient& toBeRemoved);

	// Description: Remove all elements.
	void removeAll();

	// Description: Search for target element.
	//              Returns a pointer to the element if found,
	//              otherwise, returns NULL.
	Patient* search(const Patient& target);

	// Description: Prints all elements stored in List by descending order of search key.
	void printList();

}; // end List.h

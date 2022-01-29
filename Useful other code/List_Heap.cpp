/*
 * List.cpp  ***Using a heap-allocated array***
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates allowed).
 *                   - Position-oriented list.
 *                   - List position of elements start at 1 (not 0). 
 *
 * Inspired on: May 18, 2016 - inspired from List from our textbook.
 * Date: Jan. 22 (latest modification)
 * Author: AL
 */

#include <iostream>
#include "Profile.h"
#include "List.h"  // Header file


// Constructor
List::List() : elementCount(0), maxElements(List::DEFAULT_CAPACITY) {

   cout << "Constructing a List!" << endl;   // For testing purposes ... and curiosity

} 

// Destructor
List::~List() {

	cout << "Destructing a List!" << endl;   // For testing purposes ... and curiosity
   this->clear();
}

// Description: Returns the current number of elements in the List.
int  List::getElementCount() const {
   return elementCount;
} 

// Description: Insert newElement at newPosition in the List. 
// Postcondition: If 1 <= newPosition <= getElementCount() + 1 and the insertion
//                is successful, newElement is at newPosition in the List,
//                other elements, located after newElement, "have moved" 1 position up, 
//                and the returned value is true. Otherwise, false is returned.
bool List::insert(int newPosition, const Profile& newElement) {

   // Validate newPosition: 1) Is it within the range of indices where elements 
   //                          are located in the array?
   //                       2) Still space in the array (array not full yet)?
   bool ableToInsert = (newPosition >= 1) && (newPosition <= elementCount + 1) &&             
                       (elementCount < maxElements);

   if (ableToInsert)
   {   
      // Have we allocated memory for the array yet?
      if ( elementCount == 0 ) {
         elements = new Profile[maxElements];
         if (elements == NULL) {
      		// For debug purposes
		      cout << "new Profile[maxElements] failed!" << endl;
            ableToInsert = false;
            return ableToInsert;
         }            		
      }
      // Make room for new Element by shifting all elements at
      // positions >= newPosition toward the end of the array
      // (no shift if newPosition == elementCount + 1)
      for (int pos = elementCount; pos >= newPosition; pos--)
         elements[pos] = elements[pos - 1];
         
      // Insert new Element
      elements[newPosition - 1] = newElement;
      elementCount++;  // Increase count of elements
   } 

   return ableToInsert;
}  


// Description: Removes the element at position in the List 
// Postcondition: If 1 <= position <= getElementCount() and the removal is successful,
//                the element at position in the List is removed, and
//                other elements "have moved" 1 position down, 
//                and the returned value is true. Otherwise, false is returned.
bool List::remove(int position) {
   bool ableToRemove = (position >= 1) && (position <= elementCount);
   if (ableToRemove)
   {
      // Remove Element by shifting all elements after the one at
      // position toward the beginning of the array
      // (no shift if position == elementCount)
      for (int fromIndex = position, toIndex = fromIndex - 1; fromIndex < elementCount;
	        fromIndex++, toIndex++)
         elements[toIndex] = elements[fromIndex];
         
      elementCount--;  // Decrease count of elements
   } 
   if ( elementCount == 0 ) clear( );

   return ableToRemove;
} 


// Description: Removes all elements from the List.
// Postconditions: List contains no elements and the element count is 0.
void List::clear() {

   delete [] elements;
	elements = NULL;   // a habit to get into
   elementCount = 0;
   return;
} 

   
// Description: Returns the element at position in the List.
// Precondition: 1 <= position <= getElementCount().
Profile List::getElement(int position) const {
   Profile toBeReturned;

   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= elementCount);
   if (ableToGet)
      toBeReturned = elements[position - 1];
   else
   {
      string message = "getElement() called with an empty List or an invalid position.";
      cout << message;  // throw exception may be better
   }  // end if

   return toBeReturned;
} 

   
// Description: Replaces the element at position by newElement in the List.
// Precondition: 1 <= position <= getElementCount().
void List::setElement(int position, const Profile& newElement) {
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= elementCount);
   if (ableToSet)
      elements[position - 1] = newElement;
   else
   {
      string message = "setElement() called with an empty List or an invalid position.";
      cout << message;  // throw exception may be better
   }  // end if
} 

// Description: Prints all elements in the List.
ostream & operator<<(ostream & os, const List& rhs) {
   for (int index = 0; index < rhs.elementCount; index++)
      os << "Element " << index+1 << " is " << rhs.elements[index].getName() << endl;
   
   return os;
}  

//  End of implementation file
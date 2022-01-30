/*
 * List.cpp  ***Using a heap-allocated array***
 *
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates allowed).
 *                   - Position-oriented list.
 *                   - List position of elements start at 1 (not 0).
 *
 * Inspired by: May 18, 2016 - inspired by List from our textbook.
 * Original Author: AL
 * Modified Author: Louis Lascelles-Palys
 * Date: January 29th, 2022 (latest modification)
 */

#include <iostream>
#include "Patient.h"
#include "List.h"  // Header file

// Constructor
List::List() : elementCount(0), capacity(List::INITIAL_CAPACITY) {
   cout << "Constructing a List!" << endl;
}

// Destructor
List::~List() {
	cout << "Destructing a List!" << endl;
   this->clear();
}

// Description: Returns the current number of elements in the List.
int List::getElementCount() const {
   return elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted and elementCount has been incremented.
bool List::insert(const Patient& newElement){

}

// Description: Remove an element.
// Postcondition: toBeRemoved is removed and elementCount has been decremented.
bool List::remove(const Patient& toBeRemoved){
  // Finding the element to be removed
  for (int i = 0; i  < getElementCount(); i++){
    if (elements[i] == toBeRemoved){
      for (int j = i+1; j < elementCount; j++){
        elements[j-1] = elements[j];
      }
      // If it's successfully removed, element count decreases by 1
      elementCount--;
      // And we return true because it was removed successfully
      return true;
    } else{
      return false;
    }
  }
} // End "remove"

// Description: Remove all elements.
void List::removeAll(){
  delete[] elements;
  elements = NULL;
  elementCount = 0;
  return;
}

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target){
  for (int i = 0; i < getElementCount(); i++){
    if (elements[i] == target){
      return &elements[i];
    } else{
      return NULL;
    }
  }
} // End "search"

// Description: Prints all elements stored in List by descending order of search key.
void List::printList(){

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

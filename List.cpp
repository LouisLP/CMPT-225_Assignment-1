/*
 * List.cpp  ***Using a heap-allocated array***
 *
 * Class Description: List data collection ADT for use in Assignment 1 of CMPT225
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates allowed).
 *                   - Position-oriented list.
 *                   - List position of elements start at 1 (not 0).
 *
 * Inspired by: May 18, 2016 - inspired by List from our textbook.
 * Original Author: AL
 * Modified Authors: Louis Lascelles-Palys, Maximilian Amann
 * Date: February 4th, 2022 (latest modification)
 */

#include <iostream>
#include <limits>
#include "Patient.h"
#include "List.h"  // Header file

// Default Constructor (initialization of values, where elementCount=0, and the capacity is set to a "safe" amount (10))
List::List() : elementCount(0), capacity(List::INITIAL_CAPACITY) {
   //cout << "Constructing a List!" << endl;
}

// Default Destructor (deletes the memory allocation of "elements")
List::~List() {
	//cout << "Destructing a List!" << endl;
  delete[] elements;
}

// Description: Returns the current number of elements in the List.
int List::getElementCount() const {
   return elementCount;
}

// Description: Insert an element (while sorting by CareCard number)
// Precondition: newElement must not already be in data collection (duplicate).
// Postcondition: newElement inserted and elementCount has been incremented.
bool List::insert(const Patient& newElement){
  // Find index for insertion (and deal with duplicate cases)
  int insertIndex = 0;

  for(; (insertIndex < getElementCount()) && (newElement.getCareCard() > elements[insertIndex].getCareCard()); insertIndex++);

  if(newElement.getCareCard() == elements[insertIndex].getCareCard()){
    return false;
  }

  // Pull the preceding elements by cascading them down (as long as the insertion index is less than the element count)
  if (insertIndex < getElementCount()) {
    for(int count = getElementCount(); count > insertIndex-1; count--){
      elements[count + 1] = elements[count];
    }
  }

  // Insert the element into the found insertion index
  elements[insertIndex] = newElement;
  // Increment elementCount by 1 if successful
  elementCount++;
  return true;
}

// Description: Remove an element.
// Postcondition: toBeRemoved is removed and elementCount has been decremented.
bool List::remove(const Patient& toBeRemoved){
  // Finding the element to be removed and shifting it up
  for (int i = 0; i  < getElementCount(); i++){
    if (elements[i].getCareCard() == toBeRemoved.getCareCard()){
      for (int shifter = i; shifter < getElementCount(); shifter++) {
        elements[shifter] = elements[shifter+1];
      }

      // If it's successfully removed, element count decreases by 1
      // And we return true because it was removed successfully
      elementCount--;
      return true;
    }
  }
  return false;
} // End "remove"

// Description: Modify an element in the list
// Postcondition: toBeModified is modified.
bool List::modify(const Patient& toBeModified){

  for (int i = 0; i  < getElementCount(); i++){
    if (elements[i] == toBeModified.getCareCard()){
      char input = 0;

      // Printing the "menu"
      cout << endl << "What would you like to modify?" << endl;
      // Modify name
      cout << "To modify the patients name, enter: n" << endl;
      // Modify address
      cout << "To modify the patients address, enter: a" << endl;
      // Modify phone number
      cout << "To modify the patients phone, enter: p" << endl;
      // Modify email
      cout << "To modify the patients email, enter: e" << endl;

      cout << "------------------------------------------------------" << endl;
      cout << "Your choice: " << endl;
      cin >> input;
      // Converting to lowercase if the user inputs an uppercase letter
      input = tolower(input);
      cout << "------------------------------------------------------" << endl;

      string changedInformation = "";
      string modified = toBeModified.getCareCard();
      string information;

      switch(input) {
          case 'n': {changedInformation = "name"; break;}
          case 'a': {changedInformation = "address"; break;}
          case 'p': {changedInformation = "phone"; break;}
          case 'e': {changedInformation = "email"; break;}
          default: cout << "Invalid choice." << endl;
      }

      // Asking for the changed information
      cout << "Enter the patients modified " << changedInformation << ": ";
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      getline(cin,information);

      // Adding the changed information to its respective field
      switch(input) {
          case 'n': {
            elements[i].setName(information);
            break;
            }
          case 'a': {
            elements[i].setAddress(information);
            break;
            }
          case 'p': {
            elements[i].setPhone(information);
            break;
            }
          case 'e': {
            elements[i].setEmail(information);
            break;
            }
          default: cout << "Invalid choice." << endl;
      }
      input = 0;
      return true;
    }
    else{
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
} // End "removeAll"

// Description: Search for target element - returns a pointer to the element if found, otherwise, returns NULL.
Patient* List::search(const Patient& target){
  for (int i = 0; i < getElementCount(); i++){
    if (elements[i] == target){
      cout << "Patient #" << i+1 << ": " << elements[i] << endl;
      return &elements[i];
    } else{
      return NULL;
    }
  }
} // End "search"

// Description: Prints all elements stored in List by descending order of CareCard number.
void List::printList(){
  // Checking if there are any elements in the list. If yes, print them in order
  if (getElementCount() > 0) {
    for (int i = 0; i  < getElementCount(); i++){
      cout << elements[i] << endl;
    }
  }
  else {
    cout << "No patients have been entered." << endl;
  }
} // End "printList"

// Unused functions and operators modifications

  // Description: Returns the element at position in the List.
  // Precondition: 1 <= position <= getElementCount().
  /*
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
  */
  // Description: Prints all elements in the List.
  /*
  ostream & operator<<(ostream & os, const List& rhs) {
     for (int index = 0; index < rhs.elementCount; index++)
        os << "Element " << index+1 << " is " << rhs.elements[index].getName() << endl;

     return os;
  }
  */

//  End of List.cpp

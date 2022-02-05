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
   //cout << "Constructing a List!" << endl;
}

// Destructor
List::~List() {
	//cout << "Destructing a List!" << endl;
  delete[] elements;
}

// Description: Returns the current number of elements in the List.
int List::getElementCount() const {
   return elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted and elementCount has been incremented.
bool List::insert(const Patient& newElement){
  // Find index for insertion (and deal with duplicate cases)
  int insertIndex = 0;

  for(; (insertIndex < getElementCount()) && (newElement.getCareCard() > elements[insertIndex].getCareCard()); insertIndex++);

  if(newElement.getCareCard() == elements[insertIndex].getCareCard()){
    return false;
  }

  // Push the preceding elements by cascading them up 1
  // Insert the element into the found index

  if (insertIndex < getElementCount()) {
    for(int count = getElementCount(); count > insertIndex-1; count--){
    elements[count + 1] = elements[count];
    }
  }

  elements[insertIndex] = newElement;

  // Implement if we need to rezize the list
  // if(capacity == elementCount){
  // }
  elementCount++;
  return true;
}

// Description: Remove an element.
// Postcondition: toBeRemoved is removed and elementCount has been decremented.
bool List::remove(const Patient& toBeRemoved){
  // Finding the element to be removed
  //string toBeRemovedCareCard = toBeRemoved.getCareCard();
  cout << "~ " << toBeRemoved.getCareCard() << " ~" << endl;
  cout << "~ " << elements[0] << " ~" << endl;
  cout << "~ " << elements[1] << " ~" << endl;
  cout << "~ " << elements[2] << " ~" << endl;
  for (int i = 0; i  < getElementCount(); i++){
    if (elements[i] == toBeRemoved.getCareCard()){
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

// Description: Modify an element.
// Postcondition: toBeModified is modified.
bool List::modify(const Patient& toBeModified){
  // Finding the element to be removed
  
  for (int i = 0; i  < getElementCount(); i++){
    if (elements[i] == toBeModified.getCareCard()){
      char input = 0;

      // Printing the "menu"
      cout << "What would you like to modify?" << endl;
      // Modify CareCard
      cout << "To modify the patients CareCard, enter: c" << endl;
      // Modify name
      cout << "To modify the patients name, enter: n" << endl;
      // Modify address
      cout << "To modify the patients address, enter: a" << endl;
      // Modify phone number
      cout << "To modify the patients phone, enter: p" << endl;
      // Modify eMail
      cout << "To modify the patients eMail, enter: e" << endl;

      cout << "------------------------------------------------------" << endl;
      cout << "Your choice: " << endl;
      cin >> input;
      // Converting to lowercase if the user inputs an uppercase letter
      input = tolower(input);
      cout << "------------------------------------------------------" << endl;

      string changedInformation = "";
      string modified = toBeModified.getCareCard();

      switch(input) {
          case 'c': {changedInformation = "CareCard"; break;}
          case 'n': {changedInformation = "name"; break;}
          case 'a': {changedInformation = "address"; break;}
          case 'p': {changedInformation = "phone"; break;}
          case 'e': {changedInformation = "eMail"; break;}
          default: cout << "Invalid choice." << endl;
      }

      cout << "Enter the patients modified " << changedInformation << ": ";

      switch(input) {
          case 'c': {changedInformation = "CareCard"; break;}
          case 'n': {changedInformation = "name"; break;}
          case 'a': {changedInformation = "address"; break;}
          case 'p': {changedInformation = "phone"; break;}
          case 'e': {changedInformation = "eMail"; break;}
          default: cout << "Invalid choice." << endl;
      }

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

// Description: Prints all elements stored in List by descending order of CareCard number.
void List::printList(){
  if (getElementCount() > 0) {
    for (int i = 0; i  < getElementCount(); i++){
      cout << "PATIENT #" << i << ": " << elements[i] << endl;
    }
  }
  else {
    cout << "No patients have been entered." << endl;
  }

}

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
//  End of implementation file

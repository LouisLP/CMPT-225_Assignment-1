/*
 * Patient.cpp
 *
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique CareCard number.
 *                  This CareCard number must have 10 digits.
 *                  This CareCard number cannot be modified.
 *
 * Authors: Louis Lascelles-Palys, Maximilian Amann
 * Date: February 4th, 2022 (latest modification)
 */

// You can add #include statements if you wish.
#include <iostream>
#include <string>
#include "Patient.h"

// Default Constructor
// Description: Create a patient with a CareCard number of "0000000000".
// Postcondition: All data members set to "To be entered",
//                except the CareCard number which is set to "0000000000".
Patient::Patient() {
	careCard = "0000000000";
	name = "To be entered";
	address = "To be entered";
	phone = "To be entered";
	email = "To be entered";
}

// Parameterized Constructor
// Description: Create a patient with the given CareCard number.
// Postcondition: If aCareCard does not have 10 digits, then CareCard is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard) {
// You need to complete this method.
	name = "To be entered";
	address = "To be entered";
	phone = "To be entered";
	email = "To be entered";
	if (aCareCard.length() != 10){
		cout << "CareCard length wasn't entered as 10-digits, defaulting to 0000000000" << endl;
		careCard = "0000000000";
	} else{
		careCard = aCareCard;
	} // End CareCard check
}

// New Parameterized Constructor 2 (all attributes)
// Description: Create a patient with ALL attributes filled (carecard, name, address, phone, and email).
// Postcondition: If aCareCard does not have 10 digits, then CareCard is set to "0000000000".
Patient::Patient(string aCareCard, string aName, string anAddress, string aPhone, string anEmail) {
// You need to complete this method.
	name = aName;
	address = anAddress;
	phone = aPhone;
	email = anEmail;

	if (aCareCard.length() != 10){
		cout << "CareCard length wasn't entered as 10-digits, defaulting to 0000000000" << endl;
		careCard = "0000000000";
	} else{
		careCard = aCareCard;
	} // End CareCard check
}

// Getters and setters
// Description: Returns patient's name.
string Patient::getName() const{
	return name;
} // End of "getName"

// Description: Returns patient's address.
string Patient::getAddress() const{
	return address;
} // End of "getAddress"

// Description: Returns patient's phone.
string Patient::getPhone() const{
	return phone;
} // End of "getPhone"

// Description: Returns patient's email.
string Patient::getEmail() const{
	return email;
} // End of "getEmail"

// Description: Returns patient's CareCard.
string Patient::getCareCard() const{
	return careCard;
} // End of "getCareCard"

// Description: Sets the patient's name.
void Patient::setName(const string aName){
	name = aName;
} // End of "setName"

// Description: Sets the patient's address.
void Patient::setAddress(const string anAddress){
	address = anAddress;
} // End of "setAddress"

// Description: Sets the patient's phone.
void Patient::setPhone(const string aPhone){
	phone = aPhone;
} // End of "setPhone"

// Description: Sets the patient's email.
void Patient::setEmail(const string anEmail){
	email = anEmail;
} // End of "setEmail"

//----------------------------------------------
// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same CareCard number.
bool Patient::operator == (const Patient & rhs) {
	// Compare both Patient objects
	return this->careCard == rhs.getCareCard();
} // end of operator ==

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the CareCard number of "this" Patient object is > the CareCard
//              number of "rhs" Patient object
bool Patient::operator > (const Patient & rhs) {
	// Compare both Patient objects
	return this->careCard > rhs.getCareCard();
} // end of operator >

// Description: Less than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the CareCard number of "this" Patient object is < the CareCard
//              number of "rhs" Patient object.
bool Patient::operator < (const Patient & rhs) {
	// Compare both Patient objects
	return this->careCard < rhs.getCareCard();
} // end of operator <

// For testing purposes!
// Description: Prints the content of "this".
ostream & operator<<(ostream & os, const Patient & p) {
	os << p.careCard << " - Patient: " << p.name << ", "
	   << p.address << ", " << p.phone << ", " << p.email << endl;

	return os;
} // end of operator<<
//----------------------------------------------

// end of Patient.cpp

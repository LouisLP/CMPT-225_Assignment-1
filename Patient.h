/*
 * Patient.h
 *
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique CareCard number.
 *                  This CareCard number must have 10 digits.
 *                  This CareCard number cannot be modified.
 *
 * Author: Louis Lascelles-Palys
 * Date: January 24th, 2022
 */

#pragma once

// You can add #include statements if you wish.
#include <string>

using namespace std;


class Patient {

private:
	// Constant size of our array
	static const int ARRAY_SIZE = 10;
	// Patient's CareCard number (important piece of information)
	string careCard;
	// Patient's name (first and last)
	string name;
	// Patient's address
	string address;
	// Patient's phone number
	string phone;
	// Patient's email address
	string email;

public:

/*
 * You can add more private methods to this class,
 * but you cannot remove the methods below
 * nor can you change their prototype.
 * Bottom line: you cannot change the public interface of this class.
 *
 */

	// Default Constructor
	// Description: Create a patient with a CareCard number of "0000000000".
	// Postcondition: All data members set to "To be entered",
	//                except the CareCard number which is set to "0000000000".
	Patient();

	// Parameterized Constructor
	// Description: Create a patient with the given CareCard number.
	// Postcondition: If aCareCard does not have 10 digits, then CareCard is set to "0000000000".
	//                All other data members set to "To be entered".
	Patient(string aCareCard);

	// New Parameterized Constructor 2 (all attributes)
	// Description: Create a patient with ALL attributes filled (carecard, name, address, phone, and email).
	// Postcondition: If aCareCard does not have 10 digits, then CareCard is set to "0000000000".
	Patient(string aCareCard, string aName, string anAddress, string aPhone, string anEmail);

	// Getters and setters
	// Description: Returns patient's name.
	string getName() const;

	// Description: Returns patient's address.
	string getAddress() const;

	// Description: Returns patient's phone.
	string getPhone() const;

	// Description: Returns patient's email.
	string getEmail() const;

	// Description: Returns patient's CareCard.
	string getCareCard() const;

	// Description: Sets the patient's name.
	void setName(const string aName);

	// Description: Sets the patient's address.
	void setAddress(const string anAddress);

	// Description: Sets the patient's phone.
	void setPhone(const string aPhone);

	// Description: Sets the patient's email.
	void setEmail(const string anEmail);

	// Overloaded Operators
	// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
	//              Returns true if both Patient objects have the same CareCard number.
	bool operator == (const Patient & rhs);

	// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
	//              Returns true if the CareCard number of "this" Patient object is > the CareCard
	//              number of "rhs" Patient object.
	bool operator > (const Patient & rhs);

	// Description: Less than operator. Compares "this" Patient object with "rhs" Patient object.
	//              Returns true if the CareCard number of "this" Patient object is < the CareCard
	//              number of "rhs" Patient object.
	bool operator < (const Patient & rhs);

	// For testing purposes!
	// Description: Prints the content of "this".
	friend ostream & operator<<(ostream & os, const Patient & p);

	// New method: printPatient
	// Description: prints all attributes of "this" patient
	void printPatient();

}; // end of Patient.h

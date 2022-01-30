/*
 * walkIn.cpp
 *
 * Class Description: Main interface of receptionist's access to patient records at walk-in clinic.
 * Class Invariant: --
 *
 * Author: Louis Lascelles-Palys
 * Date: January 29th, 2022
 */

#include <iostream>
#include "Patient.h"
#include "List.h"

using namespace std;

// Description: adds a new patient based off of given Care Card number
void enter(List& patientList){
  string input;
  cout << "You have chosen to enter a new patient." << endl;
  cout << "Please enter the 10-digit CareCard number of the new patient: ";
  cin >> input;

  Patient newPatient = Patient(input);
  // Checking to see if the patient can be added (bool value from List.cpp)
  bool valid = patientList.insert(newPatient);
  if(!valid){
    cout << "Error: unable to insert new patient." << endl;
  } else{
    cout << "New patient has been successfully entered into the system." << endl;
    patientList.printList();
  }
}

// Description: removes a patient based off of given Care Card number
void remove(List& patientList){
  string input;
  cout << "You have chosen to remove a patient." << endl;
  cout << "Please enter the 10-digit CareCard number of the patient you'd like to remove: ";
  cin >> input;

  Patient patientToRemove = Patient(input);
  // Checking to see if the patient can be removed (bool value from List.cpp)
  bool valid = patientList.remove(patientToRemove);
  if(!valid){
    cout << "Error: unable to remove patient. Check your Care Card number and try again." << endl;
  } else{
    cout << "Patient has been successfully removed from the system." << endl;
    patientList.printList();
  }
}

// Description: searches for an existing patient based off of given Care Card number
void search(List& patientList){
  string input;
  cout << "You have chosen to search for a patient." << endl;
  cout << "Please enter the 10-digit CareCard number of the patient you'd like to search for: ";
  cin >> input;

  Patient patientToSearch = Patient(input);
  // Searching for the patient (pointer)
  Patient * patient = patientList.search(patientToSearch);
  if(patient == NULL){
    cout << "Error: unable to find patient." << endl;
  } else{
    cout << "Patient has been successfully found in the system." << endl;
    patientList.printList();
  }
}

// Implement me (add parameter for patient)
void modify(){

}

// Implement me (add parameter for patient)
void printAll(){

}

// Beging main function (giving the receptionist menu options)
int main() {

    List * patients = new List();
    bool done = false;
    char input = 0;

    // Printing the "menu"
    cout << "Welcome to the Walk-in Clinic Patient System!" << endl;

    // Keep displaying options until the user is done
    while(!done){

        cout << "-------------------------------------------------------" << endl;
        // Enter a new patient
        cout << "To enter a patient to the system, enter: e" << endl;
        // Remove a patient
        cout << "To remove a patient from the system, enter: r" << endl;
        // Search for a patient
        cout << "To search for an existing patient, enter: s" << endl;
        // Modify a patient
        cout << "To modify a patient's record, enter: m" << endl;
        // Print all patients (in descending order of CareCard numbers)
        cout << "To list all patients in the system, enter: a" << endl;

        // Exit case
        cout << "To exit, enter: x" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "Your choice: " << endl;
        cin >> input;
        // Converting to lowercase if the user inputs an uppercase letter
        input = tolower(input);
        cout << "------------------------------------------------------" << endl;

        switch(tolower(input)) {
            case 'e': enter(patients); break;
            case 'r': remove(patients); break;
            case 's': search(patients); break;
            case 'm': modify(patients); break;
            case 'a': printAll(patients); break;
            // Exit case (user is "done" when done = true)
            case 'x': cout << "Goodbye!" << endl; done = true; break;
            default: cout << "Invalid choice. Please try again!" << endl;
        }
    }

    return 0;
  } // End main

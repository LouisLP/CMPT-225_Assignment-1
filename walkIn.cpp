#include <iostream>
#include "Patient.h"
#include "List.h"

using namespace std;

// Implement me (add parameter for patient)
void enter(){

}

// Implement me (add parameter for patient)
void remove(){

}

// Implement me (add parameter for patient)
void search(){

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
        // Print all patients (in descending order of care card numbers)
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
            default: cout << "Not sure what you mean. Please try again!" << endl;
        }
    }

    return 0;
  } // End main

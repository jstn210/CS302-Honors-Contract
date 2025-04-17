// NAME: Justin Ly
// ASSIGNMENT: Honors Contract
// PURPOSE: Demonstrates the functions of the Dictionary ADT and creates a contact list

#include "arrayDictionary.h"
#include <string>
#include <iostream>

using namespace std;

void addContacts(ArrayDictionary<string, string>& contacts);

int main(){

    ArrayDictionary<string, string> contacts;
    addContacts(contacts);
    cout << "CONTACTS" << endl;
    cout << contacts;

    string addName, addNumber;
    cout << "NEW CONTACT" << endl;
    cout << "Name: ";
    cin >> addName;
    cout << endl << "Phone Number (###-###-####): ";
    cin >> addNumber;
    cout << endl;
    contacts.add(addName, addNumber);
    cout << "CONTACTS" << endl;
    cout << contacts;

    string remName;

    cout << "REMOVE CONTACT" << endl;
    cout << "Name: ";
    cin >> remName;
    cout << endl;
    contacts.remove(remName);
    cout << "CONTACTS" << endl;
    cout << contacts;

    string searchName;

    cout << "SEARCH CONTACT" << endl;
    cout << "Name: ";
    cin >> searchName;
    cout << "Phone #: " << contacts.getValue(searchName) << endl;

    return 0;
}

void addContacts(ArrayDictionary<string, string>& contacts){
    contacts.add("Gabe", "123-456-7890");
    contacts.add("John", "246-813-5790");
    contacts.add("Daniel", "420-420-4200");
    contacts.add("Ben", "777-888-9999");
    contacts.add("Cole", "909-909-9090");
    contacts.add("Mark", "545-767-1212");
}

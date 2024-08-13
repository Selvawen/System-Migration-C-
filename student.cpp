// student.cpp

#include "student.h"

using namespace std;

// Implement the constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete[], DegreeProgram degreeProgram) {
    setStudentID(studentID);
    setFirstName(firstName);
    setLastName(lastName);
    setEmailAddress(emailAddress);
    setAge(age);
    setDaysToComplete(daysToComplete);
    setDegreeProgram(degreeProgram);
}

// Implement the accessors
string Student::getStudentID() {
    return studentID;
}

string Student::getFirstName() {
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

string Student::getEmailAddress() {
    return emailAddress;
}

int Student::getAge() {
    return age;
}

int* Student::getDaysToComplete() {
    return daysToComplete;
}

DegreeProgram Student::getDegreeProgram() {
    return degreeProgram;
}

// Implement the mutators
void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDaysToComplete(int daysToComplete[]) {
    for (int i = 0; i < 3; i++) {
        this->daysToComplete[i] = daysToComplete[i];
    }
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

// Implement the print() function
void Student::print() {
    cout << getStudentID() << "\t";
    cout << getFirstName() << "\t\t";
    cout << getLastName() << "\t";
    cout << getAge() << "\t\t";
    cout << "{" << getDaysToComplete()[0] << ",";
    cout << getDaysToComplete()[1] << ",";
    cout << getDaysToComplete()[2] << "}\t";

    // Print the enumerated type as a string
    switch (getDegreeProgram()) {
        case SECURITY:
            cout << "SECURITY";
            break;
        case NETWORK:
            cout << "NETWORK";
            break;
        case SOFTWARE:
            cout << "SOFTWARE";
            break;
    }
    cout << endl;
}


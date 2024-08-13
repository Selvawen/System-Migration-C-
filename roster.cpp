// roster.cpp

#include "roster.h"
#include <iostream>
#include <string>

using namespace std;

// Implement the constructor
Roster::Roster() {
    this->lastIndex = -1;
    this->capacity = 5;
    this->classRosterArray = new Student * [capacity];
}

// Implement the destructor
Roster::~Roster() {
    for (int i = 0; i <= lastIndex; i++) {
        delete this->classRosterArray[i];
    }
}

// Parse the student data and add it to the roster
void Roster::parseThenAdd(string studentData) {
    // Check if the roster is full.
    if (lastIndex < 5) {
        lastIndex++; // Update lastIndex

        // Parse the student data.
        size_t rhs = studentData.find(",");
        string studentID = studentData.substr(0, rhs);

        size_t lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        string firstName = studentData.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        string lastName = studentData.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        string emailAddress = studentData.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        int age = stoi(studentData.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        DegreeProgram degreeProgram;
        // Convert the degree program string to an enum.
        if(studentData.substr(lhs, rhs - lhs) == "SECURITY") {
            degreeProgram = SECURITY;
        } else if(studentData.substr(lhs, rhs - lhs) == "NETWORK") {
            degreeProgram = NETWORK;
        } else if(studentData.substr(lhs, rhs - lhs) == "SOFTWARE") {
            degreeProgram = SOFTWARE;
        } else {
            cerr << "INVALID DEGREE PROGRAM!" << endl;
            exit(-1);
        }

        // Add the student to the roster.
        add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);

    } else {
        cerr << "ERROR: The roster is full!" << endl;
        exit(-1);
    }
}

// Add a student to the roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysToComplete[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysToComplete, degreeProgram);
}

// Remove a student from the roster by student ID
void Roster::remove(string studentID) {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i]; // Free memory
            classRosterArray[i] = classRosterArray[lastIndex];
            lastIndex--; // Update lastIndex
            cout << "Removing " << studentID << ":\n\n";
            printAll();
            return; // Exit the function
        }
    }

    // If the loop completes without finding the student, print an error message
    cout << "Removing " << studentID << " again\n\n";
    cout << "The student with the ID: " << studentID << " was not found.\n";
}

// Print all students in the roster
void Roster::printAll() {
    // Sort the roster by student ID
    for (int i = 0; i <= lastIndex; ++i) {
        for (int j = i + 1; j <= lastIndex; ++j) {
            if (classRosterArray[i]->getStudentID() > classRosterArray[j]->getStudentID()) {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[j];
                classRosterArray[j] = temp;
            }
        }
    }

    // Print the roster
    for (int i = 0; i <= lastIndex; ++i) {
        classRosterArray[i]->print();
    }
    cout << endl;
}

// Print the average number of days in courses for a student
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) { // If the student is found
            int* days = classRosterArray[i]->getDaysToComplete(); // Get the days to complete
            cout << "Student ID: " << studentID << ", average days in course is: " << (days[0] + days[1] + days[2]) / 3 << endl;
            return; // Exit the function
        }
    }

    // If the student was not found
    cout << "The student with the ID: " << studentID << " was not found.\n";
}

// Print all invalid email addresses
void Roster::printInvalidEmails() {
    cout << "Displaying invalid emails:\n\n";
    for (int i = 0; i <= lastIndex; ++i) {
        string email = classRosterArray[i]->getEmailAddress();
        // Check for spaces, @, and .
        if ((email.find("@") == string::npos) || (email.find(".") == string::npos) || (email.find(" ") != string::npos)) {
            cout << email << " - is invalid.\n";
        }
    }
    cout << endl;
}

// Print all students in a degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    cout << "\nShowing students in degree program: ";
    switch (degreeProgram) {
        case SECURITY:
            cout << "SECURITY\n";
            break;
        case NETWORK:
            cout << "NETWORK\n";
            break;
        case SOFTWARE:
            cout << "SOFTWARE\n";
            break;
        default:
            cerr << "INVALID DEGREE PROGRAM!" << endl;
            exit(-1);
    }
    cout << endl;
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}

// main.cpp

#include <iostream>
#include "roster.cpp"

using namespace std;

int main() {
    // Print the header
    cout << "C867-Scripting & Programming: Applications\n";
    cout << "Language: C++\n";
    cout << "Student ID: 011493105\n";
    cout << "Name: Benjamin Anderson\n\n";

    // Instantiate the roster
    Roster* classRoster = new Roster();

    // Student data table
    const string studentData[] ={
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Benjamin,Anderson,band752@wgu.edu,30,35,40,55,SOFTWARE"
    };

    // Add each student to the roster
    for (int i = 0; i < 5; ++i) {
        classRoster->parseThenAdd(studentData[i]);
    }

    // Print all students in the roster
    cout << "Displaying all students:\n";
    classRoster->printAll();

    // Print all invalid emails
    classRoster->printInvalidEmails();

    // Print student average days in 3 courses
    for (int i = 0; i < 5; ++i) {
        classRoster->printAverageDaysInCourse("A" + to_string(i + 1));
    }

    // Print all students in a degree program
    classRoster->printByDegreeProgram(SOFTWARE);

    // Remove a student and handle non-existent ID removal
    classRoster->remove("A3");
    classRoster->remove("A3");

    // Release the roster memory.
    classRoster->~Roster();

    return 0;
}
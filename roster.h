// roster.h

#ifndef ROSTER_H
#define ROSTER_H

#include "student.cpp"

using namespace std;

class Roster {
private:
    int lastIndex;
    int capacity;
    Student** classRosterArray;

public:
    // Constructor
    Roster();

    // Destructor
    ~Roster();

    // Member functions
    void parseThenAdd(string studentData); // To parse student data and add it to the roster
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
};

#endif // ROSTER_H
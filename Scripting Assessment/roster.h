#pragma once
#include <iostream>
#include "degree.h"
#include "student.h"
#include <string>
using namespace std;

class Roster {
public:
	void StudentParse(string row);
	void addStudent(string studentID, string firstName, string lastName, string email, int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void removeStudent(string studentID);
	void printAll();
	void printAverageDaysInCourse();
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();

private:
	int studentInd = -1;
	const static int numStudents = 5;
	Student* studentArray[numStudents];
};


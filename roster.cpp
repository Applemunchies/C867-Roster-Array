#include <iostream>
#include "roster.h"
#include "student.h"
#include <string>
#include <sstream>

//Parses data by finding commas to segment data into different variables
void Roster::StudentParse(string studentData) {
	size_t id;
	size_t rest;
	string degreeName;

	id = studentData.find(",");
	string studentID = studentData.substr(0, id);

	rest = id + 1;
	id = studentData.find(",", rest);
	string firstName = studentData.substr(rest, id - rest);

	rest = id + 1; 
	id = studentData.find(",", rest);
	string lastName = studentData.substr(rest, id - rest);

	rest = id + 1;
	id = studentData.find(",", rest);
	string email = studentData.substr(rest, id - rest);

	rest = id + 1;
	id = studentData.find(",", rest);
	int age = stoi(studentData.substr(rest, id - rest));

	rest = id + 1;
	id = studentData.find(",", rest);
	int daysInCourse1 = stoi(studentData.substr(rest, id - rest));

	rest = id + 1;
	id = studentData.find(",", rest);
	int daysInCourse2 = stoi(studentData.substr(rest, id - rest));

	rest = id + 1;
	id = studentData.find(",", rest);
	int daysInCourse3 = stoi(studentData.substr(rest, id - rest));

	rest = id + 1;
	id = studentData.find(",", rest);
	degreeName = studentData.substr(rest, id - rest);

	DegreeProgram degreeprogram = SECURITY;
		if (degreeName == "NETWORK") {
			degreeprogram = NETWORK;
	}
		else if (degreeName == "SOFTWARE") {
			degreeprogram = SOFTWARE;
		}
		this->addStudent(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);

}
//Adds students to Student class and well as adding them into the array.
void Roster::addStudent(string studentID, string firstName, string lastName, string email, int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {

	int daysToComplete[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };


	studentArray[++studentInd] = new Student(studentID, firstName, lastName, email, age, daysToComplete, degreeprogram);
	

};
//Removes students with ID set by parameter in main.cpp. If ID is found it swaps places with the last student in the array and omits it during the print function
void Roster::removeStudent(string studentID) {
	bool studentRemoved = false;
	int i;

	for (i = 0; i <= Roster::studentInd; i++) {
		if (studentArray[i]->GetStudentID() == studentID) {
			studentRemoved = true;

			if (i < numStudents - 1) {
				Student* temp = studentArray[i];
				studentArray[i] = studentArray[numStudents - 1];
				studentArray[numStudents - 1] = temp;
			}

			Roster::studentInd--;
		}
	}
	if (studentRemoved) {
		cout << studentID << " removed from class." << endl;
		cout << endl;
		this->printAll();
	}
	else {
		cout << studentID << " not found." << endl;
	};
}
	
//Prints using fuction in student.cpp
void Roster::printAll() {
	int i;
	for (i = 0; i <= Roster::studentInd; i++) {
			studentArray[i]->print();
	}
}
//Find the average days by using the Mean formula
void Roster::printAverageDaysInCourse() {
	int i;
	int averageAmount;
	for (i = 0; i <= studentInd; i++) {
		averageAmount = studentArray[i]->GetDaysToComplete()[0] + studentArray[i]->GetDaysToComplete()[1] + studentArray[i]->GetDaysToComplete()[2];
			cout << "Average Days In Course for " << studentArray[i]->GetFirstName() << " " << studentArray[i]->GetLastName() << ": " << averageAmount / 3 << endl;
	}
	cout << endl;
}
//Find invalid emails by searching for certain character requirements. Finding the @, . , and making sure there is no space in the email
void Roster::printInvalidEmails() {
	int i;
	string emailAddress;
	bool badEmail = false;

	cout << "Outputting Invalid Emails:" << endl;
	cout << endl;

	for (i = 0; i <= Roster::studentInd; i++) {
		emailAddress = studentArray[i]->GetEmail();
		if (emailAddress.find("@") == string::npos || emailAddress.find(" ") != string::npos || emailAddress.find(".") == string::npos) {

			badEmail = true;

			cout << "Invalid Email: " << studentArray[i]->GetEmail() << endl;
		}
	}
}
//Printing students with the same degree set by the parameter in main.cpp
void Roster::printByDegreeProgram(DegreeProgram degreeprogram) {
	int i;
	cout << "Filtering by Degree Program:" << endl;

	for (i = 0; i <= Roster::studentInd; ++i) {
		if (studentArray[i]->GetDegreeProgram() == degreeprogram) {
			
			studentArray[i]->print();

		}
		cout << endl;
	}
}
//Destructor
Roster::~Roster() {
	int i;

	for (i = 0; i < numStudents; i++) {
		delete studentArray[i];
		studentArray[i] = nullptr;
	}
}
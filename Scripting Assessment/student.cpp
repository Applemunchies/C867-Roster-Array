#include <iostream>
#include "student.h"
using namespace std;


//Setters
void Student::SetStudentId(string studentID) {
	this->studentID = studentID;
	
}
void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::SetLastName(string lastName) {
	this->lastName = lastName;
}
void Student::SetEmail(string email) {
	this->email = email;
}
void Student::SetAge(int age) {
	this->age = age;
}
void Student::SetDaysToComplete(int daysToComplete[]) {
	for (int i = 0; i < daysSize; i++) {
		this->daysToComplete[i] = daysToComplete[i];
	}
}
void Student::SetDegreeProgram(DegreeProgram degreeprogram) {
	this->degreeProgram = degreeProgram;
}
//Getters
string Student::GetStudentID() {
	return this->studentID;
}
string Student::GetFirstName() {
	return this->firstName;
}
string Student::GetLastName() {
	return this->lastName;
}
string Student::GetEmail() {
	return this->email;
}
int Student::GetAge() {
	return this->age;
}
int* Student::GetDaysToComplete() {
	return this->daysToComplete;
}
DegreeProgram Student::GetDegreeProgram() {
	return this->degreeProgram;
}

//Default Constructor. If no values are inputted, default values are outputted.
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < daysSize; i++) {
		this->daysToComplete[i] = 0;
	}
	this->degreeProgram = DegreeProgram::SECURITY;
}

//Constructor for the Student Class when there are values.
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete[], DegreeProgram degreeProgram) 
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = emailAddress;
	this->age = age;
	for (int i = 0; i < daysSize; i++) {
		this->daysToComplete[i] = daysToComplete[i];
	}
	this->degreeProgram = degreeProgram;

}
//Destructor
Student::~Student() {

}

//Print function. Added Extra spaces for Age and Days To Complete for visual clarity
void Student::print() {
	cout << GetStudentID();
	cout << "	First Name: " << GetFirstName();
	cout << "	Last Name: " << GetLastName();
	cout << "	Email: " << GetEmail();
	cout << "		Age: " << GetAge();
	cout << "		Days to Complete: {" << GetDaysToComplete()[0] << "," << GetDaysToComplete()[1] << "," << GetDaysToComplete()[2] << "}";
	cout << "	Degree Program: " << degreeProgramStrings[GetDegreeProgram()];
	cout << endl << endl;
};
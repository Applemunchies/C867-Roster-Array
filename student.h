#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "degree.h"
using namespace std;

class Student {
public:
	const static int daysSize = 3;

public:
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysToComplete[], DegreeProgram degreeProgram);
	~Student();
	
	/*----------------------------------*/
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmail();
	int GetAge();
	int* GetDaysToComplete();
	DegreeProgram GetDegreeProgram();
	/*---------------------------------*/
	void SetStudentId(string studentID);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmail(string email);
	void SetAge(int age);
	void SetDaysToComplete(int daysToComplete[]);
	void SetDegreeProgram(DegreeProgram degreeProgram);

	void print();

	

private :
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysToComplete[daysSize];
	DegreeProgram degreeProgram;
};
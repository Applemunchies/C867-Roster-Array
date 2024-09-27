// Scripting Assessment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;

int main()
{
    //Initiates Roster class named studentArray
    Roster studentArray;
    const int totalStudents = 5;

    const string studentData[] = {
         "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
         "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
         "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
         "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
         "A5,Oscar,Aramburo,oarambu@wgu.edu,24,63,63,63,SOFTWARE"
    };

    cout << "C867" << endl;
    cout << "C++" << endl;
    cout << "007106500" << endl;
    cout << "Oscar Aramburo" << endl;
    cout << endl;

    for (int i = 0; i < totalStudents; ++i) {
        studentArray.StudentParse(studentData[i]);
       
    }

    studentArray.printAll();
    cout << endl;

    studentArray.printInvalidEmails();
    cout << endl;

    studentArray.printAverageDaysInCourse();
    cout << endl;
    
    studentArray.printByDegreeProgram(SOFTWARE);
    cout << endl;

    studentArray.removeStudent("A3");
    
    studentArray.removeStudent("A3");
    
    return 0;   
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

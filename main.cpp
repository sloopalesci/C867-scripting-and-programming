//
//  main.cpp
//  SalesciStudent
//
//  Created by Scott Alesci on 11/5/20.
//

#include <iostream>
#include "roster.hpp"

int main(int argc, const char * argv[]) {
    
    const string studentData[] =

    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Scott,Alesci,salesci@wgu.com,34,30,60,90,SOFTWARE",
    };
    
    const int numStudents = 5;
    Roster classRoster;
    
    for(int i=0; i<numStudents; i++){
        classRoster.parse(studentData[i]);
    }
    
    // Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
    cout << "Scripting and Programming - Applications – C867, C++, Student ID: #001467219, Scott Alesci" << endl << endl;

    cout << "Displaying all Students:" << endl;
    classRoster.printAll();
    cout << endl << endl;
    
    cout << "Displaying invalid emails:" << endl;
    classRoster.printInvalidEmails();
    cout << endl << endl;
        
    cout << "Displaying average number of days for each student:" << endl;
    for(int i=0; i<numStudents; i++){
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    cout << endl << endl;
     
    cout << "Printing students with SOFTWARE degrees:" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    
    cout << "Removing Student with Student ID: A3" << endl;
    classRoster.remove("A3");
    cout << endl << endl;
    
    cout << "Displaying all Students. (Should be missing A3) " << endl;
    classRoster.printAll();
    cout << endl;

    cout << "Removing Student with Student ID A3 (for the second time)" << endl;
    classRoster.remove("A3");
    cout << endl;

    
    
    return 0;
}

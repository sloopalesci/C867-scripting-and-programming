//
//  roster.cpp
//  SalesciStudent
//
//  Created by Scott Alesci on 11/6/20.
//

#include "roster.hpp"

void Roster::parse(string row){
    int rhs = int(row.find(","));
    string studentID = row.substr(0, rhs);
    
    int lhs = rhs + 1;
    rhs = int(row.find(",", lhs));
    string firstName = row.substr(lhs, rhs-lhs);
    
    lhs = rhs + 1;
    rhs = int(row.find(",", lhs));
    string lastName = row.substr(lhs, rhs-lhs);
    
    lhs = rhs + 1;
    rhs = int(row.find(",", lhs));
    string emailAddress = row.substr(lhs, rhs-lhs);
    
    lhs = rhs + 1;
    rhs = int(row.find(",", lhs));
    int age = stoi(row.substr(lhs, rhs-lhs));
    
    lhs = rhs + 1;
    rhs = int(row.find(",", lhs));
    int daysInCourse1 = stoi(row.substr(lhs, rhs-lhs));

    lhs = rhs + 1;
    rhs = int(row.find(",", lhs));
    int daysInCourse2 = stoi(row.substr(lhs, rhs-lhs));
    
    lhs = rhs + 1;
    rhs = int(row.find(",", lhs));
    int daysInCourse3 = stoi(row.substr(lhs, rhs-lhs));

    lhs = rhs + 1;
    rhs = int(row.find(",", lhs));
    string dgr = row.substr(lhs, rhs-lhs);
    DegreeProgram degree = SOFTWARE;
    if(dgr == "SECURITY"){
        degree = SECURITY;
    }
    else if (dgr == "NETWORK"){
        degree = NETWORK;
    }
    
    
    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);

}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram){
    
    int courseArr[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, courseArr, degreeprogram);
}

void Roster::printAll(){
    Student::printHeader();
    for(int i=0; i<=Roster::lastIndex; i++){
        classRosterArray[i]->print();
    }
}

void Roster::printByDegreeProgram(DegreeProgram greePro){
    Student::printHeader();
    for(int i=0; i<=Roster::lastIndex; i++){
        if(Roster::classRosterArray[i]->getDegreeProgram() == greePro){
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}

void Roster::printInvalidEmails(){
    /* Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' '). */
    bool any = false;
    for(int i=0; i<=Roster::lastIndex; i++){
        string studEmail = (classRosterArray[i]->getEmail());
        //if(studEmail.find(' ') == string::npos || studEmail.find('@') != string::npos || studEmail.find('.') != string::npos){
        if(studEmail.find(' ') != string::npos || studEmail.find('@') == string::npos || studEmail.find('.') == string::npos){

            any = true;
            cout << studEmail << endl;
        }
    }
    if(!any) cout << "NONE" << endl;
}

void Roster::remove(string studentID){
    bool success = false;
    for(int i=0; i<=Roster::lastIndex; i++){
        if(classRosterArray[i]->getStudentID() == studentID){
            success = true;
            if (i < numStudents-1){
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents-1];
                classRosterArray[numStudents-1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    if(success){
        cout << studentID << " removed from roster." << endl << endl;
    }
    else cout << studentID << " not found." << endl << endl;
}

void Roster::printAverageDaysInCourse(string studentID){
    for(int i=0; i<=Roster::lastIndex; i++){
        if(classRosterArray[i]->getStudentID() == studentID){
            cout << classRosterArray[i]->getStudentID() << ": " << ((classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[i]->getDaysInCourse()[2])/3) << endl;
        }
    }
    /*for(int i=0; i<=Roster::lastIndex; i++){
        cout << classRosterArray[i]->getStudentID() << ": ";
        cout << ((classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[i]->getDaysInCourse()[2])/3) << endl;
    }
    cout << endl;*/
}

Roster::~Roster(){
    cout << "Destructor Called!" << endl << endl;
    for(int i=0; i<numStudents; i++){
        cout << "Destroying Student #" << i+1 << endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

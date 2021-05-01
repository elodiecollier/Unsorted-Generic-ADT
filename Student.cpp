#include "Student.h"
#include "UnsortedList.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Student::Student() {
  studentID = 0;
  studentName = "";
} //Student

Student::Student(int ID, string Name) {
  studentID = ID;
  studentName = Name;
} //Student

int Student::getStudentID() {
  return studentID;
} //getStudentID

string Student::getStudentName() {
  return studentName;
} //getStudentName

void Student::setStudentID(int newID) {
  studentID = newID;
  return;
} //setStudentID

void Student::setStudentName(string newName) {
  studentName = newName;
} //setStudentName


bool Student::operator==(Student A) const {
  if (studentID == A.getStudentID()) {
    return true;
  } //if
  return false;
} //operator==

void Student::operator=(Student A) {
  studentID = A.getStudentID();
  studentName = A.getStudentName();
} //operator=

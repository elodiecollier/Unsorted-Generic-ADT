#ifndef STUDENT_H 
#define STUDENT_H 
#include<string>
#include "UnsortedList.h"

using namespace std;
 

class Student {

public:

  Student();
  Student(int ID, string Name);
  int getStudentID();
  string getStudentName();
  void setStudentID(int newID);
  void setStudentName(string newName);
  bool operator==(Student A) const;
  void operator=(Student A);  
  
private:
  
  int studentID;
  string studentName;
  
}; //Student
#endif

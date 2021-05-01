// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include "UnsortedList.cpp"
#include "Student.h"
using namespace std;
void testIntegerList();
void testStudentList();
int main()
{
	int datatype;
	// Prompt user to enter type of elements 
	cout << "Enter Elements Type\n1 for integer\n2 for Student\n";
	cin >> datatype;
	switch (datatype)
	{
	case 1: testIntegerList();
		    break;
	case 2: testStudentList();
		    break;
	}
	//Ö.append any needed code here
	return 0;
}


void testIntegerList()
{
	UnsortedList<int> list(5);
	string command;
	ifstream inFile;
	ofstream outFile;
	inFile.open("intcommands.txt");
	outFile.open("outFile.txt");
	int number;
	inFile >> command; // read commands from a text file

	while (command != "Quit")
	{
		try

		{
			if (command == "MakeEmpty")
				(list.makeEmpty());

			else if (command == "IsEmpty")
				if (list.isEmpty())
					outFile << "list is empty\n";
				else
					outFile << "list is not empty\n";
			else if (command == "IsFull")
			{
				if (list.isFull())
					outFile << "List is full\n";
				else
					outFile << "List is not full\n";
			}
			else if (command == "PutItem")
			{
				inFile >> number;
				list.putItem(number);
			}
			else if (command == "DeleteItem")
			{
				inFile >> number;
				list.deleteItem(number);
			}

			else if (command == "GetLength")
				outFile << list.getLength() << "\n";
			else if (command == "PrintList")
			{
				outFile << "List Items: ";
				int value;
				for (int index = 0; index < list.getLength(); index++)
				{
					value = list.getAt(index);
					outFile << value << " ";
				}
				outFile << "\n";
			}

			else if (command == "GetAt")
			{
				int index;
				inFile >> index;
				outFile << "Item at index " << index << " is:" << list.getAt(index) << endl;
			}
			else
				outFile << "Unrecognized command";
			inFile >> command;

		} // try

		catch (FullList)
		{
			outFile << "List is full, Insertion failed" << endl;
			inFile >> command;
		}
		catch (DuplicateItem)
		{
			outFile << "Duplicate Item, Insertion failed" << endl;
			inFile >> command;
		}
		catch (OutOfBound)
		{
			outFile << "Index is out of range" << endl;
			inFile >>command;
		}
		catch (ItemNotFound)
		{
			outFile << "Item is not in the list" << endl;
			inFile >> command;
		}
	} // while
} // testIntegerList

void testStudentList() 
{
  UnsortedList<Student> list(5);
  string command;
  ifstream inFile;
  ofstream outFile;
  inFile.open("studcommands.txt");
  outFile.open("outFile.txt");
  int ID;
  string Name;
  Student stud;
  inFile >> command;

  while (command != "Quit") {
    
    try
      {

	if (command == "MakeEmpty")
	  (list.makeEmpty());
	
	else if (command == "IsEmpty")
	  if (list.isEmpty())
	    outFile << "list is empty\n";
	  else
	    outFile << "list is not empty\n";
	else if (command == "IsFull")
	  {
	    if (list.isFull())
	      outFile << "List is full\n";
	    else
	      outFile << "List is not full\n";
	  }
	else if (command == "PutItem")
	  {
	    inFile >> ID;
	    inFile >> Name;
	    stud.setStudentID(ID);
	    stud.setStudentName(Name);
	    list.putItem(stud);
	  } //PutItem
	else if (command == "DeleteItem")
	  {
	    inFile >> ID;
	    inFile >> Name;
	    stud.setStudentID(ID);
	    stud.setStudentName(Name);
	    list.deleteItem(stud);
	  }
	else if (command == "GetLength")
	  outFile << list.getLength() << "\n";
	else if(command == "PrintList")
	  {
	    outFile << "List Items: ";
	    for (int index = 0; index < list.getLength(); index++) {
	      stud = list.getAt(index);
	      ID = stud.getStudentID();
	      Name = stud.getStudentName();
	      outFile << ID << " " << Name << " ";
	    } //for
	    outFile << "\n";
	  }
	else if (command == "GetAt")
	  {
	    int index;
	    inFile >> index;
	    stud = list.getAt(index);
	    ID = stud.getStudentID();
	    Name = stud.getStudentName();
	    outFile << "Item at Index " << index << " is: " << ID << " " << Name << endl;
	  } //GetAt
	else
	  outFile << "Unrecognized command";
	inFile >> command;
      } //try
    
    catch (FullList)
      {
	outFile << "List is full, Insertion failed" << endl;
	inFile >> command;
      }
    catch (DuplicateItem)
      {
	outFile << "Duplicate Item, Insertion failed" << endl;
	inFile >> command;
      }
    catch (OutOfBound)
      {
	outFile << "Index is out of range" << endl;
	inFile >>command;
      }
    catch (ItemNotFound)
      {
	outFile << "Item is not in the list" << endl;
	inFile >> command;
      } //catch
    
} //while
}// test StudentList

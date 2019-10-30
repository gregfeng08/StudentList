#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip> 

using namespace std;
/*
Name: Gregory Feng
Date: 10/30/19
Desc: This program makes use of a struct to create a list of students and their information ranging from their GPA, ID, First name, and Last name. These values can be inputted, deleted by ID, added, and there is also a quit function that clears everything.
 */

struct Student { //Structure Definition
  char firstName[10];
  char lastName[10];
  int ID;
  float GPA;
};

int main() {
  bool quit = false; //While true loop until quit
  vector<Student*>*studentList = new vector<Student*>; //Vector Pointer Definition
  while (quit == false) {
    char input[10];
    int size = 0;
    float GPArounded = 0;
    cout << "Input a command (ADD/PRINT/DELETE/EXIT)" << endl; 
    cin >> input;
    if (strcmp(input, "ADD") == 0) { //When adding a new student
      studentList->push_back(new Student()); //Add new student struct
      cout << "ID?" << endl;
      cin >> studentList->at(studentList->size()-1)->ID; //Put it into the id
      cout << "First Name?" << endl;
      cin >> studentList->at(studentList->size()-1)->firstName; 
      cout << "Last Name?" << endl;
      cin >> studentList->at(studentList->size()-1)->lastName;
      cout << "GPA?" << endl;
      cin >> studentList->at(studentList->size()-1)->GPA;
      size++; //My weird adding way
    }
    if (strcmp(input, "DELETE") == 0) { //When deleting a student
      int IDInput = 0;
      cout << "What ID do you want to delete?" << endl; 
      cin >> IDInput; 
      vector<Student*>::iterator i;
      for (i = studentList->begin(); i != studentList->end(); i++) { //Use an iterator to look through all of the arrays and find the one inputted
	if ((*i)->ID == IDInput) {
	  studentList->erase(i); //Erase that specific ID
	  cout << "Cleared!" << endl;
	  break; //Break out when you find so tha tyou don't have to go through all of them
	}	
      }
    }
    if (strcmp(input, "PRINT") == 0) { //If they want to print
      vector<Student*>::iterator i;
      double GPArounding = 0; //Something that can be deleted to make the code more efficient
      for (i = studentList->begin(); i != studentList->end(); i++) {
	GPArounding = (*i)->GPA;
	cout <<(*i)->firstName << " " <<(*i)->lastName << ", " <<(*i)->ID << ", " << setprecision(3) << GPArounding << endl; //Print everything through the iterator and make sure to have 3 sig figs
      }
    }
    if (strcmp(input, "EXIT") == 0) { //If they want to exit
      vector<Student*>::iterator i;
      for (i = studentList->begin(); i != studentList->end(); i++) { //Loop through everything w/iterator
	studentList->erase(i); //Erase everything
	cout << "All entries have been cleared!" << endl;
      }
      cout << "Bye!" << endl; //Bye
      quit = true; //Get out of the while loop
    }

  }
}
 

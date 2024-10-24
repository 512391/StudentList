#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>

/*
  Author: Jay Williamson
  Date: 10/24/2024
  This program maintains a list of students which can be added to or deleted from
  you can also print the students and type QUIT to exit
 */

using namespace std;


//Student define
struct Student
{
  char firstName[20];
  char lastName[20];
  float GPA;
  int id;
};

//Prints all of the student
 void printStudents(vector<Student*>& students)
 {
   //creates an iterator to go through the students  
          for (vector<Student*>::iterator it = students.begin() ; it != students.end(); ++it) {
	    //prints out the students
	    cout << (*it)->firstName << " " << (*it)->lastName << "\n";

	    //makes it so there are 2 decimal places
	    cout << fixed;
	    cout << setprecision(2);
	    cout << (*it)->GPA << "\n";
	    
	    cout << (*it)->id << "\n";
	  }
 }

//Makes and returns a new students
Student* makeStudent()
{
  //variables for the student
  char firstName[10] = {};
  char lastName[10] = {};
  float GPA = 0;
  int id = 0;

  //gets the students info
          cout << "Enter Student First Name\n";
          cin >> firstName;
	  cout << "Enter Student Last Name\n";
          cin >> lastName;
          cout << "Enter GPA\n";
          cin >> GPA;
          cout << "Enter ID\n";
          cin >> id;

	  //creates the new students
          Student* newStudent = new Student();

	  //copies all of the info into the student
          strcpy(newStudent->firstName, firstName);
	  strcpy(newStudent->lastName, lastName);
          newStudent->GPA = GPA;
          newStudent->id = id;
	  
	  return newStudent;
}

int main()
{
  //the vector that holds all of the students
  vector<Student*> students;

  //the input
  char input[7] = {' ', ' ', ' ', ' ', ' ', ' ', ' '};
  const char emptyInput[7] = {' ', ' ', ' ', ' ', ' ', ' ', ' '};

  //gets initial input
  cout << "Enter one of the following inputs, PRINT. ADD, DELETE, or QUIT \n";
  cin >> input;

//checks if it should quit and end
  while(strncmp(input, "QUIT", 4) != 0)
    {
      //Checks if it is adding a student
      if(strncmp(input, "ADD", 3) == 0)
	{
	  Student* st = makeStudent();

	  //adds the student that was made to the vector
	  students.push_back(st);
	}//Checks if it should print the students
      else if(strncmp(input, "PRINT", 5) == 0)
	{
	  printStudents(students);
	}//Checks if it should delete a student
      else if(strncmp(input, "DELETE", 6) == 0)
	{
	  int id = 0;
	  //gets an id to check for
	  cout << "Enter an ID to delete \n";
	  cin >> id;

	  //index of student to delete
	  int i = 0;
	  //checks if it has already found a student to delete
	  bool hasReached = false;

	  //makes an iterator to go through the students
	  for (std::vector<Student*>::iterator it = students.begin() ; it != students.end(); ++it)
	    {
	      //checks if this is the student to delete and it hasnt chosen a student to delete yes
	      if((*it)->id == id && !hasReached)
		{
		  hasReached = true;
		}
	      else if ((*it)->id != id && !hasReached)
		{
		  ++i;
		}
		
	    }//checks if there is a studen to delete
	  if(hasReached)
	    {
	      //stores it so it can fully delete the student lates
	      Student* student = students.at(i);
	      //removes the student from the vector
	      students.erase(students.begin() + i+1);
	      //fully deletes the student
	      delete student;
	    }
	  else
	    {
	      cout << "invalid id \n";
	    }
	}

      //clears the input array
      for(int i = 0; i < 7; i++)
	{
	  input[i] = emptyInput[i]; 
	}

      //gets next input
      cout << "Enter one of the following inputs, PRINT. ADD, DELETE, or QUIT \n";
      cin >> input;
    }
  
  cout << "bye bye";

  return 0;
}

#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

//Student struct
struct student
{
   char firstName[30];
   char lastName[30];
   int studentID;
   float GPA;
};

//Prototypes
void add(vector<student*> &vect);
void printStudents(vector<student*> vect);
void deleteStudent(vector<student*> &vect);

//Loops to run commands
int main()
{
  vector<student*> studentList; //Vector of pointers to students structs
  bool quit = false; //Flip to quit
  char actions[4][7] = {"ADD", "DELETE", "PRINT", "QUIT"}; //Allowed actions to do

  //DEBUG
  //int iterations = 0;
  
  //Loops and asks for actions each time
  while(!quit)
    {
      //Quit
      if(quit) {return 0;}
  
      //Get action
      cout << "What is your action? (ADD, DELETE, PRINT, or QUIT)" << &endl;
      char action[6];
      cin.get(action, 7);

      //Print which action
      //cout << "Debug; action: " << action << &endl;

      if(strcmp(action, actions[0]) == 0) {add(studentList);} //Add  
      else if(strcmp(action, actions[1]) == 0) {deleteStudent(studentList);} //Delete
      else if(strcmp(action, actions[2]) == 0) {printStudents(studentList);} //Print
      else if(strcmp(action, actions[3]) == 0) {quit = !quit;} //Quit

      action[0] = '\0'; //Reset action

      //iterations++;
    }
}

void add(vector<student*> &vect)
{
  //Get input
  char firstName[30];
  cout << "What is the first name of the student to add?" << &endl;
  cin.ignore();
  cin.get(firstName, 31);

  char lastName[30];
  cout << "What is the last name of the student to add?" << &endl;
  cin.ignore();
  cin.get(lastName, 31);
  
  int studentID = 0;
  cout << "What is the ID of the student to add?" << &endl;
  cin >> studentID;
  cin.ignore();
  
  float GPA = 0.0;
  cout << "What is the GPA of the student to add?" << &endl;
  cin >> GPA;
  cin.ignore();

  //Make struct
  student* newStudent = new student;
  strcpy((*newStudent).firstName, firstName);
  strcpy((*newStudent).lastName, lastName);
  (*newStudent).studentID = studentID;
  (*newStudent).GPA = GPA;

  //Add struct to vector
  vect.push_back(newStudent);
}

void printStudents(vector<student*> vect)
{
  cout << "Students" << &endl;
  for(int i = 0; i < vect.size(); i++)
    {
      cout << fixed << setprecision(2);
      cout << (*vect[i]).firstName << " " << (*vect[i]).lastName << ", " << (*vect[i]).studentID << ", " << (*vect[i]).GPA << &endl;
    }
  cin.ignore();
}
  
void deleteStudent(vector<student*> &vect)
{
  int ID = 0;
  cout << "What is the ID of the student to delete?" << &endl;
  cin >> ID;
  cin.ignore();
  
  for(int i = 0; i < vect.size(); i++)
    {
      if((*vect[i]).studentID == ID)
	{
	  delete vect[i];
	  vect.erase(vect.begin() + i);
	  return;
	}
    }
}

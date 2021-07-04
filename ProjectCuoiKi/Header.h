#ifndef Header_h
#define Header_h
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student
{
	string no;
	string student_id;
	string first_name;
	string last_name;
	string gender;
	string day_of_birth;
	string month_of_birth;
	string year_of_birth;
	string social_id;
};

struct Node
{
	Student* data;
	Node* next;
};

struct Class
{
	char* class_name;
	Node* head;
	Node* tail;
};

struct Node_class
{
	Class* data;
	Node_class* next;
};

struct School_year
{
	int the_beginning_year;
	int the_end_year;
	Node_class* head;
	Node_class* tail;
};

//6to11
struct course
{
	//start date-end date
	int startDay0;
	int startMonth0;
	//int endYear0;
	int endDay0;
	int endMonth0;
	//session
	int firstDay;
	int firstSession;
	int secondDay;
	int secondSession;
	// info course
	char* courseID;
	char* courseName;
	char* teacherName;
	int numberCredits;
	int maxStudentCourse;
};

struct NODE
{
	course* data;
	NODE* pNext;
};

struct Semester
{
	int createASemester;
	int schoolYear;
	int startDay;
	int startMonth;
	int endDay;
	int endMonth;
	NODE* pHead;
	NODE* pTail;
};

bool checkDate(string day, string month, string year);
void enterTheNameOfClass(char*& name);
void enterTheNameOfClass(char*& name);
Student* infoStudent();
Node* createNode(Student* data);
Node_class* createNodeClass(Class* data);
void createSchoolYear(School_year*& sy);
void createClass(School_year*& school, Class*& classes);
void addClassToSchoolYear(School_year*& sy, Class* cl);
void addStudentToClass(Class*& cl, Student* st);
void inputClass(School_year*& sy);
void readToFile(char* file_name, School_year*& sy, char* name);
void inputStudentToClass(School_year*& school);

#endif
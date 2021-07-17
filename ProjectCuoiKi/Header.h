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
	string the_course_was_register;
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
	int theBeginningYear;
	int theEndYear;
	Node_class* head;
	Node_class* tail;
};

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

struct LIST
{
	NODE* pHead;
	NODE* pTail;
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

struct listStudent
{
	Node* pHead;
	Node* pTail;
};

struct listCourse
{
	NODE* pHead;
	NODE* pTail;
};

struct Scoreboard
{
	float finalMarks;
	float GPA;
	float overallGPA;
};

void registerAAcoount();
bool checkLoggin(string username, string password);
void changePassword();

//Check&convert
bool checkName(char* name1, char* name2);
bool checkDate(string day, string month, string year);
const char* checkOrder(int n);
bool checkStartDateInCourse(int day_course, int month_course, int day_semester, int month_semester);
bool checkEndDateInCourse(int day_course, int month_course, int day_semester, int month_semester);
const char* convertDay(int day);
const char* convertSession(int session);

//1to5
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
void ouputInfoStudent(Student* st);

// 6 - 11 
NODE* createNodeCourse(course* data);
void createASemester(Semester*& se);
void createSemester(Semester*& se);
void addTail(Semester*& se, course* c);
course* createACourseRegistrationSession(Semester* se, course* c);
void addACourseToThisSemester(Semester*& se, course* c);
void outputCourse(course* c);


//12 - 20
void initListStudent(listStudent& ls);
void initListCourse(listCourse& lc);
void enrollACourse(Semester*& se, Student*& st, listStudent& ls, listCourse& lc);
void addTailStudent(listStudent& ls, Node* p);
void addTailCourse(listCourse& lc, NODE* k);
Node* createNodeStudent(Student* data);
void outputListOfEnrolledCourse(listCourse lc);
void deleteHeadCourse(listCourse& lc);
void deleteTailCourse(listCourse& lc);
void removeACourseFromEnrolledList(listCourse& lc);
void outputListOfYourCourse(listCourse lc);
void outputListOfClasses(School_year* sy);
void outputListOfStudentInAClass(School_year* sy, char* name);

#endif
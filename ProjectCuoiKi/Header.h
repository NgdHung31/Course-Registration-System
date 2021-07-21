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

struct listStudent
{
	Node* pHead;
	Node* pTail;
};

struct course
{
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
	//List student enroll in course
	listStudent list_student;
};

struct NODE
{
	course* data;
	NODE* pNext;
};

struct session
{
	int startDay0;
	int startMonth0;
	int endDay0;
	int endMonth0;
};

struct listCourse
{
	NODE* pHead;
	NODE* pTail;
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
void printInfo1Class(School_year* sy, char* name);
void printAllClass(School_year* sy);
void removeHeadSchoolYear(School_year*& sy);
void removeTailSchoolYear(School_year*& sy);
bool removeClass(School_year*& sy);
void removeHeadClass(Class*& cl);
void removeTailClass(Class*& cl);
bool removeStudent(School_year*& sy);

// 6 - 11 
NODE* createNodeCourse(course* data);
void createASemester(Semester*& se);
void createSemester(Semester*& se);
void addTail(Semester*& se, course* c);
void createACourseRegistrationSession(Semester* se, course*& c, session& ss);
course* createACourse(Semester*& se, course* c);
void outputCourse(course* c);
void printList(Semester*& se);
void updateInformation(Semester*& se);
void deleteHead(Semester*& se);
void deleteTail(Semester*& se);
bool deleteCourse(Semester*& se);

//12 - 20
void initListStudent(listStudent& ls);
void initListCourse(listCourse& lc);
void enrollACourse(Semester*& se, Student*& st, listStudent& ls, listCourse& lc);
bool checkExistingCourse(listCourse& lc, int cFirstDay, int cFirstSession, int cSecondDay, int cSecondSession);
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
void outputListOfCourses(Semester* se);
void outputListOfStudentsInACourse(listStudent ls);



//21-25
void outputListOfStudentsInACourseToCSVfile(Semester*& se);
#endif

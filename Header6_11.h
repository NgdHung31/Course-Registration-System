#ifndef Header6_11_h
#define Header6_11_h
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

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

void create_semester(Semester*& se);
NODE* createNODE(course* data);
void createSemester(Semester*& se);
course* Create_a_course_registration_session(Semester* se, course* rs);
void Add_a_course_to_this_semester(Semester*& se , course* c);
void addTail(Semester*& se, course* c);
void printList(Semester*& se);
void Update_information(Semester*& se);
bool deleteCourse(Semester*& se);
bool check_name(char* name1, char* name2);

#endif

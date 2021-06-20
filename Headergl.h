#ifndef Headergl_h
#define Headergl_h
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

struct course
{
	//start date-end date
	int startDay0;
	int startMonth0;
	int endYear0;
	int endDay0;
	int endMonth0;
	//session
	int firstDay;
	int firstSession;
	int secondDay;
	int secondSession;
	// info course
	int courseID;
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

struct semester
{
	int createASemester;
	int schoolYear;
	int startDay;
	int startMonth;
	int endDay;
	int endMonth;
	LIST* listCourses;
};

void createList(LIST*& l);
NODE* createNODE(course* data);
semester* createSemester();
course* registrationSession(semester*& se, int year);
course* createCourse();
void addTail(course* c, LIST*& l);
void printList(LIST* l);
void addNode_p_AfterNode_q(course* c, LIST*& l, int& x, NODE* p);
void deleteCourse(LIST*& l, int& x);
//bool check_name(char* name1, char* name2);

#endif

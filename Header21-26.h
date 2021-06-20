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
struct Course
{
	int course_id;
	int course_name;
	int teacher_name;
	int number_of_credits;
	int max_students;
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
	Semester semester_of_school_year;
	Node_class* head;
	Node_class* tail;
};

struct Semester
{
	list_of_course_in_one_semester semester_1;
	list_of_course_in_one_semester semester_2;
	list_of_course_in_one_semester semester_3;
};

struct Course
{
	string ID;
	string name_of_course;
	string name_of_teacher;
	string credits;
	string number_of_students;
	string schedule;
	list_student_in_a_course list;
};

struct node_student_in_a_Course
{
	Student data;
	node_student_in_a_Course* next;
};

struct list_student_in_a_course
{
	node_student_in_a_Course* head;
	node_student_in_a_Course* tail;
};

struct node_course
{
	Course data;
	node_course* next;
};

struct list_of_course_in_one_semester
{
	node_course* head;
	node_course* tail;
};

//struct School_year
//{
//	int the_beginning_year;
//	int the_end_year;
//	List_class* List_class;
//};

struct Scoreboard
{
	float final_marks;
	float GPA;
	float overall_GPA;
};
#ifndef Header1_5_h
#define Header1_5_h
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
	Node_class* head;
	Node_class* tail;
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

Node* create_node(Student* data);
Node_class* create_node_class(Class* data);
Student* info_student();
bool check_name(char* name1, char* name2);
bool check_date_of_birth(string day, string month, string year);
void Enter_the_name(char*& name);
void register_a_account();
bool check_loggin(string username, string password);
void change_password();
void create_school_year(School_year*& sy);
void create_class(School_year*& school, Class*& classes);
void Add_class_to_school_year(School_year*& sy, Class* cl);
void Add_student_to_class(Class*& cl,Student* st);
void Input_class(School_year*& sy);
void read_to_file(char* file_name, School_year*& sy, char* name);
void Input_student_to_class(School_year*& school);
void print_info_1_class(School_year* sy, char* name);
void print_all_class(School_year* sy);
bool remove_class(School_year*& sy);
bool remove_student(School_year*& sy);
void ouput_info_student(Student* st);
#endif
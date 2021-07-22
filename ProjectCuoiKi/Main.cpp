#include "Header.h"

int main()
{
	School_year* school = new School_year;
	Semester* se = new Semester;
	course* c = new course;
	Student* st = new Student;
	listStudent ls;
	listCourse lc;
	initListCourse(lc);
	initListStudent(ls);

	menu(school, se, c, st, ls, lc);

	return 0;
}


#include "Header21-26.h"

node_course* create_node_course(Course data)
{
	node_course* new_node = new node_course;
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void add_tail_list_student_in_a_course(list_of_course_in_one_semester& l, Course data)
{
	node_course* new_node = create_node_course(data);
	if (l.head == NULL)
	{
		l.head = l.tail = new_node;
	}
	else
	{
		l.tail->next = new_node;
		l.tail = new_node;
	}
}


void output_student_to_csv_flie(School_year& sy)
{
	cout << "Input school year: ";
	cout << "    The beginning of school year: "; cin >> sy-
	cout << "    The end of school year: "
}
CSC10002 - Programming Techniques – Final Project – A
Course Registration System
Class: 20CTT3, 20KDL1
There are 2 types of users in the system.
Academic staff members, for example, Ms. Le Thi Anh Thao, Ms. Nguyen Thi Minh Phuc, Ms.
Hoang Thanh Tu...
Students: APCS, CLC, VP...
He/she has to log in to the system.
Then, he/she can view his/her profile info, change password, or log out of the system
At the beginning of a school year (often in September), an academic staff member will:
1. Create a school year (2020-2021, for example)
2. Create several classes for 1st year students. For example: class 20APCS1, class 20APCS2, class 20CLC1..., class 20CLC11, class 20VP...
3. Add new 1st year students to 1st-year classes.
4. For quick input, he/she can import a CSV file containing all students in a specific class to the system, instead of adding one by one: No, Student ID, First name, Last name, Gender, Date of Birth, Social ID.
5. He/she does not need to add 2nd year, 3rd year, or 4th-year students, because these students had been added in the previous years.
There are 3 semesters in a school year: Semester 1 (Fall), Semester 2 (Summer), and Semester 3
(Autumn).
At the beginning of a semester, an academic staff member will:
6. Create a semester: 1, 2, or 3, school year, start date, end date. Choose the school year that the newly created semester belongs to. The created semester will be the current /the default semester for all the below actions.
7. Create a course registration session: start date, end date.
8. Add a course to this semester: course id, course name, teacher name, number of   the maximum number of students in the course (default 50), day of the week, and the S2 (09:30), S3(13:30) and S4 (15:30)). A course will be taught in 2 sessions in a week.
 9. View list of courses. 
10. Update course information. 
11. Delete a course.
 
When a course registration session is active, a student can:
12. Log in to the system, of course.
13. Enroll in a course. If 2 sessions of the new course are conflicted with existing enrolled
course sessions, he/she cannot enroll in it. He/she can enroll in at most 5 courses in a
semester.
14. View list of enrolled courses.
15. Remove a course from the enrolled list.
When a course registration session is close, a student still can:
16. View list of his/her courses. He/she will study these courses in this semester.
At any time, an academic staff member can:
17. View list of classes.
18. View list of students in a class (for example, 20APCS1...)
19. View list of courses.
20. View list of students in a course

At the end of a semester, an academic staff member can:
21. Export list of students in a course to a CSV file
22. Import the scoreboard of a course. A scoreboard will have at least the following columns: No, Student ID, Student Full Name, Total Mark, Final Mark, Midterm Mark, Other Mark. (An academic staff member will export the list of students in a course, send the CSV file to the teacher, the teacher will enter student results in this file, send it back to the staff, and then the staff will import the scoreboard to the system).
23. View the scoreboard of a course.
24. Update a student result.
25. View the scoreboard of a class, including final marks of all courses in the semester, GPA in this semester, and the overall GPA. When the scoreboard has been published (by the academic staff member), a student can:
        26. View his/her scoreboard.
Technical requirements
1. The text files, the binary files are ok. The databases are not allowed.
2. C++ language.
3. Only dynamic arrays or linked lists are allowed.
4. char[], char*, and string are allowed.
5. Use Github to control your source code versions. Each member must have at least 20
commits and must spread on at least 15 different days.

// Author: Jose Lael Louis

#ifndef COURSE_H
#define COURSE_H
#include <vector>

class Student;

class Course  // class definition for Course
{
private:
	std::string courseID;
	std::string title;
	int capacity;
	std::vector<Course> prerequisites;
	std::vector<Student> registeredStudents;
public:
	Course(std::string ID, std::string title, int capacity);
	Course();
	void showCourseInfo();
	void registerStudent(Student student, Course &course);
	void showRegisteredStudents(Course &course);
	bool hasCapacity();
	std::string getTitle();
	std::vector<Student> getRegisteredStudents();
};
#endif
// Author: Jose Lael Louis

#ifndef ADVISOR_H
#define ADVISOR_H
#include "Student.h"
#include "Course.h"
#include "Advisor.h"
#include <unordered_map>
//class Student;
//class Course;

class Advisor
{
private:
	std::unordered_map<std::string, Course> idToCourse;
	std::vector<Student> students;
public:
	Advisor();
	Advisor(std::vector<Course> courses);
	void registerCourses(Student &student);
	void showRegistrationReport();

};

#endif
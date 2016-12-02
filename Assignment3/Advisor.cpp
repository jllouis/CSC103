// Author: Jose Lael Louis

#include <iostream>
#include "Advisor.h"
#include "Student.h"
#include "Course.h"

Advisor::Advisor()
{

}

Advisor::Advisor(std::vector<Course> courses)  // constructor
{
	for (Course c : courses)
	{
		idToCourse.insert_or_assign(c.getTitle(), c);
	}
}

void Advisor::registerCourses(Student &student) // register student's classes
{
	std::vector<Course> courses = student.getCourses();
	for (unsigned int i = 0; i < courses.size(); i++)
	{
		courses[i].registerStudent(student, courses[i]);
	}
}

void Advisor::showRegistrationReport()  // print registration reports
{
	for (auto &c : idToCourse)
	{
		c.second.showCourseInfo();
		c.second.showRegisteredStudents(c.second);
		std::cout << std::endl;
		std::vector<Student> registeredStudents = c.second.getRegisteredStudents();
		for (Student s : registeredStudents)
		{
			std::cout << s.getName() << " is registered for: " << std::endl;
			std::vector<Course> courses = s.getCourses();
			for (Course l : courses)
				std::cout << l.getTitle() << std::endl;
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}
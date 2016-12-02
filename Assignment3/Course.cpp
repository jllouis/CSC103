// Author: Jose Lael Louis
// Author: Jose Lael Louis
#include <iostream>
#include "Student.h"
#include "Course.h"

Course::Course()
{
	this->title = "N/A";
	this->capacity = 0;
	this->courseID = "N/A";
	this->prerequisites = {};
	this->registeredStudents = {};
}

Course::Course(std::string ID, std::string title, int capacity)
{
	this->title = title;
	this->courseID = ID;
	this->capacity = capacity;
	this->prerequisites = {};
	this->registeredStudents = {};
}
void Course::showCourseInfo()
{
	// Displays ID, Title, Capacity of course
	std::cout << "Title: " << title << std::endl;
	std::cout << "Course ID: " << courseID << std::endl;
	std::cout << "Capacity: " << capacity << std::endl;
	
}

void Course::registerStudent(Student student, Course &course) // registers student if class isn't full
{
	if (hasCapacity())
	{
		course.registeredStudents.push_back(student);
	}
	else
		std::cout << getTitle() << " course full!" << std::endl;
}

void Course::showRegisteredStudents(Course &course)  // show which students are registered for the course
{
	std::cout << "Registered Students: " << std::endl;
	for (Student s : registeredStudents)
	{
		std::cout << s.getName() << std::endl;
	}
	
}

bool Course::hasCapacity() // does class have any more room?
{
	return ((int)registeredStudents.size() < capacity);
}

std::string Course::getTitle()  // gets title of course
{
	return title;
}

std::vector<Student> Course::getRegisteredStudents()  // returns vector of registered students
{
	return registeredStudents;
}
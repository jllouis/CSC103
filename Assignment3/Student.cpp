// Author: Jose Lael Louis

#include <iostream>
#include <vector>
#include "Course.h"
#include "Advisor.h"
#include "Student.h"

class Advisor;

Student::Student()
{
	studentID = NULL;
	name = "";
}

Student::Student(int ID, std::string name, std::vector<Course> coursesDesired)
{
	this-> studentID  = ID;
	this-> name = name;
	this-> coursesDesired = coursesDesired;
}

void Student::requestDesiredCourses(Advisor& advisor) //queries advisor to register courses
{
	advisor.registerCourses(*this);
}

std::string Student::getName()  // returns name of student
{
	return name;
}

std::vector<Course> Student::getCourses()  // returns courses student watns to register for
{
	return coursesDesired;
}

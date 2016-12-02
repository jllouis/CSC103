// Author: Jose Lael Louis

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <vector>
#include "Course.h"
#include "Advisor.h"

class Advisor; 

class Student  // class defining the student object
{
private:
	int studentID;
	std::string name;
	std::vector<Course> coursesPassed;
	std::vector<Course> coursesDesired;
	std::vector<Course> coursesRegistered;

public:
	Student(int ID, std::string name, std::vector<Course> coursesDesired);
	Student();
	void requestDesiredCourses(Advisor&);
	std::string getName();
	std::vector<Course> getCourses();
};
#endif
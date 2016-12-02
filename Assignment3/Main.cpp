/* CSC 103 Assignment 3
 * Author: Jose L. Louis
 * Date: 9/08/2015
 */ 

#include <iostream>
#include "Course.h"
#include "Student.h"
#include "Advisor.h"
#include <vector>

int main(void)
{
	// Creating course objects
	Course CS101("CS101", "Introduction to C", 20);
	Course MAT300("MAT300", "Calculus A", 30);
	Course CE100("CE100", "Circuit Analysis", 20);
	Course PHY350("PHY350", "Modern Physics", 50);
	Course WRT240("WRT240", "Technical Writing", 25);
	
	// creating vectors of desiredCourses
	std::vector<Course> allCourses = {CS101, MAT300, CE100, PHY350, WRT240};
	std::vector<Course> adamsCourses{ CS101, MAT300, WRT240 };
	std::vector<Course> jamesCourses{ CS101, PHY350, CE100 };
	std::vector<Course> mikecourses{ WRT240, CE100, MAT300 };
	
	//Test students created
	Student testStudent1(12345678, "Adam Bob", adamsCourses);
	Student testStudent2(32149544, "James West", jamesCourses);
	Student testStudent3(84328543, "Mike Bentancourt", mikecourses);
	
	//creating advisor and registering classes for test students
	Advisor advisor(allCourses);
	advisor.registerCourses(testStudent1);
	advisor.registerCourses(testStudent2);
	advisor.registerCourses(testStudent3);
	advisor.showRegistrationReport();  // print report
	
	std::cout << std::endl;

	return 0;
}
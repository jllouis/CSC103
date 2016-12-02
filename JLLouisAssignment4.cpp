/* Assignment #4
 * Author: Jose L. Louis
 * CSC 103
 * The City College of the City University of New York
 * The Grove School of Engineering
**/

#include <iostream>  // for input and output
#include <fstream>  // to stream external files
#include <string>   // for string manipulation
#include <sstream> // string stream
#include <map>    // for the std::map class
#include <vector> // for the vector class

void readFile(std::string fileName); // reads and prints file
void processFields(std::string line); // prints fields of lines in line
double getAreaAvg(std::string area); // returns the average gdp of an area
std::string minGDP(std::string region); // returns which year had lowest GDP of in the region

std::map<std::string, std::map<std::string, double>> theMap;  // where all the data is stored

int main(void)
{

	std::vector<std::string> regions{ "Arab World","East Asia & Pacific (all income levels)" , "Latin America & Caribbean (all income levels)" ,
		"Europe & Central Asia (all income levels)","Middle East & North Africa (all income levels)" , "North America" ,
		"Sub-Saharan Africa (all income levels)" };
	readFile("UNdata_GDP by Area.csv");  // source

	std::cout << "--------------------------------" << std::endl;  // seperate step

	//map test for step 3
	{
		for (auto &x : theMap) // for each region
		{
			std::cout << x.first << ":" << std::endl; 

			for (auto &y : x.second) // for each year
			{
				std::cout << y.first << " " << y.second << std::endl;
			}

			std::cout << std::endl;
		}
	}

	std::cout << "--------------------------------" << std::endl;  // seperate step

	// displays average GDPs and years with minimum GDPs of all regions
	for (std::string s : regions)
	{
		std::cout << s << "'s Average GDP: " << getAreaAvg(s) << std::endl;
		std::cout << s << "'s Year of Minimum GDP: " << minGDP(s) << std::endl;
		std::cout << std::endl;
	}

	getchar();  // to prevent closing of console window until enter is pressed (on MS Windows);

	return 0;
}

void readFile(std::string fileName)  // prints the contents of a file
{
	std::string line;  // to store read lines
	std::ifstream inputStream(fileName); // stream contents of this file

	std::getline(inputStream, line, '\n');  // "throws away" first line

	while (!inputStream.eof()) // while not end of file
	{
		std::getline(inputStream, line, '\n');  // read a line
		processFields(line);
		printf("\n");
	}
}

void processFields(std::string line)
{
	std::istringstream input(line);
	std::string token0, token1, token2;

	//assigns and outputs each field of the line
	// token0,1,2 contains the 0th 1st and 2nd strings in the line respectively
	{
		std::getline(input, token0, ',');
		std::cout << token0 << std::endl;
		std::getline(input, token1, ',');
		std::cout << token1 << std::endl;
		std::getline(input, token2, ',');
		std::cout << token2 << std::endl;
	}

	//insert line entries to the map
	theMap[token0][token1] = std::stod(token2);
}

double getAreaAvg(std::string area)
{
	std::vector<double> gdps; // to store values to average
	double sum = 0;

	for (auto &map : theMap[area])  // sum up all GDPs for that region
	{
		gdps.push_back(map.second);
		sum += map.second;
	}

	return (sum / (double)gdps.size());  // return the average
}

std::string minGDP(std::string region)  // gets year with lowest GDP
{
	std::string tempYear = "?"; // to temporarily store the current minimum
	double tempGDP = 9E+20;

	for (auto &map : theMap[region])
	{
		if (map.second < tempGDP)
		{
			tempGDP = map.second; // replace temp value with current minimum GPD
			tempYear = map.first; // replace temp value with current year with min GDP
		}
	}

	return tempYear;
}
// END OF PROGRAM
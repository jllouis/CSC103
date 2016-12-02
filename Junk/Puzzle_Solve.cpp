/* Author: J. L. Louis
Attempt 1 of Puzzle Solver
*/

#include <iostream> // for cout and cin
#include <ctime> // for time()
#include <cinttypes> // for precise integer types
#include <vector> // for vectors
#include <ctype.h> // for isdigit()
#include <string> // to handle strings

int getRandomIntMod4() //get random value from 0-3 to randomize which operation to insert
{
	return rand() % 4;
}

char chooseOperator() //gets random operator to put in between the chars or signal for concatenation
{
	switch (getRandomIntMod4())
	{
	case 0:
		return '+';
		break;
	case 1:
		return '-';
		break;
	case 2:
		return '*';
	default:		//signal for no operation, but concatenation
		return 0;
		break;
	}
}

int32_t calculate(uint8_t a, uint8_t b, char symbol)	// adds, substracts, multiplies two operands depending on their symbol
{
	switch (symbol)
	{
	case '+':
		return a + b;
		break;
	case '-':
		return a - b;
		break;
	case '*':
		return a * b;
		break;
	default:	// this shouldn't happen
		printf("%s", "FATAL ERROR!");
		return -1;
	}
}

int32_t compute(std::vector<uint8_t> a, std::vector<char> b) // computes and return the result of two component vectors
{
	int32_t runningTotal = a[0]; // to store commulative value of the sequential operation evaluation of the expression

	for (uint8_t i = 1; i < a.size(); i++)
		runningTotal = calculate(runningTotal, a[i], b[i - 1]); // total = total (+,-,*) next number

	return runningTotal;
}

std::string construct() // constructs random formula based on random operators (or nothing) put between the digits 1-9
{
	char digits[]{ '1','2','3','4','5','6','7','8','9' }; //digit reference to make programming easier
	char returnString[18];	// to copy vector into and pass return as a string
	std::vector<char> construction;  // this vector is the formula that will be converted to a string to be evaluated

	for (uint8_t i = 0; ; i++) // places random operator or nothing in between the digits
	{
		if (digits[i] == '9')	//last digit just insert the digit and end loop
		{
			construction.push_back(digits[i]);
			construction.push_back('\0');
			break; // stop when last digit is reached
		}

		switch (char operation = chooseOperator())
		{
		case 0:
			construction.push_back(digits[i]);  // 0 is the signal to concatenate current construction with next digit without inserting an operator in-between
			break;
		default:
			construction.push_back(digits[i]);
			construction.push_back(operation);  // if no concatenate signal, insert received operator
			break;
		}
	}

	uint8_t i = 0;
	for (; construction[i] != NULL; i++) // copying constructed vector into a char[] to be returned as string
		returnString[i] = construction[i];
	returnString[i] = NULL; // string terminator - so it can be returned as a valid string

	return returnString;
}

bool evaluate(std::string toCompute, int target) //see if what construct() returned equals to target, parses the expression and sends it piece by piece to be computed
{
	//uint32_t total = 0;

	//bool end = false;
	//for (uint8_t i = 0, beginSubstring = 0, substringLen = 0; !end;)
	//{
	//	
	//	while (isdigit(toCompute[i])) // find length of next number
	//		substringLen++; ++i;
	//	
	//	total += calculate(total, atoi(toCompute.c_str.substr(beginSubstring, substringLen )), toCompute.at(beginSubstring + substringLen)); // ... sen
	//	beginSubstring += substringLen + 1;
	//	substringLen = 0; // reset substrinLen
	//	i = 0;	// and also i
	//}

	std::vector<uint8_t> numberComponents; // to store numerical components;
	std::vector<char> operationalComponents; // to store operational components

											 //	bool lastDigit = false;
	char numberStorage[9], symbolStorage; // to store operator symbol

	for (uint8_t i = 0, j = 0; i <= toCompute.length();) // for every character in the expression string
	{
		if (!(i > toCompute.length() - 1))  // if the index is not greater than the length of the string
			while (isdigit(toCompute.at(i)))
			{
				numberStorage[j++] = toCompute.at(i++); // add digit to value holder, to be transfered and a single number to construction vector
				if (i > toCompute.length() - 1)
					break;
			}

		{
			numberStorage[j] = '\0';
			numberComponents.push_back(atoi(numberStorage)); //insert new number to number vector
			if (!(i > toCompute.length() - 1))
				symbolStorage = toCompute.at(i++);
			operationalComponents.push_back(symbolStorage);  //insert operator symbol to component vector
			j = 0; // reset j
		}

		if (numberComponents[numberComponents.size() - 1] == NULL) // hotfix to prevent the program from continuing beyond the length of the string
			break;

		if (!(i > toCompute.length() - 1)) // to prevent going past the index bound
		{
			if (toCompute.at(i) == '9')
			{
				numberComponents.push_back(9);
				break;
			}
		}

	}
	/*std::cout << "Done!\n";*/
	return (compute(numberComponents, operationalComponents) == target); // return whether or not the expression evaluates to the target value

}

int main(void) // MAIN PROGRAM
{
	srand(static_cast<unsigned int>(time(NULL))); // seed random
	int target; // to store target number
	std::string constructed; // to store constructed string
	std::cout << "Enter your target number: "; // prompt user to enter target number
	std::cin >> target; // input target number


	for (uint16_t i = 0; i < 1000000; i++)  // check i random expressions
		if (evaluate(constructed = construct(), target))  // does the random expression evaluate to the target number?
			std::cout << constructed << " = " << target << std::endl;  // if so, print the expression

	printf("\nPress enter to end program. . .");  // inform the user that the program needs them to press enter to quit
	getchar(); // need press enter for console window to close

	return 0;  // everything is cool!
}

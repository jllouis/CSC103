//Author: Jose L. Louis

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

template <class T>
class Matrix
{
private:
	std::vector<T> matrix;
	unsigned m, n;  // m rows, n columns
	unsigned numLines, width; // number of lines and number of words per line

	void initializeMatrix(std::string fileName)  // prints the contents of a file
	{
		std::string line;  // to store read lines
		std::ifstream inputStream(fileName); // stream contents of this file
		unsigned nol = 0; //number of lines
		unsigned now = 0; // number of words per line

		while (!inputStream.eof()) // while not end of file
		{
			std::getline(inputStream, line, '\n');  // read a line
			now = countWords(line);
			++nol;
		}

		inputStream.close();

		this->m = now;
		this->n = nol;
	}

	T matrixMultStep(const Matrix& mat, const unsigned aconstrow, const unsigned bconstcol) // multiplies a's certain row, to b's certain column
	{
		T sum = 0;
		for (unsigned k = 0, j = 0; k < bconstcol; k++, j++)
			sum += get(aconstrow, k) * mat.get(j, bconstcol);

		return sum;
	}

	unsigned countWords(std::string line)
	{
		std::istringstream input(line);
		std::vector<std::string> tokens;

		// inserts each number into the vector as string
		for (unsigned i = 0; std::getline(input, tokens[i], ' '); i++)
			std::cout << tokens[i] << std::endl;
		return tokens.size();
	}

	std::vector<std::string> processLine(std::string line)
	{
		std::istringstream input(line);
		std::vector<std::string> tokens;

		// inserts each number into the vector as string
		for (unsigned i = 0; std::getline(input, tokens[i], ' '); i++)
			std::cout << tokens[i] << std::endl;
		return tokens;
	}

public:
	Matrix(){}

	Matrix(unsigned m, unsigned n)
	{
		this->m = m;
		this->n = n;
		matrix.resize(m, n);
		numLines = 0;
		width = 0;
	}
	
	Matrix(std::string file)
	{
		initializeMatrix(file); // set dimmensions of the matrix depending on the input file

		// populate matrix
		std::string line;
		std::ifstream inputStream(file);
		std::vector<std::string> receivedTokens;
		for (unsigned i = 0; !inputStream.eof(); i++)
		{
			 std::getline(inputStream, line, '\n');
			 receivedTokens = processLine(line);
			 for (unsigned j = 0; j < receivedTokens.size(); j++)
			 {
				 set(i, j, atoi(receivedTokens[j].c_str()));
			 }
		}
	}

	auto begin()
	{
		return matrix.begin();
	}

	auto end()
	{
		return matrix.end();
	}

	unsigned num_rows() const
	{
		return m;
	}

	unsigned num_cols() const
	{
		return n;
	}

	T get(int row, int column) const
	{
		return get(row, column);
	}

	void set(int row, int column, const T& val)
	{
		set(m,n,val);
	}

	 Matrix& Matrix::operator+(const Matrix& m1)
	{
		Matrix temp(m,n);

		if ((m != m1.num_rows()) || (m != m1.num_cols())) // validity check
			exit(-2);  // error

		//matrix addition algorithm
		for (unsigned i = 0; i < m; i++)
			for (unsigned j = 0; j < n; j++)
				temp.set(i, j, get(i,j) + m1.get(i,j));

		return temp;
	}

	 Matrix& Matrix::operator*(const Matrix& m1)
	 {
		 /*const unsigned msize = m1.num_cols();*/
		 Matrix newMatrix(n, m1.num_cols());

		 // r1xc1 * r2xc2 => r1 =m ,c1 =n, r2 = m1.num_rows, c2 = m1.num_cols

		 if (n != m1.num_rows()) // validity check
			 exit(-1); // error

		 for (unsigned i = 0; i < n; i++)
			 for (unsigned j = 0; j < m1.num_cols(); j++)
				 newMatrix.set(i, j, matrixMultStep(m1, i, j));

		 return newMatrix;
	 }

	 Matrix<T> transpose(Matrix& m)
	 {
		/* vector<T> transposed[m.num_cols()][m.num_rows()];  */
		 Matrix<T> result(m.num_cols(), m.num_rows());// NxM matrix' tranpose will be MxN

		 //matrix transposition algorithm
		 for (unsigned i = 0; i < m.num_rows(); i++)
			 for (unsigned j = 0; j < m.num_cols(); j++)
				 /*transposed[j][i] = m[i][j];*/
				 result.set(j, i, m.get(i,j));

		 return result;
	 }

	 void printResults(std::string outfile)
	 {
		 std::ofstream output;
		 output.open(outfile);
		 for (unsigned i = 0; i < n; i++)
		 {
			 for (unsigned j = 0; j < m; j++)
				 output << get(i,j) << " ";
			 output << "\n";
		 }
		 std::cout << "Output in file \"" << outfile << "\". Check your output directory!" << std::endl;
	 }
};

int main(void)
{
	Matrix<int> a("a.text");
	Matrix<int> b("b.text");
	Matrix<int> c = c.transpose((a + a)*b);

	c.printResults("c.text");
	system("PAUSE");
	return 0;
}
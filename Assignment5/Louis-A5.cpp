/* Author: Jose L. Louis
** CSC 103 Assingment 5
** Date: 12/2/2015
** CCNY Grove School of Engineering
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
//#include <cstdlib>

template<class T>
class customArray
{
private:
	T *elem;

protected:
	unsigned sz;
public:

	customArray()
	{
		sz = 0;
		elem = new T[1000];
	}

	unsigned getSize()
	{
		return sz;
	}

	void add(T thing)
	{
		elem[sz] = thing;
		++sz;
	}

	void remove(unsigned index)
	{
		if (index > sz)
		{
			std::cout << "Out of bounds!" << std::endl;
		}

		else
		{
			for (unsigned i = index; i < sz; ++i)
				elem[index] = elem[i + 1];
		}
	}

	T get(unsigned index)
	{
		if (index > sz)
		{
			std::cout << "Out of bounds!" << std::endl;
		}

		else
		return elem[index];
	}

	void change(unsigned index, T thing)
	{
		if (index > sz)
		{
			std::cout << "Out of bounds!" << std::endl;
		}
		
		else
		{
			elem[index] = thing;
		}
	}

	~customArray()
	{
		delete[] elem;
	}

};

template <class T>
class Node
{
private:
	int number;
	T value;
public:
	Node()
	{
		number = 0;
		value = NULL;
	}
	Node(int num, T val)
	{
		number = num;
		value = val;
	}

	int getNumber()
	{
		return number;
	}

	T getValue()
	{
		return value;
	}

};

template <class T>
class Edge
{
	
private:
	Node<T> v1, v2;
public:
	Edge()
	{
		
	}
	Edge(Node<T> v1, Node<T> v2)
	{
		this->v1 = v1;
		this->v2 = v2;
	}

};

template <class T>
class Graph
{
	
private:
	customArray<Node<int>> vertices;
	customArray<Edge<T>> edges;
	customArray<int> degreesPerNode;

public:
	Graph(std::string fileName)
	{
		readFile(fileName);
	}
	void readFile(std::string fileName)  // prints the contents of a file
	{
		std::string line;  // to store read lines
		std::ifstream inputStream(fileName); // stream contents of this file

											 //std::getline(inputStream, line, '\n');  // "throws away" first line

		while (!inputStream.eof()) // while not end of file
		{
			std::getline(inputStream, line, '\n');  // read a line
			processLines(line);
		}
	}

	void processLines(std::string line)
	{
		std::istringstream input(line);
		std::string token0, token1, token2;
		std::string a, b;

		//assigns and outputs each field of the line
		// token0,1,2 contains the 0th 1st and 2nd strings in the line respectively
		{
			std::getline(input, token0, ' ');
			//std::cout << token0 << std::endl;
			std::getline(input, token1, ' ');
			//std::cout << token1 << std::endl;
			std::getline(input, token2, ' ');
			//std::cout << token2 << std::endl;
		}

		if (token0 == "v")  // if first letter of line is v, create new vertex
		{
			vertices.add(Node<int>(stoi(token1), stoi(token2)));
			degreesPerNode.add(0);
		}

		else if (token0 == "e")  // if first letter is e, add new edge
		{
			a = token1;
			b = token2;
			edges.add(Edge<T>(vertices.get(stoi(a)), vertices.get(stoi(b))));
			degreesPerNode.change(stoi(a), degreesPerNode.get(stoi(a)) + 1);
			degreesPerNode.change(stoi(b), degreesPerNode.get(stoi(b)) + 1);
		}
	}

	customArray<T> getAllVertices() // returns customArray of all vertices
	{
		return vertices;
	}

	customArray<T> getAllEdges()  // returns customArray of all edges
	{
		return edges;
	}

	void addVertext(Node<T> v)  // adds vertex to graph (but doesn't connect it
	{
		vertices.add(v);
	}

	bool removeVertext(Node<T> v)  // removes vertex from graph
	{
		for (unsigned i = 0; i < vertices.getSize(); i++)
		{
			if (vertices.get(i) == v)
			{
				vertices.change(i, NULL);
				return true;
			}
		}

		std::cout << "Couldn't find v!" << std::endl;
		return false;
	}

	void addEdge(Edge<T> e)  // adds edge to graph
	{
		edges.add(e);
	}

	bool removeEdge(Edge<T> e)  // removes edge from graph
	{
		for (unsigned i = 0; i < edges.getSize(); i++)
		{
			if (edges.get(i) == e)
			{
				edges.change(i, NULL);
				return true;
			}
		}
		
		std::cout << "Couldn't find e!" << std::endl;
		return false;
	}

	void getDegreeOfVertex(Node<T> v)
	{
		bool found = false;
		for (unsigned i = 0; i < vertices.getSize(); i++)
		{
			if (vertices.get(i) == v)
			{
				std::cout << "Degree of v is : " << vertices.get(i) << std::endl;
			}
		}
	}

	void printResults()
	{
		std::ofstream output;
		output.open("output.txt");
		for (unsigned i = degreesPerNode.getSize(), count = 1; i > 0; i--, count++)
			output << count << " " << degreesPerNode.get(i-1) << "\n";
		std::cout << "Output in file \"output.txt\". Check your output directory!" << std::endl;
	}
};

int main(void)
{
	// testing customArray
	//customArray<int> mything;
	//
	//mything.add(1);
	//mything.add(3);
	//mything.add(5);
	//mything.add(6);
	//mything.add(0);
	//mything.add(5);
	//mything.add(0);
	//mything.add(2);

	//for (unsigned i = 0; i < mything.getSize(); i++)
	//{
	//	std::cout << mything.get(i) << std::endl;
	//}
	//
	//mything.get(mything.getSize() + 2);	// should be out of bounds

	Graph<int> mygraph("input.txt");
	mygraph.printResults();

	//system("PAUSE"); // prevents console from closing without user input
	return 0;
}
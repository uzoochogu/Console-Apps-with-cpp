/*
In this challenge, we work with string streams.

stringstream is a stream class to operate on strings. It implements input/output operations on memory (string) based streams. stringstream can be helpful in different type of parsing. The following operators/functions are commonly used here

Operator >> Extracts formatted data.
Operator << Inserts formatted data.
Method str() Gets the contents of underlying string device object.
Method str(string) Sets the contents of underlying string device object.
Its header file is sstream.

One common use of this class is to parse comma-separated integers from a string (e.g., "23,4,56").

stringstream ss("23,4,56");
char ch;
int a, b, c;
ss >> a >> ch >> b >> ch >> c;  // a = 23, b = 4, c = 56
Here  is a storage area for the discarded commas.

If the >> operator returns a value, that is a true value for a conditional. Failure to return a value is false.

Given a string of comma delimited integers, return a vector of integers.
Function Description

Complete the parseInts function in the editor below.

parseInts has the following parameters:

string str: a string of comma separated integers
Returns

vector<int>: a vector of the parsed integers.
Note You can learn to push elements onto a vector by solving the first problem in the STL chapter.

Input Format

There is one line of  integers separated by commas.

Constraints

The length of  is less than .

Sample Input

23,4,56
Sample Output

23
4
56

Testing:
I implemented a test file for this project. The test cases are added there.
*/


#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

vector<int> parseInts(string str) 
{
	// Complete this function
    stringstream ss{str};
    vector<int> values;
    int num_buf = {}; 
    char ch = {}; //storage area for discarded commas

    while(ss >> num_buf)
    {
        values.push_back(num_buf);
        ss >> ch;
    }

    return values;
}

//driver code
//I made made my custom test environment so that test cases can be put in a file
int main() 
{
    std::fstream testFile("test_for_StringStream_Challenge.txt", std::ios::in); 

    //check if it opens
    if (!testFile.is_open()) 
    {
        std::cout << "failed to open " << "test_for_StringStream_Challenge.txt" << '\n';
    } 
    else
    {
        for( std::string lineBuffer ;std::getline(testFile, lineBuffer);) //keep reading the file
        {
            string str{lineBuffer};
            //cin >> str; //Use this to give user defined input or rather add to the test file
            vector<int> integers = parseInts(str);
            std::cout << "\nOutput:\n";
            for(int i = 0; i < integers.size(); i++) 
            {
                cout << integers[i] << "\n";
            }

        }       
        
    }    
    return 0;
}
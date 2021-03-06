#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Checking if a given character is a capital letter
int iscapital(char x)
{
	if (x >= 'A' && x <= 'Z')
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

bool rlEncode(string uncompressedData, vector<int> &lengths, vector<char> &chars)
{	
	char tempChar = ' ';
	int count = 0;

	for (string::iterator it = uncompressedData.begin(), end = uncompressedData.end(); it != end; ++it)
	{	
		// Check for valid string
		if ( isdigit(*it) || iscapital(*it) || isspace(*it) || !isalpha(*it) )
		{
			cout << "Error, invalid input";
			return false; // Error, letter either a digit or a capital letter
		}

		// The real meat of the program >.<
		if (*it == tempChar)
		{
			count++;
		}
		else
		{
			tempChar = *it;

			if (count != 0)
			{
				lengths.push_back(count);
			}
			
			chars.push_back(*it);			
			count = 1; // Start counting from zero, for a new character
		}				
	}

	lengths.push_back(count);
	
	return true;
}

int main()
{
	string data;	

	vector<int> runLengths;
	vector<int>::const_iterator countIter;

	vector<char> characters;
	vector<char>::const_iterator charIter;

    cout << "Enter the data to be compressed:"; 
	getline(cin, data); // Input don't stop at whitespace character

	// Passing vectors to function by reference
	if (rlEncode(data, runLengths, characters))
	{
		cout << "Compressed data: ";
		
		// Iterate through vectors
		for (countIter = runLengths.begin(), charIter = characters.begin();
				countIter != runLengths.end(), charIter != characters.end();
					++countIter, ++charIter)
		{
			cout << *countIter ;
			cout << *charIter ;
		}			
	}

	return 0;
}
#include <string>
#include <vector>
#include <iostream>
#include <locale> 
#include <unordered_map>
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	locale loc;
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i],loc);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	//base case
	if(currentStringVector.empty()) {
		string testPal;
		for(string str : candidateStringVector) {
			testPal += str;
		}
		if(isPalindrome(testPal)) {
			palindromes.push_back(candidateStringVector);
			numPal++;
		}
		return;
	}

	if(!cutTest2(candidateStringVector, currentStringVector)) {return;}

	//recursion loop
	for(int i = 0; i < currentStringVector.size(); i++) {
		candidateStringVector.push_back(currentStringVector[i]);
		currentStringVector.erase(currentStringVector.begin() + i);

		recursiveFindPalindromes(candidateStringVector, currentStringVector);

		currentStringVector.insert(currentStringVector.begin(), candidateStringVector.back());
		candidateStringVector.pop_back();
	}
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
	numPal = 0;
}

FindPalindrome::~FindPalindrome()
{

}

int FindPalindrome::number() const
{
	return numPal;
}

void FindPalindrome::clear()
{
	numPal = 0;
	words.clear();
	palindromes.clear();
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	int numChars = 0;
	std::unordered_map<char, int> map;
	for(string str : stringVector) {
		for(char c : str) {
			numChars++;
			map[tolower(c)]++;
		}
	}

	if (numChars % 2) {
		for(string str : stringVector) {
			for(char c : str) {
				if (!(map[tolower(c)] % 2)) {return false;}
			}
		}
		return true;
	} else {
                for(string str : stringVector) {
                        for(char c : str) {
                                if (map[tolower(c)] % 2) {return false;}
                        }
                }
                return true;
	}

}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	int numChars1 = 0;
	int numChars2 = 0;
	std::unordered_map<char, int> map1;
	std::unordered_map<char, int> map2;
        for(string str : stringVector1) {
                for(char c : str) {
                        numChars1++;
                        map1[tolower(c)]++;
                }
        }
        for(string str : stringVector2) {
                for(char c : str) {
                        numChars2++;
                        map2[tolower(c)]++;
                }
        }

	if(numChars1 <= numChars2) {
        	for(string str : stringVector1) {
                	for(char c : str) {
                        	if(map2[tolower(c)] < map1[tolower(c)]) {return false;}
                	}
        	}
		return true;
	} else {
        	for(string str : stringVector2) {
                	for(char c : str) {
                       		 if(map1[tolower(c)] < map2[tolower(c)]) {return false;}
                	}
        	}
		return true;
	}
}

bool FindPalindrome::add(const string & value)
{
	for(char c : value) {
		if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {return false;}
	}
	for(string word : words) {
		string wordLow = word;
		string valueLow = value;
		convertToLowerCase(wordLow);
		convertToLowerCase(valueLow);

		if(wordLow == valueLow) {return false;}
	}
	words.push_back(value);
	numPal = 0;
	vector<string> candidate;
	if(this->cutTest1(words)) {recursiveFindPalindromes(candidate, words);}
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	for(string value : stringVector) {
        	for(char c : value) {
        	        if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {return false;}
        	}
        	for(string word : words) {
                	string wordLow = word;
                	string valueLow = value;
                	convertToLowerCase(wordLow);
               		convertToLowerCase(valueLow);

                	if(wordLow == valueLow) {return false;}
        	}
        	words.push_back(value);
	}
        numPal = 0;
        vector<string> candidate;
        if(this->cutTest1(words)) {recursiveFindPalindromes(candidate, words);}
}

vector< vector<string> > FindPalindrome::toVector() const
{
	return palindromes;
}


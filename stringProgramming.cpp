// Thanh Nha Phan
// CS 1337
// Lab 41

#include <iomanip>
#include <iostream>
#include <cctype> //  for ispunct, tolower, ect.

using namespace std;

int main() {
	char ch;
	while (cin.get(ch)) {
		if (isdigit(ch)) {
		}
		else if (ispunct(ch)) {
		}
		else if (isupper(ch)) {
			cout << static_cast<char>(tolower(ch));
		}
		else {
			cout << ch;
		}
	}
	return 0;
}

// Count the number of space and punctation, and the number of characters of a string
int main() {
	char ch;
	int charCount['Z' + 1], punctCount = 0, spaceCount = 0;
	for (int i = '0'; i <= 'Z'; i++) {
		charCount[i] = 0;
	}
	while (cin.get(ch)) {
		if (isspace(ch)) {
			spaceCount++;
		}
		else if (ispunct(ch)) {
			punctCount++;
		}
		else if (isalnum(ch)) {
			charCount[toupper(ch)]++;
		}
	}
	if (spaceCount != 0 || punctCount != 0) {
		cout << "whitespace = " << spaceCount << endl;
		cout << "punctuation = " << punctCount << endl;
	}
	cout << setw(17) << setfill('-') << '-' << setfill(' ') << endl;
	cout << left << setw(10) << "Character" << right << setw(7) << "Count" << endl;
	cout << setw(17) << setfill('-') << '-' << setfill(' ') << endl;
	for (int i = '0'; i <= 'Z'; i++) {
		if (charCount[i] != 0) {
			cout << right << setw(5) << static_cast<char>(i) << setw(12) << charCount[i] << endl;
		}
	}
	cout << setw(17) << setfill('-') << '-' << setfill(' ') << endl;
	return 0;
}

// Count the number of words
int main() {
	char ch;
	bool isInAWord = false;
	int wordCount = 0;
	while(cin.get(ch)) {
		if (isspace(ch)) {
			isInAWord = false;
		}
		else if (!isInAWord) {
			isInAWord = true;
			wordCount++;
		}
	}
	cout << "Number of words = " << wordCount << endl;
}

// Count the number of lines
int main() {
	char ch;
	bool lineEnds = true;
	int lineCount = 0;
	while (cin.get(ch)) {
		// When get a new character, count it as one line
		if (lineEnds) {
			lineCount++;
			lineEnds = false;
		}
		// if a new line character is found, set lineEnds to true in order for lineCount to get
		// counted when the loop starts over
		if (ch == '\n') {
			lineEnds = true;
		}
		// When a new line character is found at the end of the last line,
		// it is not going to get counted as a new line because there is no character after
		// the last line
	}
	cout << "Thanh Nha Phan - CS 1337 - Lab 45\n\n";
	cout << "Number of lines = " << lineCount << endl;
	return 0;
}

// Print each line with corresponding order number
int main() {
	char ch;
	bool lineEnds = true;
	int lineCount = 0;
	while (cin.get(ch)) {
		if (lineEnds) {
			lineCount++;
			// The line with number order
			cout << right << setw(4) << lineCount << ":  ";
			lineEnds = false;
		}
		// Print all characters of the line
		cout << ch;
		if (ch == '\n') {
			lineEnds = true;
		}
	}
	return 0;
}

// Function that returns a string with all uppercase letters
string uppercase(string s) {
	string::iterator ch;
	for (ch = s.begin(); ch < s.end(); ch++) {
		if(islower(*ch)) {
			*ch = toupper(*ch);
		}
	}
	return s;
}

// Function that replaces all digits with hashtag #
string replaceDigits(string s) {
	string::iterator ch;
	for (ch = s.begin(); ch < s.end(); ch++) {
		if (isdigit(*ch)) {
			*ch = '#';
		}
	}
	return s;
}

// Function that reverses all characters of a string
string stringReverse(string s) {
	//set the length of the string to variable len
	unsigned int len = s.length();
	//create temporary character to swap two characters in the string
	char chTem;
	for (unsigned int i = 0; i < len/2; i++) {
		chTem = s[len - i - 1];
		s[len - i - 1] = s[i];
		s[i] = chTem;
	}
	return s;
}
// Another way to do this

// Read all the last 4 coutsto know what this function is all about
int main() {
	unsigned int wordCount = 0, vowelCount = 0, consonantCount = 0, nonAlphaCount = 0;
	string word;
	while (cin >> word) {
		wordCount++;
		if (isalpha(word[0])) {
			switch(toupper(word[0])) {
				case 'A':
				case 'E':
				case 'O':
				case 'I':
				case 'U':
					vowelCount++;
					break;
				default:
					consonantCount++;
			}
		}
		else {
			nonAlphaCount++;
		}
	}
	cout << "Total Number of Words = " << wordCount << endl;
	cout << "Number of Words Beginning with a Vowel = " << vowelCount << endl;
	cout << "Number of Words Beginning with a Consonant = " << consonantCount << endl;
	cout << "Number of Words Beginning with a Non-Alpha = " << nonAlphaCount << endl;
	
	return 0;
}

// Function that romoves all punctations in s string
string removePunctuation(string s) {
	unsigned int i = 0;
	while (i < s.length()) {
		if (ispunct(s[i])) {
			s.erase(i, 1);
		}
		else {
			i++;
		}
	}
	return s;
}

// Function that removes all white space in s string
string removeWhitespace(string s) {
	unsigned int i = 0;
	while (i < s.length()) {
		if (isspace(s[i])) {
			s.erase(i, 1); 
		}
		else {
			i++;
		}
	}
	return s;
}

// Function sort - sorts the n-element array of strings in
// ascending order using an exchange sort
void sort(string array[], int n) {
	string *p, *q, tem;
	for (p = array; p < array + n - 1; p++) {
		for (q = p + 1; q < &array[n]; q++) {
			if (*p > *q) {
				tem = *p;
				*p = *q;
				*q = tem;
			}
		}
	}
}

// Function boolean to determine whether a string is an imperfect palindrome or not
bool isPalindrome(string s) {
	// make all characters in the string to all uppercase
	s = uppercase(s);
	// remove all punctuations in the string
	s = removePunctuation(s);
	// remove all white space in the string
	s = removeWhitespace(s);
	if (s == stringReverse(s)) {
		return true;
	}
	return false;
}

// Function passwordVerifier returns true if string password
// represents a valid password and false otherwise. A valid 
// password must
//   1) be at least six characters long,
//   2) contain at least one uppercase letter,
//   3) contain at least one lowercase letter, and
//   4) contain at least one digit character.
bool passwordVerifier(string password) {
	unsigned int charCount = 0, upperCount = 0, lowerCount = 0, digitCount = 0;
	string::iterator itr;
	for (itr = password.begin(); itr < password.end(); itr++) {
		// Count the number of characters in the password
		charCount++;
		// Count the number of uppercase letter in the password
		if (isupper(*itr)) {
			upperCount++;
		}
		// Count the number of lowercase letter in the password
		if (islower(*itr)) {
			lowerCount++;
		}
		// Count the number of digit character in the password
		if (isdigit(*itr)) {
			digitCount++;
		}
	}
	// Check if the password has at least six characters
	if (charCount >= 6 && upperCount >= 1 && lowerCount >= 1 && digitCount >= 1) {
		return true;
	}
	return false;
}

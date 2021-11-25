// Thanh Nha Phan
// CS 1337
// Lab 16

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototype
unsigned int encrypt(unsigned int); //This function is for encrypting number
void printLine(ostream& out, int n); //This function is for creating hyphens

int main() {
	unsigned int num;
	
	printLine(cout, 23);
	cout << "Original      Encrypted\n";
	cout << " Number        Number  \n";
	printLine(cout, 23);
	
	while (cin >> num) {
		cout << setw(8) << num << setw(6) << " " << setw(9) << encrypt(num) << endl;
	}
	printLine(cout, 23);
	
	return 0;
}

//This is for defining encrypt function
unsigned int encrypt(unsigned int num) {
	unsigned int a, b, c, d;
	a = (num/1000 + 7) % 10;
	b = (num/100 + 7) % 10;
	c = (num/10 + 7) % 10;
	d = (num/1 + 7) % 10;
	num = c*1000 + d*100 + a*10 + b;

   return num;
}

//Define printLine function
void printLine(ostream& out, int n) {
	char ch = out.fill();
	out << setfill('-') << setw(n) << '-' << setfill(ch) << endl;
	return;
}
// Thanh Nha Phan
// CS 1337
// Lab 15

#include <iostream>
#include <iomanip>
using namespace std;

unsigned int reverseInt(unsigned int num) {
	unsigned int remainder, reverseNum = 0;
	while(num != 0) {
		remainder = num % 10;
		reverseNum = reverseNum*10 + remainder;
		num /= 10;
	}
	return reverseNum;
}

void printLine(ostream& out, int n) {
	char ch = out.fill();
	out << setfill('-') << setw(n) << '-' << setfill(ch) << endl;
	return;
}

int main() {
	unsigned int num;
	
	printLine(cout, 26);
	cout << " Original         Reverse\n";
	cout << "  Number           Number\n";
	printLine(cout, 26);
	
	while (cin >> num) {
		cout << setw(10) << num << setw(6) << " " << setw(10) << reverseInt(num) << endl;
	}
	printLine(cout, 26);
	
	return 0;
}

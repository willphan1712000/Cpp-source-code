// Thanh Nha Phan
// CS 1337
// Lab 14

#include <iostream>
using namespace std;

int main() {
	string ssn, an, gn, sn; // an is area number, gn is group number, sn is serial numbers
	cout << "Thanh Nha Phan - CS 1337 - Lab 14\n\n";
	cout << "-----------------------\n";
	cout << "  Input      Formatted \n";
	cout << "-----------------------\n";
	
	while (cin >> ssn) {
		an = ssn.substr(0,3);
		gn = ssn.substr(3,2);
		sn = ssn.substr(5,4);
		cout << ssn << "   " << an << "-" << gn << "-" << sn << "\n";
	}
	cout << "-----------------------\n";
	return 0;
}
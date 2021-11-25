// Thanh Nha Phan
// CS 1337
// Lab 07
#include <iostream>
using namespace std;

int main() {
	int a, b, c, abc;
	cout << "Thanh Nha Phan - CS 1337 - Lab 07\n\n";
	for (abc = 100; abc <= 999; abc += 1) {
		// below is another way to find a,b,c using subtraction
		a = abc / 100;
		b = (abc - a*100)/10;
		c = abc - a*100 - b*10;
		if (a+b+c == a*b*c) {
			cout << abc << "\n";
		}
	}
	
	return 0;
}
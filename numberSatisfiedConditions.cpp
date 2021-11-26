// Thanh Nha Phan
// CS 1337
// Lab 07
#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, e, ab, abc, abcde;
	cout << "a+b+c == a*b*c\n\n";
	for (abc = 100; abc <= 999; abc += 1) {
		// below is another way to find a,b,c using subtraction
		a = abc / 100;
		b = (abc - a*100)/10;
		c = abc - a*100 - b*10;
		if (a+b+c == a*b*c) {
			cout << abc << "\n";
		}
	}
   cout << "abc % 9 == 0 && a % 2 == 0 && b % 2 == 0 && c % 2 == 0\n\n";
	for (abc = 100; abc <= 999; abc += 1) {
		// below is another way to find a,b,c using subtraction
		a = abc / 100;
		b = (abc - a*100)/10;
		c = abc - a*100 - b*10;
		if (abc % 9 == 0 && a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
			cout << abc << "\n";
		}
	}
    cout << "abcde = 10000; abcde <= 99999; abcde += 1\n\n";
	for (abcde = 10000; abcde <= 99999; abcde += 1) {
		a = abcde / 10000 % 10;
		b = abcde / 1000 % 10;
		c = abcde / 100 % 10;
		d = abcde / 10 % 10;
		e = abcde / 1 % 10;
		ab = abcde / 1000 % 100;
		if (ab == d*e && b == 4*e && e == d - 7 && c == a + b) {
			cout << abcde << "\n";
		}
	}
	return 0;
}

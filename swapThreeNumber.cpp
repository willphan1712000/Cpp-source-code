// Thanh Nha Phan
// CS 1337
// Lab 34
#include <iostream>
using namespace std;

void orderThree(int& small, int& medium, int& large) {
	// Declear swap variable to find small, medium, and large
	int swap;
	// if medium is higher than large, then swap those numbers
	if (medium > large) {
		swap = large;
		large = medium;
		medium = swap;
	}
	// if swap is higher than medium, then swap those numbers
	if (small > medium) {
		swap = medium;
		medium = small;
		small = swap;
	}
	
	// Compare medium and large
	if (medium > large) {
		swap = large;
		large = medium;
		medium = swap;
	}
}
// When using pointers, do it the same but we dereference the address of values
void orderThree(int *small, int *medium, int *large) {
	int swap;
	if (*medium > *large) {
		swap = *large;
		*large = *medium;
		*medium = swap;
	}
	if (*small > *medium) {
		swap = *medium;
		*medium = *small;
		*small = swap;
	}
	if (*medium > *large) {
		swap = *large;
		*large = *medium;
		*medium = swap;
	}
}
int main()
{
  int a, b, c, copyA, copyB, copyC;

  while (cin >> a >> b >> c)
  {
    copyA = a;
    copyB = b;
    copyC = c;

    cout << "Reference -- Before:  "
         << "a = " << a << ", b = " << b << ", c = " << c;
    orderThree(a, b, c);
    cout << " After:  "
         << "a = " << a << ", b = " << b << ", c = " << c << endl;

    a = copyA;
    b = copyB;
    c = copyC;

    cout << "Pointer   -- Before:  "
         << "a = " << a << ", b = " << b << ", c = " << c;
    orderThree(&a, &b, &c);
    cout << " After:  "
         << "a = " << a << ", b = " << b << ", c = " << c << endl;
  }

  return 0;
}

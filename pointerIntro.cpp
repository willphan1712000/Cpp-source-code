// Thanh Nha Phan
// CS 1337
// Lab 32

#include <iostream>

using namespace std;

// Function larger receives two value parameters, a and b, and returns
// the larger of the two.
int larger(int a, int b) {
	if (a > b)  {
		return a;
	}
	else {
		return b;
	}
}

// Function larger has two parameters, each a pointer to a const int.
// The function returns the larger of the two int values.
int larger(const int *a, const int *b) {
	if (*a > *b)  {
		return *a;
	}
	else {
		return *b;
	}
}

int main()
{
  int a, b;

  while (cin >> a >> b)
  {
    cout << "The larger of " << a << " and " << b << " is "
         << larger(a, b) << endl;

    cout << "The larger of " << a << " and " << b << " is "
         << larger(&a, &b) << endl << endl;
  }

  return 0;
}

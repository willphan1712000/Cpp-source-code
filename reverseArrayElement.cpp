// Thanh Nha Phan
// CS 1337
// Lab 37
#include <iostream>
#include <cstdlib>
using namespace std;

// reverseArrayUsingIndexing:  Using indexing, this function reverses
// the elements of the n-element integer array in place; that is, the
// function exchanges the first and last elements, the second and
// next-to-last elements, and so on.
// Because there is no way to return an entire array as an argument to a function
// Therefore, it is changed a little bit by passing a pointer of the array to the function
void reverseArrayUsingIndexing(int *array, int n) {
	for (int i = 0; i <= (n/2-1); i++) {
		int swap;
		swap = *(array+i);
		*(array+i) = *(array + n - 1 - i);
		*(array + n - 1 - i) = swap;
	}
}

// reverseArrayUsingPointers:  Using pointers, this function reverses
// the elements of the n-element integer array in place; that is, the
// function exchanges the first and last elements, the second and
// next-to-last elements, and so on.
void reverseArrayUsingPointers(int *array, int n) {
	int *left, *right, swap;
	for (left = &array[0], right = &array[n-1]; left < right; left++, right--) {
		swap = *left;
		*left = *right;
		*right = swap;
	}
}

void printArrayUsingPointers(const int *array, int n, ostream& os)
{
  const int *ptr;
  const int *const endPtr = array + n;

  if (n > 0)
  {
    os << "array" << endl << '{' << endl;
    for (ptr = array; ptr < endPtr; ++ptr)
      os << "  [" << ptr - array << "] = " << *ptr << endl;
    os << '}' << endl;
  }
}

int main()
{
  int i, array[100], *ptr;
  
  i = 0;
  ptr = array;
  while (i < 100 && cin >> *ptr++)
    i++;

  if (i == 0) 
    cout << "No data" << endl;
  else
  {
    cout << "Before call to reverseArrayUsingIndexing()" << endl;
    printArrayUsingPointers(array, i, cout);
    reverseArrayUsingIndexing(array, i);
    cout << "After call to reverseArrayUsingIndexing()" << endl;
    printArrayUsingPointers(array, i, cout);
    reverseArrayUsingPointers(array, i);
    cout << "After call to reverseArrayUsingPointers()" << endl;
    printArrayUsingPointers(array, i, cout);
  }

  return EXIT_SUCCESS;
}



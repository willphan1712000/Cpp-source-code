// Thanh Nha Phan
// CS 1337
// Lab 38
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// isIncreasingUsingIndexing:  Using indexing, this function returns
// true if the elements of the n-element array are in increasing
// order; that is, array[i] < array[i+1] for i = 0, 1, 2, ..., n-2.
// The function returns false otherwise.
bool isIncreasingUsingIndexing(const int array[], int n) {
	for (int i = 0; i < n-1; i++) {
		if (array[i] > array[i+1]) {
			return false;
		}
	}
	return true;
}

// isIncreasingUsingPointers:  Using pointers, this function returns
// true if the elements of the n-element array are in increasing
// order and false otherwise.
bool isIncreasingUsingPointers(const int *array, int n) {
	const int *p;
	for(p = &array[0]; p < &array[n-1]; p++) {
		if (*p > *(p+1)) {
			return false;
		}
	}
	return true;
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
  bool answer;
  
  i = 0;
  ptr = array;
  while (i < 100 && cin >> *ptr++)
    i++;

  if (i == 0) 
    cout << "No data" << endl;
  else
  {
    printArrayUsingPointers(array, i, cout);
    answer = isIncreasingUsingIndexing(array, i);
    cout << boolalpha;
    cout << "isIncreasingUsingIndexing(array, i) = " << answer << endl;
    answer = isIncreasingUsingPointers(array, i);
    cout << "isIncreasingUsingPointers(array, i) = " << answer << endl;
  }

  return EXIT_SUCCESS;
}

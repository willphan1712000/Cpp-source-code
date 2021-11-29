// Thanh Nha Phan
// CS 1337
// Lab 39
#include <iostream>
#include <cstdlib>
using namespace std;

// modeUsingIndexing:  Using indexing, this function returns the mode
// of the n-element integer array.  The mode is defined as the value
// which occurs most frequently in a set of data.  The count of the
// number of times the mode occurs in the array is returned via the
// third parameter.
int modeUsingIndexing(const int array[], int n, int& count) {
	int mode, fre;	// fre is frequency
	count = 0;
	for(int i = 0; i < n; i++) {
		fre = 0;
		for(int j = 0; j < n; j++) {
			if (array[j] == array[i]) {
				fre++;
			}
		}
		if (fre > count) {
			count = fre;
			mode = array[i];
		}
	}
	return mode;
}
	
// modeUsingPointers:  Using pointers, this function returns the mode
// of the n-element integer array.  The mode is defined as the value
// which occurs most frequently in a set of data.  The count of the
// number of times the mode occurs in the array is returned via the
// third parameter.
int modeUsingPointers(const int *array, int n, int& count) {
	int mode, fre;
	const int *p1, *p2;
	count = 0;
	for (p1 = &array[0]; p1 < &array[n]; p1++) {
		fre = 0;
		for (p2 = &array[0]; p2 < &array[n]; p2++) {
			if (*p2 == *p1) {
				fre++;
			}
		}
		if (fre > count) {
			count = fre;
			mode = *p1;
		}
	}
	return mode;
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
  int i, array[100], *ptr, mode, count;
  
  i = 0;
  ptr = array;
  while (i < 100 && cin >> *ptr++)
    i++;

  if (i == 0) 
    cout << "No data" << endl;
  else
  {
    printArrayUsingPointers(array, i, cout);
    mode = modeUsingIndexing(array, i, count);
    cout << "Using Indexing Mode = " << mode << " count = " << count << endl;
    mode = modeUsingPointers(array, i, count);
    cout << "Using Pointers Mode = " << mode << " count = " << count << endl;
  }

  return EXIT_SUCCESS;
}

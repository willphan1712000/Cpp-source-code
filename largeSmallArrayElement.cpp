// Thanh Nha Phan
// CS 1337
// Lab 36
#include <iostream>
#include <cstdlib>
using namespace std;

// largestUsingIndexing:  receives an n-element integer array and returns
// the index of the largest element; the function uses indexing
int largestUsingIndexing(const int array[], int n) {
	int temLargest = array[0], index = 0;
	for (int i = 1; i < n; i++) {
		if (temLargest < array[i]) {
			temLargest = array[i];
			index = i;
		}
	}
	return index;
}


// largestUsingPointers:  receives an n-element integer array and returns
// a pointer to the largest element; the function uses pointers
int *largestUsingPointers(const int *array, int n) {
	const int *p, *ptrToLargest;
	ptrToLargest = &array[0];
	for (p = &array[1]; p < &array[n]; p++) {
		if (*ptrToLargest < *p) {
			ptrToLargest = p;
		}
	}
	return const_cast<int *>(ptrToLargest);
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
  int i, array[100], *ptr, largestIndex, *largestPtr;
  
  i = 0;
  ptr = array;
  while (i < 100 && cin >> *ptr)
  {
    i++;
    ptr++;
  }

  if (i == 0) 
    cout << "No data" << endl;
  else
  {
    printArrayUsingPointers(array, i, cout);
    largestIndex = largestUsingIndexing(array, i);
    cout << "Largest Using Indexing = " << array[largestIndex]
         << " and located at index " << largestIndex << endl;
    largestPtr = largestUsingPointers(array, i);
    cout << "Largest Using Pointers = " << *largestPtr
         << " and located at index " << largestPtr - array << endl;
  }

  return EXIT_SUCCESS;
}

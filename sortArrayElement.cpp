// Thanh Nha Phan
// CS 1337
// Lab 40
#include <iostream>
using namespace std;


// selectionSortUsingPointers:  Using pointers, this function sorts
// in ascending order the n-element integer array using a selection sort.
void selectionSortUsingPointers(int *array, int n) {
	int minValue, *p1, *p2, *minPtr;
	for (p1 = &array[0]; p1 < &array[n-1]; p1++) {
		minPtr = p1;
		minValue = *p1;
		for (p2 = p1 + 1; p2 < &array[n]; p2++) {
			if (*p2 < minValue) {
				minValue = *p2;
				minPtr = p2;
			}
		}
		swap(*minPtr, *p1);
	}
}
void selectionSortUsingIndexing(int array[], int size)
{
  int minIndex, minValue;

  for (int start = 0; start < (size - 1); start++)
  {
    minIndex = start;
    minValue = array[start];
    for (int index = start + 1; index < size; index++)
    {
      if (array[index] < minValue)
      {
        minValue = array[index];
        minIndex = index;
      }
    }
    swap(array[minIndex], array[start]);
  }
}

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
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
  int i, array[100], *copyOfArray, *ptr, *ptr2;
  
  // initialize array via values read from the keyboard
  i = 0;
  ptr = array;
  while (i < 100 && cin >> *ptr++)
    i++;

  // dynamically allocate an array large enough to hold a copy of array
  try
  {
    copyOfArray = new int[i];
  }
  catch (bad_alloc error)
  {
    cerr << "Couldn't allocate memory. Exiting." << endl;
    cerr << "Exception occurred: " << error.what() << endl;
    exit(EXIT_FAILURE);
  }

  // make the copy of array element-by-element to copyOfArray
  for (ptr = array, ptr2 = copyOfArray; ptr < array + i; ++ptr, ++ptr2)
    *ptr2 = *ptr;

  if (i == 0) 
    cout << "No data" << endl;
  else
  {
    cout << "Before call to selectionSortUsingIndexing:" << endl;
    printArrayUsingPointers(array, i, cout);
    selectionSortUsingIndexing(array, i);
    cout << endl << "After call to selectionSortUsingIndexing:" << endl;
    printArrayUsingPointers(array, i, cout);

    cout << endl << "Before call to selectionSortUsingPointers:" << endl;
    printArrayUsingPointers(copyOfArray, i, cout);
    selectionSortUsingPointers(copyOfArray, i);
    cout << endl << "After call to selectionSortUsingPointers:" << endl;
    printArrayUsingPointers(copyOfArray, i, cout);
  }

  delete [] copyOfArray;

  return EXIT_SUCCESS;
}

// Thanh Nha Phan
// CS 1337
// Lab 35
#include <iostream>
#include <cstdlib>
using namespace std;

// sumUsingIndexing:  receives an n-element integer array and returns
// the sum of the elements; the function uses indexing
int sumUsingIndexing(const int array[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += array[i];
	}
	return sum;
}

// sumUsingPointers:  receives an n-element integer array and returns
// the sum of the elements; the function uses pointers
int sumUsingPointers(const int *array, int n) {
	const int *p;
	int sum = 0;
	for (p = &array[0]; p < &array[n]; p++) {
		sum += *p;
	}
	return sum;
}

void printArrayUsingIndexing(const int array[], int n, ostream& os)
{
  int i;

  if (n > 0)
  {
    os << "array" << endl << '{' << endl;
    for (i = 0; i < n; ++i)
      os << "  [" << i << "] = " << array[i] << endl;
    os << '}' << endl;
  }
}

int main()
{
  int i;
  int array[100];
  
  i = 0;
  while (i < 100 && cin >> array[i])
    i++;

  if (i == 0) 
    cout << "No data" << endl;
  else
  {
    printArrayUsingIndexing(array, i, cout);
    cout << "Sum Using Indexing = " << sumUsingIndexing(array, i) << endl;
    cout << "Sum Using Pointers = " << sumUsingPointers(array, i) << endl;
  }

  return EXIT_SUCCESS;
}

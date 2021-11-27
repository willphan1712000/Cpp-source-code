// Thanh Nha Phan
// CS 1337
// Lab 24

#include <iostream>
#include <bits.h>
#include <iomanip>

using namespace std;

extern const int N;

// printQuaternary:  Writes the quaternary representation of word to
// output stream os.
void printQuaternary(int word, ostream& os) {
	for (int i = (N - 1)/2 * 2; i >= 0; i -= 2) {
		os << getBits(word, i ,2);
	}
}

// printOctal:  Writes the octal representation of word to output
// stream os.
void printOctal(int word, ostream& os) {
	for (int i = (N - 1)/3 * 3; i >= 0; i -= 3) {
		os << getBits(word, i ,3);
	}
}

void printLine(int length, ostream& os)
{
  char ch = os.fill();
  os << setfill('-') << setw(length) << "-" << setfill(ch) << endl;
}


int main()
{
  int num;

  // Print heading
  printLine(79, cout);
  cout << setw(9) << "Decimal" << setw(24) << "Binary"
       << setw(29) << "Quaternary" << setw(14) << "Octal" << endl;
  printLine(79, cout);

  while (cin >> num)
  {
    cout << right << setw(11) << num << setw(3) << " "
         << bitset<N>(num) << setw(3) << " ";
    printQuaternary(num, cout);
    cout << setw(3) << " ";
    printOctal(num, cout);
    cout << endl;
  }

  printLine(79, cout);

  return EXIT_SUCCESS;
}

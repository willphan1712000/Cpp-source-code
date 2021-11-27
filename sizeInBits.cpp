// Thanh Nha Phan
// CS 1337
// Lab 22

#include <iostream>
#include <iomanip>
using namespace std;

// sizeOfShort determines the number of bits in the internal
// representation of a short
unsigned int sizeOfShort(void) {
	short int num = 0x1;
	unsigned int bitCount = 0;
	while (num != 0x0) {
		bitCount++;
		num <<= 1;
	}
	return bitCount;
}
// sizeOfInt determines the number of bits in the internal
// representation of an int
unsigned int sizeOfInt(void) {
	int num = 0x1;
	unsigned int bitCount = 0;
	while (num != 0x0) {
		bitCount++;
		num <<= 1;
	}
	return bitCount;
}

// sizeOfLong determines the number of bits in the internal
// representation of a long
unsigned int sizeOfLong(void) {
	long int num = 0x1;
	unsigned int bitCount = 0;
	while (num != 0x0) {
		bitCount++;
		num <<= 1;
	}
	return bitCount;
}

// sizeOfLongLong determines the number of bits in the internal
// representation of a long long
unsigned int sizeOfLongLong(void) {
	long long int num = 0x1;
	unsigned int bitCount = 0;
	while (num != 0x0) {
		bitCount++;
		num <<= 1;
	}
	return bitCount;
}


void printLine(ostream& out, int n)
{
  char ch = out.fill();
  out << setfill('-') << setw(n) << "-" << setfill(ch) << endl;
  return;
}

int main()
{
  // output table title and heading
  cout << "     Number of Bits in the" << endl
       << "  Internal Representation of" << endl
       << "Fundamental Integral Data Types" << endl;
  printLine(cout, 31);
  cout << "     Data Type      # Bits" << endl;
  printLine(cout, 31);

  cout << "     short" << setw(14) << sizeOfShort() << endl;
  cout << "     int" << setw(16) << sizeOfInt() << endl;
  cout << "     long" << setw(15) << sizeOfLong() << endl;
  cout << "     long long" << setw(10) << sizeOfLongLong() << endl;

  printLine(cout, 31);

  return EXIT_SUCCESS;
}

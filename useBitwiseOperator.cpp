// Thanh Nha Phan
// CS 1337
// Lab 19
// The purpose is to use bitwise operator to perform tasks

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

// Function isOdd returns true if num is odd and false otherwise
bool isOdd(int num) {
	if ((num & 0x1) == 0x1) {
		return true;
	}
	return false;
}
// Function isNegative returns true if num is negative and false otherwise
bool isNegative(int num) {
	// Create unsigned number with all zeros
	const unsigned int zeros = 0x0;
	// Flip all bits of created number
	const unsigned int Ones = ~zeros;
	// Shift flipped number to the rightb 1 bit
	const unsigned int leftMostBitOff = Ones >> 1;
	// Flip shifted number again
	const unsigned int leftMostBitOn = ~leftMostBitOff;
	// Create an if statement
	return ((num & leftMostBitOn) == leftMostBitOn);
}
// printBinary writes the binary representation of the integer n to
// output stream os
void printBinary(int n, ostream& os)  {
	// the purpose is to create a series of bit that has only a bit on going from left to right
	// Create all zero bits - 00000000
	const unsigned int zeros = 0x0;
	// Flip all bits - 11111111
	const unsigned int ones = ~zeros;
	// Shift 1 bit to the right - 01111111
	const unsigned int leftMostBitOff = ones >> 1;
	// Flip again - 10000000
	const unsigned int leftMostBitOn = ~leftMostBitOff;
	unsigned int currentBitOn = leftMostBitOn;
	while (currentBitOn != 0x0) {
		if ((n & currentBitOn) == currentBitOn) {
			os << "1";
		}
		else {
			os << "0";
		}
		// kepp shifting leftMostBitOn 1 bit to the right
		currentBitOn >>= 1;
	}
}

int main()
{
  int num;
  cout << "Enter n: " << endl;
  while (cin >> num) {
    cout << num << " is " << (isOdd(num) ? "odd" : "even") << endl;
    cout << num << " is " << (isNegative(num) ? "negative" : "not negative") << endl;
    cout << num << " base 10 = ";
    printBinary(num, cout);
    cout << " base 2" << endl;
  }

  return EXIT_SUCCESS;
}

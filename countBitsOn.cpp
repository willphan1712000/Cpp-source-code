// Thanh Nha Phan
// CS 1337
// Lab 23

#include <iostream>
#include <bitset>
#include <iomanip>
using namespace std;

// Returns the number of bits that are on (i.e., equal to 1) in word
unsigned int bitsOn(int n) {
	//These four lines below are to create unsigned integer bits with the only left most bit is on
	const unsigned int zeros = 0x0;
	const unsigned int ones = ~zeros;
	const unsigned int leftMostBitOff = ones >> 1;
	const unsigned int leftMostBitOn = ~leftMostBitOff;
	unsigned int currentNum = leftMostBitOn;
	//Initialize bitsOnCount to count whatever a bit is on
	int bitsOnCount = 0;
	//Create while loop
	while (currentNum != 0x0) {
		if ((n & currentNum) == currentNum) {
			bitsOnCount++;
		}
		currentNum >>= 1;
	}
	return bitsOnCount;
	
	
}
extern const int N = sizeof(int) * CHAR_BIT; // # of bits in an int
int main()
{
  int num, numBitsOn;

  while (cin >> num)
  {
    cout << num << " base 10 = ";
    cout << bitset<N>(num) << " base 2 has ";
    numBitsOn = bitsOn(num);
    cout << numBitsOn << left << setw(5) << (numBitsOn == 1 ? " bit" : " bits")
    << right << " on" << endl;
  }

  return EXIT_SUCCESS;
}

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <bitset>
#include <climits>

using namespace std;

/*
Scan word, starting from bit startingBit, toward more significant
bits, until the first 0 bit is found. Return the index of the found
bit.  If the bit at startingBit is already what's sought, then
startingBit is returned.  If there's no bit found, then UINT_MAX is
returned.
*/
unsigned int scan0(unsigned int word, unsigned int startingBit) {
	for (int presentBit = startingBit; presentBit < N; presentBit++) {
		// Use getBit to get a bit with an index of presentBit and test it whether or not it is zero
		if (getBit(word, presentBit) == 0) {
			return presentBit;
		}
	}
	return UINT_MAX;
}

extern const int N = sizeof(int) * CHAR_BIT; // # of bits in an int

int main()
{
  unsigned int i, x;

  while (cin >> x)
  {
    cout << setw(10) << x << " base 10 = " 
         << bitset<N>(x) << " base 2" << endl;
    for (i = 0; i < static_cast<unsigned int>(N); ++i)
      cout << "scan0(x, " << setw(2) << i << ") = " 
           << setw(2) << scan0(x, i) << endl;
    cout << endl;
  }

  return EXIT_SUCCESS;
}

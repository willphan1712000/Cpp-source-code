// Thanh Nha Phan
// CS 1337
// Lab 28

#include <iostream>
#include <bits.h>
#include <iomanip>

using namespace std;

// printHexadecimal:  Writes the hexadecimal representation of word to
// output stream os.
void printHexadecimal(int word, ostream& os) {
	for (int i = (N-1)/4 * 4; i >= 0; i -= 4) {
		// Create getFourBits variable to store the value of getBits function
		int getFourBits = getBits(word, i , 4);
		// Because number being less than 10 is not represented by any characters (A, B, ...)
		if (getFourBits < 10) {
			os << getFourBits;
		}
		// If not, it should be represented by corresponding character
		else {
			char hexaChar[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
			// Get each character's index in the array by getFourBits subtract 10
			os << hexaChar[getFourBits - 10];
		}
		
	}
}

void printLine(int length, ostream& os)
{
  char ch = os.fill();
  os << setfill('-') << setw(length) << "-" << setfill(ch) << endl;
}

extern const int N = sizeof(int) * CHAR_BIT; // # of bits in an int

int main()
{
  int num;

  // Print heading
  printLine(60, cout);
  cout << setw(9) << "Decimal" << setw(24) << "Binary" 
       << setw(27) << "Hexadecimal" << endl;
  printLine(60, cout);

  while (cin >> num)
  {
    cout << right << setw(11) << num << setw(3) << " "
         << bitset<N>(num) << setw(4) << " ";
    printHexadecimal(num, cout);
    cout << endl;
  }

  printLine(60, cout);

  return EXIT_SUCCESS;
}

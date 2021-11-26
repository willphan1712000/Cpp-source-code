// Thanh Nha Phan
// CS 1337
// Lab 18

#include <iostream>
using namespace std;

// Function reverseInt returns an integer whose digits are in the
// reverse order of num.  For example, if num is 1234, the returned
// integer would be 4321.
unsigned int reverseInt(unsigned int num) {
	unsigned int remainder, reverseNum = 0;
	while(num != 0) {
		remainder = num % 10;
		reverseNum = reverseNum*10 + remainder;
		num /= 10;
	}
	return reverseNum;
}

// Function generateSequence receives num (the first term in a
// sequence) and an output stream out. The function computes
// additional terms in the sequence and writes them to out. After the
// initial term, subsequent terms are computed by inverting the order
// of the decimal digits in (num + 4).  For example, if num is 4, the
// sequence generated is 4, 8, 21, 52, 65, 96, 1, 5, 9, 31, 53, 75,
// 97, 101, 501, ... The function returns which element in the
// sequence equals 1.  In the example given here, the return value is
// 6.
unsigned int generateSequence(unsigned int num, ostream& out) {
	unsigned int k = 0;
	out << num;
	while (num != 1) {
		num = reverseInt(num + 4);
		out << ", " << num;
		k++;
	}
	cout << "\n";
	return k;
}

int main()
{
  unsigned int num, k;

  while (cin >> num)
  {
    k = generateSequence(num, cout);
    cout << "n = " << num << ", " << "k = " << k << endl << endl;
  }

  return 0;
}

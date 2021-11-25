// Thanh Nha Phan
// CS 1337
// Lab 15

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

//InitializeDigits function sets each element of an array to false
void initializeDigits(bool digits[], int n, bool value) {
   for (int i = 0; i < n; i++) {
      digits[i] = false;
   }
}

//This function sets an element in the array whose index is each digit to true
void determineDigits(bool digits[], int n, int abcde) {
   int a, b, c, d, e;
   a = abcde / 10000 % 10;
   digits[a] = true;
   b = abcde / 1000 % 10;
   digits[b] = true;
   c = abcde / 100 % 10;
   digits[c] = true;
   d = abcde / 10 % 10;
   digits[d] = true;
   e = abcde / 1 % 10;
   digits[e] = true;

}

//This function is responsible for checking if all elements in the digit array are all true
bool checkDigits(const bool digits[], int n) {
   for (int i = 0; i < n; i++) {
      if (digits[i] == false) {
         return false;
      }
   }
   return true;
}

//This function creates a line of hyphens
void printLine(ostream& out, int n) {
   char ch = out.fill();
   cout << setfill('-') << setw(n) << "-" << setfill(ch) << endl;
   return;
}

int main() {
   int n;
   bool digits[10];
   printLine(cout, 13);
   cout << "  n      2n  " << endl;
   printLine(cout, 13);
   for (n = 1234; n <= 49876; n++) {
      initializeDigits(digits, 10, false);
      determineDigits(digits, 10, n);
      determineDigits(digits, 10, 2*n);
      if (checkDigits(digits, 10)) {
         cout << setfill('0') << setw(5) << n << "   " << setw(5) << 2*n << setfill(' ') << endl;
      }
   }
   printLine(cout, 13);

   return 0;
}

int main()
{
  int n;
  bool digits[10];

  printLine(cout, 13);
  cout << "  n      2n  " << endl;
  printLine(cout, 13);

  for (n = 1234; n <= 49876; ++n)
  {
    initializeDigits(digits, 10, false);
    determineDigits(digits, 10, n);
    determineDigits(digits, 10, 2 * n);
    if (checkDigits(digits, 10))
      cout << setfill('0') << setw(5) << n << "   " 
           << setw(5) << 2 * n << setfill(' ') << endl;
  }

  printLine(cout, 13);

  return 0;
}


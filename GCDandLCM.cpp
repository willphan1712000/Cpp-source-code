// Function that finds the greatest common divisor of two integers
int gcd(int u, int v) {
  if (u < 0 || v < 0) {
    u = -u;
    v = -v;
  }
  if (u == 0) {
    return u;
  }
  if (v == 0) {
    return v;
  }
  int temp;
  while(u%v > 0) {
    temp = u % v;
    u = v;
    v = temp;
  }
  return v;
}

// Function that finds the least common multiple of two integers
int lcm(int u, int v) {
  return (u*v)/gcd(u, v);
}

// Another way to do this
int main()
{
    int num1, num2, gcd;
    cout << "\n\n Find the Greatest Common Divisor of two numbers:\n";
    cout << "-----------------------------------------------------\n";
    cout << " Input the first number: ";
    cin >> num1;
    cout << " Input the second number: ";
    cin >> num2;

    for (int i = 1; i <= num1 && i <= num2; i++) 
    {
        if (num1 % i == 0 && num2 % i == 0) 
        {
            gcd = i;
        }
    }
    cout << " The Greatest Common Divisor is: " << gcd << endl;
    return 0;
}

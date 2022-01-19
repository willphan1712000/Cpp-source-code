bool isLeap(int year)
{
   bool isLeap;
   if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
      isLeap = true;
   else
      isLeap = false;
   return isLeap;
}

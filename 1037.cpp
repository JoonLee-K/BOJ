#include <iostream>
using namespace std;

int main() {

   int a;
   cin >> a;

   int smallest, largest;
   int buff;

   cin >> buff;

   smallest = buff;
   largest = buff;

   for (int i = 1; i < a; i++) {
      cin >> buff;
      if (buff < smallest) { smallest = buff; }
      else if (buff > largest) { largest = buff; }
   }

   cout << smallest * largest << endl;

   return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
   int n;
   cin >> n;

   int list[n];
   int largest = 0;

   for (int i = 0; i < n; i++) {
      cin >> list[i];
   }

   sort(list, list + n);

   for (int i = 0; i < n; i++) {
      int buff = (n - i) * list[i];
      if (largest < buff) largest = buff;
   }

   cout << largest << endl;

   return 0;
}
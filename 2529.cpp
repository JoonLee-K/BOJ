#include<iostream>
#include<vector>
using namespace std;

int main() {
   int n;
   cin >> n;
   char list[n];

   for (int i = 0; i < n; i++) {
      cin >> list[i];
   }

   vector<int> largest(1);
   int pLargest[n + 1];
   vector<int> smallest(1);
   int pSmallest[n + 1];

   int pivotL = 1;
   int pivotR = 1;

   for (int i = 1; i <= n; i++) {
      if (list[i-1] == '<') {
         largest.insert(largest.begin() + (pivotL++), i);

         smallest.__emplace_back(i);
         pivotR = 1;
      }
      else if (list[i-1] == '>') {
         largest.insert(largest.begin(), i);
         pivotL = 1;

         smallest.insert(smallest.end()-(pivotR++), i);
      }
   }

   for (int i = 0; i <= n; i++) {
      pLargest[largest[i]] = i;
   }

   for (int i = 0; i <= n; i++) {
      cout << pLargest[i] + (9 - n);
   }

   cout << endl;

   for (int i = 0; i <= n; i++) {
      pSmallest[smallest[i]] = i;
   }

   for (int i = 0; i <= n; i++) {
      cout << pSmallest[i];
   }

   cout << endl;

   return 0;
}
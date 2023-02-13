#include<iostream>
using namespace std;

int main() {

   int N, K;

   cin >> N >> K;
   int rate[N];

   for (int i = N-1; i >= 0; i--) {
      cin >> rate[i];
   }

   int i = 0;
   int count = 0;

   while(i < N) {
      if (K == 0) break;

      if (rate[i] <= K) {
         count += (K / rate[i]);
         K -= (rate[i] * (K / rate[i]));
      }
      i++;
   }

   cout << count << endl;

   return 0;
}
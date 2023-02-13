#include<iostream>
#include<queue>
using namespace std;

int main() {
   int n, m; // n가지 동전 | m원

   cin >> n >> m;
   int rate[n];

   for (int i = 0; i < n; i++) {
      cin >> rate[i];
   }

   queue<int> q;

   for (int i = 0; i < n; i++) {
      int p1 = m / rate[n];
      int p2 = m % rate[n];

      for (int j = 0; j <= p1; j++) {
         
      }
   }

}
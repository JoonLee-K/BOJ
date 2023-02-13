#include<iostream>
#include<vector>
using namespace std;

int main() {
   int stairs;
   cin >> stairs;

   vector<int> rate(stairs + 1, 0); // rate
   vector<int> dp(301);

   for(int i = 1; i <= stairs; i++) {
      int buff;
      cin >> buff;
      rate[i] = buff;
   }

   dp[0] = 0;
   dp[1] = 0 + rate[1];
   dp[2] = rate[1] + rate[2];

   for (int i = 3; i <= stairs; i++) {
      dp[i] = rate[i] + rate[i-1] + dp[i - 3] >= rate[i] + dp[i - 2] ? rate[i] + rate[i-1] + dp[i - 3] : rate[i] + dp[i - 2];
   }

   cout << dp[stairs] << endl;

   return 0;
}
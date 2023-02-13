#include<iostream>
using namespace std;

int main() {

   ios_base::sync_with_stdio(false);
	cin.tie(NULL);
   int buff;
   cin >> buff;

   int dp[1000] = {0,};
   dp[0] = 1;
   dp[1] = 3;

   for (int i = 2; i < buff; i++) {
      dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
   }
   cout << dp[buff - 1] << endl;

   return 0;
}
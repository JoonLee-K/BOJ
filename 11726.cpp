#include<iostream>
#include<vector>
using namespace std;
int main() {

   ios_base::sync_with_stdio(false);
	cin.tie(NULL);
   int buff;
   cin >> buff;

   vector<int> dp(1001, 0);
   dp[1] = 1;
   dp[2] = 2;

   for (int i = 3; i <= buff; i++) {
      dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
   }

   cout << dp[buff] << endl;

   return 0;
}
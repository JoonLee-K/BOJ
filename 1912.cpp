#include <iostream>
#include <vector>
using namespace std;

int main() {
   int n;
   cin >> n;

   vector<int> nums(n + 1, 0);

   for (int i = 0; i < n; i++) {
      int buff;
      cin >> buff;
      nums[i] = buff;
   }

   int dp[n];
   dp[0] = nums[0];
   int largest = nums[0];

   for(int i = 1; i < n; i++) {
      dp[i] = dp[i-1] + nums[i] > nums[i] ? dp[i-1] + nums[i] : nums[i];
      largest = largest > dp[i] ? largest : dp[i];
   }

   cout << largest << endl;

   return 0;
}
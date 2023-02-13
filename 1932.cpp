#include<iostream>
#include<vector>
using namespace std;

int main() {

   int n;
   cin >> n;
   vector<vector <int> > tri(n, vector<int>() );

   for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
         int buff;
         cin >> buff;
         tri[i].__emplace_back(buff);
      }
   }

   for (int i = n - 1; i > 0; i--) {
      for (int j = 0; j < i; j++) {
         tri[i - 1][j] += tri[i][j] > tri[i][j + 1] ? tri[i][j] : tri[i][j + 1];
         int test = tri[i][j] > tri[i][j + 1] ? tri[i][j] : tri[i][j + 1];
      }
   }

   cout << tri[0][0] << endl;

   return 0;
}
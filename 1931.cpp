#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

   vector< vector<int> > list(1, vector<int>());
   int n, m = 214748364-1, M = 0;
   cin >> n;

   for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      m = m > a ? a : m;
      M  = M < b ? b : M;

      if (M >= list.size()) {
         list.resize(M+1);
      }

      list[a].__emplace_back(b);
   }
   vector<int> possiblity(M + 1, 0);
   int largest = 0;

   for (int i = m; i <= M; i++) {

      sort(list[i].begin(), list[i].end());

      largest = largest < possiblity[i] ? possiblity[i] : largest;

      for (int j = 0; j < list[i].size(); j++) {
         possiblity[list[i][j]] = largest + 1;
         largest = largest < possiblity[i] ? possiblity[i] : largest;
      }
   }

   cout << largest << endl;

   return 0;
}
#include<iostream>
#include<utility>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

void dfs(vector< vector<int> > &houses, int x, int y, vector< vector<bool> > &map, int &count);

int main() {

   int m;
   cin >> m;

   vector< vector<int> > houses(m + 2, vector<int>(m + 2));
   vector< vector<bool> > map(m + 2, vector<bool>(m + 2));
   stack< pair<int, int> > s;

   for (int i = 1; i <= m; i++) {
      char buff[m];
      cin >> buff;
      for (int j = 1; j <= m; j++) {
         houses[i][j] = buff[j-1] - 48; // char을 int로 변환
         if (houses[i][j] == 1) s.push(make_pair(i, j));
      }
   }

   int c = 0;

   vector<int> print;

   while(!s.empty()) {
      int pinx = s.top().first;
      int piny = s.top().second;

      if (map[pinx][piny] == false) {
         c++;
         map[pinx][piny] = true;
         int result = 0;
         dfs(houses, pinx, piny, map, result);
         print.emplace_back(result);
      }

      s.pop();
   }
   cout << c << endl;

   sort(print.begin(), print.end());

   for (int i = 0; i < print.size(); i++) cout << print[i] << endl;

   return 0;
}

void dfs(vector< vector<int> > &houses, int x, int y, vector< vector<bool> > &map, int &count) {
   count = count + 1;
   for (int i = 0; i < 4; i++) {
      if (i == 0) {
         if (!map[x][y - 1] && houses[x][y - 1] == 1) {
            map[x][y - 1]  = true;
            dfs(houses, x, y - 1, map, count);
         }
      }

      else if (i == 1) {
         if (!map[x + 1][y] && houses[x + 1][y] == 1) {
            map[x + 1][y]  = true;
            dfs(houses, x + 1, y, map, count);
         }
      }

      else if (i == 2) {
         if (!map[x][y + 1] && houses[x][y + 1] == 1) {
            map[x][y + 1]  = true;
            dfs(houses, x, y + 1, map, count);
         }
      }

      else if (i == 3) {
         if (!map[x - 1][y] && houses[x - 1][y] == 1) {
            map[x - 1][y]  = true;
            dfs(houses, x - 1, y, map, count);
         }
      }
   }
}
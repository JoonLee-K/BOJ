#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int main() {
   int n, m;

   cin >> n >> m;

   vector< vector<int> > map(n + 2, vector<int>(m + 2) );
   vector< vector<bool> > visit(n + 2, vector<bool>(m + 2, false) );

   for (int i = 1; i <= n; i++) {
      char nums[m];
      cin >> nums;
      for (int j = 1; j <= m; j++) {
         map[i][j] = nums[j-1] - 48;
      }
   }

   queue< pair<int, pair<int, int> > > q;
   q.push(make_pair(1, make_pair(1, 1)));

   while(!q.empty()) {

      int count = q.front().first;
      int x = q.front().second.first;
      int y = q.front().second.second;

      if (x == n && y == m) {
         cout << count << endl;
         break;
      }

      if (map[x][y + 1] == 1 && !visit[x][y + 1]) {
         visit[x][y + 1] = true;
         q.push(make_pair(count + 1, make_pair(x, y + 1)));
      }
      if (map[x + 1][y] == 1 && !visit[x + 1][y]) {
         visit[x + 1][y] = true;
         q.push(make_pair(count + 1, make_pair(x + 1, y)));
      }
      if (map[x][y - 1] == 1 && !visit[x][y - 1]) {
         visit[x][y - 1] = true;
         q.push(make_pair(count + 1, make_pair(x, y - 1)));
      }
      if (map[x - 1][y] == 1 && !visit[x - 1][y]) {
         visit[x - 1][y] = true;
         q.push(make_pair(count + 1, make_pair(x - 1, y)));
      }

      q.pop();
   }

}
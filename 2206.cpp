#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int main() {
   int n, m;

   cin >> n >> m;

   vector< vector<int> > map(n + 4, vector<int>(m + 4, 1));
   vector< vector<bool> > visit(n + 4, vector<bool>(m + 4, false));

   for (int i = 2; i < map.size()-2; i++) {
      char buff[m];
      cin >> buff;
      for (int j = 2; j < map[i].size()-2; j++) {
         map[i][j] = buff[j-2] - 48;
      }
   }

   queue< pair< pair< int, int >, pair<int, bool> > > q;

   q.push(make_pair(make_pair(2, 2), make_pair(1, false) ) ); // 테투리 2크기로 둘렀기에 여기서 시작점은 2, 2임
   visit[2][2] = true;
   int c = -1;

   while(!q.empty()) {
      int y = q.front().first.first;
      int x = q.front().first.second;
      int count = q.front().second.first;
      bool jumped = q.front().second.second;

      if (x == m + 1 && y == n + 1) {
         cout << count << endl;
         c++;
         break;
      }

      if (map[y][x + 1] == 1 && !visit[y][x + 1] && !jumped ) {
         visit[y][x + 1] = true;
         q.push(make_pair(make_pair(y, x + 1), make_pair(count + 1, !jumped)));
      }
      if (map[y + 1][x] == 1 && !visit[y + 1][x] && !jumped ) {
         visit[y + 1][x] = true;
         q.push(make_pair(make_pair(y + 1, x), make_pair(count + 1, !jumped)));
      }
      if (map[y][x - 1] == 1 && !visit[y][x - 1] && !jumped ) {
         visit[y][x - 1] = true;
         q.push(make_pair(make_pair(y, x - 1), make_pair(count + 1, !jumped)));
      }
      if (map[y - 1][x] == 1 && !visit[y - 1][x] && !jumped ) {
         visit[y - 1][x] = true;
         q.push(make_pair(make_pair(y - 1, x), make_pair(count + 1, !jumped)));
      }


      if (map[y][x + 1] == 0 && !visit[y][x + 1]) {
         visit[y][x + 1] = true;
         q.push(make_pair(make_pair(y, x + 1), make_pair(count + 1, jumped)));
      }
      if (map[y + 1][x] == 0 && !visit[y + 1][x]) {
         visit[y + 1][x] = true;
         q.push(make_pair(make_pair(y + 1, x), make_pair(count + 1, jumped)));
      }
      if (map[y][x - 1] == 0 && !visit[y][x - 1]) {
         visit[y][x - 1] = true;
         q.push(make_pair(make_pair(y, x - 1), make_pair(count + 1, jumped)));
      }
      if (map[y - 1][x] == 0 && !visit[y - 1][x]) {
         visit[y - 1][x] = true;
         q.push(make_pair(make_pair(y - 1, x), make_pair(count + 1, jumped)));
      }

      q.pop();
   }

   if (c == -1) cout << c << endl;

   return 0;
}
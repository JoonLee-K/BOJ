#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int main() {

   int n, m; // 차례로 수빈, 동생
   cin >> n >> m;

   queue< pair<int, int> > qq;
   bool visit[100001] = {false, };

   qq.push(make_pair(n, 0));
   visit[n] = true;

   while(!qq.empty()) {
      pair<int, int> me = qq.front();

      if (me.first == m) {
         cout << me.second << endl;
         break;
      }

      if (me.first * 2 > 0 && me.first * 2 < 100001 && !visit[me.first * 2]) {
         int warp = me.first * 2;
         visit[me.first * 2] = true;
         qq.push(make_pair(warp, me.second + 1));
      }
      if (me.first - 1 >= 0 && me.first - 1 < 100001 && !visit[me.first - 1]) {
         int walkM = me.first - 1;
         visit[me.first - 1] = true;
         qq.push(make_pair(walkM, me.second + 1));
      }

      if (me.first + 1 >= 0 && me.first + 1 < 100001 && !visit[me.first + 1]) {
         int walkP = me.first + 1;
         visit[me.first + 1] = true;
         qq.push(make_pair(walkP, me.second + 1));
      }

      qq.pop();
   }

   return 0;
}
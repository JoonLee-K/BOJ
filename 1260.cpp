#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(vector< vector<int> > &vec, int pin, vector<bool> &map);
void bfs(vector< vector<int> > &vec, int pin, vector<bool> &map);

int main () {
   int v, e, p;

   cin >> v >> e >> p;

   vector< vector<int> > vec(v + 1);

   for (int i = 0; i < e; i++) {

      int a, b;
      cin >> a >> b;

      vec[a].emplace_back(b);//.push_back(b);
      vec[b].emplace_back(a);
   }

   // sort(v.begin(), v.end());
   for (int i = 1; i < v + 1; i++) {
      sort(vec[i].begin(), vec[i].end());
   }

   // make dfs
   vector<bool> map(v + 1, false);
   dfs(vec, p, map);
   cout << endl;

   // make bfs
   map = vector<bool>(v + 1, false);
   bfs(vec, p, map);
   cout << endl;

   return 0;
}

void bfs(vector< vector<int> > &vec, int pin, vector<bool> &map) {

   queue<int> q;
   q.push(pin);
   cout << pin << " ";
   map[pin] = true;
   
   while(!q.empty()) {
      for (int i = 0; i < vec[q.front()].size(); i++) {
         if (map[vec[q.front()][i]] == false) {
            map[vec[q.front()][i]] = true;
            q.push(vec[q.front()][i]);
            cout << vec[q.front()][i] << " ";
         }
      }

      q.pop();
   }
}

void dfs(vector< vector<int> > &vec, int pin, vector<bool> &map) {

   if (map[pin] != true) {
      map[pin] = true;
      cout << pin << " ";
   }
   else {
      return;
   }

   for (int j = 0; j < vec[pin].size(); j++) {
      int buff = vec[pin][j];
      dfs(vec, buff, map);
   }
}
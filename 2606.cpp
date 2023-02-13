#include<iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
   int v;
   cin >> v;

   int e;
   cin >> e;

   vector<bool> comsMap(v, false);
   vector< vector<int> > comsTable(v + 1, vector<int>() );

   for (int i = 0; i < e; i++) {
      int a, b; // buffer
      cin >> a >> b;
      comsTable[a].__emplace_back(b);
      comsTable[b].__emplace_back(a);
   }

   queue<int> q;

   q.push(1);
   int c = -1;

   while(!q.empty()){
      for(int i = 0; i < comsTable[q.front()].size(); i++){
         int toGo = comsTable[q.front()][i];
         if (comsMap[toGo] == false)  {
            comsMap[toGo] = true;
            q.push(toGo);
            c++;
         }
      }
      q.pop();
   }

   cout << c << endl;
   return 0;
}
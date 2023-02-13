#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int main() {

   int num;

   cin >> num;
   queue<pair<int, int> > q;

   q.push(make_pair(num, 0));

   while(!q.empty()) {
      int n = q.front().first;
      int count = q.front().second;

      if (n == 1) {
         cout << count << endl;
         break;
      }

      if (n % 3 == 0) {
         q.push(make_pair(n / 3, count + 1));
      }


      if (n % 2 == 0) {
         q.push(make_pair(n / 2, count + 1));
      }

      q.push(make_pair(n - 1, count + 1));

      q.pop();
   }

   return 0;
}
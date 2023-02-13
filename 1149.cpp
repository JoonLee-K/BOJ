#include<iostream>
#include<vector>
using namespace std;

int main() {
   int h;
   cin >> h;  

   vector<vector<int> > price(h, vector<int>(3) );

   for (int i = 0; i < h; i++) {
      int buff[3];
      cin >> buff[0] >> buff[1] >> buff[2];

      price[i][0] = buff[0];
      price[i][1] = buff[1];
      price[i][2] = buff[2];
   }

   for (int i = 0; i < h-1; i++) {
      price[i + 1][0] += price[i][1] < price[i][2] ? price[i][1] : price[i][2];
      price[i + 1][1] += price[i][0] < price[i][2] ? price[i][0] : price[i][2];
      price[i + 1][2] += price[i][0] < price[i][1] ? price[i][0] : price[i][1];
   }

   int s = 1000003;

   for (int i = 0; i < 3; i++) {
      s = s > price[h-1][i] ? price[h-1][i] : s;
   }
   
   cout << s << endl;

   return 0;
}
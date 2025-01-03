#include <bits/stdc++.h>
using namespace std;
int main() 
{ 
   list<int>list;
   int val;
   while(true){
    cin >> val;
    if(val == -1){
        break;
    }
    list.push_back(val);
   }
   list.sort();
   list.unique();

   for(int val : list){
    cout << val << " ";
   }
    return 0; 
} 
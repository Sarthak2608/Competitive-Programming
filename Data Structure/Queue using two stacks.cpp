/*
  Queue using two stacks 
*/
#include <bits/stdc++.h>
using namespace std;


stack<int> st1,st2;

void add_queue(int val)
{
  st1.push(val);
}

int pop_queue()
{
   if(st2.size()==0)
   {
     while(st1.size()!=0)
     {
       st2.push(st1.top());
       st1.pop();
     }
   }

  if(st2.size()==0)
    return -1;
  int val=st2.top();
  st2.pop();
  return val;
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

 for(int i=1;i<=5;i++)
 {
  add_queue(i);
 }
 for(int i=1;i<=10;i++)
 {
  cout<<pop_queue()<<endl;
 }
 


}

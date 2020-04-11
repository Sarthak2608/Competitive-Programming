/*
  queue using two stack
*/
#include <bits/stdc++.h>
using namespace std;


stack<array<int,2>> st;

int minimum_in_stack()
{
  int val=INT_MAX;
  if(st.size()!=0)
  {
    val=st.top()[1];
  }
  return val;
}

void add_stack(int val)
{
  if(st.size()==0)
    st.push({val,val});
  else
    st.push({val,min(minimum_in_stack(),val)});
}

int pop_stack()
{
  int val=-1;
  if(st.size()!=0)
  {
     val=st.top()[0];
     st.pop();
  }
  return val;
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

 for(int i=1;i<=5;i++)
 {
  add_stack(rand()%10+1);
 }
 for(int i=1;i<=10;i++)
 {
  cout<<minimum_in_stack()<<" ";
  cout<<pop_stack()<<endl;
 }
 


}

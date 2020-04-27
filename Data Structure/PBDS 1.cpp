#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef
tree<
	int,
	null_type,
	less<int>,   //less_equal<int>
	rb_tree_tag,
	tree_order_statistics_node_update>
ordered_set;

signed main() {

     ordered_set s;
     for(int i=1;i<=11;i++)
     {
          s.insert(i);             //It Stores only unique values
          s.insert(i);
     }
     s.erase(11)                   //erase the key 
     cout<<s.order_of_key(11)<<endl;  //returns the number of elemnets which are smaller than 11
      
     for(int i=0;i<=9;i++)      
     cout<<*s.find_by_order(i)<<endl;   //return the ith smallest element
     
	return 0;
}

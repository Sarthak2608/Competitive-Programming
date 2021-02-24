/*
https://www.youtube.com/watch?v=hVl2b3bLzBw
*/
#include <bits/stdc++.h> 
using namespace std; 



class Solution{
    public:
        void merge(int arr1[], int arr2[], int n, int m) 
        { 
            // code here 
            /*
            Algorithm
            initialise gap=n+m
                then for each i 
                    if arr[i]>arr[i+gap]
                    then swap
                gap=ceil(gap/2)
            */
            int gap=(n+m+1)/2;
            while(gap>0)
            {
                int *x1,*y1;
                for(int i=0;i+gap<n+m;i++)
                {
                    int x=i;
                    int y=i+gap;
                    if(x>=n){
                        x-=n;
                        x1=&arr2[x];
                    }
                    else{
                        x1=&arr1[x];
                    }
                    if(y>=n){
                        y-=n;
                        y1=&arr2[y];
                    }
                    else{
                        y1=&arr1[y];
                    }
                    if(*x1>*y1){
                        int z=*x1;
                        *x1=*y1;
                        *y1=z;
                    }
                }
                if(gap==1)
                break;
                gap=(gap+1)/2;
            }
        } 
};

// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    int arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            printf("%d ", arr1[i]); 
        
       
	    for (int i = 0; i < m; i++) 
		    printf("%d ", arr2[i]); 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends

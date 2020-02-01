/*
Permutaion of length 4
Idx: 0		0 1 2 3 					
Idx: 1		0 1 3 2 					
Idx: 2		0 2 1 3 				
Idx: 3		0 2 3 1 					
Idx: 4		0 3 1 2 				
Idx: 5		0 3 2 1 					
Idx: 6		1 0 2 3
Idx: 7		1 0 3 2
Idx: 8		1 2 0 3
Idx: 9		1 2 3 0
Idx: 10		1 3 0 2
Idx: 11		1 3 2 0
Idx: 12		2 0 1 3
Idx: 13		2 0 3 1
Idx: 14		2 1 0 3
Idx: 15		2 1 3 0
Idx: 16		2 3 0 1
Idx: 17		2 3 1 0
Idx: 18		3 0 1 2
Idx: 19		3 0 2 1
Idx: 20		3 1 0 2
Idx: 21		3 1 2 0
Idx: 22		3 2 0 1
Idx: 23		3 2 1 0
*/






int FindIndexOfpermutaion(vector<int> v)
{
      int l=v.size();
      int fact[l+1];
      fact[0]=1;
      for(int i=1;i<=l;i++)
      {
          fact[i]=fact[i-1]*i;
      } 
      
      int ans=0;
      for(int i=0;i<v.size();i++)
      {
          ans+=fact[l-i-1]*v[i];
          for(int j=i+1;j<l;j++)
          {
              if(v[j]>v[i])
              v[j]-=1;
          }
      }
      return ans;
}

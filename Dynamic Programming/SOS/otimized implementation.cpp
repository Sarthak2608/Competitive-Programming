/*
optimized
https://codeforces.com/blog/entry/45223
*/


int N=30;
int F[5+1ll<<N];

for(int i = 0;i < N; ++i) for(int mask = (1ll<<N)-1; mask >=0 ; --mask){
    if(mask & (1<<i))
      F[mask] += F[mask^(1<<i)];
} 

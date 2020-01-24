/*
  a=a1*(10^20)+a2
  b=b1*(10^20)+b2
  a*b= (a1*b2+a2*b1)*(10^20) + (a2*b2) +a1*b1*(10^40)
  Time Complexity = O(1) 
 */


long long multiply(long long a,long long b,long long m)
{
    long long a1=a>>20;
    long long a2=a&1048575;
    long long b1=b>>20;
    long long b2=b&1048575;
    return (a2*b2 + ((a1*b2+a2*b1)<<20) + ((a1*b1<<20)%m<<20))%m;
}

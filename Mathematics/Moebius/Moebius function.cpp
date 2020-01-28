/*
if n is a squared prime factor number then U(n)=0;
U(1)=1
if n is a square free number with even number of prime factor then U(n)=1
if n is a square free number with odd number of prime factor then U(n)=-1
*/

int moebius(int n)
{
    int val=1;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(n%(i*i)==0)
            return 0;
            val*=-1;
        }
    }
    if(n>1)
    val*=-1;
    return val;
}


/*
If p is prime because then p%i will always coprime with p

(p%i)%p = ( p-(p/i)*i )%p
(p%i)%p = ( -(p/i)*i )%p

divide by (p%i)*i

(1/i)%p= ( -(p/i)/(p%i) )%p
inv[i]%p= ( p -(p/i)*inv[p%i] )%p

*/
void modInverse(int p)
{
    vector<int> inv(p,1);
    for(int i=2;i<p;i++)
    {
        inv[i]=(p-((p/i)*inv[p%i])%p)%p;
    }
}

/*
if m is prime then phi(m)=m-1
*/

ll modInverse(ll a ,ll m)
{
  return pow(a,phi(m)-1,m);
}

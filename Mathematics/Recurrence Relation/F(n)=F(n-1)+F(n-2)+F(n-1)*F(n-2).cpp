/*
https://www.codechef.com/problems/ECODOWN
https://www.codechef.com/viewsolution/31905220
https://codeforces.com/blog/entry/76076

 F(n)=F(n-1)+F(n-2)+F(n-1)*F(n-2)
 (1+F(n))=(1+F(n-1))*(1+F(n-2))
 G(n)=G(n-1)*G(n-2)
 log(G(n))=log(G(n-1)) + log((G(n-2))
 H(n) = H(n-1) + H(n-2)
 
 | H(n-1) | = | 0 1 |^n * |H(0)|
 | H(n)   | = | 1 1 |     |H(1)|
 A=BC(Above matrix)
 
 G(n)%mod= 2^( H(n))%(mod-1) ) %mod
 
 G(n)%mod =2^( {B[1][0]*H(0) +B[1][1]*H(1) }%(mod-1) )%mod
 
 G(n)%mod =2^( { log((1+F(0))^B[1][0]) +log((1+F(1))^B[1][1]) }%(mod-1) )%mod
 G(n)%mod= {(1+F(0))^B[1][0]} * {(1+F(1))^B[1][1]} %mod;
 F(n)=G(n)-1
 
 
 
 
 
 

 */

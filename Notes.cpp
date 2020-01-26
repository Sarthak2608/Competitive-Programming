
int com_double(double a,double b)
{
  if(fabs(a-b)<1e-10)
  {
      return 0;
  }
  return a>b?1:-1;
}

/* 
Rounding Functions in C++

round(4.7)=4.8
trunc(4.6200)=4
fabs(2.38-2.1)=0.28
*/

/*Number of Digtits in base b = 1 + floor( log b (N) )
Example : 
In base 10 ,N=1430 ,
here number of digits=1+floor(3.15)=4
*/

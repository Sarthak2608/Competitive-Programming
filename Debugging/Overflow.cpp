if( a*b > INT_MAX)
return 0;
//or
if( a > INT_MAX/b)
return 0;

// check a*b*c > MAX
if( a > INT_MAX/b || a*b > INT_MAX /c)
return 0;

//chack a*b+c>MAX
if( a > INT_MAX/b || a*b>INT_MAX-c)
return 0;

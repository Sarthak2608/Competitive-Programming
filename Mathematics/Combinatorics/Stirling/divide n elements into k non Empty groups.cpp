/*
Apply Memorisation 
Idea:
Element 1 have the choices of k groups or it will go into any group and then this group will not take any other element.
*/

int stirling(int n,int k)
{
    if(n==k||k==1)
    return 1;
    
    return k*stirling(n-1,k)+stirling(n-1,k-1);
}

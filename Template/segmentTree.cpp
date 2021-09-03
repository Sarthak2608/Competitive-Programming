struct node
{
  int x;
  int prop;
  node(){
    prop=0;
    x=0;
  }
}; 

class SegmentTree{

    public:

    vector<node> bit;

    vector<int> a;

    void init(int n,vector<int> &b){
        bit=vector<node>(4*n+5);
        a=b;
    }

    node merge(node a,node b)
    {
      node c;
     
      return c;
    }

    void build(int id,int l,int r)
    {
      if(l==r)
      {
          
          return;
      }
      int mid=(l+r)/2;
      build(2*id,l,mid);
      build(2*id+1,mid+1,r);
      bit[id]=merge(bit[2*id],bit[2*id+1]);
    }
    void propagate(int id,int l,int r){
        int mid=(l+r)/2;
        if(2*id<bit.size()){
        }
        if(2*id+1<bit.size()){
            
        }

        bit[id].prop=0;
    }
    node get(int id,int l,int r,int L,int R)
    {
      propagate(id,l,r);
      if(R<l||r<L){
        node c;
        
        return c;
      }
      if(L<=l&&r<=R)
      {
        return bit[id];
      }
      int mid=(l+r)/2;
      return merge(get(2*id,l,mid,L,R),get(2*id+1,mid+1,r,L,R));
    }
     
    void upd(int id,int l,int r,int L,int R,int v)
    {
      propagate(id,l,r);
      if(R<l||r<L)
        return;
      if(L<=l&&r<=R)
      {
        
        return;
      }
      int mid=(l+r)/2;
      upd(2*id,l,mid,L,R,v);
      upd(2*id+1,mid+1,r,L,R,v);
      bit[id]=merge(bit[2*id],bit[2*id+1]);
    }

};

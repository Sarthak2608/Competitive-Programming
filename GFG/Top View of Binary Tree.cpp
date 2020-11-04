
//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree


deque<array<int,2>> q;
int d;
void dfs(Node *node,int x,int level=0)
{
    if(node==NULL)
    return ;
    if(x<d)
    {
        d--;
        q.push_front({INT_MAX,INT_MAX});
    }
    if(((int)q.size()+d-1)<x)
    {
        q.push_back({INT_MAX,INT_MAX});
    }
    q[x-d]=min(q[x-d],{level,node->data});
    dfs(node->left,x-1,level+1);
    dfs(node->right,x+1,level+1);
}

void topView(struct Node *root)
{
    q.clear();
    d=0;
    q.push_back({INT_MAX,INT_MAX});
    dfs(root,0);
    while(q.size())
    {
        cout<<q.front()[1]<<" ";
        q.pop_front();
    }

    
}



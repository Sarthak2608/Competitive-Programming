class WordDictionary {
public:
    const int N=1e5;
    int** link;
    int *tot;    
    int sz;
    
    /** Initialize your data structure here. */
    WordDictionary() {
        sz=1;
        tot=new int [N];
        for(int i=0;i<N;i++)
            tot[i]=0;
        link=new int* [N];
        link[1]=new int[26];
        for(int j=0;j<26;j++)
            link[1][j]=-1;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int root=1;
        for(auto &i:word)
        {
            if(link[root][i-'a']==-1){
                link[root][i-'a']=++sz;
                link[sz]=new int[26];
                for(int j=0;j<26;j++)
                    link[sz][j]=-1;
            }
            root=link[root][i-'a'];
  //          cout<<i<<" "<<root<<endl;
        }
        tot[root]++;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool find(string &word,int node,int pos)
    {
        if(pos==word.size())
            return false;
        int i=0,j=25;
        if(word[pos]==i+'a')
        {
            i=word[pos]-'a';
            j=i;
        }
        for(;i<=j;i++)
        {
            if(link[node][i]==-1)
                continue;
            if(word[pos]==i+'a'||word[pos]=='.')
            {
                if(pos+1==word.size()&&tot[link[node][i]])
                    return 1;
                
                if(find(word,link[node][i],pos+1))
                    return true;
            }
        }
        return false;
    }
    bool search(string word) {
     return find(word,1,0);   
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

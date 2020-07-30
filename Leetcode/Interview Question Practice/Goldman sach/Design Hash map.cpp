/*
https://leetcode.com/problems/design-hashmap/
*/

class MyHashMap {
public:
    /** Initialize your data structure here. */
    int sz;
    vector<list<array<int,2>>> v;
    MyHashMap() {
        sz=1331;
        v.resize(sz+1);
    }
    int hash(int key)
    {
        return key%sz;
    }
    list<array<int,2>>::iterator find(int key)
    {
        int k=hash(key);
        auto it=find_if(v[k].begin(),v[k].end(),[key](array<int,2> a){
           return (a[0]==key); 
        });
        return it;
    }
    /** value will always be non-negative. */
    void put(int key, int value) {
       
        int k=hash(key);
        auto it=find(key);
        if(it==v[k].end())
        {
            v[k].push_back({key,value});
        }
        else
        {
            (*it)[1]=value;
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
         int k=hash(key);
        auto it=find(key);
        if(it==v[k].end())
        {
           return -1;
        }
        else
        {
            return (*it)[1];
        }
        return 0;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int k=hash(key);
        auto it=find(key);
        if(it!=v[k].end())
        {
            v[k].erase(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

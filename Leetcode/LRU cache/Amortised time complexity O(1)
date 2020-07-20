/*
https://leetcode.com/problems/lru-cache/
*/
class LRUCache {
public:
    int sz,c;
    deque<int> q;
    unordered_map<int,int> mp,mp2;
    LRUCache(int capacity) {
        sz=0;
        c=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        q.push_back(key);
        mp2[key]++;
        return mp[key];
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            mp[key]=value;
            q.push_back(key);
            mp2[key]++;
            return;
        }
        
        if(sz<c)
        {
            sz++;
            mp[key]=value;
            q.push_back(key);
            mp2[key]++;
            return;
        }
        
        
        while(mp2[q.front()]>1)
        {
            mp2[q.front()]--;
            q.pop_front();
        }
        mp.erase(q.front());
   //     cout<<q.front()<<endl;
        mp2[q.front()]--;
        q.pop_front();
            
        mp[key]=value;
        q.push_back(key);
        mp2[key]++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

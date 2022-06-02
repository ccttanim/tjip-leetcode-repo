class Skiplist {
public:
    int mp[100000];
    Skiplist() {
        memset(mp,0,sizeof(mp));
    }
    
    bool search(int target) {
         return mp[target];
    }
    
    void add(int num) {
        mp[num]++;
    }
    
    bool erase(int num) {
         if(mp[num]) {
             mp[num]--;
             return true;
         }else {
             return false;
         }
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */

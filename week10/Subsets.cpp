class Solution {
public:
    void store(int ind, vector<vector<int>>& ret,vector<int>& s, vector<int>& nums, int n){
        if(ind==n){
            ret.push_back(s);
            return;
        }
       
        s.push_back(nums[ind]);
        store(ind+1,ret,s,nums,n);
        s.pop_back();
        
        store(ind+1,ret,s,nums,n);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();
        vector<int> s;
        store(0,ret,s,nums,n);
        return ret;
    }
};

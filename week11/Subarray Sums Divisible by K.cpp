class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
     
        unordered_map<int,int> mp;
        mp[0]++;
        
        int n = nums.size();
        int temp = 0;
        
        int count = 0;
        
        for(int i=0;i<n;i++){
            temp = temp + nums[i];
            
           
            int mod = (temp % k + k) % k;
            
            if(mp.find(mod) != mp.end()){
                count = count + mp[mod];
                mp[mod]++;
            }else{
                mp[mod]++;
            }
        }
        
        
        return count;
    }
};

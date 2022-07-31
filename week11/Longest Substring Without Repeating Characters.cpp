class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set <char> hash;
        
        int oi = 0;
        int ci = 0;
        
        int max = 0;
        
       
        
      
        
        while (oi < s.length() && ci < s.length())
        {
            for (int i = oi; i <= ci; i++)
            {
                char ch = s[i];
                
                if (hash.count(ch) <= 0)
               
                {
                    hash.insert (ch);
                }
                
                else
                
                {
                    if (hash.size() > max)
                    {
                        max = hash.size();
                    }
                    
                    hash.erase (s[oi]);
                    oi++;
                    break;
                }
            }
            if (hash.size() > max)
            {
                max = hash.size();
            }
            
            ci++;
            hash.clear();
        }
        
        return max;
    }
};

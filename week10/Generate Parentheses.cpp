class Solution {
public:

void find_vali_combination(string temp , vector<string> & res , int n , int open,int close){
    
  
    
    if(open==0 and close ==0){
        
        res.push_back(temp);
        return;
    }
    
    
    if(open>0)
    {
        find_vali_combination(temp+"(" , res , n , open-1,close);
        
    }
    
    
    if(close>0 and close>open){
        
        find_vali_combination(temp+")" ,res  , n , open , close-1);
    }
    
   
}
vector<string> generateParenthesis(int n) {
    
    
    string temp ="";
    
    
    vector<string>res ;
    
    int open = n , close=n;
    find_vali_combination(temp ,res ,n,open , close);
    
    return res;
    
}
};

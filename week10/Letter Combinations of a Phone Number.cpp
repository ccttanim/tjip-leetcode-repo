class Solution {
    vector<string>buttons{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>res;
    string temp;
public:
    void help(string &d,int l){
        if(d.size()==0)
            return;
        if(l==d.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<buttons[d[l]-'0'].size();i++){
            temp+=buttons[d[l]-'0'][i];
            help(d,l+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        help(digits,0);
        return res;
    }
};

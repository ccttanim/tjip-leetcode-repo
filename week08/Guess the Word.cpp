/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int calculateScore(string &ref, string &cand)
    {
        int res = 0;
        for(int i = 0;i<ref.size();i++)
            res += ref[i] == cand[i];
        return res;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        while(wordlist.size() > 1)
        {
            int rdx = rand() % wordlist.size();
            string query_string = wordlist[rdx];
            vector<string> newlist;
            for(auto &wd : wordlist)
            {
                if(calculateScore(wd, query_string) == score)
                    newlist.push_back(wd);
            }
            wordlist = newlist;
        }
        master.guess(wordlist[0]);
    }
};

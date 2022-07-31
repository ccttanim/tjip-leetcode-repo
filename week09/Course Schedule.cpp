class Solution {
public:
    vector<vector<int>>g;
    vector<int> vis, tp;
    bool bfs(int s)
    {
        vis[s]=1, tp[s]=1;
        for(auto e:g[s])
        {
            if(!vis[e]){
                if(bfs(e)) return true;
            }
            else if(tp[e]) return true;
        }
        tp[s]=0;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& p) {
        g.resize(n), vis.resize(n,0), tp.resize(n,0);
        for(auto e:p) g[e[0]].push_back(e[1]);
        for(int i=0; i<n;i++) if(!vis[i]) if(bfs(i)) return false;
        return true;
    }
};

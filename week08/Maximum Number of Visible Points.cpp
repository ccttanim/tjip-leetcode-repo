
// Time:  O(nlogn)
// Space: O(n)
public:
    double getAngle(int x, int y)
    {
        return atan2(y, x) * (180 / M_PI);
    }
    
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) 
    {
        int result = 0;
        vector<double> angels;
        for (int i = 0; i < points.size(); i++)
        {
            int xDiff = points[i][0] - location[0];
            int yDiff = points[i][1] - location[1];
            
            if (xDiff == 0 && yDiff == 0)
            {
                result++;
            }
            else
            {
                double angle = getAngle(xDiff, yDiff);
                if (angle < 0)
                {
                    angle += 360;
                }
                
                angels.push_back(angle);
            }
        }
        
        sort(angels.begin(), angels.end());
        int n = angels.size();
        for (int i = 0; i < n; i++)
        {
            angels.push_back(angels[i] + 360);
        }
        
        int start = 0;
        int end = 0;
        int maxPoints = 0;
        for (end = 0; end < 2*n; end++)
        {
            while (angels[end] - angels[start] > (double)angle)
            {
                start++;
            }
            
            maxPoints = max(maxPoints, end - start + 1);
        }
        
        return result + maxPoints;
    }
};

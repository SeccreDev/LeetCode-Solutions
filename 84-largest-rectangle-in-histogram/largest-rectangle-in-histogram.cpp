class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        priority_queue<pair<int,int>> pq;
        int ans = -1e9;
        int n = heights.size();
        for(int i=0;i<n;++i)
        {
            int idx = i;
            int x = heights[i];
            while(!pq.empty() && pq.top().first >= x)
            {
                int cal = abs(i - pq.top().second);
                ans = max(ans,cal*pq.top().first);
                idx = pq.top().second;
                pq.pop();
            }
            pq.push({x,idx});
        }
        while(!pq.empty())
        {
            int cal = abs(n - pq.top().second);
            ans = max(ans,cal*pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
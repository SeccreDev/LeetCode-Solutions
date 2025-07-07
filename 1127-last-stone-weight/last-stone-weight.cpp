
class Solution
{
    public:
        int stoneGame(priority_queue<int>pq)
        {
            int stone1, stone2, newstone = 0;
            while (pq.size() > 1)
            {
                stone1=pq.top();
                pq.pop(); 
                stone2=pq.top();
                pq.pop();
                if(stone1!=stone2)
                {
                    pq.push(stone1-stone2);
                }
            }
            if(!pq.empty())
            {
                return pq.top();
            }
            else
            {
                return 0;
            }
        }
        int lastStoneWeight(vector<int>& stones)
        {
            priority_queue<int> pq;
            for(int i=0;i<stones.size();i++)
            {
                pq.push(stones[i]);
            }
            int ans = stoneGame(pq);  
            return ans; 
        }
};
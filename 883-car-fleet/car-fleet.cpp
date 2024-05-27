class Solution
{
    public:
        int carFleet(int target, vector<int>& position, vector<int>& speed)
        {
            int size = speed.size();
            vector<pair<int,int>> positionAndSpeed;

            for(int i = 0; i < size; i++)
            {
                positionAndSpeed.push_back({position[i], speed[i]});
            }

            sort(positionAndSpeed.begin(), positionAndSpeed.end());

            int amountOfCarFleets = 0;
            double max= 0;
            for(int k = size - 1; k >= 0; k--)
            {
                double time  = 1.0 * (target - positionAndSpeed[k].first) / positionAndSpeed[k].second;
                if(time > max)
                {
                    amountOfCarFleets += 1;
                    max = time;
                }
            } 
            return amountOfCarFleets;  
        }
};
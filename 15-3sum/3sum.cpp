class Solution
{
    public:
        vector<vector<int>> threeSum(vector<int>& nums)
        {
            sort(nums.begin(), nums.end());
            vector <vector<int>> answer;

            for(int i = 0; i < nums.size() - 2; i++)
            {

                if(i > 0 && nums[i] == nums[i-1])
                {
                    continue;
                }

                int next = i + 1;
                int last = nums.size() - 1;

                while  (next < last)
                {
                    int sum = nums[i] + nums[next] + nums[last];

                    if (sum == 0)
                    {
                        // Triplet found
                        answer.push_back({nums[i], nums[next], nums[last]});
                        
                        // Skipping duplicate elements for next and last
                        while(next < last && nums[next] == nums[next + 1])
                        {
                            next++;
                        }

                        while(next < last && nums[last] == nums[last - 1])
                        {
                            last--;
                        }

                        // Update the pointers next and last
                        next++;
                        last--;
                    }
                    else if(sum < 0)
                    {
                        // Increment next to increase the sum
                        next++;
                    }
                    else
                    {
                        // Decrement last to decrease the sum
                        last--;
                    }
                }
            }
            return answer;
        }
};

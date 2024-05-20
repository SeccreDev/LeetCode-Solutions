class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        if (!nums.empty())
        {
            sort(nums.begin(), nums.end());
            int counter = 1;
            int longestCounter = 0;
            for(int i = 1; i < nums.size(); i++)
            {
                // Same number doesn't add or break 'consecutive elements', so we just skip it
                if(nums[i] != nums[i-1])
                {
                    if((nums[i-1] + 1) == nums[i])
                    {
                        counter += 1;
                    }
                    else
                    {
                        longestCounter = max(longestCounter, counter);
                        counter = 1;
                    }
                }
            }
            return max(longestCounter, counter);
        }
        
        return 0;
    }
};

class Solution
{
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k)
        {
            deque<int> currMax;
            for (int i = 0; i < k; i++)
            {
                while (not currMax.empty() and nums[i] > nums[currMax.back()])
                {
                    currMax.pop_back();
                }
                currMax.push_back(i);
            }

            vector<int> result;
            for (int i = k; i < nums.size(); i++)
            {
                result.push_back(nums[currMax.front()]);
                if (currMax.front() == i - k)
                {
                    currMax.pop_front();
                }

                while (not currMax.empty() and nums[i] > nums[currMax.back()])
                {
                    currMax.pop_back();
                }
                currMax.push_back(i);
            }
            result.push_back(nums[currMax.front()]);

            return result;
        }
};
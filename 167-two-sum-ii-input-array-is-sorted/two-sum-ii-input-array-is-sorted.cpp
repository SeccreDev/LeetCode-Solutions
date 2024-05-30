class Solution
{
    public:
        vector<int> twoSum(vector<int>& numbers, int target)
        {
            unordered_map <int, int> map;

            for(int i = 0; i < numbers.size(); i++)
            {
                int difference = target - numbers[i];
                if(map.count(difference))
                {
                    return {map[difference]+1, i+1};
                }
                map[numbers[i]] = i;
            }
            return {};
        }
};
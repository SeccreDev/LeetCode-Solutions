class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        unordered_map <int, int> elements;

        for(int i = 0; i < nums.size(); i++)
        {
            elements[nums[i]]++;
        }

        int majority = nums.size()/2;
        for(auto i: elements)
        {
            if(i.second > majority)
            {
                return i.first;
            }
        }

        return 0;
    }
};
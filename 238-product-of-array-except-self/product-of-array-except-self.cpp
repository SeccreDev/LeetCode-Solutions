class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        // Time Limit Exceeded
        // vector <int> answer;
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     int product = 1;
        //     for(int j = 0; j < nums.size(); j++)
        //     {
        //         if(i == j)
        //         {
        //             continue;
        //         }
        //         product = product * nums[j];
        //     }
        //     answer.push_back(product);
        // }
        // return answer;

        int size = nums.size();
        vector <int> answer(size);
        answer[0] = 1;

        for (int i = 1; i < size; i++)
        {
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        int right = 1;
        for (int j = size - 2; j  >= 0; --j)
        {
            right = right * nums[j + 1];
            answer[j] = answer[j] * right;
        }

        return answer;

        


    }
};
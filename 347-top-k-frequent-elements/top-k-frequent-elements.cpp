class Solution
{
    public:
        vector<int> topKFrequent(vector<int>& nums, int k)
        {
            // Will store numbers inside an unordered_map (key being the numbers in the vector, and the value being the number of times the key is found in the vector)
            unordered_map <int, int> mapFrequent;
            for(const auto &x : nums)
            {
                mapFrequent[x]++;
            }

            // A temporal vector to sort the values we get from the unordered_map
            vector <pair<int, int>> temp;
            for(const auto &x : mapFrequent)
            {
                temp.push_back(x);
            }

            sort(temp.begin(), temp.end(), [&](pair<int, int> &a, pair<int, int> &b){ return a.second > b.second; });

            // A vector that will return the most frequent numbers
            vector <int> answer;
            for(int i = 0; i < k; i++)
            {
                answer.push_back(temp[i].first);

            }

            return answer;

        }
};
class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string answer = "";
        sort(strs.begin(), strs.end());
        int vectorSize = strs.size();
        string first = strs[0];
        string last = strs[vectorSize - 1];

        for(int i = 0; i <min(first.size(), last.size()); i++)
        {
            if(first[i] != last[i])
            {
                return answer;
            }
            answer += first[i];
        }
        return answer;
    }
};
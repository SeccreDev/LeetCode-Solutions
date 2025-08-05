class Solution
{
    public:
        void solve(vector<string> &ans, string &temp, unordered_map<char,string> mpp, string digits, int idx)
        {
            if (idx == digits.length())
            {
                ans.push_back(temp);
                return;
            }

            char ch = digits[idx];
            string str = mpp[ch];

            for (int i = 0; i < str.length(); i++)
            {
                temp.push_back(str[i]);
                solve(ans, temp, mpp, digits, idx + 1);
                temp.pop_back();
            }
        }

        vector<string> letterCombinations(string digits)
        {
            if (digits.length() == 0)
                return {};

            vector<string> ans;
            string temp = "";

            unordered_map<char, string> mpp;
            mpp['2'] = "abc";
            mpp['3'] = "def";
            mpp['4'] = "ghi";
            mpp['5'] = "jkl";
            mpp['6'] = "mno";
            mpp['7'] = "pqrs";
            mpp['8'] = "tuv";
            mpp['9'] = "wxyz";

            solve(ans, temp, mpp, digits, 0);
            return ans;
        }
};
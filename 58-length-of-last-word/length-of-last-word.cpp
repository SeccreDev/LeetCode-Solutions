class Solution {
public:
    int lengthOfLastWord(string s)
    {
        string word = "";
        for(int i = s.length() - 1; i >= 0; i--)
        {
            if(s[i] == ' ')
            {
                if (word == "")
                {
                    continue;
                }
                break;
            }
            else
            {
                word += s[i];
            }
        }
        return word.length();
    }
};
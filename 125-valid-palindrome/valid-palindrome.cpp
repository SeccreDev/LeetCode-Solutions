class Solution {
public:
    bool isPalindrome(string s)
    {
        string t;
        for(const auto& a:s)
        {
            if(a>='A' && a<='Z')
            {
                // Converts uppercase to lowercase and adds it to string t
                t.push_back(a-'A' + 'a');
            }
            else if(a>='a' && a<='z')
            {
                // Adds the lowercase character to string t
                t.push_back(a);
            }
            else if(a>='0' && a<='9')
            {
                // Adds the number to string t
                t.push_back(a);
            }
        }

        // Compares the first half and the second half of string t. If these are not equal then the string is not a palindrome.
        int len = t.size();
        for(int i=0; i < len / 2; ++i)
        {
            if(t[i] != t[len-i-1])
            {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k)
    {
        int count = 0, left = 0;
        unordered_map <char, int> map;

        for (int right = 0; right < s.size(); right++)
        {
            map[s[right]] = map[s[right]] + 1;
            count = max(count, map[s[right]]);

            if (right - left + 1 - count > k)
            {
                map[s[left]] -= 1;
                left += 1;
            }
        }

        return s.size() - left;
        
    }
};
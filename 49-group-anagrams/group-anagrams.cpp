class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> umap;

        for(const auto &x: strs)
        {
            string key = x;
            sort(key.begin(), key.end());
            umap[key].push_back(x);
        }

        vector<vector<string>> groupedAnagrams;
        for(auto x: umap)
        {
            groupedAnagrams.push_back(x.second);
        }
        return groupedAnagrams;
    }
};
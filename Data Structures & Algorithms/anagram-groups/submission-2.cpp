class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;

        for (string word : strs) {
            vector<int> count(26,0);
            for (char c : word) {
                count[122-c]++;
            }

            string key = "";
            for (int x : count) {
                key += to_string(x) + '#';
            }
            mp[key].push_back(word);
        }

        vector<vector<string>> anagrams;

        for (auto i : mp) {
            anagrams.push_back(i.second);
        }

        return anagrams;
    }
};

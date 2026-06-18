class Solution {
public:

struct ArrayHash {
    size_t operator()(const array<int, 26>& arr) const {
        size_t hash = 0;

        for(int x : arr) {
            hash = hash*31+x;
        }

        return hash;
    }
};
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, vector<string>, ArrayHash> mp;

        for (string word : strs) {
            array<int, 26> count{};
            for (char c : word) {
                count[122-c]++;
            }

            mp[count].push_back(word);
        }

        vector<vector<string>> anagrams;

        for (auto i : mp) {
            anagrams.push_back(i.second);
        }

        return anagrams;
    }
};

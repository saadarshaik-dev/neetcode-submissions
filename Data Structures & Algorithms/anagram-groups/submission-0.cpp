class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> hm;

        vector<vector<string>> anagrams;

        for (string word : strs) {
            map<char, int> count;
            for (char c : word) {
                count[c]++;
            }

            hm[count];
            hm[count].push_back(word);
        }

        for (auto i : hm) {
            anagrams.push_back(i.second);
        }

        return anagrams;
    }
};

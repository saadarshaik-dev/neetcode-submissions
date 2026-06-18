class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        map<char, int> s_letter_count;

        for (char c : s) {
            if (s_letter_count.find(c) != s_letter_count.end())
                s_letter_count[c]++;
            else
                s_letter_count.insert({c, 1});
        }

        for (char c : t) {
            if (s_letter_count.find(c) == s_letter_count.end())
                return false;
            else {
                if (s_letter_count[c] > 0)
                    s_letter_count[c]--;
                else
                    return false;
            }
        }

        return true;
    }
};

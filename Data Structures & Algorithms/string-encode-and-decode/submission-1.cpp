class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";

        for (string word : strs) {
            encoded_string += to_string(word.length()) + "#" + word;
        }

        //cout << encoded_string << endl;
        return encoded_string;
    }

    vector<string> decode(string s) {
        string decoded_string = "";
        vector<string> ans;

        for (int i = 0; i < s.length();) {
            cout << "idhar " << i << s[i] << endl;
            if (s[i] > 47 && s[i] < 58) {
                string num;
                while(s[i] != '#') {
                    num += s[i];
                    i++;
                }
                int count = stoi(num);
                i++;
                cout << i << s[i+count] << endl;
                string word = "";
                word += s.substr(i, count);
                cout << "word is " << word << endl;
                ans.push_back(word);
                i += count;
            }
        }

        return ans;
    }
};

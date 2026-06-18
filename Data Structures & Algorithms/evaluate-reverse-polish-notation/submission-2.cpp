class Solution {
public:
    bool is_digits(const std::string &str)
    {
        return str.find_first_not_of("0123456789") == std::string::npos;
    }

    int evalRPN(vector<string>& tokens) {
        stack<string> s;

        for (string word : tokens) {
            if (word[0] == '-' && word.length()>1) {
                s.push(word);
            }
            else if (is_digits(word)) {
                s.push(word);
            }
            else {
                int num1 = stoi(s.top());
                s.pop();
                int num2 = stoi(s.top());
                s.pop();

                if (word == "+") {
                    num2 += num1;
                }
                else if (word == "-") {
                    num2 -= num1;
                }
                else if (word == "*") {
                    num2 *= num1;
                }
                else {
                    num2 /= num1;
                }

                s.push(to_string(num2));
            }
        }

        return stoi(s.top());
    }
};

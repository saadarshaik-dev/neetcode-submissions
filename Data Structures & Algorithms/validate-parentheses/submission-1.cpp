class Solution {
public:
    bool isValid(string str) {
        stack<char> s;

        for (char c : str) {
            if (c == '(' || c == '{' || c == '[')
                s.push(c);
            else {
                if (s.size() == 0)
                    return false;
                if (c == ')' && s.top() == '(')
                    s.pop();
                else if (c == '}' && s.top() == '{')
                    s.pop();
                else if (c == ']' && s.top() == '[')
                    s.pop();
                else
                    return false;
            }
        }
    
    if (s.size() == 0)
        return true;
    else
        return false;
    }
};

class Solution {
public:
    bool isValid(char c) {
        return (c>='A' && c<='Z') || (c>='a' && c <='z') || (c>='0' && c <='9');
    }

    bool isPalindrome(string s) {
        int n = s.length();
        int left = 0, right = n-1;

        while (left < right && left < n && right >=0) {
            while (!isValid(s[left]) && left < n) {
                left++;
                continue;
            }
            while (!isValid(s[right]) && right >= 0) {
                right--;
                continue;
            }

            cout << left << " " << right << endl;

            if (tolower(s[left]) != tolower(s[right]))
                return false;
            left++;
            right--;
        }

        return true;
    }
};

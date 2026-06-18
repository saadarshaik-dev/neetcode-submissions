#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> minUntilNow;

public:
    MinStack() {}

    void push(int val) {
        s.push(val);
        if (minUntilNow.empty() || val <= minUntilNow.top()) {
            minUntilNow.push(val);
        }
    }

    void pop() {
        if (s.empty()) return;

        if (s.top() == minUntilNow.top()) {
            minUntilNow.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minUntilNow.top();
    }
};
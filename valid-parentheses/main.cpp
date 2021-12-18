class Solution {
public:
    // O(n) time and O(n) space complexity
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.size() == 0) {
                    return false;
                }
                char top = st.top();
                st.pop();
                if (s[i] == ')' && top != '(') {
                    return false;
                } else if (s[i] == '}' && top != '{') {
                    return false;
                } else if (s[i] == ']' && top != '[') {
                    return false;
                }
            }
        }

        if (st.size() > 0) {
            return false;
        }
        return true;
    }
};

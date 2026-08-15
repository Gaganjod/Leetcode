class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for (char digit : num) {
            while (!st.empty() && k > 0 && st.back() > digit) {
                st.pop_back();
                k--;
            }
            st.push_back(digit);
        }
        // Edge case 1;
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }
        // remove leading zeros
        while (st.size() > 1 && st[0] == '0') {
            st.erase(st.begin());
        }

        if (st.empty()) {
            return "0";
        }
        return st;
    }
};
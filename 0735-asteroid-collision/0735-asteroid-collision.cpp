class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for (int num : asteroids) {

            // If positive, it can never collide
            // with anything currently in the stack.
            if (num > 0) {
                st.push(num);
                continue;
            }

            // Current negative asteroid is assumed alive
            bool isAlive = true;

            // Check for collisions
            while (!st.empty() && st.top() > 0) {

                // Case 1:
                // Top positive asteroid is smaller
                if (st.top() < abs(num)) {
                    st.pop();
                }

                // Case 2:
                // Both have same size
                else if (st.top() == abs(num)) {
                    st.pop();

                    // Current negative asteroid also breaks
                    isAlive = false;
                    break;
                }

                // Case 3:
                // Top positive asteroid is bigger
                else {
                    // Current negative asteroid breaks
                    isAlive = false;
                    break;
                }
            }

            // If current asteroid survived
            if (isAlive) {
                st.push(num);
            }
        }

        // Convert stack to vector
        vector<int> ans(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
class Solution {
    struct Group {
        int start;
        int len;
    };

    class SparseTable {
        vector<vector<int>> st;
        vector<int> lg;

    public:
        SparseTable(const vector<int>& a) {
            int n = a.size();

            lg.resize(n + 1);
            for (int i = 2; i <= n; i++)
                lg[i] = lg[i / 2] + 1;

            if (n == 0) return;

            int K = lg[n] + 1;
            st.assign(K, vector<int>(n));
            st[0] = a;

            for (int k = 1; k < K; k++) {
                for (int i = 0; i + (1 << k) <= n; i++) {
                    st[k][i] = max(
                        st[k - 1][i],
                        st[k - 1][i + (1 << (k - 1))]
                    );
                }
            }
        }

        int query(int l, int r) {
            if (l > r) return 0;

            int k = lg[r - l + 1];

            return max(
                st[k][l],
                st[k][r - (1 << k) + 1]
            );
        }
    };

public:
    vector<int> maxActiveSectionsAfterTrade(
        string s,
        vector<vector<int>>& queries
    ) {
        int n = s.size();
        int ones = 0;

        for (char c : s)
            ones += (c == '1');

        vector<Group> groups;
        vector<int> idx(n);

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0') {
                    groups.back().len++;
                } else {
                    groups.push_back({i, 1});
                }
            }

            idx[i] = (int)groups.size() - 1;
        }

        if (groups.empty())
            return vector<int>(queries.size(), ones);

        vector<int> merge;

        for (int i = 0; i + 1 < groups.size(); i++) {
            merge.push_back(
                groups[i].len + groups[i + 1].len
            );
        }

        SparseTable st(merge);
        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int best = ones;
            int left = -1;

            if (idx[l] != -1) {
                int g = idx[l];

                left = groups[g].len -
                       (l - groups[g].start);
            }

            int right = -1;

            if (idx[r] != -1) {
                int g = idx[r];

                right = r - groups[g].start + 1;
            }

            int startGroup = idx[l] + 1;
            int endGroup;

            if (s[r] == '1')
                endGroup = idx[r];
            else
                endGroup = idx[r] - 1;

            if (
                s[l] == '0' &&
                s[r] == '0' &&
                idx[l] + 1 == idx[r]
            ) {
                best = max(
                    best,
                    ones + left + right
                );
            } else {
                int L = startGroup;
                int R = endGroup - 1;

                if (L <= R) {
                    best = max(
                        best,
                        ones + st.query(L, R)
                    );
                }
            }

            if (
                s[l] == '0' &&
                idx[l] + 1 <= endGroup
            ) {
                best = max(
                    best,
                    ones +
                    left +
                    groups[idx[l] + 1].len
                );
            }

            if (
                s[r] == '0' &&
                idx[l] < idx[r] - 1
            ) {
                best = max(
                    best,
                    ones +
                    right +
                    groups[idx[r] - 1].len
                );
            }

            ans.push_back(best);
        }

        return ans;
    }
};
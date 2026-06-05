class Solution {
public:
    vector<int> ans;
    int solve(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        if (ans[n] != -1)
            return ans[n];

        return ans[n] = solve(n - 1) + solve(n - 2);
    }
    int climbStairs(int n) {
        ans.resize(n + 1, -1);
        return solve(n);
    }
};

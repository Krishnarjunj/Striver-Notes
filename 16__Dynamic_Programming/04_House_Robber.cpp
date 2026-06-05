class Solution {
public:
    vector<int> ans;

    int solve(int n, vector<int>& nums) {
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        if (ans[n] != -1)
            return ans[n];

        int rob = nums[n - 1] + solve(n - 2, nums);
        int no_rob = solve(n - 1, nums);

        return ans[n] = max(rob, no_rob);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        ans.resize(n + 1, -1);
        return solve(n, nums);
    }
};

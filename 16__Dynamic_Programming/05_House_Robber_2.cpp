class Solution {
public:
    vector<int> ans;

    int solve(int n, vector<int>& nums, bool rob_last) {
        if (rob_last) {
            if (n == 1)
                return 0;
            if (n == 2)
                return nums[1];

            if (ans[n] != -1)
                return ans[n];

            int rob = solve(n - 2, nums, rob_last) + nums[n - 1];
            int dont_rob = solve(n - 1, nums, rob_last);

            return ans[n] = max(rob, dont_rob);
        } else {
            if (n == 1)
                return nums[0];
            if (n == 2)
                return max(nums[0], nums[1]);

            if (ans[n] != -1)
                return ans[n];

            int rob = solve(n - 2, nums, rob_last) + nums[n - 1];
            int dont_rob = solve(n - 1, nums, rob_last);

            return ans[n] = max(rob, dont_rob);
        }
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        ans.resize(n + 1, -1);

        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        int rob_last = solve(n - 2, nums, true) + nums[n-1];
        fill(ans.begin(), ans.end(), -1);
        int dont_rob_last = solve(n - 1, nums, false);

        return max(rob_last, dont_rob_last);
    }
};

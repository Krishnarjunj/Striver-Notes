class Solution {
public:
    vector<int> ans;
    int solve(int n, vector<int>& heights, int k){
        if(n==1) return 0;

        if(ans[n]!=INT_MAX) return ans[n];

        for(int i = 1; i <= k ; i ++){
            if(n<=i) break;
            int jump_i = solve(n-i, heights, k) + abs(heights[n - i - 1] - heights[n-1]);

            ans[n] = min(ans[n], jump_i);
        }

        return ans[n];
    }

    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        ans.resize(n+1, INT_MAX);
        return solve(n, heights, k);
    }
};


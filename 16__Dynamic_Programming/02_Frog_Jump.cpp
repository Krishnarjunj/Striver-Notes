class Solution {
	public:
	vector<int> ans;
	
	int solve(int n, vector<int>& height) {
		if (n == 1)
			return 0;
		
		if (ans[n] != -1)
			return ans[n];
		
		int onejump = solve(n - 1, height) + abs(height[n - 2] - height[n - 1]);
		int twojump = INT_MAX;
		
		if (n>2) {
			twojump = solve(n - 2, height) + abs(height[n - 3] - height[n - 1]);
		}
		
		return ans[n] = min(onejump, twojump);
	}
	
	int minCost(vector<int>& height) {
		int n = height.size();
		ans.resize(n + 1, -1);
		return solve(n, height);
		
	}
};


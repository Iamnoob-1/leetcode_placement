class Solution {
public:
    int recursion(vector<int>& nums, int n, vector<int>& dp) {
        if (n == 0) return nums[0];
        if (n == 1) return max(nums[0], nums[1]);
        if (dp[n] != -1) return dp[n];

        int pick = nums[n] + recursion(nums, n - 2, dp);
        int notPick = recursion(nums, n - 1, dp);
        return dp[n] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> temp1(nums.begin() + 1, nums.end());
        vector<int> temp2(nums.begin(), nums.end() - 1);

        vector<int> dp1(temp1.size(), -1);
        vector<int> dp2(temp2.size(), -1);

        return max(recursion(temp1, temp1.size() - 1, dp1),
                   recursion(temp2, temp2.size() - 1, dp2));
    }
};

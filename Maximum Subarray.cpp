/* class Solution
{
public:
    vector<int> dp;

    int maxS(vector<int> &nums, int i, int Sum)
    {
        if (i == nums.size())
        {
            return Sum;
        }
        if (dp[i] != INT_MIN)
            return dp[i];
        dp[i] = maxS(nums, i + 1, 0);
        dp[i] = max(nums[i], nums[i] + dp[i]);
        // dp[i] = max(nums[i], dp[i]);
        return dp[i];
    }

    int maxSubArray(vector<int> &nums)
    {
        dp.assign(nums.size() + 10, -1e4 - 1);
        // maxS(nums, 0, 0);
        int mx = INT_MIN;
        dp[nums.size() - 1] = nums.back();
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (dp[i] + nums[i] < nums[i])
            {
                dp[i] = 0;
            } 
            dp[i] = max(dp[i + 1] + nums[i], nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
}; */
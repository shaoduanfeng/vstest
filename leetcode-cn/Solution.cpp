#include "Solution.h"

int Solution::maxSubArray(vector<int>& nums)
{
	int ans = 0, maxn = INT_MIN;
	auto len = nums.size();
	for (int i = 0; i < len; i++) 
	{
		if (ans < 0) ans = 0;  //如果前面的和小0，那么重新开始求和
		ans += nums[i];
		maxn = max(maxn, ans);
	}
	return maxn;
}

int Solution::climbStairs(int n)
{
	if (n < 1) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	int a = 1, b = 2,res = 0;
	for (int i = 3; i < n; ++i)
	{
		res = a + b;
		a = b;
		b = res;
	}
	return res;
}

int Solution::maxProfit(vector<int>& prices)
{
	if (prices.size() == 0) return 0;
	int buyprices = prices[0], saleprices = 0;
	for (int i = 0; i < prices.size(); ++i)
	{
		buyprices = min(buyprices,prices[i]);
		saleprices = max(saleprices, prices[i] - buyprices);
	}
	return saleprices;
}

int Solution::rob198(vector<int>& nums)
{
	if (nums.empty()) return NULL;
	if (nums.size() == 1) return nums[0];
	vector<int> dp(nums.size() + 3);//维护一个dp，dp的元素表示当前能得到的金额
	dp[0] = nums[0]; //初始状态
	dp[1] = max(nums[0], nums[1]); //初始状态
	for (auto i = 2; i < nums.size(); ++i)
	{
		dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
	}
	
	return dp[nums.size() - 1];
}

int Solution::rob213(vector<int>& nums)
{
	//需要维护两个dp,一个是包含第一个元素，一个是不包含第一个元素，最后作比较。
	auto len = nums.size();
	if (len == 0) return 0;
	if (len == 1) return nums[0];
	if (len == 2) return max(nums[0],nums[1]);
	vector<int> dp1(len);
	vector<int> dp2(len);
	dp1[0] = nums[0];
	dp1[1] = max(nums[0],nums[1]);
	dp2[0] = nums[1];
	dp2[1] = max(nums[1],nums[2]);
	for (auto i = 2; i < len - 1; ++i)
	{
		//对于dp1来说，与198类似
		dp1[i] = max(nums[i] + dp1[i - 2],dp1[i - 1]);
		//对于dp2来说，在初始化dp2[1]的时候已经使用了nums[2]元素
		//所以这里不能用nums[i]而是使用nums[i + 1]
		dp2[i] = max(nums[i + 1] + dp2[i - 2],dp2[i - 1]);
	}
	return max(dp1[len - 2], dp2[len - 2]);
}

int Solution::getMoneyAmount(int n)
{

	return 0;
}

#include "Solution.h"

int Solution::maxSubArray(vector<int>& nums)
{
	int ans = 0, maxn = INT_MIN;
	auto len = nums.size();
	for (int i = 0; i < len; i++) 
	{
		if (ans < 0) ans = 0;  //���ǰ��ĺ�С0����ô���¿�ʼ���
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
	vector<int> dp(nums.size() + 3);//ά��һ��dp��dp��Ԫ�ر�ʾ��ǰ�ܵõ��Ľ��
	dp[0] = nums[0]; //��ʼ״̬
	dp[1] = max(nums[0], nums[1]); //��ʼ״̬
	for (auto i = 2; i < nums.size(); ++i)
	{
		dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
	}
	
	return dp[nums.size() - 1];
}

int Solution::rob213(vector<int>& nums)
{
	//��Ҫά������dp,һ���ǰ�����һ��Ԫ�أ�һ���ǲ�������һ��Ԫ�أ�������Ƚϡ�
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
		//����dp1��˵����198����
		dp1[i] = max(nums[i] + dp1[i - 2],dp1[i - 1]);
		//����dp2��˵���ڳ�ʼ��dp2[1]��ʱ���Ѿ�ʹ����nums[2]Ԫ��
		//�������ﲻ����nums[i]����ʹ��nums[i + 1]
		dp2[i] = max(nums[i + 1] + dp2[i - 2],dp2[i - 1]);
	}
	return max(dp1[len - 2], dp2[len - 2]);
}

int Solution::getMoneyAmount(int n)
{

	return 0;
}

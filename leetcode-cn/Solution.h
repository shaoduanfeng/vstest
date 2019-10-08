#pragma once
//#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int maxSubArray(vector<int>& nums);
	int climbStairs(int n);
	int maxProfit(vector<int>& prices);
	int rob198(vector<int>& nums);//198.打家劫舍
	int rob213(vector<int>& nums);//213.打家劫舍II
	int getMoneyAmount(int n); //375.猜数字大小II
};


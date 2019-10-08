#include <iostream>
#include "Solution.h"

int main()
{
	Solution S;
	/*vector<int> v1 = { -2,1,-3,4,-1,2,1,-5,4 };
	cout << S.maxSubArray(v1) << endl;*/
	vector<int> v2 = { 1,2,3,1 };
	//cout << S.maxProfit(v2) << endl;
	cout << S.rob213(v2) << endl;
	return 0;
}
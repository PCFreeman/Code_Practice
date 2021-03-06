#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
	if (nums.size() == 0)
	{
		return{ -1,-1 };
	}

	int l = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
	int u = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

	if (l >= nums.size() || nums[l] != target) 
	return { -1, -1 };
	else 
	return { l, u - 1 };
}

void main()
{
	vector<int> nums = { 5, 7, 7, 8, 8, 10 };
	int target = 8;

	searchRange(nums, target);
}
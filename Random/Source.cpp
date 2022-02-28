#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == target || nums[i] > target)
		{
			return i;
		}
		else if (i== nums.size()-1&&target> nums[i])
		{
			return i + 1;
		}
	}
	return 0;
}

void main()
{
	vector<int> tem = { 1,3,5,6 };
	  cout<<searchInsert(tem, 7);
}
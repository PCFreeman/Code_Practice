#include<iostream>
#include<vector>

using namespace std;
int maxSubArray(vector<int>& nums) {

    int n = nums.size();
    int sum = 0;
    int max_so_far = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        max_so_far = max(max_so_far, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return max_so_far;
}

void main()
{
    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
    maxSubArray(nums);
}
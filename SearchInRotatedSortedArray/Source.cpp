#include<iostream>
#include<vector>
using namespace std;

int srchtrgt(int target, int st, int en, vector<int>& nums) {
    int a = -1;
    while (st <= en) {
        int m = st + (en - st) / 2;
        if (nums[m] == target) {
            a = m;
            break;
        }
        else if (nums[m] > target) en = m - 1;
        else st = m + 1;
    }
    return a;
}
//to find pivot
int findpivot(vector<int>& nums) {
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (mid<end && nums[mid]>nums[mid + 1]) {
            return mid;
        }
        if (mid > start && nums[mid] < nums[mid - 1]) {
            return mid - 1;

        }
        if (nums[start] > nums[mid]) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}
int search(vector<int>& nums, int target) {
    int pivot = findpivot(nums);
    if (pivot == -1) {
        return srchtrgt(target, 0, nums.size() - 1, nums);
    }
    if (nums[pivot] == target) {
        return pivot;
    }
    if (target >= nums[0]) {
        return srchtrgt(target, 0, pivot - 1, nums);
    }
    return srchtrgt(target, pivot + 1, nums.size() - 1, nums);

}

void main()
{
    vector<int> nums = { 4,5,6,7,0,1,2 };
    int target = 0;
    cout<<search(nums, target);
}
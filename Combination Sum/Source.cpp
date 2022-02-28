#include<iostream>
#include<vector>
#include<algorithm>
#include <set>
using namespace std;

void findCombinations(int index, int targetSum, vector<int>& arr, vector<int>& ds, set<vector<int>>& v) {
    //base condition
    if (index == arr.size()) {
        if (targetSum == 0) {
            v.insert(ds);
        }
        return;
    }
    //pick value at index
    if (arr[index] <= targetSum) {
        ds.push_back(arr[index]);
        findCombinations(index + 1, targetSum - arr[index], arr, ds, v);
        ds.pop_back();
    }
    //not pick
    findCombinations(index + 1, targetSum, arr, ds, v);
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> ds;
    vector<vector<int>> ans;
    set<vector<int> > v;
    sort(candidates.begin(), candidates.end());
    findCombinations(0, target, candidates, ds, v);
    for (auto x : v) {
        ans.push_back(x);
    }
    return ans;
}


void main()
{
    vector<int>candidates = { 10,1,2,7,6,1,5 };
    int target = 8;
    combinationSum2(candidates, target);

}
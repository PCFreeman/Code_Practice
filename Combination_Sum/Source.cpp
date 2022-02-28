#include<iostream>
#include<vector>

using namespace std;

void comb(vector<int>& candidates, int target, vector<int>& ds, vector<vector<int>>& ans, int index)
{
    if (index == candidates.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    if (target >= candidates[index])
    {
        ds.push_back(candidates[index]);
        comb(candidates, target - candidates[index], ds, ans, index);
        ds.pop_back();
    }
    comb(candidates, target, ds, ans, index + 1);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>ds;
    comb(candidates, target, ds, ans, 0);
    return ans;

}

void main()
{
    vector<int>candidates = { 2, 3, 6, 7 };
    int target = 7;
    combinationSum(candidates, target);

}
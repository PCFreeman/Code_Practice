#include<iostream>
#include<vector>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {

	int first = cost[0];
	int second = cost[1];
	int cur = 0;
	for (int i = 2; i < cost.size(); i++)
	{
		cur = cost[i] + min(first, second);
		first = second;
		second = cur;
	}
	return min(first, second);
}

void main()
{
	vector<int> exm = { 1,100,1,1,1,100,100,1,100,1 };
	cout << minCostClimbingStairs(exm);
}
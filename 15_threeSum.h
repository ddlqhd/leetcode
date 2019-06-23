#pragma once
#include <vector>
#include <algorithm>

using namespace std;
class Solution15
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		int nNonnegativePos = getNonnegativePos(nums);

		for (int i = 0; i < nNonnegativePos; ++i)
		{
			for (int j = i + 1; j )
			{
			}
		}
	}

private:
	int getNonnegativePos(const vector<int>& nums)
	{
		int idx = 0;
		for (auto item : nums)
		{
			if (item > 0)
			{
				return idx;
			}
			else
			{
				++idx;
			}
		}
		return idx;
	}
};
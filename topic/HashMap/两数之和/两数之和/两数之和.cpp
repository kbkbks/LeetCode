// 两数之和.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vec_size = nums.size();
		map<int, int> tmp1;
		map<int, int> tmp2;
		map<int, int> tmp;
		map<int, int>::iterator iter;
		for (int i = 0; i < vec_size; i++)
		{
			int dif = target - nums[i];
			if (tmp.find(dif) != tmp.end() )
			{
				result.push_back(tmp[dif]);
				result.push_back(i);
				return result;
			}
			tmp.insert(pair<int,int>(nums[i], i));
		}

		return result;
	}

public:
	int vec_size;
	vector<int> result;
};

int main()
{
	Solution solution;
	vector<int> nums = { 2, 7, 11, 15 };
	vector<int> result = solution.twoSum(nums,9);


	return 0;
}

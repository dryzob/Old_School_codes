/*
 Given an array positive numbers, find the maximum sum of a subsequence such that no two numbers in the sequence are adjacent in the array.
 Your algorithm should be O(n) where n is the number of elements in the array.
 Assume at least one element is present in the array
 */
#include <iostream>
#include <vector>
#include <algorithm>

using std::max;
using std::cout;
using std::endl;
using std::vector;

int maxSum(vector<int>& nums) {
	int const numElem = nums.size();
	int sums[numElem]; // answer array

	// establish initial conditions
	sums[0] = nums.at(0);
	sums[1] = max(nums.at(0), nums.at(1));
	// build array starting after initials
	for (int i = 2; i < nums.size(); i++) {
		sums[i] = max(sums[i-1], (sums[i-2] + nums.at(i)));
	}
	// return last sum
	return sums[nums.size() - 1];
}


int main() {
	vector<int> nums;
	// Test 1
	nums = {75, 105, 120, 75, 90, 135};
	cout << maxSum(nums) << endl; //330
	// Test 2
	nums = {5, 5, 10, 100, 10, 5};
	cout << maxSum(nums) << endl; //110
	// Test 3
	nums = {3, 2, 7, 10};
	cout << maxSum(nums) << endl; //13
	// Test 4
	nums = {3, 2, 5, 10, 7};
	cout << maxSum(nums) << endl; //15
}



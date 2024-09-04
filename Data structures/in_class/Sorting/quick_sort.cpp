#include <iostream>
#include <vector>
#include <random>

using namespace std;

vector<int> quicksort(vector<int>& nums) {
	if (nums.size() < 2) {
		return nums;
	}
	default_random_engine generator;
	uniform_int_distribution<int> distribution(0, nums.size());
	int pivotIdx = distribution(generator);
	int pivot = nums[pivotIdx];
	vector<int> left;
	vector<int> right;
	for (auto num : nums) {
		if (num < pivot)
			left.push_back(num);
		else if (num > pivot)
			right.push_back(num);
		
	}
	left = quicksort(left);
	right = quicksort(right);
	left.push_back(pivot);
	left.insert(left.end(), right.begin(), right.end());
	return left;
	
}

void print(const vector<int>& nums) {
	for (auto num: nums) {
		cout << num << " ";
	}
	cout << endl;

}

int main() {
	vector<int> nums{5, 4, 8, 0, 6, 11, 1};
	print(quicksort(nums));

}

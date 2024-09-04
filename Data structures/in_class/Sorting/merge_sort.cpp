// Merge sort
#include <iostream>
#include <vector>
#include <algorithm> // For copy
#include <random> // For random number generators
#include <chrono> // For timinig measurements

using namespace std;

void print(vector<int>& vec) {
	for (auto ele : vec)
		cout << ele << " ";
	cout << endl;
}

void merge(vector<int>& nums, vector<int>& left, vector<int>& right) {
	int i = 0, j = 0, k = 0;
	while ((j < left.size()) && (k < right.size())) {
		if (left[j] <= right[k]) {
			nums[i] = left[j];
			i++;
			j++;
		} else {
			nums[i] = right[k];
			i++;
			k++;
		}
	}
	while(j < left.size())  { // Remaining elements of left
		nums[i] = left[j];
		i++;
		j++;
	}
	while(k < right.size()) {
		nums[i] = right[k];
		i++;
		k++;
	}


}

void mergesort(vector<int>&nums) {
	// Base case - one element, nothing to sort

	if (nums.size() > 1) {
		int mid = nums.size()/2;
		vector<int> left(mid);
		vector<int> right(nums.size()-mid);
		copy(nums.begin(), nums.begin() + mid, left.begin());
		copy(nums.begin() + mid, nums.end(), right.begin());
		mergesort(left);
		mergesort(right);
		merge(nums, left, right);
		
	}
}

void bubblesort(vector<int>& nums) {
	bool swapped = true;
	while (swapped) {
		swapped = false;
		for (int i = 0; i < nums.size()-1; i++) {
			if (nums[i] > nums[i+1]) {
				int temp = nums[i];
				nums[i] = nums[i+1];
				nums[i+1] = temp;
				swapped = true;
			}
		}
	}
}			

int main() {
	// Test 1 - random input with repeated entries
	vector<int> nums1{6, 7, 8, 1, 2, 7};
	mergesort(nums1);
	cout << "Test1: ";
	print(nums1);

	// Test 2 - empty input
	vector<int> nums2{};
	mergesort(nums2);
	cout << "Test2: ";
	print(nums2);

	// Test 3 - sorted input
	vector<int> nums3{10, 11, 12, 13};
	mergesort(nums3);
	cout << "Test3 ";
	print(nums3);

	// Test 4 - reverse sorted input
	vector<int> nums4{8, 3 , 1, 0};
	mergesort(nums4);
	cout << "Test4: ";
	print(nums4);

	// Create a large random vector
	int largeNum = 100000; // 100,000 ints
	vector<int> nums5;
	default_random_engine generator;
  	uniform_int_distribution<int> distribution(0,100000);
	for (int i = 0; i < largeNum; i++) { 
		nums5.push_back(distribution(generator));
	}
	vector<int> checknums(10); // Print out first 10 entries
	copy(nums5.begin(), nums5.begin()+10, checknums.begin());
	cout << "Check: ";
	print(checknums);

	// Measure run time of mergesort with large input
	auto start = chrono::steady_clock::now();	
	mergesort(nums5);
	auto end = chrono::steady_clock::now();
	auto runtime = chrono::duration_cast<chrono::milliseconds>(end-start).count();
	cout << "Mergesort: time taken in milliseconds " << runtime << " ms" << endl;


	// Measure run time of bubble sort with large input
	// Reinitialize random ints
	for (int i = 0; i < largeNum; i++) { 
		nums5[i] = distribution(generator);
	}
	copy(nums5.begin(), nums5.begin()+10, checknums.begin());
	cout << "Check: ";
	print(checknums);

	start = chrono::steady_clock::now();	
	bubblesort(nums5);
	end = chrono::steady_clock::now();
	runtime = chrono::duration_cast<chrono::milliseconds>(end-start).count();
	cout << "Bubblesort: time taken in milliseconds " << runtime << " ms" << endl;
	copy(nums5.begin(), nums5.begin()+10, checknums.begin());
	print(checknums);

	// Measure run time of STL sort with large input
	// Reinitialize random ints
	for (int i = 0; i < largeNum; i++) { 
		nums5[i] = distribution(generator);
	}
	copy(nums5.begin(), nums5.begin()+10, checknums.begin());
	cout << "Check: ";
	print(checknums);

	start = chrono::steady_clock::now();	
	sort(nums5.begin(), nums5.end());
	end = chrono::steady_clock::now();
	runtime = chrono::duration_cast<chrono::milliseconds>(end-start).count();
	cout << "STL sort: time taken in milliseconds " << runtime << " ms" << endl;


}
	

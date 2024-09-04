/*
Leetcode Problem 242 - Valid Anagram

 Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.

NOTE: Your code has to run in O(n) time where n is the number of letters. 
Zero points for any non-O(n) algorithm.
*/

#include <iostream>
#include <unordered_map>

using namespace std;
bool isAnagram(string s, string t);

int main() {
	string s = "anagram";
	string t = "nagaram";
	if (isAnagram(s, t)) cout << "True" << endl;
	else cout << "False" << endl;
	s = "rat";
	t = "car";
	if (isAnagram(s, t)) cout << "True" << endl;
	else cout << "False" << endl;
}

bool isAnagram(string s, string t) {
	unordered_map<char, int> word1 = {{'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0}, 
		{'g', 0}, {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0},
		{'m', 0}, {'n', 0}, {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0},
		{'s', 0}, {'t', 0}, {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0},
		{'y', 0}, {'z', 0}};
	unordered_map<char, int> word2 = {{'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0}, 
		{'g', 0}, {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0},
		{'m', 0}, {'n', 0}, {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0},
		{'s', 0}, {'t', 0}, {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0},
		{'y', 0}, {'z', 0}};

	if (s.size() != t.size()) return false; // different sized words can't be anagrams

	cout << word1.empty() << endl;

	for (int i = 0; i < s.size(); i++) {
		word1[s[i]] += 1;
		word2[t[i]] += 1;
	}

	if (word1 == word2) return true;
	else return false;
}
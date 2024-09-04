// For an input string of words, find the most frequently occuring word. In case of ties, report any one of them. 
// Your algorithm should be O(n) time where n is the number of words in the string
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;


string findWord(vector<string>& tokens);
 
int main() {
	string line = "I felt happy because I saw the others were happy and because I knew I should feel happy but I wasn’t really happy";
	
	// Convert string to a vector of words
	char delimiter = ' ';
	string token;
	istringstream tokenStream(line);
	vector<string> tokens;
	while (getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}	
	cout << "The most frequently occuring word is: " << findWord(tokens) << endl;
	
}

string findWord(vector<string>& tokens) {
	unordered_map<string, int> words;
	pair<string, int> max = {"blah", 0};

	for (int i = 0; i < tokens.size(); i++) {
		if (words.find(tokens.at(i)) == words.end()) { // word not added yet
			words[tokens.at(i)] = 1;
		} else {
			words[tokens.at(i)] += 1;
		}
	}
	for (auto w = words.begin(); w != words.end(); w++) {
		if (w->second >= max.second) {
			max.first = w->first;
			max.second = w->second;
		}
	}
	return max.first;
}



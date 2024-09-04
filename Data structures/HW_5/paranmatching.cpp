/* 
Write a function that returns if a string of paranthesis are matched. 
You are required to use the STL stack datastructure in your code for O(n) time complexity.
See 5.17 in the book for problem description and a stack based algorithm. 
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std; 
  
// function to check if paranthesis are balanced 
bool areParanthesisBalanced(string expr) {
	stack<char> patternHold;
	patternHold.push('a');
	bool balanced = true;
	for (int i = 0; i < expr.size(); i++) {
		//cout << "\t\tSTART" << endl;
		switch (expr[i]) {
			case ')':
				if (patternHold.top() != '(') {
					balanced = false;
				} else {
					patternHold.pop();
					//cout << "\tclosed" << endl;
				}
				break;
			case '}':
				if (patternHold.top() != '{') {
					balanced = false;
				} else {
					patternHold.pop();
					//cout << "\tclosed" << endl;
				}
				break;
			case ']':
				if (patternHold.top() != '[') {
					balanced = false;
				} else {
					patternHold.pop();
					//cout << "\tclosed" << endl;
				}
				break;
			default:
				patternHold.push(expr[i]);
				//cout << "stacked" << endl;
				break;
		}
	}
	patternHold.pop();
	if (!(patternHold.empty())) balanced = false;
	return balanced;
} 
  
// Test - DO NOT MODIFY
int main() 
{ 
    vector<string> parans = {"{()}[]", "[[", "))", "{[()]}", "({[])}"}; 
  	
	for(auto expr : parans) {
    	if (areParanthesisBalanced(expr)) 
        	cout << "Balanced" << endl; 
    	else
        	cout << "Not Balanced" << endl;
	} 
    return 0; 
}

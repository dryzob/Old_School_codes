// sum an array with recursion

#include <iostream>
#include <vector>

int sumArrayIterative(std::vector<int>& vec) {
    int sum = 0;
    for (unsigned int i = 0; i < vec.size(); i++) {
        sum += vec.at(i);
    }
    return sum;
}
int sumArrayRecursiveHelper(std::vector<int>& vec, int stop) {
    if (stop == 0) return vec.at(stop);
    return vec.at(stop) + sumArrayRecursiveHelper(vec, stop-1);
}

int sumArrayRecursive(std::vector<int>& vec) {
    return sumArrayRecursiveHelper(vec, vec.size()-1);
}

int main() {
    std::vector<int> vec = {1, 7, 3, 4, 8};
    std::cout << "Iterative: " << sumArrayIterative(vec) << " Recursive: " << sumArrayRecursive(vec) << std::endl;

    return 0;
}
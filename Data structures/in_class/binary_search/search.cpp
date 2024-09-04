#include <iostream>
#include <vector>

int sumArray(std::vector<int>& v) {
    return sumArrayHelper(v, 0, v.size());
}

int sumArrayHelper(std::vector<int>& v, int begin, int end) {
    int mid = end / 2;
    
}

int main() {
    std::vector<int> numb = {1,5,8,6,3};
    std::cout << "Sum: " << sumArray(numb) << std::endl;
}
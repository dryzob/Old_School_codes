#include <iostream>
#include <vector>

int vectorMax(std::vector<int> &v) {
    int currentMax = v[0];
    int n = v.size();
    for (int i=1; i < n; i++) {
        if (currentMax < v[i]) {
            currentMax = v[i];
        }
    }
    return currentMax;
}

// Doing Recursion and stuff

#include <iostream>

int recursiveFactoral(int num) {
    if (num == 0) return 1;
    return num * recursiveFactoral(num - 1);
}

int power(int n, int m) {
    if (m == 0) return 1;
    return n * power(n, m - 1);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Usage: \"./test <n> <m>\" " << std::endl;
        return -1;
    }
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    std::cout << "Factorial of " << n << ": " << recursiveFactoral(n) << std::endl;
    std::cout << n << " to the power of " << m << ": " << power(n, m) << std::endl;

    return 1;
}
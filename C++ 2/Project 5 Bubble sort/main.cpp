#include <iostream>

using namespace std;

void bubbleSort(int* a, int size);
void swap(int* x, int* y);

int main() {
    
    const int SIZE = 5;
    int a1[] = {3, 4, 8, 2, 1};
    int* p = nullptr;

    bubbleSort(a1, SIZE);
    
    for(int i = 0; i < SIZE; i++){
        cout << a1[i] << endl;
    }

    bubbleSort(nullptr, SIZE);
    
    
    return 0;
}

void bubbleSort(int* a, int size) {
    // Check if pointer is null
    if (a == nullptr)
        return;
    
    // Loop for the number of passes
    for (int j = 0; j < size; j++) {
        // Loop for swapping items
        for (int i = 0; i < size - 1; i++) {
            if (*(a + i) > *(a + i + 1))
                swap((a + i + 1), (a + i));
        }
    }
    
}

void swap(int* x, int* y) { // Swaps the two given spots
    
    int temp = *x;
    *x = *y;
    *y = temp;
    
}
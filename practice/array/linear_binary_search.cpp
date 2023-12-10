#include <iostream>
using namespace std;

// Linear Search (Iterative)
int linearSearchIterative(const int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; // Return the index if target is found
        }
    }
    return -1; // Return -1 if target is not found
}

// Linear Search (Recursive)
int linearSearchRecursive(const int arr[], int target, int index, int size) {
    if (index >= size) {
        return -1; // Return -1 if target is not found
    }

    if (arr[index] == target) {
        return index; // Return the index if target is found
    }

    return linearSearchRecursive(arr, target, index + 1, size);
}

// Binary Search (Iterative)
int binarySearchIterative(const int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Return the index if target is found
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Return -1 if target is not found
}

// Binary Search (Recursive)
int binarySearchRecursive(const int arr[], int target, int left, int right) {
    if (left > right) {
        return -1; // Return -1 if target is not found
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid; // Return the index if target is found
    } else if (arr[mid] < target) {
        return binarySearchRecursive(arr, target, mid + 1, right);
    } else {
        return binarySearchRecursive(arr, target, left, mid - 1);
    }
}

int main() {
    const int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 6;

    // Linear Search (Iterative)
    int linearIterativeResult = linearSearchIterative(arr, size, target);
    if (linearIterativeResult != -1) {
        cout << "Linear Search (Iterative): Element found at index " << linearIterativeResult << endl;
    } else {
        cout << "Linear Search (Iterative): Element not found" << endl;
    }

    // Linear Search (Recursive)
    int linearRecursiveResult = linearSearchRecursive(arr, target, 0, size);
    if (linearRecursiveResult != -1) {
        cout << "Linear Search (Recursive): Element found at index " << linearRecursiveResult << endl;
    } else {
        cout << "Linear Search (Recursive): Element not found" << endl;
    }

    // Binary Search (Iterative)
    int binaryIterativeResult = binarySearchIterative(arr, size, target);
    if (binaryIterativeResult != -1) {
        cout << "Binary Search (Iterative): Element found at index " << binaryIterativeResult << endl;
    } else {
        cout << "Binary Search (Iterative): Element not found" << endl;
    }

    // Binary Search (Recursive)
    int binaryRecursiveResult = binarySearchRecursive(arr, target, 0, size - 1);
    if (binaryRecursiveResult != -1) {
        cout << "Binary Search (Recursive): Element found at index " << binaryRecursiveResult << endl;
    } else {
        cout << "Binary Search (Recursive): Element not found" << endl;
    }

    return 0;
}

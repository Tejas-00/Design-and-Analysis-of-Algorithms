#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[low], arr[i - 1]);
    return (i - 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[6] = {10, 7, 8, 9, 1, 5};

    cout << "Original array: ";
    printArray(arr, 6);

    quickSort(arr, 0, 6 - 1);

    cout << "Sorted array: ";
    printArray(arr, 6);

    return 0;
}

//                    SECTION: 1

/*
    algorithm(arr, size)
        Call MergeSort(arr, 0, size-1)
        print all elements of array

    MergeSort(arr[], l,  r)
        If r > l
            1. Find the middle point to divide the array into two halves:
                    middle m = l+ (r-l)/2
            2. Call mergeSort for first half:
                    Call mergeSort(arr, l, m)
            3. Call mergeSort for second half:
                    Call mergeSort(arr, m+1, r)
            4. Merge the two halves sorted in step 2 and 3:
                    Call merge(arr, l, m, r)
*/

//               SECTION: 2

#include <iostream>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid, int const right) {
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0,    // Initial index of first sub-array
        indexOfSubArrayTwo = 0;     // Initial index of second sub-array
    int indexOfMergedArray = left;  // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void algorithm(int arr[], int size) {
    mergeSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Driver code */
int main() {
    int arr[] = {83, 1, 45, 95, 45, 52, 11, 47, 0, 45, 67, 82};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    algorithm(arr, arr_size);
}

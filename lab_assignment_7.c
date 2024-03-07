#include <stdio.h>
#include <stdlib.h>
#define LIST_LENGTH 9

void initializeSwaps(int *swaps) {
    for (int c = 0; c < LIST_LENGTH; c++) {
        swaps[c] = 0;
    }
}

void initializeLists(int *list1, int *list2) {
    int baseList1[LIST_LENGTH] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int baseList2[LIST_LENGTH] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    for (int c = 0; c < LIST_LENGTH; c++) {
        list1[c] = baseList1[c];
        list2[c] = baseList2[c];
    }
}

void printArraysAndSwaps(int *array, int *swaps, int swapSum) {
    for (int c = 0; c < LIST_LENGTH; c++) {
        printf("Element %d has been swapped %d times.\n", array[c], swaps[c]);
    }
    printf("Total swaps: %d\n\n", swapSum);
}

int bubbleSort(int list[], int swaps[], int listLength) {
    int intermediateSwapSum = 0;

    if (listLength <= 1) {
        return 0;
    }

    //Go from the beginning to the end.
    for (int c = 1; c < listLength; c++) {
        //If this slot is smaller than the last one, swap.
        if (list[c-1] > list[c]) {
            int temp = list[c-1];
            list[c-1] = list[c];
            list[c] = temp;
            temp = swaps[c-1] + 1;
            swaps[c-1] = swaps[c] + 1;
            swaps[c] = temp;
            intermediateSwapSum++;
        }
    }

    return intermediateSwapSum + bubbleSort(list, swaps, (listLength - 1));
}

int selectionSort(int list[], int swaps[], int firstIndex) {
    int intermediateSwapSum = 0;

    if (firstIndex >= (LIST_LENGTH - 1)) {
        return 0;
    }

    //Go from the end to the beginning.
    int targetIndex = firstIndex;
    for (int c = (firstIndex + 1); c < LIST_LENGTH; c++) {
        //If this slot is smaller than the smallest we know, take a note of it.
        if (list[c] < list[targetIndex]) {
            targetIndex = c;
        }
    }

    //If the first index isn't the smallest, swap.
    if (targetIndex != firstIndex) {
        int temp = list[firstIndex];
        list[firstIndex] = list[targetIndex];
        list[targetIndex] = temp;
        temp = swaps[firstIndex] + 1;
        swaps[firstIndex] = swaps[targetIndex] + 1;
        swaps[targetIndex] = temp;
        intermediateSwapSum++;
    }

    return intermediateSwapSum + selectionSort(list, swaps, (firstIndex + 1));
}

int main() {
    int list1[LIST_LENGTH];
    int list2[LIST_LENGTH];
    int swaps[LIST_LENGTH];
    initializeLists(list1, list2);
    initializeSwaps(swaps);

    int swapSum = bubbleSort(list1, swaps, (LIST_LENGTH));
    printf("Array 1 (Bubble Sort):\n");
    printArraysAndSwaps(list1, swaps, swapSum);
    initializeSwaps(swaps);

    swapSum = bubbleSort(list2, swaps, (LIST_LENGTH));
    printf("Array 2 (Bubble Sort):\n");
    printArraysAndSwaps(list2, swaps, swapSum);
    initializeSwaps(swaps);
    initializeLists(list1, list2);
    
    swapSum = selectionSort(list1, swaps, 0);
    printf("Array 1 (Selection Sort):\n");
    printArraysAndSwaps(list1, swaps, swapSum);
    initializeSwaps(swaps);

    swapSum = selectionSort(list2, swaps, 0);
    printf("Array 2 (Selection Sort):\n");
    printArraysAndSwaps(list2, swaps, swapSum);
    return 0;
}
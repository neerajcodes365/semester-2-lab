#include <stdio.h>

// Define a structure to hold the data
struct Student {
    int rollNumber;
    float marks;
};

// Function to perform insertion sort on an array of students
void insertionSort(struct Student arr[], int n) {
    int i, j;
    struct Student key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j].rollNumber > key.rollNumber) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to print the array of students
void printArray(struct Student arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Roll Number: %d, Marks: %.2f\n", arr[i].rollNumber, arr[i].marks);
    }
}

int main() {
    // Sample array of students
    struct Student students[] = {
        {101, 78.5},
        {103, 88.9},
        {102, 65.2},
        {105, 91.7},
        {104, 72.3}
    };
    int n = sizeof(students) / sizeof(students[0]);

    // Perform insertion sort
    insertionSort(students, n);

    // Print the sorted array
    printf("Sorted array of students:\n");
    printArray(students, n);

    return 0;
}
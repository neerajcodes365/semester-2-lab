#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct car {
    char name[30];
    int mileage;
};
typedef struct car car;

void swap(car *x, car *y) {
    car temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(car arr[], int size, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[l].mileage > arr[largest].mileage)
        largest = l;

    if (r < size && arr[r].mileage > arr[largest].mileage)
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
    }
}


void heapsort(car arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    if (n < 1 || n > 1000) return 0;

    car cars[n];

    for (int i = 0; i < n; i++) {
        char input[100];
       scanf(" %[^\n]", input); 

       
        int len = strlen(input);
        int j = len - 1;

        
        char mileage_str[10];
        while (j >= 0 && input[j] >= '0' && input[j] <= '9') {
            mileage_str[len - 1 - j] = input[j];
            j--;
        }
        mileage_str[len - j] = '\0';

       
        strrev(mileage_str);
        cars[i].mileage = atoi(mileage_str);

      
        strncpy(cars[i].name, input, j + 1);
        cars[i].name[j + 1] = '\0';
    }

    heapsort(cars, n);

    for (int i = n - 1; i >= 0; i--) {
        printf("%s %d\n", cars[i].name, cars[i].mileage);
    }

    return 0;
}

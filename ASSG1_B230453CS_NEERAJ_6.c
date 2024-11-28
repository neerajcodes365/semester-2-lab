#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= j && arr[i] <= pivot)
            i++;
        while (arr[j] >= pivot && j >= i)
            j--;
        if (i <= j)
            swap(&arr[i], &arr[j]);
        else
            break;
    }

    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;

    scanf("%d", &n);

    if(n<0 || n>10000) return 0 ;

    int songs[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &songs[i]);
    }

    for (int i = 0; i < n; i++) {
        if(n<0 || n>1000000) return 0 ;
    }


    quickSort(songs, 0, n - 1);


    for (int i = 0; i < n; i++) {
        printf("%d ", songs[i]);
    }

    return 0;
}

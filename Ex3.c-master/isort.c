#include <stdio.h>
#define SIZE 50


int ans[SIZE];
int arr[SIZE] = {0};

/**
 * Moves the array to the right - by i elements from pointer location.
 * @param arr - Pointer to an element from an array
 * @param i - The number of elements that need to be moved
 */
void shift_element(int *arr, int i) {
    while (i > 0) {
        *(arr + i) = *(arr + i - 1);
        i--;
    }
}

/**
 * Sorting given element to an array.
 * @param arr  - The container array
 * @param len - The length in the array we want to sort
 */
void insertion_sort(int *arr, int len) {
    int flag = 0;
    for (int i = 0; i <= len; ++i) {
        if (*(ans+i) == -1 || *(ans+i) >= *arr) {// Refers to the case where we want to move to the right
                shift_element(ans + i, len - i);
                *(ans+i) = *arr;
                flag = -1;//To prevent entering the outside 'if'
                break;
        }
    }
    if (flag == 0) {// In case the element you want to add is bigger than all of them
        *(ans+len -1)= *arr;
    }
}

int main() {
    //Initiating the ans array to -1
    for (int i = 0; i < SIZE ; ++i) {
        *(ans+i) = -1;
    }

    //Entering Size numbers to an arr
    printf("Enter %d numbers: ",SIZE);
    for (int i = 0; i < SIZE; ++i) {
        scanf("%d", (arr+i));

    }
    printf("\n");

    //Sorting
    for (int i = 0; i < SIZE; ++i) {
        insertion_sort(arr + i, i);
    }

    //Printing the final array
    for (int j = 0; j < SIZE; ++j) {
        if(j==SIZE-1){//Printing the last index
            printf("%d", *(ans+j));
            break;
        }
        printf("%d,", *(ans+j));
    }
    return 0;
}


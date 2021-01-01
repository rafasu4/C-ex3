#include <stdio.h>
#include "isort.h"
#define SIZE 50


int ans[SIZE];
int arr[SIZE] = {0};


// Moves the array to the right - by i elements from pointer location
void shift_element(int *arr, int i) {
    while (i > 0) {
        *(arr + i) = *(arr + i - 1);
        i--;
    }
}


//Sorting given element to an array
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
    for (int i = 0; i < SIZE; ++i) {
           int x=0;
    
           scanf("%d", &x);
           *(arr+i)=x;
          

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
    printf("\n");
    return 0;
}


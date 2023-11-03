// merge sort
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
void quick_sort(int *arr, int start, int end);
void input(int *arr, int size);
void print(int *arr, int size);
void main() {
  int size;
  while (1) {
    printf("Enter the size of the array:");
    scanf("%d", &size);
    if (size > 0) {
      break;
    }
    printf("!! Enter a valid size !!\n");
  }

  int *arr = (int *)calloc(size, sizeof(int));
  input(arr, size);
  quick_sort(arr, 0, size - 1);
  print(arr, size);
}
void input(int *arr, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("Enter the element at index %d:", i);
    scanf("%d", (arr + i));
  }
}
void quick_sort(int *arr, int start, int end) {
  if (start >= end) { // start > end is sufficient
    return;
  } else {
    int j = start;
    int i = j - 1;
    for (j; j <= end; j++) {
      if (arr[j] < arr[end] || j == end) {
        int temp = arr[++i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    printf("qs:");
    print(arr + start, end - start + 1);
    quick_sort(arr, start, i - 1);
    quick_sort(arr, i + 1, end);
  }
}
void print(int *arr, int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    printf("%d,", arr[i]);
  }
  printf("\b]\n");
}

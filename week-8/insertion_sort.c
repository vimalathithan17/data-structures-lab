// insertion sort
#include <stdio.h>
#include <stdlib.h>
void insertion_sort(int *arr, int size);
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
  insertion_sort(arr, size);
  print(arr, size);
}
void input(int *arr, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("Enter the element at index %d:", i);
    scanf("%d", (arr + i));
  }
}
void insertion_sort(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    int current_val = arr[i];
    int j;
    for (j = i - 1; j >= 0; j--) {
      if (arr[j] > current_val) {
        arr[j + 1] = arr[j];
      } else {
        break;
      }
    }
    arr[j + 1] = current_val;
    print(arr, size);
  }
}
void print(int *arr, int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    printf("%d,", arr[i]);
  }
  printf("\b]\n");
}

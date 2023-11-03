// bubble sort
#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int *arr, int size);
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
  bubble_sort(arr, size);
  print(arr, size);
}
void input(int *arr, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("Enter the element at index %d:", i);
    scanf("%d", (arr + i));
  }
}
void bubble_sort(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    int sorted = 1;
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        sorted = 0;
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
    print(arr, size);
    if (sorted) {
      return;
    }
  }
}
void print(int *arr, int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    printf("%d,", arr[i]);
  }
  printf("\b]\n");
}

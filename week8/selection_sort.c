// selection sort
#include <stdio.h>
#include <stdlib.h>
void selection_sort(int *arr, int size);
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
  selection_sort(arr, size);
  print(arr, size);
}
void input(int *arr, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("Enter the element at index %d:", i);
    scanf("%d", (arr + i));
  }
}
void selection_sort(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    int min_val_index = i;
    for (int j = i; j < size; j++) {
      if (arr[j] < arr[min_val_index]) {
        min_val_index = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[min_val_index];
    arr[min_val_index] = temp;
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

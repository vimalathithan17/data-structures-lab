#include <stdio.h>
#include <stdlib.h>
void input(int *arr, int size);
void print(int *arr, int size);
void count_sort(int *arr, int size);
int find_max(int *arr, int size);
int *count(int *arr, int size, int max);
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
  print(arr, size);
  count_sort(arr, size);
  printf("Sorted array is:");
  print(arr, size);
}

void input(int *arr, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("Enter the element at index %d:", i);
    scanf("%d", (arr + i));
  }
}
void print(int *arr, int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    printf("%d,", arr[i]);
  }
  printf("\b]\n");
}
void count_sort(int *arr, int size) {
  int max = find_max(arr, size);
  int *count_arr = count(arr, size, max);
  int i = 0, j = 0;
  for (i; i <= max; i++) {
    int count = j + count_arr[i];
    for (j; j < count; j++) {
      arr[j] = i;
    }
  }
}
int find_max(int *arr, int size) {
  int max_index = 0;
  for (int i = 0; i < size; i++) {
    if (arr[max_index] < arr[i]) {
      max_index = i;
    }
  }
  // printf("max:%d", arr[max_index]);
  return arr[max_index];
}
int *count(int *arr, int size, int max) {
  int *count_arr = (int *)calloc(max + 1, sizeof(int));
  for (int i = 0; i < size; i++) {
    count_arr[arr[i]] += 1;
  }
  // print(count_arr, max + 1);
  return count_arr;
}

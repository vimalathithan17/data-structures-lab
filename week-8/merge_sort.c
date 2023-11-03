// merge sort
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
int *merge_sort(int *arr, int start, int end);
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
  arr = merge_sort(arr, 0, size - 1);
  print(arr, size);
}
void input(int *arr, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("Enter the element at index %d:", i);
    scanf("%d", (arr + i));
  }
}
int *merge_sort(int *arr, int start, int end) {
  if (start == end) {
    int *new_arr = (int *)calloc(1, sizeof(int));
    new_arr[0] = arr[start];
    return new_arr;
  } else if (start > end) { // not needed
    return NULL;
  } else {
    int mid = (start + end) / 2;
    int *left_arr = merge_sort(arr, start, mid);
    int *right_arr = merge_sort(arr, mid + 1, end);

    int left_size = mid - start + 1;
    int right_size = end - (mid + 1) + 1;
    printf("left_arr:");
    print(left_arr, left_size);
    printf("right_arr:");
    print(right_arr, right_size);
    if (left_size == 0) {
      printf("lft 0\n");
      return right_arr;
    } else if (right_size == 0) {
      printf("rigt 0\n");
      return left_arr;
    } else {
      int sub_arr_size = left_size + right_size;
      int *sub_arr = (int *)calloc(sub_arr_size, sizeof(int));
      int i, j, k;
      for (i = 0, j = 0, k = 0; i < left_size && j < right_size; k++) {
        if (left_arr[i] < right_arr[j]) {
          sub_arr[k] = left_arr[i];
          i++;
        } else {
          sub_arr[k] = right_arr[j];
          j++;
        }
      }
      if (i != left_size) {
        for (i; i < left_size; i++, k++) {
          sub_arr[k] = left_arr[i];
        }
      } else if (j != right_size) {
        for (j; j < right_size; j++, k++) {
          sub_arr[k] = right_arr[j];
        }
      }
      free(left_arr);
      free(right_arr);
      return sub_arr;
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

#include <stdio.h>
#include <stdlib.h>
void input(int *arr, int size);
int find_minimum(int *arr, int size);
int main() {
  int size;
  while (1) {
    printf("Enter the size:");
    scanf("%d", &size);
    if (size > 0) {
      break;
    }
    printf("!! Enter a number greater than 0.Try Again !!\n");
  }

  int *arr = (int *)calloc(size, sizeof(int));
  input(arr, size);
  printf("after input\n");
  int min_val = find_minimum(arr, size);
  printf("after fimi");
  printf("the minimum value is %d\n", min_val);
  return 1;
}
void input(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("Enter the element at index %d:", i);
    scanf("%d", arr + i);
    printf("inp\n");
  }
}

int find_minimum(int *arr, int size) {
  int low = 0;
  int high = size - 1;
  int mid = (low + high) / 2;
  int i = 0;
  printf("o %d %d %d %d\n", i, low, mid, high);
  while (1) {
    printf("in loop\n");
    if (low == high) {
      printf("==");
      return arr[low];
    } else if (mid == 0) {
      printf("mid==0-");
      if (arr[mid] < arr[size - 1] && arr[mid] < arr[(mid + 1) % size]) {
        printf("r-mid\n");
        return arr[mid];
      } else {
        printf("l++");
        low++;
      }
    } else if ((arr[mid] < arr[mid - 1]) && (arr[mid] < arr[mid + 1])) {
      printf("smllst");
      return arr[mid];
    } else if ((arr[mid] > arr[mid - 1]) && (arr[mid] > arr[mid + 1])) {
      printf("grtst");
      return arr[mid + 1];
    } else {
      if (arr[low] < arr[mid] && arr[mid] < arr[high]) {
        printf("s g");
        high = mid - 1;
      } else if (arr[low] < arr[mid] && arr[high] < arr[mid]) {
        printf("s s-");
        if (arr[low] < arr[high]) {
          printf("l<h");
          high = mid - 1;
        } else {
          printf("l>h");
          low = mid + 1;
        }
      } else if (arr[low] > arr[mid] && arr[high] > arr[mid]) {
        printf("g g-");
        if (arr[low] > arr[high]) {
          printf("l>h");
          high = mid - 1;
        } else {
          printf("l<h");
          low = mid + 1;
        }
      }
      mid = (low + high) / 2;
      printf("-->%d %d %d %d\n", i, low, mid, high);
      i++;
      if (i > 6) {
        printf("broke");
        return 0;
      }
    }
  }
}

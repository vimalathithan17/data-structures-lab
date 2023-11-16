#include <stdio.h>
#include <stdlib.h>
void input(int *arr, int size);
void print(int *arr, int size);
int *radix_sort(int *arr, int size);
int find_max(int *arr, int size);
int find_digits(int num);
int find_digits(int num);
int extract(int value, int place);
int power(int base, int exponent);
int *parse(int *arr, int size, int place);
int *count(int *parse_arr, int size, int max);
int *position(int *count_arr, int size);
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
  arr = radix_sort(arr, size);
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
int *radix_sort(int *arr, int size) {
  int max = find_max(arr, size);
  int digits = find_digits(max);
  // int *res_arr;
  for (int i = 0; i < digits; i++) {
    int *parse_arr = parse(arr, size, i + 1);
    int max_val = find_max(parse_arr, size);
    int *count_arr = count(parse_arr, size, max_val);
    int *position_arr = position(count_arr, max_val + 1);
    int *res_arr = (int *)calloc(size, sizeof(int));
    // printf("\npa,ca,pos");
    // print(parse_arr, size);
    // print(count_arr, max_val + 1);
    // print(position_arr, max_val + 1);
    // printf("maxval:%d", max_val);
    for (int j = size - 1; j >= 0; j--) {
      int value = extract(arr[j], i + 1);
      res_arr[(--position_arr[value])] = arr[j];
      /* printf("arr[j]:%d p :%d val:%d pos:%d ra:%d\n", arr[j], i + 1, value,
             position_arr[value], res_arr[position_arr[value]]);*/
    }
    // free(arr);
    arr = res_arr;
    // printf("res_arr");
    // print(arr, size);
    // print(res_arr, size);
  }
  return arr;
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
int find_digits(int num) {
  int digits = 0;
  while (num != 0) {
    num /= 10;
    digits++;
  }
  return digits;
}
int power(int base, int exponent) {
  int result = 1;
  for (int i = 0; i < exponent; i++) {
    result *= base;
  }
  return result;
}
int extract(int value, int place) {
  return ((value % power(10, place)) / power(10, place - 1));
}
int *parse(int *arr, int size, int place) {
  int *parse_arr = (int *)calloc(size, sizeof(int));
  for (int i = 0; i < size; i++) {
    parse_arr[i] = extract(arr[i], place);
    // printf("arr i %d pa i %d p %d", arr[i], parse_arr[i], place);
  }
  return parse_arr;
}
int *count(int *parse_arr, int size, int max) {
  // printf("in ca,max:%d", max);
  int *count_arr = (int *)calloc(max + 1, sizeof(int));
  for (int i = 0; i < size; i++) {
    // printf("i %d", i);
    // print(count_arr, max + 1);
    count_arr[parse_arr[i]] += 1;
  }
  // print(count_arr, max + 1);
  return count_arr;
}
int *position(int *count_arr, int size) {
  int *position_arr = (int *)calloc(size, sizeof(int));
  int position_count = 0;
  for (int i = 0; i < size; i++) {
    position_count += count_arr[i];
    position_arr[i] = position_count;
  }
  return position_arr;
}

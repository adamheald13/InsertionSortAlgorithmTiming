#include "InsertionSort.h"

void InsertionSort::sort(long array[], long size)
{
  for(long i = 2; i < size; i++) {
    long j = i;
    long temp = array[i];
    while(temp < array[j - 1]) {
      array[j] = array[j -1];
      j--;
    }
    array[j] = temp;
  }
}

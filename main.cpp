/* srand example */
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include "Timer.cpp"
#include "InsertionSort.h"
using namespace std;

Timer timer;
InsertionSort sorter;

long part1DataSet[200000];
long part2DataSet[400000];

void timingPart1();
void timingPart2();
void initDataSet(long size);

int main ()
{
  std::cout << "---------- Part 1 ----------" << std::endl;
  srand(time(NULL));
  for(int i = 0; i < 10; i++)
    timingPart1();

  std::cout << "---------- Part 2 ----------" << std::endl;
  srand(20);
  for(int i = 0; i < 5; i++)
    timingPart2();

  return 0;
}

void timingPart1()
{
  long size = 200000;
  initDataSet(size);
  timer.start();
  sorter.sort(part1DataSet, size);
  timer.printTime(timer.stop());
}

void timingPart2()
{
  long size = 400000;
  initDataSet(size);
  timer.start();
  sorter.sort(part2DataSet, size);
  timer.printTime(timer.stop());
}

void initDataSet(long size)
{
  part2DataSet[0] = -100000;
  part1DataSet[0] = -100000;

  if(size == 200000) {
    for(long i = 1; i < size; i++) {         //generate data set
      part1DataSet[i] = rand()%80001 - 40000;
    }
  } else {
    for(long i = 1; i < size; i++) {         //generate data set
      part1DataSet[i] = rand()%160001 - 40000;
    }
  }
}

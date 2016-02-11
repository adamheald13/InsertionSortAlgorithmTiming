/* srand example */
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <fstream>
#include "Timer.cpp"
#include "InsertionSort.h"
using namespace std;

Timer timer;
InsertionSort sorter;
ofstream outStream;

double duration;

long part1DataSet[200000];
long part2DataSet[400000];

void timingPart1();
void timingPart2();
void initDataSet(long size);

int main ()
{
  std::cout << "---------- Part 1 ----------" << std::endl;
  srand(time(NULL));
  outStream.open("Lab03Part1Results.txt");
  for(int i = 0; i < 10; i++)
    timingPart1(i);

  std::cout << "---------- Part 2 ----------" << std::endl;
  srand(20);
  outStream.open("Lab03Part2Results.txt");
  for(int i = 0; i < 5; i++)
    timingPart2(i);

  return 0;
}

void timingPart1(int i)
{
  long size = 200000;
  initDataSet(size);
  timer.start();
  sorter.sort(part1DataSet, size);
  duration = timer.stop();
  outStream << "Run " << i + 1 << ": " duration << " seconds";
}

void timingPart2(int i)
{
  long size = 400000;
  initDataSet(size);
  timer.start();
  sorter.sort(part2DataSet, size);
  duration = timer.stop();
  outStream << "Run " << i + 1 << ": " duration << " seconds";
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

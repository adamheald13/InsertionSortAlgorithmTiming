/* srand example */
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
using namespace std;

void timingPart1();
int *part1DataSet = new int[200000];
void timingPart2();
int *part2DataSet = new int[400000];

int main ()
{
  timingPart1();
  timingPart2();

  delete part1DataSet;
  delete part2DataSet;

  return 0;
}

void timingPart1()
{
  std::cout << "---------- Part 1 ----------" << std::endl;

  srand(time(NULL));

  for(int i = 0; i < 200000; i++) {         //generate data set
    part1DataSet[i] = rand()%80000 - 40000;
  }
}

void timingPart2()
{
  std::cout << "---------- Part 2 ----------" << std::endl;

  srand(20);

  for(int i = 0; i < 400000; i++) {         //generate data set
    part2DataSet[i] = rand()%160000 - 80000;
  }
}

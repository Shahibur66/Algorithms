
#include <stdio.h>

struct Activity {
  char id[5];
  int start;
  int finish;
};

void activitySelection(Activity activities[], int n);

int main(void) {

  Activity activities[8] = {
    {"a1", 1, 3},
    {"a2", 0, 4},
    {"a3", 1, 2},
    {"a4", 4, 6},
    {"a5", 2, 9},
    {"a6", 5, 8},
    {"a7", 3, 5},
    {"a8", 4, 5}
  };

  int n = 8;

  activitySelection(activities, n);

  return 0;
}

void activitySelection(Activity activities[], int n) {

  int i, j;

  Activity temp;

  for(i = 1; i < n; i++) {
    for(j = 0; j < n - 1; j++){
      if(activities[j].finish > activities[j+1].finish) {
        temp = activities[j];
        activities[j] = activities[j+1];
        activities[j+1] = temp;
      }
    }
  }

 
  printf("Sorted activities as per finish time (ascending order)\n");
  printf("%10s %10s %10s\n", "Activity", "Start", "Finish");
  for(i = 0; i < n; i++) {
    printf("%10s %10i %10i\n", activities[i].id, activities[i].start, activities[i].finish);
  }


  printf("-----Selected Activities-----\n");
  printf("%10s %10s %10s\n", "Activity", "Start", "Finish");
  printf("%10s %10i %10i\n", activities[0].id, activities[0].start, activities[0].finish);

 
  i = 0;
  for(j = 1; j < n; j++) {
    if(activities[j].start >= activities[i].finish) {
      printf("%10s %10i %10i\n", activities[j].id, activities[j].start, activities[j].finish);
      i = j;
    }
  }
}

/*
Output

Sorted activities as per finish time (ascending order)
  Activity      Start     Finish
        a3          1          2
        a1          1          3
        a2          0          4
        a7          3          5
        a8          4          5
        a4          4          6
        a6          5          8
        a5          2          9
-----Selected Activities-----
  Activity      Start     Finish
        a3          1          2
        a7          3          5
        a6          5          8
*/

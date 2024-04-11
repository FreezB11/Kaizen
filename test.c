#include <stdio.h>
#define ROWS 3
#define COLS 3

void func(int array[ROWS][COLS])
{
  int i, j;

//   for (i=0; i<ROWS; i++)
//   {
//     for (j=0; j<COLS; j++)
//     {
//       array[i][j] = i*j;
//     }
//   }
  for (i=0; i<ROWS; i++)
  {
    for (j=0; j<COLS; j++)
    {
      printf("%d %d == %d\n",i,j,array[i][j]);
    }
  }
}

void func_vla(int rows, int cols, int array[rows][cols])
{
  int i, j;

  for (i=0; i<rows; i++)
  {
    for (j=0; j<cols; j++)
    {
      array[i][j] = i*j;
    }
  }
}

int main()
{
  int x[ROWS][COLS] = {{1,2,3},
                       {4,5,6},
                       {7,8,9}};

  func(x);
  func_vla(ROWS, COLS, x);
}

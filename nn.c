#include <stdio.h>
#include <time.h>
#include "lib/calculas.h"

int dataset[4][2] ={
  //{x,y}
    {0,0},
    {1,2},
    {2,4},
    {3,6}
}; 

// here y=2x

//y= m*x+b;

int w = 0; // weight
double cost =0;


int main (){

    for(int i =0;i<4;i++){
        int x = dataset[i][0];
        int y_desired = dataset[i][1];
        int y = w*x;

        cost += (y_desired-y)*(y_desired-y); 

        double dcost = df(cost,w);

        printf("%d == %d, cost:: %lf\n",y_desired,y,cost);

    }



    return 0;
}
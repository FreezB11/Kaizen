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

double w = 0; // weight
double cost(int y1,int y2){

    double cost = (y1-y2)*(y1-y2);

    return cost;
}

double costt = 0;

int main (){

    for(int i =0;i<4;i++){
        int x = dataset[i][0];
        int y_desired = dataset[i][1];
        int y = w*x;

         costt += cost(y,y_desired);

        double dcost = df(cost,w);
        w -= dcost;

        printf("%d == %d, cost:: %lf\n",y_desired,y,costt);

    }



    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAND_MAX 2147483647
// float eps = 1.61012e-4;

#define train_count (sizeof(train)/sizeof(train[0]))

int train[][3] ={
  //{x,y}
    {0,0,0},
    {1,0,1},
    {0,1,1},
    {1,1,1}
}; 

float rand_float(void){
    return (float)rand()/(float)RAND_MAX;
}

float cost(float w1,float w2){
    float result = 0.0f;
    for(size_t i =0;i<train_count;++i){
        float x1 = train[i][0];
        float x2 = train[i][1];
        float y = x1*w1+x2*w2;
        float d = y - train[i][1];
        result += d*d; 
        // printf("actual :: %f, expected :: %d\n",y,train[i][1]);
    }

    result /= train_count;
    return result;
}
int main(){
    srand(69);
    float w1 = rand_float();
    float w2 = rand_float();

    printf("w1= %f,w2 = %f\n",w1,w2);
    return 0;
}

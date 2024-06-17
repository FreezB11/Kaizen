#include <iostream>
#include <string>
//testing
struct tests
{
    int x;
    int sq(int x){
        return x*x;
    };
};
//learning
class player{
public:
    std::string name;
    float pos_x,pos_y;
    float speed;
    void ipp(float x,float y){
        pos_x = x;
        pos_y =y;
    }
    void move(float dx,float dy){
        pos_x += dx*speed;
        pos_y += dy*speed;
    }

};

int main(){

    // struct tests t;
    // t.x = 5;
    // t.sq(5);
    // std::cout << t.sq(5) << std::endl;

    player p;
    p.name = "adam";
    p.speed = 0.6;
    p.ipp(0,0);
    p.move(5,6);

    std::cout << p.pos_x <<"||"<< p.pos_y << std::endl;

    return 0;
}
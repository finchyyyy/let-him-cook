#include "Box.h"

    //when she destruct on my box till i uhhhhhhhhhh
virtual Box::~Box(){}

bool overlap(Box a, Box b){
        //bounds check
    if(a.width == 0 || a.height == 0 || b.width == 0 || b.height == 0)
        return false;

        //normalise
    if(a.width < 0){a.width *= -1; a.posX -= a.width;}
    if(b.width < 0){b.width *= -1; b.posX -= b.width;}
    if(a.height < 0){a.height *= -1; a.posY -= a.height;}
    if(b.height < 0){b.height *= -1; b.posY -= b.height;}

        //calculate
    return (a.posX < (b.posX + b.width))
        && (b.posX < (a.posX + a.width))
        && (a.posY < (b.posY + b.height))
        && (b.posY < (a.posY + a.height));
}

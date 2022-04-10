#include "rectangle.h"
int Rectangle::area(){
    return width*height;
}
int Rectangle::perimeter(){
    return 2*(width+height);
}
#include <stdio.h>
int main(void) {
    int x, y, z, m;
    x = 5;
    y = 4;
    z = 8;
    m = 0;
    if(x<y)
    {
        m=x;
    }else {
        m=y;
    }
    if(m<z){
        ;
    } else {
        m = z;
    }
}
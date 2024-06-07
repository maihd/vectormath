#include <stdio.h>


typedef float vec2 __attribute__((vector_size(8), aligned(4)));


int main()
{
    vec2 a = (vec2){ 0, 1 };
    vec2 b = (vec2){ 2, 3 };
    vec2 c = a + b;

    printf("c = {%f, %f}\n", c[0], c[1]);

    // Compile error
    // printf("c = {%f, %f}\n", c.x, c.y);

    return 0;
}

//! EOF


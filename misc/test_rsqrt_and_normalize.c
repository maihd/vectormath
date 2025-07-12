#include <stdio.h>
#include "scalarmath.h"
#include "vectormath.h"

int main()
{
    float len = 0;
    float f = float_rsqrt(len);
    float f2 = float_fast_rsqrt(len);
    float f3 = float_fast_rsqrt(len + 1e-37f);

    printf("len = %f\n", len);
    printf("f = %f\n", f);
    printf("f2 = %f\n", f2);
    printf("f3 = %f\n", f3);

    vec2 v = vec2_new(0, 0);
    float vlen = vec2_len(v);
    vec2 n = vec2_norm(v);
    printf("n = (%f, %f)\n", n.x, n.y);

    return 0;
}

//! EOF


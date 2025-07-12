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
    vec2 n = vec2_norm(v);
    printf("n = (%f, %f)\n", n.x, n.y);
    printf("n.len = %f\n", vec2_len(n));

    vec2 v2 = vec2_new(2, 2);
    vec2 n2 = vec2_norm(v2);
    printf("n2 = (%f, %f)\n", n2.x, n2.y);
    printf("n2.len = %f\n", vec2_len(n2));

    return 0;
}

//! EOF


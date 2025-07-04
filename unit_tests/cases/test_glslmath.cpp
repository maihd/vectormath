#include "../test_framework.h"

#include <glslmath.h>

DEFINE_UNIT_TEST("glslmath: BLINN PHONG")
{
    /* GLSL source code
    attribute vec3 inputPosition;
    attribute vec3 inputNormal;

    uniform mat4 projection, modelview, normalMat;

    varying vec3 normalInterp;
    varying vec3 vertPos;

    void main() 
    {
        gl_Position = projection * modelview * vec4(inputPosition, 1.0);
        vec4 vertPos4 = modelview * vec4(inputPosition, 1.0);
        vertPos = vec3(vertPos4) / vertPos4.w;
        normalInterp = vec3(normalMat * vec4(inputNormal, 0.0));
    }
    */

    vec3 inputPosition = {};
    vec3 inputNormal = {};
    
    mat4 projection = {}, modelview = {}, normalMat = {};

    vec3 normalInterp;
    vec3 vertPos;

    vec4 gl_Position = (projection * modelview) * vec4(inputPosition, 1.0f);
    vec4 vertPos4 = modelview * vec4(inputPosition, 1.0f);
    vertPos = vec3(vertPos4) / vertPos4.w;
    normalInterp = vec3(normalMat * vec4(inputNormal, 0.0f));
}

//! EOF

#pragma once

#include <stdint.h>

// Make sure do not include other OpenGL loaders
#ifdef __gl_h_
#error OpenGL header already included, remove this include, GLLoader.h already provides it
#else
#define __gl_h_
#endif

// -----------------------------------------------------
// OpenGL types
// -----------------------------------------------------

// DONOT DEFINE TYPES, USE TYPES OF STDINT.H

// -----------------------------------------------------
// OpenGL functions
// -----------------------------------------------------

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#   define GL_APICALL __stdcall
#else
#   define GL_APICALL
#endif

#define GL_FUNC(Name, TReturn, ...) extern TReturn (GL_APICALL* Name)(##__VA_ARGS__)

#ifdef __cplusplus
extern "C" {
#endif

GL_FUNC(glClearColor, void, float r, float g, float b, float a);
GL_FUNC(glClear, void, uint32_t mask);

GL_FUNC(glViewport, void, int x, int y, int w, int h);
GL_FUNC(glDrawArrays, void, uint32_t mode, int start, int count);
GL_FUNC(glDrawElements, void, uint32_t mode, int count, uint32_t type, const void* indices);

GL_FUNC(glEnable, void, uint32_t mode);
GL_FUNC(glDisable, void, uint32_t mode);

GL_FUNC(glBlendFunc, void, uint32_t sfactor, uint32_t dfactor);
GL_FUNC(glBlendEquation, void, uint32_t equation);

GL_FUNC(glBindTexture, void, uint32_t target, uint32_t texture);
GL_FUNC(glTexParameteri, void, uint32_t target, uint32_t pname, uint32_t param);
GL_FUNC(glTexImage2D, void, uint32_t target, int level, int internalFormat, int width, int height, int border, uint32_t format, uint32_t type, const void* pixels);

GL_FUNC(glGenTextures, void, int count, uint32_t* textures);
GL_FUNC(glDeleteTextures, void, int count, uint32_t* textures);
GL_FUNC(glActiveTexture, void, uint32_t textureIndex);

GL_FUNC(glCreateProgram, uint32_t);
GL_FUNC(glDeleteProgram, void, uint32_t program);
GL_FUNC(glLinkProgram, void, uint32_t program);
GL_FUNC(glUseProgram, void, uint32_t program);

GL_FUNC(glGetProgramiv, void, uint32_t program, uint32_t pname, int* param);
GL_FUNC(glGetProgramInfoLog, void, uint32_t program, int bufSize, int* length, char* infoLog);

GL_FUNC(glCreateShader, uint32_t, uint32_t type);
GL_FUNC(glDeleteShader, void, uint32_t shader);

GL_FUNC(glAttachShader, void, uint32_t program, uint32_t shader);
GL_FUNC(glDetachShader, void, uint32_t program, uint32_t shader);

GL_FUNC(glShaderSource, void, uint32_t shader, int count, const char** sources, const int* length);
GL_FUNC(glCompileShader, void, uint32_t shader);

GL_FUNC(glGetUniformLocation, int, uint32_t program, const char* name);
GL_FUNC(glUniform3f, void, int location, float x, float y, float z);
GL_FUNC(glUniformMatrix4fv, void, int location, int count, int transpose, const float* value);

GL_FUNC(glGetShaderiv, void, uint32_t shader, uint32_t pname, int* param);
GL_FUNC(glGetShaderInfoLog, void, uint32_t shader, int bufSize, int* length, char* infoLog);

GL_FUNC(glGenBuffers, void, int count, uint32_t* buffers);
GL_FUNC(glDeleteBuffers, void, int count, const uint32_t* buffers);

GL_FUNC(glBindBuffer, void, uint32_t type, uint32_t buffer);
GL_FUNC(glBufferData, void, uint32_t type, int size, const void* data, uint32_t usage);

GL_FUNC(glGenVertexArrays, void, int count, uint32_t* vertexArrays);
GL_FUNC(glDeleteVertexArrays, void, int count, const uint32_t* vertexArrays);
GL_FUNC(glBindVertexArray, void, uint32_t vertexArray);

GL_FUNC(glEnableVertexAttribArray, void, int location);
GL_FUNC(glVertexAttribPointer, void, int location, int size, uint32_t type, uint8_t normalized, int stride, const void* pointer);

// -----------------------------------------------------
// OpenGL enum values
// -----------------------------------------------------

enum
{
    GL_COLOR_BUFFER_BIT = 0x00004000,

    GL_RGB = 0x1907,
    GL_RGBA = 0x1908,
    GL_TEXTURE_2D = 0x0DE1,
    GL_NEAREST = 0x2600,
    GL_LINEAR = 0x2601,
    GL_NEAREST_MIPMAP_NEAREST = 0x2700,
    GL_LINEAR_MIPMAP_NEAREST = 0x2701,
    GL_NEAREST_MIPMAP_LINEAR = 0x2702,
    GL_LINEAR_MIPMAP_LINEAR = 0x2703,
    GL_TEXTURE_MAG_FILTER = 0x2800,
    GL_TEXTURE_MIN_FILTER = 0x2801,
    GL_TEXTURE_WRAP_S = 0x2802,
    GL_TEXTURE_WRAP_T = 0x2803,
    GL_CLAMP = 0x2900,
    GL_REPEAT = 0x2901,

    GL_TEXTURE0 = 0x84C0,
    GL_TEXTURE1 = 0x84C1,
    GL_TEXTURE2 = 0x84C2,
    GL_TEXTURE3 = 0x84C3,
    GL_TEXTURE4 = 0x84C4,
    GL_TEXTURE5 = 0x84C5,
    GL_TEXTURE6 = 0x84C6,
    GL_TEXTURE7 = 0x84C7,

    GL_DELETE_STATUS = 0x8B80,
    GL_COMPILE_STATUS = 0x8B81,
    GL_LINK_STATUS = 0x8B82,

    GL_FRAGMENT_SHADER = 0x8B30,
    GL_VERTEX_SHADER = 0x8B31,

    // -----------------------------------------------------
    // Draw types
    // ----------------------------------------------------- 

    GL_POINTS = 0x0000,
    GL_LINES = 0x0001,
    GL_LINE_LOOP = 0x0002,
    GL_LINE_STRIP = 0x0003,
    
    GL_TRIANGLES = 0x0004,
    GL_TRIANGLE_STRIP = 0x0005,
    GL_TRIANGLE_FAN = 0x0006,

    // -----------------------------------------------------
    // Vertex buffer
    // ----------------------------------------------------- 

    GL_ARRAY_BUFFER = 0x8892,
    GL_ELEMENT_ARRAY_BUFFER = 0x8893,

    GL_STREAM_DRAW = 0x88E0,
    GL_STREAM_READ = 0x88E1,
    GL_STREAM_COPY = 0x88E2,
    GL_STATIC_DRAW = 0x88E4,
    GL_STATIC_READ = 0x88E5,
    GL_STATIC_COPY = 0x88E6,
    GL_DYNAMIC_DRAW = 0x88E8,
    GL_DYNAMIC_READ = 0x88E9,
    GL_DYNAMIC_COPY = 0x88EA,

    // -----------------------------------------------------
    // Data types
    // ----------------------------------------------------- 
    
    GL_INT8     = 0x1400,
    GL_UINT8    = 0x1401,
    GL_INT16    = 0x1402,
    GL_UINT16   = 0x1403,
    GL_INT32    = 0x1404,
    GL_UINT32   = 0x1405,
    GL_FLOAT    = 0x1406,
    GL_DOUBLE   = 0x140A,

    // -----------------------------------------------------
    // Modes
    // ----------------------------------------------------- 

    GL_BLEND = 0x0BE2,

    // -----------------------------------------------------
    // Blend functions & equations
    // -----------------------------------------------------    

    GL_ACCUM = 0x0100,
    GL_LOAD = 0x0101,
    GL_RETURN = 0x0102,
    GL_MULT = 0x0103,
    GL_ADD = 0x0104,
    GL_NEVER = 0x0200,
    GL_ACCUM_BUFFER_BIT = 0x00000200,
    GL_LESS = 0x0201,
    GL_EQUAL = 0x0202,
    GL_LEQUAL = 0x0203,
    GL_GREATER = 0x0204,
    GL_NOTEQUAL = 0x0205,
    GL_GEQUAL = 0x0206,
    GL_ALWAYS = 0x0207,
    GL_SRC_COLOR = 0x0300,
    GL_ONE_MINUS_SRC_COLOR = 0x0301,
    GL_SRC_ALPHA = 0x0302,
    GL_ONE_MINUS_SRC_ALPHA = 0x0303,
    GL_DST_ALPHA = 0x0304,
    GL_ONE_MINUS_DST_ALPHA = 0x0305,
    GL_DST_COLOR = 0x0306,
    GL_ONE_MINUS_DST_COLOR = 0x0307,
    GL_SRC_ALPHA_SATURATE = 0x0308,
};

// -----------------------------------------------------
// Load OpenGL functions
// -----------------------------------------------------

typedef enum GLLoadError
{
    GLLoadError_None,
    GLLoadError_LoadDriverFailed,
    GLLoadError_FunctionNotFound,
} GLLoadError;

GLLoadError glLoadFunctions();

// -----------------------------------------------------
// Function to create OpenGL context
// -----------------------------------------------------

void* glCreateContext(struct WindowDesc* window);
void  glDeleteContext(void* context);
void  glMakeContextCurrent(struct WindowDesc* window, void* context);

#ifdef __cplusplus
}
#endif
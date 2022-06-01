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

#define DECL_GL_FUNC(RETURN_TYPE, NAME, ...) typedef RETURN_TYPE (GL_APICALL NAME##Fn)(##__VA_ARGS__); extern NAME##Fn* NAME

#ifdef __cplusplus
extern "C" {
#endif

DECL_GL_FUNC(void,      glClearColor, float r, float g, float b, float a);
DECL_GL_FUNC(void,      glClear, uint32_t mask);

DECL_GL_FUNC(void,      glViewport, int32_t x, int32_t y, int32_t w, int32_t h);
DECL_GL_FUNC(void,      glDrawArrays, uint32_t mode, int32_t start, int32_t count);
DECL_GL_FUNC(void,      glDrawElements, uint32_t mode, int32_t count, uint32_t type, const void* indices);

DECL_GL_FUNC(void,      glEnable, uint32_t mode);
DECL_GL_FUNC(void,      glDisable, uint32_t mode);

DECL_GL_FUNC(void,      glBlendFunc, uint32_t sfactor, uint32_t dfactor);
DECL_GL_FUNC(void,      glBlendEquation, uint32_t equation);

DECL_GL_FUNC(void,      glBindTexture, uint32_t target, uint32_t texture);
DECL_GL_FUNC(void,      glTexParameteri, uint32_t target, uint32_t pname, uint32_t param);
DECL_GL_FUNC(void,      glTexImage2D, uint32_t target, int32_t level, int32_t internalFormat, int32_t width, int32_t height, int32_t border, uint32_t format, uint32_t type, const void* pixels);

DECL_GL_FUNC(void,      glGenTextures, int32_t count, uint32_t* textures);
DECL_GL_FUNC(void,      glDeleteTextures, int32_t count, uint32_t* textures);
DECL_GL_FUNC(void,      glActiveTexture, uint32_t textureIndex);

DECL_GL_FUNC(uint32_t,  glCreateProgram);
DECL_GL_FUNC(void,      glDeleteProgram, uint32_t program);
DECL_GL_FUNC(void,      glLinkProgram, uint32_t program);
DECL_GL_FUNC(void,      glUseProgram, uint32_t program);

DECL_GL_FUNC(void,      glGetProgramiv, uint32_t program, uint32_t pname, int32_t* param);
DECL_GL_FUNC(void,      glGetProgramInfoLog, uint32_t program, int32_t bufSize, int32_t* length, char* infoLog);

DECL_GL_FUNC(uint32_t,  glCreateShader, uint32_t type);
DECL_GL_FUNC(void,      glDeleteShader, uint32_t shader);

DECL_GL_FUNC(void,      glAttachShader, uint32_t program, uint32_t shader);
DECL_GL_FUNC(void,      glDetachShader, uint32_t program, uint32_t shader);

DECL_GL_FUNC(void,      glShaderSource, uint32_t shader, int32_t count, const char** sources, const int32_t* length);
DECL_GL_FUNC(void,      glCompileShader, uint32_t shader);

DECL_GL_FUNC(int,       glGetUniformLocation, uint32_t program, const char* name);
DECL_GL_FUNC(void,      glUniform3f, int32_t location, float x, float y, float z);
DECL_GL_FUNC(void,      glUniformMatrix4fv, int32_t location, int32_t count, int32_t transpose, const float* value);

DECL_GL_FUNC(void,      glGetShaderiv, uint32_t shader, uint32_t pname, int32_t* param);
DECL_GL_FUNC(void,      glGetShaderInfoLog, uint32_t shader, int32_t bufSize, int32_t* length, char* infoLog);

DECL_GL_FUNC(void,      glGenBuffers, int32_t count, uint32_t* buffers);
DECL_GL_FUNC(void,      glDeleteBuffers, int32_t count, const uint32_t* buffers);

DECL_GL_FUNC(void,      glBindBuffer, uint32_t type, uint32_t buffer);
DECL_GL_FUNC(void,      glBufferData, uint32_t type, int32_t size, const void* data, uint32_t usage);

DECL_GL_FUNC(void,      glGenVertexArrays, int32_t count, uint32_t* vertexArrays);
DECL_GL_FUNC(void,      glDeleteVertexArrays, int32_t count, const uint32_t* vertexArrays);
DECL_GL_FUNC(void,      glBindVertexArray, uint32_t vertexArray);

DECL_GL_FUNC(void,      glEnableVertexAttribArray, int32_t location);
DECL_GL_FUNC(void,      glVertexAttribPointer, int32_t location, int32_t size, uint32_t type, uint8_t normalized, int32_t stride, const void* pointer);

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
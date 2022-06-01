#pragma once

#include "GlLoader.hpp"
#include <string>

#include <vectormath.h>

struct Shader
{
public:
	Shader(std::string const& vertexPath, std::string const& fragmentPath);

	void Activate();

	void SetUniform(const std::string& name, const mat4& value)
	{
		glUniformMatrix4fv(glGetUniformLocation(mId, name.c_str()), 1, GL_TRUE, (const GLfloat*)&value);
	}

	void SetUniform(const std::string& name, const vec3& value)
	{
		glUniform3f(glGetUniformLocation(mId, name.c_str()), value.x, value.y, value.z);
	}

private:
	GLuint mId;
};

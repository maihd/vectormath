#version 330 core

out vec4 FragColor;

in vec3 normal;
in vec3 fragPosWorld;

uniform vec3 uColor;

vec3 lightColor = vec3(1.0, 1.0, 1.0);

vec3 lightPos = vec3(-100.0, 50.0, 100.0);

void main()
{
	// Ambient
	float ambientStrength = 0.5;
	vec3 ambient = ambientStrength * lightColor;

	// Diffuse
	vec3 norm = normalize(normal);
	vec3 lightDir = normalize(lightPos - fragPosWorld);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;


	vec3 result = (ambient + diffuse) * uColor;
	FragColor = vec4(result, 1.0);
}

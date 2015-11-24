#version 330 core

in vec3 vertex;
in vec3 normal;

in vec3 vmatamb;
in vec3 vmatdiff;
in vec3 vmatspec;
in float vmatshin;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 TG;
uniform mat4 TG_patr;

uniform vec3 posFocus;

// Output to FS
out vec4 vertSCO;
out vec4 posFocusSCO;
out vec3 NormSCO;

out vec3 matamb;
out vec3 matdiff;
out vec3 matspec;
out float matshin;


void main()
{
    mat3 NormalMatrix = inverse(transpose(mat3(view*TG)));
    NormSCO = normalize(NormalMatrix * normal);
    posFocusSCO = view * TG_patr * vec4(posFocus,1);
    vertSCO = view * TG * vec4(vertex,1);

    matamb = vmatamb;
    matdiff = vmatdiff;
    matspec = vmatspec;
    matshin = vmatshin;

    gl_Position = proj * view * TG * vec4 (vertex, 1.0);
}

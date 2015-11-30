# version 330 core

in vec3 vertex;
in vec3 normal;

in vec3 matamb;
in vec3 matdiff;
in vec3 matspec;
in float matshin;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 TG;
uniform vec3 colFocus;


out vec3 matambf;
out vec3 matdifff;
out vec3 matspecf;
out float matshinf;


// Valors per als components que necessitem dels focus de llum
//vec3 colFocus = vec3(0.8, 0.8, 0.8);
vec3 llumAmbient = vec3(0.2, 0.2, 0.2);
//vec3 posFocus = vec3(0, 1, -1);  // en SCA

out vec3 fcolor;

out vec4 vertSCO;
out vec3 normalSCO;
//L es pos del focus de llum


void main()
{
    vertSCO = (view * TG * vec4 (vertex, 1.0));
    mat3 normalMatrix = inverse (transpose (mat3 (view * TG)));
    normalSCO =  normalize(normalMatrix * normal);
    //vec4 focusSCO = view *TG*vec4(posFocus,1.0);
  //  vec3 L = normalize(focusSCO.xyz - vertSCO.xyz);
//  fcolor = Lambert(normalSCO,L);
//fcolor = Phong(normalSCO,L,vertSCO);
    fcolor=colFocus;

    gl_Position = proj  * vertSCO;
    matambf=matamb;
    matdifff=matdiff;
    matspecf=matspec;
    matshinf=matshin;


}

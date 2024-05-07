#version 430

layout (location = 0) in vec3 aPos; // Pozíció attribútum beolvasása
layout (location = 1) in vec3 color; // Szín attribútum beolvasása
layout (location = 2) in vec3 aNormal; // Normális attribútum beolvasása

out vec3 myColor; // Kimeneti változó a színnek
out vec3 Normal; // Kimeneti változó a normálisnak
out vec3 FragPos; // Kimeneti változó a fragment pozíciójának

uniform mat4 model; // Model mátrix uniform változója
uniform mat4 view; // View mátrix uniform változója
uniform mat4 projection; // Projection mátrix uniform változója

void main(void)
{
	myColor = color; // A szín beállítása a bemeneti színre
	Normal = aNormal; // A normális beállítása a bemeneti normálisra
	FragPos = vec3(model * vec4(aPos, 1.0)); // A fragment pozíciójának számítása a model mátrix és a pozíció alapján

	gl_Position =  projection * view * model * vec4(aPos.x, aPos.y, aPos.z, 1.0); // A végsõ pozíció számítása a projekció, nézet és model mátrixok alkalmazásával
}

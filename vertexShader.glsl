#version 430

layout (location = 0) in vec3 aPos; // Poz�ci� attrib�tum beolvas�sa
layout (location = 1) in vec3 color; // Sz�n attrib�tum beolvas�sa
layout (location = 2) in vec3 aNormal; // Norm�lis attrib�tum beolvas�sa

out vec3 myColor; // Kimeneti v�ltoz� a sz�nnek
out vec3 Normal; // Kimeneti v�ltoz� a norm�lisnak
out vec3 FragPos; // Kimeneti v�ltoz� a fragment poz�ci�j�nak

uniform mat4 model; // Model m�trix uniform v�ltoz�ja
uniform mat4 view; // View m�trix uniform v�ltoz�ja
uniform mat4 projection; // Projection m�trix uniform v�ltoz�ja

void main(void)
{
	myColor = color; // A sz�n be�ll�t�sa a bemeneti sz�nre
	Normal = aNormal; // A norm�lis be�ll�t�sa a bemeneti norm�lisra
	FragPos = vec3(model * vec4(aPos, 1.0)); // A fragment poz�ci�j�nak sz�m�t�sa a model m�trix �s a poz�ci� alapj�n

	gl_Position =  projection * view * model * vec4(aPos.x, aPos.y, aPos.z, 1.0); // A v�gs� poz�ci� sz�m�t�sa a projekci�, n�zet �s model m�trixok alkalmaz�s�val
}

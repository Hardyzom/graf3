#version 430

in vec3 myColor; // Bemeneti vektor, ami tartalmazza a fragment sz�n�t
in vec3 Normal; // Bemeneti norm�lvektor minden fragmenthez
in vec3 FragPos; // Bemeneti vektor, ami tartalmazza a fragment poz�ci�j�t a t�rben

uniform vec3 lightPos; // Uniform v�ltoz� a f�nyforr�s poz�ci�j�hoz

out vec4 color; // Kimeneti sz�n, amit a shader �ll�t el�

void main(void)
{
	// AMBIENT
    float ambientStrength = 0.9; // Az ambient vil�g�t�s er�ss�ge
    vec3 ambient = ambientStrength * vec3(1.0, 1.0, 1.0); // Ambient sz�n, egys�ges feh�r sz�nnel szorzva az er�ss�ggel
  	
    // DIFFUSE 
    vec3 norm = normalize(Normal); // Normaliz�ljuk a norm�lvektort
    vec3 lightDir = normalize(lightPos - FragPos); // Kisz�m�tjuk a f�ny ir�nyvektor�t a poz�ci�b�l
    float diff = max(dot(norm, lightDir), 0.0); // Kisz�m�tjuk a diff�z komponenst (a norm�l �s f�nyir�ny k�zti sz�g koszinusz�t)
    vec3 diffuse = diff * vec3(1.0, 1.0, 1.0); // Sz�m�tjuk a diff�z sz�nt
            
    vec3 result = (ambient + diffuse) * myColor; // �sszeadjuk az ambient �s diffuse vil�g�t�st, majd szorozzuk a fragment sz�n�vel
    color = vec4(result, 1.0); // Be�ll�tjuk a v�gs� sz�nt, teljes alfa �rt�kkel
}
#version 430

in vec3 myColor; // Bemeneti vektor, ami tartalmazza a fragment színét
in vec3 Normal; // Bemeneti normálvektor minden fragmenthez
in vec3 FragPos; // Bemeneti vektor, ami tartalmazza a fragment pozícióját a térben

uniform vec3 lightPos; // Uniform változó a fényforrás pozíciójához

out vec4 color; // Kimeneti szín, amit a shader állít elõ

void main(void)
{
	// AMBIENT
    float ambientStrength = 0.9; // Az ambient világítás erõssége
    vec3 ambient = ambientStrength * vec3(1.0, 1.0, 1.0); // Ambient szín, egységes fehér színnel szorzva az erõsséggel
  	
    // DIFFUSE 
    vec3 norm = normalize(Normal); // Normalizáljuk a normálvektort
    vec3 lightDir = normalize(lightPos - FragPos); // Kiszámítjuk a fény irányvektorát a pozícióból
    float diff = max(dot(norm, lightDir), 0.0); // Kiszámítjuk a diffúz komponenst (a normál és fényirány közti szög koszinuszát)
    vec3 diffuse = diff * vec3(1.0, 1.0, 1.0); // Számítjuk a diffúz színt
            
    vec3 result = (ambient + diffuse) * myColor; // Összeadjuk az ambient és diffuse világítást, majd szorozzuk a fragment színével
    color = vec4(result, 1.0); // Beállítjuk a végsõ színt, teljes alfa értékkel
}
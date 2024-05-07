#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <array>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <conio.h>

using namespace std;

static int WIN_WIDTH = 600;
static int WIN_HEIGHT = 600;

float vertices[] = {
		// positions          // color		     //normals
		-0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f, -1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f, -1.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f, -1.0f,
		-0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f, -1.0f,

		-0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f, 1.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  -1.0f, 0.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  -1.0f, 0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  -1.0f, 0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  -1.0f, 0.0f,  0.0f,
		-0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  -1.0f, 0.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  -1.0f, 0.0f,  0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  1.0f,  0.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  1.0f,  0.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  1.0f,  0.0f,  0.0f,

		-0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  0.0f, -1.0f,  0.0f,
		-0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  0.0f, -1.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f, -1.0f,  0.0f,
	
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  1.0f,  0.0f
	
};


GLuint VBO;
GLuint VAO;
GLuint VAO2;
GLuint VBO2;

GLuint renderingProgram; // OpenGL rendering program inicializálása

glm::mat4 model, view, projection; // Model, view és projection mátrixok inicializálása

GLboolean	keyboard[512] = { GL_FALSE }; // Billentyûzet állapotát tároló tömb inicializálása
GLdouble	currentTime, deltaTime, lastTime = 0.0f; // Aktuális idõ, idõeltelt és utolsó idõ inicializálása
GLfloat		cameraSpeed; // Kamera sebességének inicializálása
float x = 0.0f; // Kamera pozíciójának x koordinátája
float radius = 8.0f; // Kamera körpályájának sugara
float z = 0.0f; // Kamera pozíciójának z koordinátája
// Kamera pozíciójának inicializálása
glm::vec3	cameraPos = glm::vec3(radius, x, z), // A kamera pozíciójának inicializálása a radius, x és z változókkal
			cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f),  // A kamera céljának inicializálása az origóval
			up = glm::vec3(0.0f, 0.0f, 1.0f), // A felfelé vektor inicializálása
			currentCameraPos = glm::vec3(0.0f, 0.0f, 0.0f); // Az aktuális kamera pozíciójának inicializálása az origóval


// Shader forráskód olvasását végzõ függvény
string readShaderSource(const char* filePath) {
	string content; // Fájl elérési útját várja paraméterként
	ifstream fileStream(filePath, ios::in); // Fájl megnyitása olvasásra
	string line = "";

	while (!fileStream.eof()) { // Amíg nem értünk a fájl végére
		getline(fileStream, line); // Egy sor beolvasása a fájlból
		content.append(line + "\n"); // A beolvasott sort hozzáadjuk a tartalomhoz, sorvége karakterrel együtt
	}
	fileStream.close();
	return content; // Visszaadjuk a beolvasott forráskódot
}

GLuint createShaderProgram() { // Shader program létrehozása

	GLint vertCompiled;
	GLint fragCompiled;
	GLint linked; // Shader program linkelési állapotának tárolására szolgáló változó
	string vertShaderStr= readShaderSource("vertexShader.glsl");
	string fragShaderStr= readShaderSource("fragmentShader.glsl");
	
	

	GLuint vShader = glCreateShader(GL_VERTEX_SHADER); // Vertex shader létrehozása
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
	const char* vertShaderSrc = vertShaderStr.c_str(); // Vertex shader forráskódának karakter tömbbé alakítása
	const char* fragShaderSrc = fragShaderStr.c_str();


	glShaderSource(vShader, 1, &vertShaderSrc, NULL); // Vertex shader forráskód beállítása
	glShaderSource(fShader, 1, &fragShaderSrc, NULL);


	glCompileShader(vShader); // Vertex shader fordítása
	
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &vertCompiled); // Vertex shader fordítási állapotának lekérdezése
	


	GLuint vfProgram = glCreateProgram(); // Shader program létrehozása
	glAttachShader(vfProgram, vShader); // Vertex shader csatolása a shader programhoz
	glAttachShader(vfProgram, fShader);
	
	glLinkProgram(vfProgram); // Shader program linkelése
	
	glGetProgramiv(vfProgram, GL_LINK_STATUS, &linked); // Shader program linkelési állapotának lekérdezése
	
	
	glDeleteShader(vShader); // Vertex shader törlése
	glDeleteShader(fShader);

		return vfProgram; // Létrehozott shader program azonosítójának visszaadása
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) // Billentyûzet eseménykezelõ függvény definíciója
{
	float cameraSpeed = 2.5f * deltaTime; // Kamera sebességének kiszámítása

	if (key == GLFW_KEY_UP && action == GLFW_REPEAT) // Ha a felfelé nyíl lenyomva van és ismétlõdõ esemény történik
	{
		z += 0.7f; // Kamera pozíciójának z koordinátájának növelése
		cameraPos = glm::vec3(sin(x) * radius, cos(x) * radius, z); // Kamera pozíciójának frissítése
		if (z >= 10.0f) { // Ha a kamera a maximális magasságot érte el
			z = 10.0f; // Z koordináta korlátozása
		}
	}
	if (key == GLFW_KEY_DOWN && action == GLFW_REPEAT) // Ha a lefelé nyíl lenyomva van és ismétlõdõ esemény történik
	{
		z -= 0.7f; // Kamera pozíciójának z koordinátájának csökkentése
		cameraPos = glm::vec3(sin(x) * radius, cos(x) * radius, z); // Kamera pozíciójának frissítése
		if (z <= -10.0f) { // Ha a kamera a minimális magasságot érte el
			z = -10.0f; // Z koordináta korlátozása
		}
	}
	if (key == GLFW_KEY_LEFT && action == GLFW_REPEAT) // Ha a balra nyíl lenyomva van és ismétlõdõ esemény történik
	{
		x += 0.07f; // Kamera pozíciójának x koordinátájának növelése
		cameraPos = glm::vec3(sin(x) * radius, cos(x) * radius, z); // Kamera pozíciójának frissítése
	}
	if (key == GLFW_KEY_RIGHT && action == GLFW_REPEAT) // Ha a jobbra nyíl lenyomva van és ismétlõdõ esemény történik
	{
		x -= 0.07f; // Kamera pozíciójának x koordinátájának csökkentése
		cameraPos = glm::vec3(sin(x) * radius, cos(x) * radius, z); // Kamera pozíciójának frissítése
	}
}


void computeModelMatrices() // Modell mátrixok számítására szolgáló függvény definíciója
{
	model = glm::mat4(1.0f); // Alapértelmezett egységmátrix létrehozása
	model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(1.0f, 1.0f, 1.0f)); // Modell forgatása az idõ függvényében
	model = glm::translate(model, glm::vec3(0.0f, 2.0f, 0.0f)); // Modell eltolása az y tengelyen
}

void computeCameraMatrices()
{
	view = glm::lookAt(cameraPos, cameraTarget, up); // Beállítja a nézet mátrixot a kamera pozíciójától a cél irányába, a megadott "felfelé" vektorral
	projection = glm::perspective(glm::radians(55.0f), (float)WIN_WIDTH / (float)WIN_HEIGHT, 0.1f, 100.0f); // Perspektív vetítési mátrix létrehozása
}

void init(GLFWwindow* window) { // Inicializáló függvény definíciója

	renderingProgram = createShaderProgram(); // Shader program létrehozása

	glGenBuffers(1, &VBO); // Vertex Buffer Object létrehozása
	glGenVertexArrays(1, &VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO); // VBO csatolása, hogy az operációk ezen bufferen végezhetõek legyenek

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // Adatok átadása a GPU-nak statikus felhasználásra

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Buffer leválasztása

	glBindVertexArray(VAO); // VAO csatolása

	glBindBuffer(GL_ARRAY_BUFFER, VBO); // VBO újra csatolása

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0); // Attribútum-pontozó beállítása a pozícióhoz

	glEnableVertexAttribArray(0); // Az elõzõ attribútum-pontozó engedélyezése

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float))); // Attribútum-pontozó beállítása a színekhez
	glEnableVertexAttribArray(1); // Szín attribútum engedélyezése

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(6 * sizeof(float))); // Attribútum-pontozó beállítása a normális vektorhoz
	glEnableVertexAttribArray(2); // Normális vektor attribútum engedélyezése

	glBindVertexArray(0); // VAO leválasztása
	glBindBuffer(GL_ARRAY_BUFFER, 0); // VBO leválasztása
}



void display(GLFWwindow* window, double currentTime) {

	glClearColor(0.0, 0.0, 0.0, 1.0); // Beállítja a tisztító színt feketére
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Kitörli a szín és mélység puffer tartalmát

	glEnable(GL_DEPTH_TEST); // Engedélyezi a mélységtesztet, hogy az elülsõ objektumok eltakarják a hátsókat

	glUseProgram(renderingProgram); // Aktiválja a shader programot a következõ rajzolásokhoz
	
	model = glm::mat4(1.0f); // Modell mátrix inicializálása egységmátrixként
	computeCameraMatrices(); // Kamera mátrixok kiszámítása
	unsigned int modelLoc = glGetUniformLocation(renderingProgram, "model"); // A model mátrix uniform változójának helyét kérjük le a shader programból
	unsigned int viewLoc = glGetUniformLocation(renderingProgram, "view");
	unsigned int projectionLoc = glGetUniformLocation(renderingProgram, "projection");

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); // Modell mátrix átadása a shader programnak
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view)); // Nézet mátrix átadása a shader programnak
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection)); // Vetítés mátrix átadása a shader programnak
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices)); // Rajzolja a háromszögeket a megadott vertex array alapján
	glBindVertexArray(0);
	

	glm::mat4 model = glm::mat4(1.0f); // Modell mátrix resetelése
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 2.0f)); // Modell eltolása a z tengelyen
	modelLoc = glGetUniformLocation(renderingProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); // Modell mátrix átadása ismét
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices)); // Rajzolja a háromszögeket újra
	glBindVertexArray(0);

	model = glm::mat4(1.0f); // Modell mátrix resetelése
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.0f)); // Modell eltolása negatív z irányba
	modelLoc = glGetUniformLocation(renderingProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); // Modell mátrix átadása ismét

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices)); // Rajzolja a háromszögeket ismét
	glBindVertexArray(0);

	
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height); // Beállítja a nézeti területet az ablak méretének megfelelõen
}

int main(void) {
	if (!glfwInit()) { exit(EXIT_FAILURE); } // Inicializálja a GLFW-t, és kilép, ha nem sikerült

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // Beállítja az OpenGL kontextus fõ verzióját 4-re
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // Beállítja az OpenGL kontextus alverzióját 3-ra

	GLFWwindow* window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "3. beadando - Pasch Alex Karoly", NULL, NULL);

	glfwMakeContextCurrent(window); // Beállítja az aktuális kontextust az újonnan létrehozott ablakhoz
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // Beállítja a framebuffer méretváltozás kezelõt

	glfwSetKeyCallback(window, keyCallback); // Beállítja a billentyûzet események kezelõjét
	

	if (glewInit() != GLEW_OK) { exit(EXIT_FAILURE); } // Inicializálja a GLEW-t, és kilép, ha nem sikerült
	glfwSwapInterval(1); // Engedélyezi a vsync-et


	init(window); // Inicializálja a grafikai erõforrásokat

	while (!glfwWindowShouldClose(window)) { // Folyamatos ciklus amíg az ablakot be nem zárják

		float currentTime = glfwGetTime(); // Lekéri az aktuális idõt
		deltaTime = currentTime - lastTime; // Kiszámítja az eltelt idõt az utolsó frissítés óta
		lastTime = currentTime; // Frissíti az utolsó idõpontot
		display(window, glfwGetTime()); // Meghívja a megjelenítési rutint
		glfwSwapBuffers(window); // Cserebuffer: megjeleníti a kirenderelt képet
		glfwPollEvents(); // Feldolgozza a várakozó eseményeket
	}

	glfwDestroyWindow(window); // Megszünteti az ablakot

	glfwTerminate(); // Leállítja a GLFW-t
	exit(EXIT_SUCCESS); // Kilép a programból sikeres lefutás után
}
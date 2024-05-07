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

GLuint renderingProgram; // OpenGL rendering program inicializ�l�sa

glm::mat4 model, view, projection; // Model, view �s projection m�trixok inicializ�l�sa

GLboolean	keyboard[512] = { GL_FALSE }; // Billenty�zet �llapot�t t�rol� t�mb inicializ�l�sa
GLdouble	currentTime, deltaTime, lastTime = 0.0f; // Aktu�lis id�, id�eltelt �s utols� id� inicializ�l�sa
GLfloat		cameraSpeed; // Kamera sebess�g�nek inicializ�l�sa
float x = 0.0f; // Kamera poz�ci�j�nak x koordin�t�ja
float radius = 8.0f; // Kamera k�rp�ly�j�nak sugara
float z = 0.0f; // Kamera poz�ci�j�nak z koordin�t�ja
// Kamera poz�ci�j�nak inicializ�l�sa
glm::vec3	cameraPos = glm::vec3(radius, x, z), // A kamera poz�ci�j�nak inicializ�l�sa a radius, x �s z v�ltoz�kkal
			cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f),  // A kamera c�lj�nak inicializ�l�sa az orig�val
			up = glm::vec3(0.0f, 0.0f, 1.0f), // A felfel� vektor inicializ�l�sa
			currentCameraPos = glm::vec3(0.0f, 0.0f, 0.0f); // Az aktu�lis kamera poz�ci�j�nak inicializ�l�sa az orig�val


// Shader forr�sk�d olvas�s�t v�gz� f�ggv�ny
string readShaderSource(const char* filePath) {
	string content; // F�jl el�r�si �tj�t v�rja param�terk�nt
	ifstream fileStream(filePath, ios::in); // F�jl megnyit�sa olvas�sra
	string line = "";

	while (!fileStream.eof()) { // Am�g nem �rt�nk a f�jl v�g�re
		getline(fileStream, line); // Egy sor beolvas�sa a f�jlb�l
		content.append(line + "\n"); // A beolvasott sort hozz�adjuk a tartalomhoz, sorv�ge karakterrel egy�tt
	}
	fileStream.close();
	return content; // Visszaadjuk a beolvasott forr�sk�dot
}

GLuint createShaderProgram() { // Shader program l�trehoz�sa

	GLint vertCompiled;
	GLint fragCompiled;
	GLint linked; // Shader program linkel�si �llapot�nak t�rol�s�ra szolg�l� v�ltoz�
	string vertShaderStr= readShaderSource("vertexShader.glsl");
	string fragShaderStr= readShaderSource("fragmentShader.glsl");
	
	

	GLuint vShader = glCreateShader(GL_VERTEX_SHADER); // Vertex shader l�trehoz�sa
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
	const char* vertShaderSrc = vertShaderStr.c_str(); // Vertex shader forr�sk�d�nak karakter t�mbb� alak�t�sa
	const char* fragShaderSrc = fragShaderStr.c_str();


	glShaderSource(vShader, 1, &vertShaderSrc, NULL); // Vertex shader forr�sk�d be�ll�t�sa
	glShaderSource(fShader, 1, &fragShaderSrc, NULL);


	glCompileShader(vShader); // Vertex shader ford�t�sa
	
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &vertCompiled); // Vertex shader ford�t�si �llapot�nak lek�rdez�se
	


	GLuint vfProgram = glCreateProgram(); // Shader program l�trehoz�sa
	glAttachShader(vfProgram, vShader); // Vertex shader csatol�sa a shader programhoz
	glAttachShader(vfProgram, fShader);
	
	glLinkProgram(vfProgram); // Shader program linkel�se
	
	glGetProgramiv(vfProgram, GL_LINK_STATUS, &linked); // Shader program linkel�si �llapot�nak lek�rdez�se
	
	
	glDeleteShader(vShader); // Vertex shader t�rl�se
	glDeleteShader(fShader);

		return vfProgram; // L�trehozott shader program azonos�t�j�nak visszaad�sa
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) // Billenty�zet esem�nykezel� f�ggv�ny defin�ci�ja
{
	float cameraSpeed = 2.5f * deltaTime; // Kamera sebess�g�nek kisz�m�t�sa

	if (key == GLFW_KEY_UP && action == GLFW_REPEAT) // Ha a felfel� ny�l lenyomva van �s ism�tl�d� esem�ny t�rt�nik
	{
		z += 0.7f; // Kamera poz�ci�j�nak z koordin�t�j�nak n�vel�se
		cameraPos = glm::vec3(sin(x) * radius, cos(x) * radius, z); // Kamera poz�ci�j�nak friss�t�se
		if (z >= 10.0f) { // Ha a kamera a maxim�lis magass�got �rte el
			z = 10.0f; // Z koordin�ta korl�toz�sa
		}
	}
	if (key == GLFW_KEY_DOWN && action == GLFW_REPEAT) // Ha a lefel� ny�l lenyomva van �s ism�tl�d� esem�ny t�rt�nik
	{
		z -= 0.7f; // Kamera poz�ci�j�nak z koordin�t�j�nak cs�kkent�se
		cameraPos = glm::vec3(sin(x) * radius, cos(x) * radius, z); // Kamera poz�ci�j�nak friss�t�se
		if (z <= -10.0f) { // Ha a kamera a minim�lis magass�got �rte el
			z = -10.0f; // Z koordin�ta korl�toz�sa
		}
	}
	if (key == GLFW_KEY_LEFT && action == GLFW_REPEAT) // Ha a balra ny�l lenyomva van �s ism�tl�d� esem�ny t�rt�nik
	{
		x += 0.07f; // Kamera poz�ci�j�nak x koordin�t�j�nak n�vel�se
		cameraPos = glm::vec3(sin(x) * radius, cos(x) * radius, z); // Kamera poz�ci�j�nak friss�t�se
	}
	if (key == GLFW_KEY_RIGHT && action == GLFW_REPEAT) // Ha a jobbra ny�l lenyomva van �s ism�tl�d� esem�ny t�rt�nik
	{
		x -= 0.07f; // Kamera poz�ci�j�nak x koordin�t�j�nak cs�kkent�se
		cameraPos = glm::vec3(sin(x) * radius, cos(x) * radius, z); // Kamera poz�ci�j�nak friss�t�se
	}
}


void computeModelMatrices() // Modell m�trixok sz�m�t�s�ra szolg�l� f�ggv�ny defin�ci�ja
{
	model = glm::mat4(1.0f); // Alap�rtelmezett egys�gm�trix l�trehoz�sa
	model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(1.0f, 1.0f, 1.0f)); // Modell forgat�sa az id� f�ggv�ny�ben
	model = glm::translate(model, glm::vec3(0.0f, 2.0f, 0.0f)); // Modell eltol�sa az y tengelyen
}

void computeCameraMatrices()
{
	view = glm::lookAt(cameraPos, cameraTarget, up); // Be�ll�tja a n�zet m�trixot a kamera poz�ci�j�t�l a c�l ir�ny�ba, a megadott "felfel�" vektorral
	projection = glm::perspective(glm::radians(55.0f), (float)WIN_WIDTH / (float)WIN_HEIGHT, 0.1f, 100.0f); // Perspekt�v vet�t�si m�trix l�trehoz�sa
}

void init(GLFWwindow* window) { // Inicializ�l� f�ggv�ny defin�ci�ja

	renderingProgram = createShaderProgram(); // Shader program l�trehoz�sa

	glGenBuffers(1, &VBO); // Vertex Buffer Object l�trehoz�sa
	glGenVertexArrays(1, &VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO); // VBO csatol�sa, hogy az oper�ci�k ezen bufferen v�gezhet�ek legyenek

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // Adatok �tad�sa a GPU-nak statikus felhaszn�l�sra

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Buffer lev�laszt�sa

	glBindVertexArray(VAO); // VAO csatol�sa

	glBindBuffer(GL_ARRAY_BUFFER, VBO); // VBO �jra csatol�sa

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0); // Attrib�tum-pontoz� be�ll�t�sa a poz�ci�hoz

	glEnableVertexAttribArray(0); // Az el�z� attrib�tum-pontoz� enged�lyez�se

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float))); // Attrib�tum-pontoz� be�ll�t�sa a sz�nekhez
	glEnableVertexAttribArray(1); // Sz�n attrib�tum enged�lyez�se

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(6 * sizeof(float))); // Attrib�tum-pontoz� be�ll�t�sa a norm�lis vektorhoz
	glEnableVertexAttribArray(2); // Norm�lis vektor attrib�tum enged�lyez�se

	glBindVertexArray(0); // VAO lev�laszt�sa
	glBindBuffer(GL_ARRAY_BUFFER, 0); // VBO lev�laszt�sa
}



void display(GLFWwindow* window, double currentTime) {

	glClearColor(0.0, 0.0, 0.0, 1.0); // Be�ll�tja a tiszt�t� sz�nt feket�re
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Kit�rli a sz�n �s m�lys�g puffer tartalm�t

	glEnable(GL_DEPTH_TEST); // Enged�lyezi a m�lys�gtesztet, hogy az el�ls� objektumok eltakarj�k a h�ts�kat

	glUseProgram(renderingProgram); // Aktiv�lja a shader programot a k�vetkez� rajzol�sokhoz
	
	model = glm::mat4(1.0f); // Modell m�trix inicializ�l�sa egys�gm�trixk�nt
	computeCameraMatrices(); // Kamera m�trixok kisz�m�t�sa
	unsigned int modelLoc = glGetUniformLocation(renderingProgram, "model"); // A model m�trix uniform v�ltoz�j�nak hely�t k�rj�k le a shader programb�l
	unsigned int viewLoc = glGetUniformLocation(renderingProgram, "view");
	unsigned int projectionLoc = glGetUniformLocation(renderingProgram, "projection");

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); // Modell m�trix �tad�sa a shader programnak
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view)); // N�zet m�trix �tad�sa a shader programnak
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection)); // Vet�t�s m�trix �tad�sa a shader programnak
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices)); // Rajzolja a h�romsz�geket a megadott vertex array alapj�n
	glBindVertexArray(0);
	

	glm::mat4 model = glm::mat4(1.0f); // Modell m�trix resetel�se
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 2.0f)); // Modell eltol�sa a z tengelyen
	modelLoc = glGetUniformLocation(renderingProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); // Modell m�trix �tad�sa ism�t
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices)); // Rajzolja a h�romsz�geket �jra
	glBindVertexArray(0);

	model = glm::mat4(1.0f); // Modell m�trix resetel�se
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.0f)); // Modell eltol�sa negat�v z ir�nyba
	modelLoc = glGetUniformLocation(renderingProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); // Modell m�trix �tad�sa ism�t

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices)); // Rajzolja a h�romsz�geket ism�t
	glBindVertexArray(0);

	
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height); // Be�ll�tja a n�zeti ter�letet az ablak m�ret�nek megfelel�en
}

int main(void) {
	if (!glfwInit()) { exit(EXIT_FAILURE); } // Inicializ�lja a GLFW-t, �s kil�p, ha nem siker�lt

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // Be�ll�tja az OpenGL kontextus f� verzi�j�t 4-re
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // Be�ll�tja az OpenGL kontextus alverzi�j�t 3-ra

	GLFWwindow* window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "3. beadando - Pasch Alex Karoly", NULL, NULL);

	glfwMakeContextCurrent(window); // Be�ll�tja az aktu�lis kontextust az �jonnan l�trehozott ablakhoz
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // Be�ll�tja a framebuffer m�retv�ltoz�s kezel�t

	glfwSetKeyCallback(window, keyCallback); // Be�ll�tja a billenty�zet esem�nyek kezel�j�t
	

	if (glewInit() != GLEW_OK) { exit(EXIT_FAILURE); } // Inicializ�lja a GLEW-t, �s kil�p, ha nem siker�lt
	glfwSwapInterval(1); // Enged�lyezi a vsync-et


	init(window); // Inicializ�lja a grafikai er�forr�sokat

	while (!glfwWindowShouldClose(window)) { // Folyamatos ciklus am�g az ablakot be nem z�rj�k

		float currentTime = glfwGetTime(); // Lek�ri az aktu�lis id�t
		deltaTime = currentTime - lastTime; // Kisz�m�tja az eltelt id�t az utols� friss�t�s �ta
		lastTime = currentTime; // Friss�ti az utols� id�pontot
		display(window, glfwGetTime()); // Megh�vja a megjelen�t�si rutint
		glfwSwapBuffers(window); // Cserebuffer: megjelen�ti a kirenderelt k�pet
		glfwPollEvents(); // Feldolgozza a v�rakoz� esem�nyeket
	}

	glfwDestroyWindow(window); // Megsz�nteti az ablakot

	glfwTerminate(); // Le�ll�tja a GLFW-t
	exit(EXIT_SUCCESS); // Kil�p a programb�l sikeres lefut�s ut�n
}
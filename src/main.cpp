#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>
#include <random>

constexpr int SCREEN_WIDTH = 1920;
constexpr int SCREEN_HEIGHT = 1080;

float Random(float min, float max)
{
    float random = ((float)rand()) / (float)RAND_MAX;
    float diff = max - min;
    float r = random * diff;
    return min + r;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Graphics 1", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Load opengl extension 4.6 (Windows ships with GL 1.0)*/
    gladLoadGL();

	glfwSetKeyCallback(window, key_callback);

    /* Loop until the user closes the window (our game loop, like update function in Unity) */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.22f, 0.49f, 0.17f, 1.0f);

		//Randomly move the mouse cursor
		float x = Random(0.0f, SCREEN_WIDTH);
		float y = Random(0.0f, SCREEN_HEIGHT);
		glfwSetCursorPos(window, x, y);

        /* Swap front and back buffers (this avoid screen tear)*/
        glfwSwapBuffers(window);

        /* Poll for and process events (check if any buttons has been clicked)*/
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_E && action == GLFW_PRESS)
    { //activate_airship();
    }

    if(key == GLFW_KEY_ESCAPE)
    {
        glfwSetWindowShouldClose(window, true);
	}

	const char* name = glfwGetKeyName(key, scancode);
	printf("Key pressed: %s\n", name);

}
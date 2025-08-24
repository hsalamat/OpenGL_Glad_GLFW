#include <glad/glad.h>
#include <GLFW/glfw3.h>

constexpr int SCREEN_WIDTH = 1920;
constexpr int SCREEN_HEIGHT = 1080;


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

    /* Loop until the user closes the window (our game loop, like update function in Unity) */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.22f, 0.49f, 0.17f, 1.0f);

        /* Swap front and back buffers (this avoid screen tear)*/
        glfwSwapBuffers(window);

        /* Poll for and process events (check if any buttons has been clicked)*/
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
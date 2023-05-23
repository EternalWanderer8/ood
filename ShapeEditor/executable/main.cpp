#include "backends/imgui_impl_glfw.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cstdio>

static void glfwErrorPrint(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int main()
{
    glfwSetErrorCallback(glfwErrorPrint);

    if (!glfwInit())
    {
        return 1;
    }

    // Create window with graphics context
    GLFWwindow* window = glfwCreateWindow(1280, 720, "ShapesEditor", nullptr, nullptr);

    if (!window)
    {
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGL();
    glfwSwapInterval(1); // Enable vsync

    // Background color
    ImVec4 clearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clearColor.x * clearColor.w, clearColor.y * clearColor.w, clearColor.z * clearColor.w, clearColor.w);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}
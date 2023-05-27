#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cstdio>

#include "src/EditorView/EditorView.h"

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

    const char* glslVersion = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

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

    // Create Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void) io;

    // Set Dear ImGui color theme
    ImGui::StyleColorsDark();

    // Set Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glslVersion);

    // Background color
    ImVec4 clearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    client::EditorView editorView;

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        editorView.Refresh();

        ImGui::Render();

        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clearColor.x * clearColor.w, clearColor.y * clearColor.w, clearColor.z * clearColor.w, clearColor.w);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}
#include "EditorView.h"
#include "imgui.h"

void client::EditorView::Refresh()
{
    DrawEditor();
}

void client::EditorView::DrawEditor()
{
    ImGui::Begin("Canvas", nullptr, ImGuiWindowFlags_MenuBar);

    InitMenu();
    DrawCanvas();

    ImGui::End();
}

void client::EditorView::InitMenu()
{
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("Create shape"))
        {
            if (ImGui::MenuItem("Triangle", "Ctrl + N + T"))
            {

            }
            if (ImGui::MenuItem("Rectangle", "Ctrl + N + R"))
            {

            }
            if (ImGui::MenuItem("Ellipse", "Ctrl + N + E"))
            {

            }

            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }
}

void client::EditorView::DrawCanvas()
{
    ImVec2 origin = ImGui::GetCursorScreenPos(); // ImDrawList API uses screen coordinates
    m_canvas.SetOrigin(origin);

    ImDrawList* drawList = ImGui::GetWindowDrawList();
    m_canvas.SetDrawList(drawList);

    ImVec2 canvasSize = m_canvas.GetSize();
    canvasSize.x = canvasSize.x < 50.0f ? 50.0f : canvasSize.x;
    canvasSize.y = canvasSize.y < 50.0f ? 50.0f : canvasSize.y;

    ImVec2 canvasRightBottomPoint = ImVec2(
            origin.x + canvasSize.x,
            origin.y + canvasSize.y
    );

    drawList->AddRectFilled(origin, canvasRightBottomPoint, Canvas::DEFAULT_CLEAR_COLOR);
}
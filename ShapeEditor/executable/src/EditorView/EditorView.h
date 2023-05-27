#pragma once
#include "imgui.h"
#include "../Canvas/Canvas.h"

namespace client
{

class EditorView
{
public:
    void Refresh();

private:
    void DrawEditor();
    void DrawCanvas();
    void InitMenu();

    Canvas m_canvas;
};

}
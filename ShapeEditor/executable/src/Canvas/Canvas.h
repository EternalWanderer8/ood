#pragma once
#include "imgui.h"
#include <functional>
#include <vector>

namespace client
{

class Canvas
{
public:
    ImVec2 GetSize() const;

    void SetDrawList(ImDrawList* drawList);
    void SetOrigin(ImVec2 origin);
    void ResetSize(ImVec2 size);

    inline static float DEFAULT_WIDTH = 1200.0f;
    inline static float DEFAULT_HEIGHT = 600.0f;
    inline static ImU32 DEFAULT_CLEAR_COLOR = IM_COL32(220, 220, 220, 255);

private:
    ImVec2 m_size = { DEFAULT_WIDTH, DEFAULT_HEIGHT };
    std::vector<std::function<void()>> m_drawCommands;
    ImDrawList* m_drawList = nullptr;
    ImVec2 m_origin;
};

}

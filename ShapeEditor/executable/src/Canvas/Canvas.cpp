#include "Canvas.h"

ImVec2 client::Canvas::GetSize() const
{
    return m_size;
}

void client::Canvas::SetDrawList(ImDrawList* drawList)
{
    m_drawList = drawList;
}

void client::Canvas::SetOrigin(ImVec2 origin)
{
    m_origin = origin;
}

void client::Canvas::ResetSize(ImVec2 size)
{
    m_size = size;
}

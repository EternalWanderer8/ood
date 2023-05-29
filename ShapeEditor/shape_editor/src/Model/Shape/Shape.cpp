#include "Shape.h"

model::Shape::Shape(model::ShapeType type, int zIndex)
    : m_type(type)
    , m_id(++lastId)
    , m_zIndex(zIndex)
{
}

model::ShapeId model::Shape::GetId() const
{
    return m_id;
}

model::ShapeType model::Shape::GetType() const
{
    return m_type;
}

Point model::Shape::GetTopLeftPoint() const
{
    return m_topLeftPoint;
}

Point model::Shape::GetBottomRightPoint() const
{
    return m_bottomRightPoint;
}

void model::Shape::Resize(const Point& topLeftPoint, const Point& bottomRightPoint)
{
    m_topLeftPoint = topLeftPoint;
    m_bottomRightPoint = bottomRightPoint;
}

Color model::Shape::GetFillColor() const
{
    return m_fillColor;
}

void model::Shape::SetFillColor(const Color& color)
{
    m_fillColor = color;
}

Color model::Shape::GetBorderColor() const
{
    return m_borderColor;
}

void model::Shape::SetBorderColor(const Color& color)
{
    m_borderColor = color;
}

int model::Shape::GetZIndex() const
{
    return m_zIndex;
}

void model::Shape::SetZIndex(int zIndex)
{
    m_zIndex = zIndex;
}
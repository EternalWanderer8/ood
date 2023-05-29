#pragma once
#include "IShape.h"

namespace model
{

class Shape : public IShape
{
public:
    Shape(ShapeType type, int zIndex);

    ShapeId GetId() const override;

    ShapeType GetType() const override;

    Point GetTopLeftPoint() const override;
    Point GetBottomRightPoint() const override;

    Color GetFillColor() const override;
    void SetFillColor(const Color& color) override;

    Color GetBorderColor() const override;
    void SetBorderColor(const Color& color) override;

    int GetZIndex() const override;
    void SetZIndex(int zIndex) override;

    void Resize(const Point& topLeft, const Point& bottomRight) override;

private:
    static inline const Color DEFAULT_BORDER_COLOR = { 0, 220, 70, 255 };
    static inline const Color DEFAULT_FILL_COLOR = {0, 30, 200, 255 };
    static inline const Point DEFAULT_BOTTOM_RIGHT_POINT = { 70, 70 };
    static inline const Point DEFAULT_TOP_LEFT_POINT = { 0, 0 };

    ShapeId m_id;
    int m_zIndex;
    ShapeType m_type;
    Color m_fillColor = DEFAULT_FILL_COLOR;
    Color m_borderColor = DEFAULT_BORDER_COLOR;
    Point m_topLeftPoint = DEFAULT_TOP_LEFT_POINT;
    Point m_bottomRightPoint = DEFAULT_BOTTOM_RIGHT_POINT;

    inline static ShapeId lastId = 0;
};

}
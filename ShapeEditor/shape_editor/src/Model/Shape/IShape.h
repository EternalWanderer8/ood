#pragma once
#include "../../../include/Common/Point.h"
#include "../../../include/Common/Color.h"
#include "ShapeType.h"
#include <memory>

namespace model
{

using ShapeId = size_t;

struct IShape
{
    virtual ~IShape() = default;

    virtual ShapeId GetId() const = 0;

    virtual ShapeType GetType() const = 0;

    virtual Point GetTopLeftPoint() const = 0;
    virtual Point GetBottomRightPoint() const = 0;

    virtual Color GetFillColor() const = 0;
    virtual void SetFillColor(const Color& color) = 0;

    virtual Color GetBorderColor() const = 0;
    virtual void SetBorderColor(const Color& color) = 0;

    virtual int GetZIndex() const = 0;
    virtual void SetZIndex(int zIndex) = 0;

    virtual void Resize(const Point& topLeft, const Point& bottomRight) = 0;
};

using ShapePtr = std::shared_ptr<IShape>;
using ShapeConstPtr = std::shared_ptr<const IShape>;

}
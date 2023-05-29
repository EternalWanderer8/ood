#pragma once
#include "../Shape/IShape.h"
#include <vector>

namespace model
{

struct IEditorDataObserver
{
    virtual ~IEditorDataObserver() = default;

    virtual void OnChange(const std::vector<ShapeConstPtr>& shapes) = 0;
};

}
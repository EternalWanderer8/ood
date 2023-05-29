#pragma once
#include "../../../src/Model/EditorData/IEditorDataObserver.h"
#include "../../../src/Model/Shape/IShape.h"
#include <unordered_map>
#include <optional>
#include <set>

namespace model
{

class EditorData
{
public:
    ShapeId AddShape(ShapeType type);
    void RemoveSelectedShape();
    ShapePtr GetShapeById(ShapeId id);
    ShapePtr GetSelectedShape();
    void SelectShapeAtPos(const Point& point);
    ShapePtr FindShapeByPos(const Point& point) const;

    int GetHighestShapeZIndex() const;

    void RegisterObserver(IEditorDataObserver* observer);
    void NotifyObservers() const;

private:
    std::optional<ShapeId> m_selectedShapeId;
    std::set<IEditorDataObserver*> m_subscribers;
    std::unordered_map<ShapeId, ShapePtr> m_shapes;
};

}
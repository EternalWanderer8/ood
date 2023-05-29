#include "../../../include/Model/EditorData/EditorData.h"
#include "../Shape/Shape.h"
#include <algorithm>

model::ShapeId model::EditorData::AddShape(model::ShapeType type)
{
    std::shared_ptr<IShape> shape = std::make_shared<Shape>(type, GetHighestShapeZIndex() + 1);

    m_shapes.insert({shape->GetId(), shape});

    m_selectedShapeId = shape->GetId();

    NotifyObservers();

    return shape->GetId();
}

void model::EditorData::RemoveSelectedShape()
{
    if (m_selectedShapeId.has_value())
    {
        m_shapes.erase(m_selectedShapeId.value());
        m_selectedShapeId.reset();

        NotifyObservers();
    }
}

std::shared_ptr<model::IShape> model::EditorData::GetShapeById(model::ShapeId id)
{
    if (m_shapes.find(id) != m_shapes.end())
    {
        return m_shapes[id];
    }

    throw std::out_of_range("Shape with id '" + std::to_string(id) + "' doesn't exist.");
}

model::ShapePtr model::EditorData::GetSelectedShape()
{
    if (m_selectedShapeId)
    {
        return m_shapes[m_selectedShapeId.value()];
    }

    return nullptr;
}

void model::EditorData::SelectShapeAtPos(const Point& point)
{
    ShapePtr shape = FindShapeByPos(point);

    if (shape)
    {
        m_selectedShapeId = shape->GetId();
        return;
    }

    m_selectedShapeId.reset();
}

model::ShapePtr model::EditorData::FindShapeByPos(const Point& point) const
{
    ShapePtr selectedShape;
    int maxZIndex = -INT_MIN;

    for (const auto& [id, shape] : m_shapes)
    {
        if (shape->GetTopLeftPoint().x <= point.x && point.x <= shape->GetBottomRightPoint().x
            && shape->GetTopLeftPoint().y <= point.y && point.y <= shape->GetBottomRightPoint().y
            && shape->GetZIndex() > maxZIndex)
        {
            selectedShape = shape;
            maxZIndex = shape->GetZIndex();
        }
    }

    return selectedShape;
}

int model::EditorData::GetHighestShapeZIndex() const
{
    int maxZIndex = -INT_MAX;

    for (auto& [id, shape] : m_shapes)
    {
        if (shape->GetZIndex() > maxZIndex)
        {
            maxZIndex = shape->GetZIndex();
        }
    }

    return maxZIndex;
}

void model::EditorData::RegisterObserver(model::IEditorDataObserver* observer)
{
    m_subscribers.insert(observer);
}

void model::EditorData::NotifyObservers() const
{
    std::vector<ShapeConstPtr> shapes;
    for (const auto& [id, shape] : m_shapes)
    {
        shapes.push_back(shape);
    }

    for (IEditorDataObserver* observer : m_subscribers)
    {
        observer->OnChange(shapes);
    }
}
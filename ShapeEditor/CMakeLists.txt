cmake_minimum_required(VERSION 3.23 FATAL_ERROR)
project(ShapeEditor)

set(CMAKE_CXX_STANDARD 20)

add_executable(ShapeEditor
    executable/main.cpp
    executable/src/EditorView/EditorView.h
    executable/src/EditorView/EditorView.cpp
    executable/src/Canvas/Canvas.h
    executable/src/Canvas/Canvas.cpp
    shape_editor/include/Model/EditorData/EditorData.h
    shape_editor/src/Model/Shape/IShape.h
    shape_editor/include/Common/Point.h
    shape_editor/include/Common/Color.h
    shape_editor/src/Model/Shape/ShapeType.h
    shape_editor/src/Model/EditorData/IEditorDataObserver.h
    shape_editor/src/Model/Shape/Shape.h
    shape_editor/src/Model/Shape/Shape.cpp
    shape_editor/src/Model/EditorData/EditorData.cpp)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw-3.3.8)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)

set(IMGUI_PATH ${CMAKE_CURRENT_LIST_DIR}/external/imgui)
file(GLOB IMGUI_GLOB
    ${IMGUI_PATH}/imgui.h
    ${IMGUI_PATH}/imgui.cpp
    ${IMGUI_PATH}/imconfig.h
    ${IMGUI_PATH}/imgui_demo.cpp
    ${IMGUI_PATH}/imgui_draw.cpp
    ${IMGUI_PATH}/imgui_internal.h
    ${IMGUI_PATH}/imstb_rectpack.h
    ${IMGUI_PATH}/imstb_textedit.h
    ${IMGUI_PATH}/imstb_truetype.h
    ${IMGUI_PATH}/imgui_tables.cpp
    ${IMGUI_PATH}/imgui_widgets.cpp

    ${IMGUI_PATH}/backends/imgui_impl_glfw.h
    ${IMGUI_PATH}/backends/imgui_impl_glfw.cpp
    ${IMGUI_PATH}/backends/imgui_impl_opengl3.h
    ${IMGUI_PATH}/backends/imgui_impl_opengl3.cpp
    ${IMGUI_PATH}/backends/imgui_impl_opengl3_loader.cpp
)

add_library("imgui" STATIC ${IMGUI_GLOB})

target_include_directories("imgui" PUBLIC ${IMGUI_PATH})
target_link_libraries("imgui" PRIVATE glfw)

target_link_libraries(${PROJECT_NAME} PUBLIC imgui)
target_include_directories(${PROJECT_NAME} PUBLIC imgui)
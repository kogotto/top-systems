#pragma once

#include <memory>

struct SDL_Renderer;

enum class FigureType {
    Square,
    Circle,

    count
};

constexpr inline int toInt(FigureType type) {
    return static_cast<int>(type);
}

constexpr inline FigureType toFigureType(int n) {
    return static_cast<FigureType>(n);
}

constexpr int figureTypesCount() {
    return toInt(FigureType::count);
}

class Figure {
public:
    virtual ~Figure() = 0;
    virtual void draw(SDL_Renderer* renderer) const = 0;
private:
};

using UFigure = std::unique_ptr<Figure>;

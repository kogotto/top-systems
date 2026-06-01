#pragma once

#include <memory>

struct SDL_Renderer;

class Figure {
public:
    virtual ~Figure() = 0;
    virtual void draw(SDL_Renderer* renderer) const = 0;
private:
};

using UFigure = std::unique_ptr<Figure>;

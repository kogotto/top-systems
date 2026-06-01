#pragma once

#include "SDL3/SDL_rect.h"
#include <vector>

#include <SDL3/SDL.h>

#include <Figure.hpp>

class Circle : public Figure {
public:
    Circle(int x, int y, float radius);
    ~Circle() override = default;

    void draw(SDL_Renderer* renderer) const override;
private:
    std::vector<SDL_FPoint> vertices_;
};

using UCircle = std::unique_ptr<Circle>;

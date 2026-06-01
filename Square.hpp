#pragma once

#include <SDL3/SDL.h>

#include <Figure.hpp>

class Square : public Figure {
public:
    Square(int x, int y, int size);
    ~Square() override = default;

    void draw(SDL_Renderer* renderer) const override;
private:
    SDL_FRect rect_;
};

using USquare = std::unique_ptr<Square>;

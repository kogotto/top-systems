#pragma once

#include <Figure.hpp>

class Square : public Figure {
public:
    ~Square() override;
    void draw(SDL_Renderer* renderer) const override;
private:
};

#include <Square.hpp>

Square::Square(int x, int y, int size) {
    rect_.x = x;
    rect_.y = y;
    rect_.w = rect_.h = size;
}

void Square::draw(SDL_Renderer* renderer) const {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderRect(renderer, &rect_);
}

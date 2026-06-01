#include <Square.hpp>

#include <SDL3/SDL.h>

Square::~Square() {
}

void Square::draw(SDL_Renderer* renderer) const {
    SDL_FRect rect;
    rect.x = 100;
    rect.y = 100;
    rect.h = rect.w = 300;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderRect(renderer, &rect);
    // SDL_RenderFillRect(renderer, &rect);
}

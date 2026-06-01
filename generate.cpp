#include <generate.hpp>

#include <cassert>

#include <SDL3/SDL.h>

#include <defs.hpp>
#include <Square.hpp>

namespace {

FigureType randomFigureType() {
    const auto randomTypeInt = SDL_rand(figureTypesCount());
    return toFigureType(randomTypeInt);
}

USquare generateRandomSquare() {
    const int x = SDL_rand(SCREEN_WIDTH / 2);
    const int y = SDL_rand(SCREEN_HEIGHT / 2);
    const int size = SDL_rand(std::min(SCREEN_WIDTH - x, SCREEN_HEIGHT - y));
    return std::make_unique<Square>(x, y, size);
}

UFigure generateFigure() {
    switch (const auto figureType = randomFigureType()) {
    case FigureType::Square:
        return generateRandomSquare();
    default:
        assert(false && "Unknown figure type");
    }
}

} // namespace

void generate(FiguresCollection& figures, int count) {
    for (int i = 0; i < count; ++i) {
        figures.pushBack(generateFigure());
    }
}

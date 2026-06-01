#include <Circle.hpp>

#include <cmath>
#include <numbers>

Circle::Circle(int x, int y, float radius) {
    constexpr int verticesCount = 16;
    const double step = 2 * std::numbers::pi / verticesCount;
    vertices_.reserve(verticesCount + 1);

    for (int i = 0; i <= verticesCount; ++i) {
        double xc = x + radius * std::cos(i * step);
        double yc = y + radius * std::sin(i * step);
        vertices_.push_back({
                static_cast<float>(xc),
                static_cast<float>(yc)
        });
    }
}

void Circle::draw(SDL_Renderer* renderer) const {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderLines(renderer, vertices_.data(), vertices_.size());
}

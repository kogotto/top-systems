#include <generate.hpp>

#include <Square.hpp>

namespace {

UFigure generateFigure() {
    return std::make_unique<Square>();
}

} // namespace

void generate(FiguresCollection& figures, int count) {
    for (int i = 0; i < count; ++i) {
        figures.pushBack(generateFigure());
    }
}

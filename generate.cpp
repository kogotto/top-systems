#include <generate.hpp>

namespace {

UFigure generateFigure() {
    return nullptr;
}

} // namespace

void generate(FiguresCollection& figures, int count) {
    for (int i = 0; i < count; ++i) {
        figures.pushBack(generateFigure());
    }
}

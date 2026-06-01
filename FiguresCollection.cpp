#include <FiguresCollection.hpp>

void FiguresCollection::pushBack(UFigure figure) {
    collection_.push_back(std::move(figure));
}

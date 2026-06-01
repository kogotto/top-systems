#pragma once

#include <vector>

#include <Figure.hpp>

class FiguresCollection {
public:
    using Collection = std::vector<UFigure>;

    void pushBack(UFigure figure);

    const Collection& getAll() const {
        return collection_;
    }

private:
    Collection collection_;
};

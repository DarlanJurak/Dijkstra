#ifndef GRIDWITHWEIGHTS_HPP
#define GRIDWITHWEIGHTS_HPP

#include <../SquareGrid/SquareGrid.hpp>

struct GridWithWeights: SquareGrid {
  std::unordered_set<Pos> forests;
  GridWithWeights(int w, int h): SquareGrid(w, h) {}
  double cost(Pos from_node, Pos to_node) const {
    return forests.find(to_node) != forests.end()? 5 : 1;
  }
};

#endif
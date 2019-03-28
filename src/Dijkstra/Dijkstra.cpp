#include <unordered_map>
#include <queue>

#include "../SquareGrid/SquareGrid.hpp"

std::unordered_map<Pos, Pos>
BreadthFirstSearch(SquareGrid grid, Pos start, Pos goal) {
  std::queue<Pos> frontier;
  frontier.push(start);

  std::unordered_map<Pos, Pos> came_from;
  came_from[start] = start;

  while (!frontier.empty()) {
    Pos current = frontier.front();
    frontier.pop();

    if (current == goal){
      break;
    }

    for (Pos next : grid.Neighbors(current)) {
      if (came_from.find(next) == came_from.end()) {
        frontier.push(next);
        came_from[next] = current;
      }
    }
  }
  return came_from;
}
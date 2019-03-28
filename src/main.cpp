#include "SquareGrid/SquareGrid.hpp"
#include "Dijkstra/Dijkstra.cpp"

int main(int argc, char** argv) {

    SquareGrid grid = make_diagram1();

    Pos start;
    start.x = 2;
    start.y = 2;

    Pos goal;
    start.x = 17;
    start.y = 11;
    
    auto parents = BreadthFirstSearch(grid, start, goal);
    draw_grid(grid, 2, nullptr, &parents);

    return 0;

}
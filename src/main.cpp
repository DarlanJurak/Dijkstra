#include "SquareGrid/SquareGrid.hpp"
#include "Dijkstra/Dijkstra.cpp"

void old_test_BFS();
    
int main(int argc, char** argv) {

    

    return 0;

}

void old_test_BFS(){

    SquareGrid grid = make_diagram1();

    Pos start;
    start.x = 2;
    start.y = 2;

    Pos goal;
    start.x = 17;
    start.y = 11;
    
    auto parents = BreadthFirstSearch(grid, start, goal);
    draw_grid(grid, 2, nullptr, &parents);

}
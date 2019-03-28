#include "GridWithWeights/GridWithWeights.hpp"
#include "PriorityQueue/PriorityQueue.hpp"
#include "Dijkstra/Dijkstra.cpp"

void Test0_Dijkstra();

int main(int argc, char** argv) {


    Test0_Dijkstra();
    
    return 0;

}

void Test0_Dijkstra(){

    GridWithWeights sg  = make_diagram4();

    Pos start   {1, 4};
    Pos goal    {1, 5};

    std::unordered_map<Pos, Pos>    came_from;
    std::unordered_map<Pos, double> cost_so_far;

    Dijkstra_Search(sg, start, goal, came_from, cost_so_far);

    draw_grid(sg, 2, nullptr, &came_from);
    std::cout << '\n';

    draw_grid(sg, 3, &cost_so_far, nullptr);
    std::cout << '\n';

    std::vector<Pos> path = reconstruct_path(start, goal, came_from);
    draw_grid(sg, 3, nullptr, nullptr, &path);

}
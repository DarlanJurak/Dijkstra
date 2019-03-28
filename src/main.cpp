#include <errno.h>   // for errno
#include <limits.h>  // for INT_MAX
#include <stdlib.h>  // for strtol

#include "GridWithWeights/GridWithWeights.hpp"
#include "PriorityQueue/PriorityQueue.hpp"
#include "Dijkstra/Dijkstra.cpp"

void Test0_Dijkstra(int, int, int, int);

int main(int argc, char** argv) {

    char *p;
    int num[argc -1];

    for(int i = 1; i < argc; i++){

        errno = 0;
        long conv = strtol(argv[i], &p, 10);

        // Check for errors: e.g., the string does not represent an integer
        // or the integer is larger than int
        if (errno != 0 || *p != '\0' || conv > INT_MAX) {
            std::cout << "Conversion from string to int failed" << std::endl;
        } else {
            // No error
            num[i -1] = conv;
        }

    }

    if(argc > 4){

        Test0_Dijkstra(num[0], num[1], num[2], num[3]);

    }else{

        Test0_Dijkstra(-1, -1, -1, -1);

    }

    // Test0_Dijkstra(NULL, NULL, NULL, NULL);
        
    return 0;

}

void Test0_Dijkstra(int startX=-1, int startY=-1, int goalX=-1, int goalY=-1){

    GridWithWeights sg  = make_diagram4();

    Pos start   {8, 1};
    Pos goal    {5, 4};

    if(startX > -1) start.x = startX;
    if(startY > -1) start.y = startY;
    if(goalX > -1) goal.x = goalX;
    if(goalY > -1) goal.y = goalY;

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
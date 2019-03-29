#include <unordered_map>
#include <queue>

#include "../GridWithWeights/GridWithWeights.hpp"

template<typename Pos> std::vector<Pos> reconstruct_path( Pos start, Pos goal, std::unordered_map<Pos, Pos> came_from );


/*
*
* Description: Dijkstra (lol)
*
*/
template<typename Pos, typename GridWithWeights>
void Dijkstra_Search
  (GridWithWeights graph,
   Pos start,
   Pos goal,
   std::unordered_map<Pos, Pos>& came_from,
   std::unordered_map<Pos, double>& cost_so_far)
{
  PriorityQueue<Pos, double> frontier;                                      // Ordering frontier exploration by lowest cost
  frontier.put(start, 0);                                                   // Frontier exploration starts on start point

  came_from[start]    = start;
  cost_so_far[start]  = 0;
  
  // Exploration by lowest cost
  while (!frontier.empty()) { 

    Pos current = frontier.get();                                           // Gets lowest costy position on frontier

    if (current == goal) {                                                  // Early exit when reached the goal
      break;
    }

    for (Pos next : graph.Neighbors(current)) {                             // Frontier expansion
      double new_cost = cost_so_far[current] + graph.cost(current, next);   // Add information about the cost of new frontier's position cost
      if (cost_so_far.find(next) == cost_so_far.end()                       // Position not considered yet
          || new_cost < cost_so_far[next]) {                                // During a expansion comming from other path, the cost can be lower, so we updated it
        cost_so_far[next] = new_cost;
        came_from[next]   = current;
        frontier.put(next, new_cost);
      }
    }
  }
}

template<typename Pos>
std::vector<Pos> reconstruct_path(
  Pos start, Pos goal,
  std::unordered_map<Pos, Pos> came_from)
{
     
  std::vector<Pos> path;
  Pos current = goal;
  while (current != start) {
    path.push_back(current);
    current = came_from[current];
  }
  path.push_back(start); // optional
  std::reverse(path.begin(), path.end());
  return path;
  
}
#ifndef Infinite_World_H_
#define Infinite_World_H_

#include "world.h"

class Infinite_world : public World {
 public:
  Infinite_world(const int x_ini = 1, const int y_ini = 1):World(x_ini, y_ini){}
  void handle_out_of_bounds(std::vector<Ant>& ants);
  void resize(const int x_min, const int y_min, const int x_max, const int y_max);
};
#endif //Infinite_World_H_
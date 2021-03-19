#ifndef Finite_World_H_
#define Finite_World_H_

#include "world.h"

class Finite_world : public World {
 public:
  Finite_world(const int x_ini = 1, const int y_ini = 1):World(x_ini, y_ini){}
  void handle_out_of_bounds(std::vector<Ant>& ants);
};
#endif //Finite_World_H_
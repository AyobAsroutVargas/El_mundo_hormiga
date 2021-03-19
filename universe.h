#ifndef Universe_H_
#define Universe_H_

#include "finite_world.h"
#include "infinite_world.h"
#include "ant.h"
#include <vector>

class Universe {
public:
  Universe(World* world, std::vector<Ant> ants, const int steps);
  void run_simulation(void);
 private:
  void process_step(void);
  void sort_ants(std::vector<Ant>& ants);
  World* world_;
  std::vector<Ant> ants_;
  int steps_;
};

#endif //Universe_H_
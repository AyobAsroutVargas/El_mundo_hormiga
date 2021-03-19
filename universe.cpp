#include "universe.h"

Universe::Universe(World* world, std::vector<Ant> ants, const int steps) {
  world_ = world;
  steps_= steps;
  ants_ = ants;
}

void Universe::run_simulation(void) {
  int i = 0;
  while(i <= steps_) {
    if (i == 0) {
      std::cout << "Estado inicial" << std::endl;
    } else {
      std::cout << "Iteración numero " << i << std::endl;
    }
    process_step();
    i++;
  }
}

void Universe::process_step(void) {
  sort_ants(ants_);
  world_->check_out_of_bounds(ants_);
  sort_ants(ants_);
  world_->print_world(ants_);
  for(int i = 0; i < ants_.size(); i++) {
    ants_.at(i).update(world_);
  }
  sort_ants(ants_);
  world_->check_out_of_bounds(ants_);
  sort_ants(ants_);
}

void Universe::sort_ants(std::vector<Ant>& ants) {
  Ant aux;
  for (int i = 0; i < ants.size(); i++) {
    for (int j = i + 1; j < ants.size(); j++) {
      if(ants.at(i).get_position().x > ants.at(j).get_position().x || 
        (ants.at(i).get_position().x ==  ants.at(j).get_position().x && 
        ants.at(i).get_position().y > ants.at(j).get_position().y)) {
        aux = ants.at(i);
        ants.at(i) = ants.at(j);
        ants.at(j) = aux;
      }
    }
  }
  
}
#include "finite_world.h"

void Finite_world::handle_out_of_bounds(std::vector<Ant>& ants) {
  for(int i = 0; i<ants.size(); i++) {
    if((ants.at(i).get_position().x < min_x_) || (ants.at(i).get_position().x >= max_x_)) {
      if(ants.at(i).get_position().x < min_x_) {
        ants.at(i).set_position_x(max_x_ - 1);
      }else {
        ants.at(i).set_position_x(min_x_);
      }
    }
    if((ants.at(i).get_position().y < min_y_) || (ants.at(i).get_position().y >= max_y_)) {
      if(ants.at(i).get_position().y < min_y_) {
        ants.at(i).set_position_y(max_y_ - 1);
      }else {
        ants.at(i).set_position_y(min_y_);
      }
    }
  }
}
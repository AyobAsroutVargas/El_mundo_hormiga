class World;
#ifndef World_H_
#define World_H_

#include "vector_t.h"
#include <vector>
#include "ant.h"
class World {
 public:
  World(const int x_ini = 1, const int y_ini = 1);
  int get_cell_colour(const int x, const int y) const;
  void change_cell_colour(const int x, const int y);
  void print_cell(const int& i, const int& j) const;
  void print_world(std::vector<Ant>& ants);
  void check_out_of_bounds(std::vector<Ant>& ants);
  virtual void handle_out_of_bounds(std::vector<Ant>& ants) = 0;
 protected:
  int min_x_;
  int min_y_;
  int max_x_;
  int max_y_;
  Vector_t<Vector_t<int>> board_; 
};

#endif //World_H_
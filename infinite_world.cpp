#include "infinite_world.h"

void Infinite_world::handle_out_of_bounds(std::vector<Ant>& ants) {
    for(int i = 0; i<ants.size(); i++) {
    if((ants.at(i).get_position().x < min_x_) || (ants.at(i).get_position().x >= max_x_)) {
      if(ants.at(i).get_position().x < min_x_) {
        resize(min_x_ - 1, min_y_, max_x_, max_y_);
      }else {
        resize(min_x_, min_y_, max_x_ + 1, max_y_);
      }
    }
    if((ants.at(i).get_position().y < min_y_) || (ants.at(i).get_position().y >= max_y_)) {
      if(ants.at(i).get_position().y < min_y_) {
        resize(min_x_, min_y_ - 1, max_x_, max_y_);
      }else {
        resize(min_x_, min_y_, max_x_, max_y_ + 1);
      }
    }
  }
}

void Infinite_world::resize(const int x_min, const int y_min, const int x_max, const int y_max) {
  std::cout << "Redimensionando..., pasando de eje x:" << min_x_ << "," << max_x_ << " ejey: " << min_y_ << "," << max_y_ << " a " << "eje x:" << x_min << "," << x_max << " eje y: " << y_min << "," << y_max << std::endl;
  //Creamos nuevo tablero con tamaño deseado
  Vector_t<Vector_t<int>> new_board(x_min, x_max);
  for (int i = x_min; i < x_max; i++) {
    new_board.at(i).resize(y_min, y_max);
  }

  //inicializamos el nuevo tablero
  for (int i = x_min; i < x_max; i++) {
    for (int j = y_min; j < y_max; j++) {
      new_board.at(i).at(j) = 0;
    }
  }

  //copiamos los valores del tablero actual al nuevo
  for (int i = min_x_; i < max_x_; i++) {
    for(int j = min_y_; j < max_y_; j++) {
      new_board.at(i).at(j) = board_.at(i).at(j);
    }
  }

  //actualizamos los atributos del mundo
  min_x_ = x_min;
  max_x_ = x_max;
  min_y_ = y_min;
  max_y_ = y_max;

  //redimensionamos nuestro tablero a las dimensiones deseadas
  board_.resize(min_x_, max_x_);
  for (int i = min_x_; i < max_x_; i++) {
    board_.at(i).resize(min_y_, max_y_);
  }

  //Volvemos a copiar los valores a nuestro tablero
  for (int i = min_x_; i < max_x_; i++) {
    for(int j = min_y_; j < max_y_; j++) {
      board_.at(i).at(j) = new_board.at(i).at(j);
    }
  }
}
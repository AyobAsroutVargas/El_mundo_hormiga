#include "ant.h"
#include <iostream>

Ant::Ant(void) {
  position_.x = 0;
  position_.y = 0;
  orientation_ = EAST;
}

Ant::Ant(const int& rows, const int& cols) {
  position_.x = rows/2;
  position_.y = cols/2;
  orientation_ = EAST;
}

Position Ant::get_position() {
  return position_;
}

int Ant::get_orientation(void) {
  return orientation_;
}

void Ant::change_orientation(const int& current_cell_colour) {
  switch (orientation_) {
    case NORTH:
      if(current_cell_colour == WHITE) {
        orientation_ = NORTH_WEST;
      } else if(current_cell_colour == BLACK){
        orientation_ = NORTH_EAST;
      }
      break;
    case NORTH_EAST:
      if(current_cell_colour == WHITE) {
        orientation_ = NORTH;
      } else if(current_cell_colour == BLACK){
        orientation_ = EAST;
      }
      break;
    case EAST:
      if(current_cell_colour == WHITE) {
        orientation_ = NORTH_EAST;
      } else if(current_cell_colour == BLACK){
        orientation_ = SOUTH_EAST;
      }
      break;
    case SOUTH_EAST:
      if(current_cell_colour == WHITE) {
        orientation_ = EAST;
      } else if(current_cell_colour == BLACK){
        orientation_ = SOUTH;
      }
      break;
    case SOUTH:
      if(current_cell_colour == WHITE) {
        orientation_ = SOUTH_EAST;
      } else if(current_cell_colour == BLACK){
        orientation_ = SOUTH_WEST;
      }
      break;
    case SOUTH_WEST:
      if(current_cell_colour == WHITE) {
        orientation_ = SOUTH;
      } else if(current_cell_colour == BLACK){
        orientation_ = WEST;
      }
      break;
    case WEST:
      if(current_cell_colour == WHITE) {
        orientation_ = SOUTH_WEST;
      } else if(current_cell_colour == BLACK){
        orientation_ = NORTH_WEST;
      }
      break;
    case NORTH_WEST:
      if(current_cell_colour == WHITE) {
        orientation_ = WEST;
      } else if(current_cell_colour == BLACK){
        orientation_ = NORTH;
      }
      break;  
  }
}

void Ant::move_forward(){
  switch (orientation_) {
    case NORTH:
      position_.x += -1;
      break;
    case NORTH_EAST:
      position_.x += -1;
      position_.y += 1;
      break;
    case EAST:
      position_.y += 1;
      break;
    case SOUTH_EAST:
      position_.x += 1;
      position_.y += 1;
      break;  
    case SOUTH:
      position_.x += 1;
      break;
    case SOUTH_WEST:
      position_.y += -1;
      position_.x += 1;
      break;
    case WEST:
      position_.y += -1;
      break;
    case NORTH_WEST:
      position_.y += -1;
      position_.x += -1;
      break;  
  }
}

void Ant::set_position_x(const int& x) {
  position_.x = x;
}

void Ant::set_position_y(const int& y){
  position_.y = y;
}

void Ant::set_orientation(const int& orientation) {
  orientation_ = orientation;
}

void Ant::print_ant(void) {
  switch (orientation_) {
    case NORTH:
      std::cout << '^';
      break;
    case NORTH_EAST:
      std::cout << '/';
      break;
      case EAST:
      std::cout << '>';
      break;
    case SOUTH_EAST:
      std::cout << ';';
      break;
    case SOUTH:
      std::cout << 'v';
      break;
    case SOUTH_WEST:
      std::cout << ',';
      break;
      case WEST:
      std::cout << '<';
      break;
    case NORTH_WEST:
      std::cout << '`';
      break;   
  }
}

void Ant::update(World* world) {
  change_orientation(world->get_cell_colour(position_.x, position_.y));
  world->change_cell_colour(position_.x, position_.y);
  move_forward();
}
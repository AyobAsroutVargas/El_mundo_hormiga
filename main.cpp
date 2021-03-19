#include "universe.h"
#include <vector>

int main (void) {
  int rows, cols, steps, number_of_ants, ant_pos_x, ant_pos_y, world_type;
  Ant aux_ant;
  std::vector<Ant> ants;


  std::cout << "En esta simulación se representan las casillas del mundo como ' '(balncas)\n"
  << "'X'(negras), las orientaciones de la hormiga son '^'(norte), '/'(noreste), '>'(este),\n" 
  << " ';'(sureste), 'v'(sur), ','(suroeste), '<'(oeste), '`'(noroeste)\n";
  std::cout << "\nEscoja el tipo de mundo que quiere, 0 finito, 1 infinito:";
  std::cin >> world_type;
  std::cout << "Introduzca las dimensiones del mundo\nfilas:";
  std::cin >> rows;
  std::cout << "columnas:";
  std::cin >> cols;
  std::cout << "Numero de pasos:";
  std::cin >> steps;
  std::cout << "Introduzca el numero de hormigas:";
  std::cin >> number_of_ants;
  for (int i = 0; i<number_of_ants;i++) {
    std::cout << "Introduzca la posicion de la hormiga\nX:";
    std::cin >> ant_pos_x;
    aux_ant.set_position_x(ant_pos_x);
    std::cout << "Y:";
    std::cin >> ant_pos_y;
    aux_ant.set_position_y(ant_pos_y);
    ants.push_back(aux_ant);
  }
  if (world_type == 0) {
    World* world = new Finite_world(rows,cols);
    std::cout << "\n\n";
    Universe universe(world, ants, steps);
    universe.run_simulation();
  }else {
    World* world = new Infinite_world(rows,cols);
    std::cout << "\n\n";
    Universe universe(world, ants, steps);
    universe.run_simulation();
  }
  

  return 0;
}
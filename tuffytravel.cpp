// tuffytravel.cpp
// milestone #8
// 12/19/19

#include "route.hpp"
#include <fstream>
#include <iostream>
#include <string>

int main() {

  char action;
  RouteManager rm;
  display_opening_statement();

  // used a do while loop to create the user menu
  do {
    std::cout << "What do you want to do?\n";
    std::cout << "R - Create routes\n";
    std::cout << "C - Create checked routes\n";
    std::cout << "T - Create connection routes\n";
    std::cout << "D - Display routes\n";
    std::cout << "F - Find route\n";
    std::cout << "S - Save routes\n";
    std::cout << "L - Load routes\n";
    std::cout << "X - Exit\n";
    std::cout << "Action: ";
    std::cin >> action;
    std::cin.ignore();
    std::cout << "\n";

    if (action == 'R' || action == 'r') {
      rm.add(create_route());
    } else if (action == 'C' || action == 'c') {
      rm.add(create_checked_route());
    } else if (action == 'T' || action == 't') {
      rm.add(create_connection_route());
    } else if (action == 'D' || action == 'd') {
      rm.display_routes();
    } else if (action == 'F' || action == 'f') {
      rm.find_route(get_time_to_leave());
    } else if (action == 'S' || action == 's') {
      rm.save_routes(get_filename());
    } else if (action == 'L' || action == 'l') {
      rm.load_routes(get_filename());
    }

  } while (action != 'X' && action != 'x');
  display_closing_statement();
  return 0;
}


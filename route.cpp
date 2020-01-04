// Route/RouteManager class implementations and general functions
#include "route.hpp"
#include <fstream>
#include <iostream>
#include <string>

// General Function implementations ===========================================
ConnectionRoute* create_connection_route() {
  std::string route_name = get_conroute_name();
  std::string sroute_name = get_sroute_name();
  std::string droute_name = get_droute_name();
  unsigned int departure_time = get_condeparture_time();
  unsigned int arrival_time = get_conarrival_time();

  // dynamically created ConnectionRoute object using info above
  ConnectionRoute* con_route_ptr = new ConnectionRoute(
      route_name, sroute_name, droute_name, departure_time, arrival_time);
  return con_route_ptr;
}

CheckedRoute* create_checked_route() {
  std::string route_name;
  unsigned int departure_time = 0;
  unsigned int take_off_time = 0;
  unsigned int arrival_time = 0;
  route_name = get_chkroute_name();
  departure_time = get_chkdeparture_time();
  take_off_time = get_tot();
  arrival_time = get_chkarrival_time();

  // dynamically created CheckedRoute object using info above
  CheckedRoute* checked_route_ptr =
      new CheckedRoute(route_name, departure_time, take_off_time, arrival_time);
  return checked_route_ptr;
}

Route* create_route() {
  std::string route_name;
  unsigned int departure_time = 0;
  unsigned int arrival_time = 0;
  route_name = get_route_name();
  departure_time = get_departure_time();
  arrival_time = get_arrival_time();

  // dynamically created Route object using info above
  Route* route_ptr = new Route(route_name, departure_time, arrival_time);
  return route_ptr;
}

unsigned int get_time_to_leave() {
  unsigned int leaving_time = 0;

  std::cout << "Please enter the time you plan to leave: ";
  std::cin >> leaving_time;
  std::cin.ignore();
  std::cout << "\n";
  return leaving_time;
}
// Route get info functions ============================================
std::string get_filename() {
  std::string fn;
  std::cout << "Please enter the filename: ";
  std::getline(std::cin, fn);
  return fn;
}
std::string get_route_name() {
  std::string route_name;
  std::cout << "Please enter the name of the route: ";
  std::getline(std::cin, route_name);
  return route_name;
}
unsigned int get_departure_time() {
  unsigned int departure_time = 0;
  std::cout << "Please enter the departure time of the route: ";
  std::cin >> departure_time;
  std::cin.ignore();
  return departure_time;
}
unsigned int get_arrival_time() {
  unsigned int arrival_time = 0;
  std::cout << "Please enter the arrival time of the route: ";
  std::cin >> arrival_time;
  std::cin.ignore();
  std::cout << "\n";
  return arrival_time;
}
// checkedRoute get info functions ===========================================
std::string get_chkroute_name() {
  std::string route_name;
  std::cout << "Please enter the name of the checked route: ";
  std::getline(std::cin, route_name);
  return route_name;
}
unsigned int get_chkdeparture_time() {
  unsigned int departure_time = 0;
  std::cout << "Please enter the departure time of the checked route: ";
  std::cin >> departure_time;
  std::cin.ignore();
  return departure_time;
}
unsigned int get_chkarrival_time() {
  unsigned int arrival_time = 0;
  std::cout << "Please enter the arrival time of the checked route: ";
  std::cin >> arrival_time;
  std::cin.ignore();
  std::cout << "\n";
  return arrival_time;
}
unsigned int get_tot() {
  unsigned int tot = 0;
  std::cout << "Please enter the take off time of the checked route: ";
  std::cin >> tot;
  std::cin.ignore();
  return tot;
}
// connection route get functions ===========================================
std::string get_sroute_name() {
  std::string route_name;
  std::cout << "Please enter the source route: ";
  std::getline(std::cin, route_name);
  return route_name;
}
std::string get_droute_name() {
  std::string route_name;
  std::cout << "Please enter the destination route: ";
  std::getline(std::cin, route_name);
  return route_name;
}
std::string get_conroute_name() {
  std::string route_name;
  std::cout << "Please enter the name of the connection route: ";
  std::getline(std::cin, route_name);
  return route_name;
}
unsigned int get_condeparture_time() {
  unsigned int departure_time = 0;
  std::cout << "Please enter the departure time of the connection route: ";
  std::cin >> departure_time;
  std::cin.ignore();
  return departure_time;
}
unsigned int get_conarrival_time() {
  unsigned int arrival_time = 0;
  std::cout << "Please enter the arrival time of the connection route: ";
  std::cin >> arrival_time;
  std::cin.ignore();
  std::cout << "\n";
  return arrival_time;
}
// statement functions =======================================================
void display_opening_statement() {
  std::cout << "Welcome to Tuffy Travel!";
  std::cout << "\n";
  std::cout << "\n";
}

void display_closing_statement() {
  std::cout << "Thank you for using TuffyTravel!\n\n";
}

// Route Class function Implementation ========================================
void Route::display() {
  std::cout << "Route: " << name_ << "\n"
            << "Departure time: " << departure_time_ << "\n"
            << "Arrival time: " << arrival_time_ << "\n";
}
std::string Route::save_string() {
  std::string save;
  save = "[Route]\n" + name_ + "\n" + std::to_string(departure_time_) + "\n" +
         std::to_string(arrival_time_) + "\n";
  return save;
}
// ============================================================================
// ConnectionRoute class function implementation
void ConnectionRoute::display() {
  std::cout << "Connection Route: " << Route::name() << "\n"
            << "Source: " << source_route_ << "\n"
            << "Destination: " << destination_route_ << "\n"
            << "Departure time: " << Route::departure_time() << "\n"
            << "Arrival time: " << Route::arrival_time() << "\n";
}
std::string ConnectionRoute::save_string() {
  std::string save;
  save = "[ConnectionRoute]\n" + Route::name() + "\n" + source_route_ + "\n" +
         destination_route_ + "\n" + std::to_string(Route::departure_time()) +
         "\n" + std::to_string(Route::arrival_time()) + "\n";
  return save;
}
// ============================================================================
// Checked Route function implementation ======================================
void CheckedRoute::display() {
  std::cout << "Checked Route: " << Route::name() << "\n"
            << "Departure time: " << Route::departure_time() << "\n"
            << "Take off time: " << take_off_time_ << "\n"
            << "Arrival time: " << Route::arrival_time() << "\n";
}
std::string CheckedRoute::save_string() {
  std::string save;
  save = "[CheckedRoute]\n" + Route::name() + "\n" +
         std::to_string(Route::departure_time()) + "\n" +
         std::to_string(take_off_time_) + "\n" +
         std::to_string(Route::arrival_time()) + "\n";
  return save;
}
// ===========================================================================
// RouteManager Class function Implementation =================================
void RouteManager::display_routes() {
  if (num_of_routes_in_array_ == 0) {
    std::cout << "Sorry you have no routes"
              << "\n\n";
  } else {
    std::cout << "Available routes: "
              << "\n\n";
    for (unsigned int j = 0; j < num_of_routes_in_array_; j++) {
      routes_[j]->display();
      std::cout << "\n";
    }
  }
}

void RouteManager::find_route(unsigned short int ttl) {
  if (num_of_routes_in_array_ <= 0) {
    std::cout << "Sorry, there are no routes available.";
  } else {
    Route* best_route;
    bool found_route = false;
    for (int i = 0; i < num_of_routes_in_array_; i++) {
      if (!found_route && routes_[i]->departure_time() >= ttl) {
        best_route = routes_[i];
        found_route = true;
      } else if (found_route && routes_[i]->departure_time() >= ttl &&
                 routes_[i]->departure_time() < best_route->departure_time()) {
        best_route = routes_[i];
        found_route = true;
      }
    }
    if (found_route) {
      std::cout << "We suggest you take this route:\n\n";
      best_route->display();
      std::cout << "\n";
    } else {
      std::cout << "Sorry, there is no route that leaves on or after the time "
                   "you plan to leave.\n\n";
    }
  }
}

void RouteManager::save_routes(const std::string& filename) {
  if (num_of_routes_in_array_ > 0) {
    std::ofstream output_file;
    output_file.open(filename);
    output_file << num_of_routes_in_array_ << "\n";
    for (int i = 0; i < num_of_routes_in_array_; i++) {
      output_file << routes_[i]->save_string();
    }
    output_file.close();
    std::cout << "File saved!\n\n";
  } else {
    std::cout << "Sorry, you have no routes"
              << "\n\n";
  }
}

void RouteManager::load_routes(const std::string& filename) {
  std::ifstream input_file;
  input_file.open(filename);
  if (input_file) {
    input_file >> num_of_routes_in_array_;
    input_file.ignore();
    for (int i = 0; i < num_of_routes_in_array_; i++) {
      std::string type;
      std::string temp_name;
      std::string temp_sroute_name;
      std::string temp_droute_name;
      int temp_dep_time = 0;
      int temp_arr_time = 0;
      int temp_tot = 0;

      std::getline(input_file, type);
      if (type == "[Route]") {
        std::getline(input_file, temp_name);
        input_file >> temp_dep_time;
        input_file >> temp_arr_time;
        input_file.ignore();
        routes_[i] = new Route(temp_name, temp_dep_time, temp_arr_time);

      } else if (type == "[CheckedRoute]") {
        std::getline(input_file, temp_name);
        input_file >> temp_dep_time;
        input_file >> temp_tot;
        input_file >> temp_arr_time;
        input_file.ignore();
        routes_[i] =
            new CheckedRoute(temp_name, temp_dep_time, temp_tot, temp_arr_time);
      } else {
        std::getline(input_file, temp_name);
        std::getline(input_file, temp_sroute_name);
        std::getline(input_file, temp_droute_name);
        input_file >> temp_dep_time;
        input_file >> temp_arr_time;
        input_file.ignore();
        routes_[i] =
            new ConnectionRoute(temp_name, temp_sroute_name, temp_droute_name,
                                temp_dep_time, temp_arr_time);
      }
    }
    std::cout << "File loaded!";
    input_file.close();
    current_route_ =
        num_of_routes_in_array_; // highlighted as a test, might not need (MNN)
  } else {
    std::cout << "File does not exist.";
  }
  std::cout << "\n\n";
}

void RouteManager::add(Route* rt_ptr) {
  routes_[num_of_routes_in_array_++] = rt_ptr;
  current_route_++;
}


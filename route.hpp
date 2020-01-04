
// contains the class and corresponding function prototypes
#include <iostream>
#include <string>

class Route {
private:
  std::string name_;
  unsigned int departure_time_;
  unsigned int arrival_time_;

public:
  // default constructor
  Route() : Route("Home", 2000, 2200) {}
  // non-default constructor
  Route(const std::string& name, const unsigned int& departure_time,
        const unsigned int& arrival_time)
      : name_(name), departure_time_(departure_time),
        arrival_time_(arrival_time) {}

  void set_name(const std::string& route) { name_ = route; }
  void set_departure_time(const unsigned int& departure) {
    departure_time_ = departure;
  }
  void set_arrival_time(const unsigned int& arrival) {
    arrival_time_ = arrival;
  }
  std::string name() { return name_; }
  unsigned int departure_time() { return departure_time_; }
  unsigned int arrival_time() { return arrival_time_; }
  virtual void display();
  virtual std::string save_string();
}; // end of Route class
   // --------------------------------------------------------

// CheckedRoute Class
class CheckedRoute : public Route {
private:
  unsigned int take_off_time_;

public:
  CheckedRoute() : Route("Home", 2000, 2200), take_off_time_(2010) {}
  CheckedRoute(const std::string& name, const unsigned int& departure_time,
               const unsigned int& tot, const unsigned int& arrival_time)
      : Route(name, departure_time, arrival_time), take_off_time_(tot) {}
  int take_off_time() { return take_off_time_; }
  void set_take_off_time(unsigned int tot) { take_off_time_ = tot; }
  void display() override;
  std::string save_string() override;
}; // end of CheckedRoute class ----------------------------------------

// ConnectionRoute class ------------------------------------------------
class ConnectionRoute : public Route {
private:
  std::string source_route_;
  std::string destination_route_;

public:
  ConnectionRoute()
      : Route("Walk to bus", 800, 805), source_route_("Home"),
        destination_route_("Bus stop") {}
  ConnectionRoute(const std::string& name, const std::string& sr,
                  const std::string& dr, const unsigned int& departure_time,
                  const unsigned int& arrival_time)
      : Route(name, departure_time, arrival_time), source_route_(sr),
        destination_route_(dr) {}
  std::string source_route() { return source_route_; }
  std::string destination_route() { return destination_route_; }
  void set_source_route(const std::string& sr) { source_route_ = sr; }
  void set_destination_route(const std::string& dr) { destination_route_ = dr; }
  void display() override;
  std::string save_string() override;
}; // end of connectionroute class

// RouteManager class is meant to manage the Route array
class RouteManager {
private:
  unsigned int size_;
  unsigned int current_route_;
  unsigned int num_of_routes_in_array_;
  Route* routes_[100];

public:
  RouteManager() : RouteManager(100, 0, 0) {}
  RouteManager(unsigned int size, unsigned int current_route,
               unsigned int num_of_routes_in_array)
      : size_(size), current_route_(current_route),
        num_of_routes_in_array_(num_of_routes_in_array) {}
  ~RouteManager() {
    for (int i = 0; i < num_of_routes_in_array_; ++i) {
      delete *(routes_ + i);
      routes_[i] = nullptr;
    }
  }
  void display_routes();
  void find_route(unsigned short int ttl);
  void save_routes(const std::string& filename);
  void load_routes(const std::string& filename);
  void add(Route* rt_ptr);
  // accessors and mutators
  unsigned int size() { return size_; }
  unsigned int current_route() { return current_route_; }
  unsigned int num_of_routes_in_array() { return num_of_routes_in_array_; }
  void set_size(unsigned int size) { size_ = size; }
  void set_current_route(unsigned int current_route) {
    current_route_ = current_route;
  }
  void set_num_of_routes_in_array(unsigned int num_of_routes_in_array) {
    num_of_routes_in_array_ = num_of_routes_in_array;
  }
}; // end of RouteManager Class ----------------------------------------------
// General function prototypes ================================================
std::string get_route_name();
unsigned int get_departure_time();
unsigned int get_arrival_time();
std::string get_chkroute_name();
unsigned int get_chkdeparture_time();
unsigned int get_tot();
unsigned int get_chkarrival_time();
std::string get_conroute_name();
std::string get_sroute_name();
std::string get_droute_name();
unsigned int get_condeparture_time();
unsigned int get_conarrival_time();
void display_opening_statement();
Route* create_route();
CheckedRoute* create_checked_route();
ConnectionRoute* create_connection_route();
unsigned int get_time_to_leave();
std::string get_filename();
void display_closing_statement();

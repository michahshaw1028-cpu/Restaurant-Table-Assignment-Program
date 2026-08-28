#include <iostream>
#include "Restaurant.hpp"

using namespace std;
int main() {
  // Initialize Restaurant with 2 tables
  Restaurant restaurant(2);
  
  
  // Create customers and make reservations
  shared_ptr<Customer> customer1 = make_shared<Customer>("Customer1");

  shared_ptr<Customer> customer2 = make_shared<Customer>("Customer2");

  shared_ptr<Customer> customer3 = make_shared<Customer>("Customer3");

  shared_ptr<Customer> customer4 = make_shared<Customer>("Customer4");
  // Release a table and demonstrate waitlist notification

  restaurant.reserveTable(customer1);

  return 0;
}
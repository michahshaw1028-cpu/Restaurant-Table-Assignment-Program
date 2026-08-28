#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <vector>
#include <memory>
#include "Table.hpp"
#include "Customer.hpp"


class Restaurant {
public:
  Restaurant(int initialTableCount);
  std::vector<std::unique_ptr<Table>> tables;
  std::vector<std::shared_ptr<Customer>> activeCustomers;
  std::vector<std::weak_ptr<Customer>> waitlist;  

  bool reserveTable(std::shared_ptr<Customer>& customer);
  void printWaitlist();
  void releaseTable(int tableNumber);
private:
  void notifyWaitlist();
  
 };
                                      
#endif

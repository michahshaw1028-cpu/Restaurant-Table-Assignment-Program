#include "Restaurant.hpp"
#include "Customer.hpp"
#include "removeElement.hpp"

#include <iostream>

using namespace std;

Restaurant::Restaurant(int initialTableCount){
  for(int i = 1; i <= initialTableCount; i++){
    tables.push_back(std::make_unique<Table>(i));
  }
}

bool Restaurant::reserveTable(std::shared_ptr<Customer>& customer){
  for(std::unique_ptr<Table>& table: tables){
    if((*table).getIsAvailable() == true){
      (*table).reserve();
      activeCustomers.push_back(customer);
      return true;
    } else {
      waitlist.push_back(customer);
    }
  }
  return false;
}

void Restaurant::printWaitlist(){
  cout << "The following people are waiting for a table: " << endl;
  for(std::weak_ptr<Customer> waitingCustomer : waitlist){
    std::shared_ptr<Customer> customerPtr = waitingCustomer.lock();
    cout << (*customerPtr).getName() << endl;
  }
}

void Restaurant::releaseTable(int tableNumber){
  for(std::unique_ptr<Table>& table: tables){
    if((*table).getNumber() == tableNumber){
      if((*table).getIsAvailable()){
        (*table).release();
        notifyWaitlist();
      }
    }
  }
}

void Restaurant::notifyWaitlist(){
  if(waitlist.empty()){
    return;
  } else {
    shared_ptr<Customer> customer;
    customer = waitlist[0].lock();
    if(waitlist[0].lock() == customer){
      reserveTable(customer);
      removeElement(waitlist, customer);
    }
  }
}
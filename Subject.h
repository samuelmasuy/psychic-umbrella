#pragma once

#include <list>
#include "Observer.h"

using namespace std;

class Subject {
 public:
  Subject();
  ~Subject();
  void attach(Observer* o);
  void detach(Observer* o);
  void notify();

 private:
  list<Observer*> *observers;
};


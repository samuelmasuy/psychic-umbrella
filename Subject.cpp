#include "Subject.h"
#include "Observer.h"

//Default constructor for Subject class, creates collection of observers
Subject::Subject() {
  observers = new list<Observer*>;
}
//Destructor, calls destructor for observer class
Subject::~Subject() {
  delete observers;
}

//Attaches observer to subject class by adding observer to collection of observers
void Subject::attach(Observer* o) {
  observers->push_back(o);
};

//Detaches observers from subject class by removing observer from collection of observers
void Subject::detach(Observer* o) {
  observers->remove(o);
};

//Informs observers associated with subject of state change by call update method on each observer
void Subject::notify() {
  list<Observer *>::iterator i = observers->begin();
  for (; i != observers->end(); ++i)
    (*i)->update();
};



/**
 * @file main.cpp
 * @brief Main Driver
 * @author Samuel Masuy
 * @date 2016-11-23
 */
#include <iostream>
#include "ItemDecorator.h"
#include "ItemException.h"
#include "Character.h"
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

using namespace std;

void display(Character* c) {
  cout << "getStrength: " << c->getStrength() << endl;
  cout << "getArmor: " << c->getArmor() << endl;
  cout << "getConstitution: " << c->getConstitution() << endl;
  cout << "getWisdom: " << c->getWisdom() << endl;
  cout << "getCharisma: " << c->getCharisma() << endl;
  cout << "getDexterity: " << c->getDexterity() << endl;
  cout << "getAttack: " << c->getAttack() << endl;
  cout << "getDamage: " << c->getDamage() << endl;
  cout << "getIntelligence: " << c->getIntelligence() << endl;
  cout << endl;
}

int main(int argc, char const* argv[]) {
  // Get the top level suite from the registry
  CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

  // Adds the test to the list of test to run
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(suite);

  // Change the default outputter to a compiler error format outputter
  runner.setOutputter(new CppUnit::CompilerOutputter(&runner.result(),
                      std::cerr));
  // Run the tests.
  bool wasSucessful = runner.run();

  // New base character
  Character *c = new Fighter();
  cout << "Regular Fighter" << endl;
  display(c);

  cout << "Fighter with helmet" << endl;
  try {
    c = new Helmet(c);
  } catch(exception& e) {
    cout << e.what() << endl;
  }
  display(c);

  cout << "Fighter with another helmet: fails" << endl;
  try {
    c = new Helmet(c);
  } catch(exception& e) {
    cout << e.what() << endl;
  }
  display(c);

  cout << "Fighter without helmet (bare)" << endl;
  c = c->remove("helmet");
  display(c);

  cout << "Fighter with helmet" << endl;
  try {
    c = new Helmet(c);
  } catch(exception& e) {
    cout << e.what() << endl;
  }
  display(c);

  cout << "Fighter with helmet, ring, boots" << endl;
  try {
    c = new Boots(new Ring(c));
  } catch(exception& e) {
    cout << e.what() << endl;
  }
  display(c);

  cout << "Fighter with helmet, ring, boots, weapon" << endl;
  try {
    c = new Weapon(c);
  } catch(exception& e) {
    cout << e.what() << endl;
  }
  display(c);

  cout << "Fighter with helmet, boots, ring, (weapon removed)" << endl;
  c = c->remove("weapon");
  display(c);

  getchar();

  // Return error code 1 if the one of test failed.
  return wasSucessful ? 0 : 1;
}

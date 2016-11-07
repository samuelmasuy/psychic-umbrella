//! @file
//! @brief Driver file to create and execute the test suite
//!

#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include "Map.h"
#include "MapDirector.h"

//! main() function. Entry point of the program
//! It does the following:
//! 1. Create a test suite object from the registry as populated by the code in the Test Classes
//! 2. Create a test runner that will execute all the tests in the registry
//! 3. (optionally) sets an outputter that will output the results
//! 4. Run the test cases.
int main(int argc, char* argv[]) {
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

  // example using FileMapBuilder.
  MapDirector md; //Create the Director
  FileMapBuilder* fileMapBuilder = new FileMapBuilder; //Create the Concrete Builder

  md.setMapBuilder(fileMapBuilder); // Tell the Director which Builder to use
  md.constructMap("map.txt"); // Tell the Director to construct the Map
  Map *map = md.getMap(); // Client gets the Map
  map->print(); // Client uses the Map
  delete fileMapBuilder;
  // Return error code 1 if the one of test failed.
  return wasSucessful ? 0 : 1;
}

/**
 * @file RunApp.cpp
 * @brief Run unit test, and main program. (Driver)
 * @author Samuel RRJ Masuy
 * @version 1.0
 * @date 2016-10-14
 */
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include "DiceRoller.h"

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

  std::cout << std::endl << "Main Program" << std::endl;
  // create a new instance of DiceRoller
  DiceRoller* dice_roller = new DiceRoller();

  // roll the dices.
  try {
    // roll dice with invalid query
    std::cout << "Rolling  dices with following query: " << "3doop10[+7]";
    std::cout << std::endl << "Result: ";
    dice_roller->roll("3doop10[+9]");
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  // roll the dices.
  try {
    // roll dice with invalid number of sides
    std::cout << "Rolling  dices with following query: " << "5d99[+6]";
    std::cout << std::endl << "Result: ";
    dice_roller->roll("5d99[+6]");
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  // roll the dices.
  int result = 0;
  try {
    // roll dice with valid query
    std::cout << "Rolling  dices with following query: " << "3d10[+7]";
    std::cout << std::endl << "Result: ";
    result = dice_roller->roll("4d10[+7]");

    std::stringstream display_result_stream;
    int i = 0;
    // get results from each dice.
    for (auto const& dice : dice_roller->getDices()) {
      if(i != 0)
        display_result_stream << " + ";
      display_result_stream << std::to_string(dice->getResult());
      i++;
    }
    // append the modifier.
    display_result_stream << " + " << dice_roller->getModifier() << " = " << std::to_string(result);
    std::cout << display_result_stream.str() << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  // Return error code 1 if the one of test failed.
  return wasSucessful ? 0 : 1;
}

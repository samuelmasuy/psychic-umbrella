//! @file
//! @brief Implementation file for the MapTest class, and the MapBuilder class
//!
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include "Map.h"
#include "MapDirector.h"
using namespace CppUnit;

//! Test Class for the Map class
class MapTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(MapTest);
  CPPUNIT_TEST(testMapCellFilled);
  CPPUNIT_TEST(testMapCellEmpty);
  CPPUNIT_TEST(testFileBuilder);
  CPPUNIT_TEST(testLevelBuilder);
  CPPUNIT_TEST_SUITE_END();
 public:
  void setUp();
  void tearDown();
 protected:
  void testMapCellFilled();
  void testMapCellEmpty();
  void testFileBuilder();
  void testLevelBuilder();
 private:
  Map *map;
};

//! cppunit registry creation
CPPUNIT_TEST_SUITE_REGISTRATION(MapTest);

//! method called before every test case in this test class
void MapTest::setUp() {
  map = new Map();
}

//! method called after every test case in this test class
void MapTest::tearDown() {
  delete map;
}

//! test method to test the isOccupied() method of the Map class
//! Test Case: the returned value should be true after filling the cell
//! Tested item: Map::isOccupied()
void MapTest::testMapCellFilled() {
  // context: fill a cell
  map->fillCell('w', 1, 1);
  // test: isOccupied() should return true after the cell having been filled
  CPPUNIT_ASSERT(true == map->isOccupied(1, 1));
}

//! test method to test the isOccupied() method of the Map class
//! Test Case: the returned value should be true after emptying the cell
//! Tested item: Map::isOccupied()
void MapTest::testMapCellEmpty() {
  // context: make a cell empty
  map->fillCell('.', 1, 1);
  // test: isOoccupied() should return false if the cell was not filled
  CPPUNIT_ASSERT(false == map->isOccupied(1, 1));
}

//! test method to test the testFileBuilder() method of the FileMapBuilder class
//! Test Case: the returned value should be true if there is a valid path in the map
//! Tested item: FileMapBuilder::buildMap()
void MapTest::testFileBuilder() {
  cout << endl;
  // context: create a map with a valid path
  MapDirector md; //Create the Director
  FileMapBuilder* fileMapBuilder = new FileMapBuilder(); //Create the Concrete Builder

  md.setMapBuilder(fileMapBuilder); //Tell the Director which Builder to use
  md.constructMap("map.txt"); //Tell the Director to construct the Map
  map = md.getMap(); //Client gets the Map
  map->print(); //Client uses the Map
  cout << endl << endl;

  // test: validatePath() should return true
  CPPUNIT_ASSERT(true == map->validatePath());

  delete fileMapBuilder;
}
//! test method to test the testLevelBuilder() method of the InteractiveMapBuilder class
//! Test Case: the number of chest and enemy should be equal to the level passed.
//! Tested item: InteractiveMapBuilder::buildMap()
void MapTest::testLevelBuilder() {
  cout << endl;
  // context: create a map with a valid path
  MapDirector md; //Create the Director
  InteractiveMapBuilder* interactiveMapBuilder = new InteractiveMapBuilder(); //Create the Concrete Builder

  md.setMapBuilder(interactiveMapBuilder); //Tell the Director which Builder to use
  md.constructMap("map.txt", 5); //Tell the Director to construct the Map
  map = md.getMap(); //Client gets the Map
  map->print(); //Client uses the Map
  cout << endl << endl;


  // Calculate the number of chest and enemy on the map
  int nbr_chest = 0;
  int nbr_enemy = 0;
  char cell_type;
  for (int i = 0; i < map->getColumns(); i++) {
    for (int j = 0; j < map->getRows(); j++) {
      cell_type = map->getCell(i, j);
      if (cell_type == 'c') {
        nbr_chest++;
      } else if (cell_type == 'e') {
        nbr_enemy++;
      }
    }
  }
  CPPUNIT_ASSERT(5 == nbr_chest);
  CPPUNIT_ASSERT(5 == nbr_enemy);

  delete interactiveMapBuilder;
}



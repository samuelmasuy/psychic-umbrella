/**
 * @file TestItemDecorator.cpp
 * @brief Test Decorator pattern on Character.
 * @author Samuel Masuy
 * @date 2016-11-23
 */
#include <iostream>
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
#include "ItemDecorator.h"
#include "ItemException.h"
#include "Character.h"

using namespace CppUnit;
using namespace std;

/**
 * @brief Class to test the decorator with items on character.
 */
class TestItemDecorator : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(TestItemDecorator); // declare the test suite
  CPPUNIT_TEST(testWearItem);
  CPPUNIT_TEST(testRemoveItem);
  CPPUNIT_TEST(testDuplicateItem);
  CPPUNIT_TEST(testManyItem);
  CPPUNIT_TEST_SUITE_END();
 public:
  void setUp(void);
  void tearDown(void);
 protected:
  void testWearItem(void);
  void testRemoveItem(void);
  void testDuplicateItem(void);
  void testManyItem(void);
 private:
  Character *c;
};

//Register for running the test
CPPUNIT_TEST_SUITE_REGISTRATION(TestItemDecorator);

/**
 * @brief Test if an item is succesfully worn.
 */
void TestItemDecorator::testWearItem(void) {
  c = new Helmet(c);
  CPPUNIT_ASSERT(2 == c->getIntelligence());
  CPPUNIT_ASSERT(2 == c->getWisdom());
  CPPUNIT_ASSERT(2 == c->getArmor());
  CPPUNIT_ASSERT(0 == c->getDexterity());
}

/**
 * @brief Test if an item can successfully be removed.
 */
void TestItemDecorator::testRemoveItem(void) {
  c = new Boots(new Belt(c));
  CPPUNIT_ASSERT(5 == c->getArmor());
  CPPUNIT_ASSERT(5 == c->getDexterity());
  CPPUNIT_ASSERT(1 == c->getStrength());
  CPPUNIT_ASSERT(1 == c->getConstitution());
  CPPUNIT_ASSERT(0 == c->getWisdom());
  c = c->remove("boots");
  CPPUNIT_ASSERT(0 == c->getArmor());
  CPPUNIT_ASSERT(0 == c->getDexterity());
  CPPUNIT_ASSERT(1 == c->getStrength());
  CPPUNIT_ASSERT(1 == c->getConstitution());
  CPPUNIT_ASSERT(0 == c->getWisdom());
  c = c->remove("belt");
  CPPUNIT_ASSERT(0 == c->getArmor());
  CPPUNIT_ASSERT(0 == c->getDexterity());
  CPPUNIT_ASSERT(0 == c->getStrength());
  CPPUNIT_ASSERT(0 == c->getConstitution());
  CPPUNIT_ASSERT(0 == c->getWisdom());
}

/**
 * @brief Test to make sure, two item of the same type cannot be
 * worn at the same time.
 * *Note* it should raise an exception.
 */
void TestItemDecorator::testDuplicateItem(void) {
  c = new Helmet(c);
  CPPUNIT_ASSERT_THROW(new Helmet(c), ItemAlreadyWornException);
}

/**
 * @brief Test to see if many items can be worn.
 */
void TestItemDecorator::testManyItem(void) {
  c = new Weapon(new Helmet(new Belt(new Ring(new Boots(c)))));
  CPPUNIT_ASSERT(2 == c->getIntelligence());
  CPPUNIT_ASSERT(10 == c->getArmor());
  CPPUNIT_ASSERT(5 == c->getDexterity());
  CPPUNIT_ASSERT(4 == c->getStrength());
  CPPUNIT_ASSERT(4 == c->getConstitution());
  CPPUNIT_ASSERT(5 == c->getWisdom());
  CPPUNIT_ASSERT(3 == c->getCharisma());
  CPPUNIT_ASSERT(4 == c->getAttack());
  CPPUNIT_ASSERT(4 == c->getDamage());
}

/**
 * @brief Instantiate a Fighter
 */
void TestItemDecorator::setUp(void) {
  c = new Fighter();
}

/**
 * @brief Destruct the character.
 */
void TestItemDecorator::tearDown(void) {
  delete c;
}

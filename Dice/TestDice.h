/**
 * @file TestDice.h
 * @brief Definition of class to test the Dice.
 * @author Samuel RRJ Masuy
 * @version 1.0
 * @date 2016-10-15
 */
#include "DiceRoller.h"

class TestDice : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(TestDice);  // declare the test suite
  CPPUNIT_TEST(testRollSides4);
  CPPUNIT_TEST(testRollSides100);
  CPPUNIT_TEST(testRollSidesLoops);
  CPPUNIT_TEST(testRollModifierPositive);
  CPPUNIT_TEST(testRollModifierNegative);
  CPPUNIT_TEST(testDiceNumbers);
  CPPUNIT_TEST(testDiceResult);
  CPPUNIT_TEST(testDiceSide);
  CPPUNIT_TEST(testInvalidQuery);
  CPPUNIT_TEST(testInvalidQuerySign);
  CPPUNIT_TEST(testInvalidNumberOfLoops);
  CPPUNIT_TEST(testInvalidNumberOfSides);
  CPPUNIT_TEST_SUITE_END();  // end of test suite declaration

 public:
  void setUp(void);
  void tearDown(void);

 protected:
  void testRollSides4(void);
  void testRollSides100(void);
  void testRollSidesLoops(void);
  void testRollModifierPositive(void);
  void testRollModifierNegative(void);
  void testDiceNumbers(void);
  void testDiceResult(void);
  void testDiceSide(void);
  void testInvalidQuery(void);
  void testInvalidQuerySign(void);
  void testInvalidNumberOfLoops(void);
  void testInvalidNumberOfSides(void);

 private:
  DiceRoller* dice_roller;
};

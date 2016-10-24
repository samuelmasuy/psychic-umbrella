/**
 * @file TestDice.cpp
 * @brief Define test cases to test the DiceRoller.
 * @author Samuel RRJ Masuy
 * @version 1.0
 * @date 2016-10-15
 */
#include <iostream>
#include <string>
#include <regex>
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

#include "TestDice.h"
#include "DiceExceptions.h"

// Register for running the test
CPPUNIT_TEST_SUITE_REGISTRATION(TestDice);


/**
 * @test Succesful scenario.
 * Given 1 loop, a dice with 4 sides and no modifier,
 * we expect a value between 1 and 4.
 */
void TestDice::testRollSides4(void) {
  int result = dice_roller->roll("1d4[+0]");
  CPPUNIT_ASSERT(result >= 1 && result <= 4);
}

/**
 * @test Succesful scenario.
 * Given 1 loop, a dice with 100 sides and no modifier,
 * we expect a value between 1 and 100.
 */
void TestDice::testRollSides100(void) {
  int result = dice_roller->roll("1d100[+0]");
  CPPUNIT_ASSERT(result >= 1 && result <= 100);
}

/**
 * @test Succesful scenario.
 * Given 3 loops, a dice with 10 sides and no modifier,
 * we expect a value between 3 and 30.
 */
void TestDice::testRollSidesLoops(void) {
  int result = dice_roller->roll("3d10[+0]");
  CPPUNIT_ASSERT(result >= 3 && result <= 30);
}

/**
 * @test Succesful scenario.
 * Given 1 loop, a dice with 8 sides and +99 modifier,
 * we expect a value between 100 and 108.
 */
void TestDice::testRollModifierPositive(void) {
  int result = dice_roller->roll("1d8[+99]");
  CPPUNIT_ASSERT(result >= 100 && result <= 108);
}

/**
 * @test Succesful scenario.
 * Given 1 loop, a dice with 8 sides and -99 modifier,
 * we expect a value between -98 and 90.
 */
void TestDice::testRollModifierNegative(void) {
  int result = dice_roller->roll("1d8[-99]");
  CPPUNIT_ASSERT(result >= -98 && result <= 90);
}

/**
 * @test Succesful scenario.
 * Given 5 loops, a dice with 8 sides and no modifier,
 * we expect the DiceRoller to have created 5 dice.
 */
void TestDice::testDiceNumbers(void) {
  dice_roller->roll("5d8[-0]");
  std::vector<Dice*> dices = dice_roller->getDices();
  CPPUNIT_ASSERT(dices.size() == 5);
}

/**
 * @test Succesful scenario.
 * Given 3 loops, a dice with 8 sides and no modifier,
 * we expect the first dice  to have a result between
 * 1 and 8.
 */
void TestDice::testDiceResult(void) {
  dice_roller->roll("1d8[-0]");
  int result = dice_roller->getDices().front()->getResult();
  CPPUNIT_ASSERT(result >= 1 && result <= 8);
}

/**
 * @test Succesful scenario.
 * Given 1 loop, a dice with 12 sides and -99 modifier,
 * we expect the number of side on first dice to be 12.
 */
void TestDice::testDiceSide(void) {
  dice_roller->roll("1d12[-99]");
  int sides = dice_roller->getDices().front()->getSides();
  CPPUNIT_ASSERT(sides == 12);
}

/**
 * @test Wrong scenario.
 * Given an invalid query we expect an InvalidQuerySring exception.
 */
void TestDice::testInvalidQuery(void) {
  CPPUNIT_ASSERT_THROW(dice_roller->roll("1invalid4[+0]"), InvalidQuerySring);
}

/**
 * @test Wrong scenario.
 * Given an invalid modifier sign we expect an InvalidQuerySring exception.
 */
void TestDice::testInvalidQuerySign(void) {
  CPPUNIT_ASSERT_THROW(dice_roller->roll("1d4[*0]"), InvalidQuerySring);
}

/**
 * @test Wrong scenario.
 * Given an invalid number of loops in query string we
 * expect an InvalidNumberOfLoops exception.
 */
void TestDice::testInvalidNumberOfLoops(void) {
  CPPUNIT_ASSERT_THROW(dice_roller->roll("-1d4[+0]"), InvalidNumberOfLoops);
}

/**
 * @test Wrong scenario.
 * Given an invalid number of sides we expect an InvalidNumberOfSides exception.
 */
void TestDice::testInvalidNumberOfSides(void) {
  CPPUNIT_ASSERT_THROW(dice_roller->roll("1d3[+0]"), InvalidNumberOfSides);
}

/**
 * @test Setup test cases by creating a new DiceRoller.
 */
void TestDice::setUp(void) {
  dice_roller = new DiceRoller();
}

/**
 * @test Tear down test cases by deleting the DiceRoller.
 */
void TestDice::tearDown(void) {
  delete dice_roller;
}

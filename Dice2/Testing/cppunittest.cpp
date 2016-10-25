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
#include "DiceTest.h"
using namespace CppUnit;

//! Test Class for the Dice class
class DiceTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(DiceTest);
	CPPUNIT_TEST(testDiceRollInputValidity); //test the lower bound of the returned value 
	CPPUNIT_TEST(testDiceRollingBounds); //test the upper bound of the returned value 
	CPPUNIT_TEST(testAdditionZ); // tests the addition of "z" in xdy +z
	CPPUNIT_TEST(testNumberofDice); // tests that increasing the number of dice will also increase the bounds of the results
	CPPUNIT_TEST_SUITE_END();
protected:
	void testDiceRollInputValidity();
	void testDiceRollingBounds();
	void testAdditionZ();
	void testNumberofDice();
};

//! cppunit test cases registration
CPPUNIT_TEST_SUITE_REGISTRATION(DiceTest);

void DiceTest::testAdditionZ() //if the addition works then the range should change, if it falls in that range then the addition works
{
	int result = 0;

	// test that if the string is valid, the result is calculated
	for (int j = 1; j <= 1000; j++) {
		result = Dice::roll("1d4+1");
		CPPUNIT_ASSERT(result >= 2);
		CPPUNIT_ASSERT(result <= 5);
	}
}
//if we increase the number of dice then the range should change, if it falles in the correct range then it works
void DiceTest::testNumberofDice() 
{
	int result = 0;

	// test that if the string is valid, the result is calculated
	for (int j = 1; j <= 1000; j++) {
		result = Dice::roll("2d4");
		CPPUNIT_ASSERT(result >= 2);
		CPPUNIT_ASSERT(result <= 8);
	}
	for (int j = 1; j <= 1000; j++) {
		result = Dice::roll("2d100");
		CPPUNIT_ASSERT(result >= 2);
		CPPUNIT_ASSERT(result <= 200);
	}
}
//! test method for role function of the Dice class 
//! Test Case: the the validity of input string
void DiceTest::testDiceRollInputValidity()
{
	int result = 0;

	// test that if the string is valid, the result is calculated
	result = Dice::roll("4d20");
	CPPUNIT_ASSERT(result > 0);
	result = Dice::roll("3d10+1");
	CPPUNIT_ASSERT(result > 0);

	//test that is the string is invalid, roll() returns -1
	result = Dice::roll("4d");
	CPPUNIT_ASSERT(result == -1);
	result = Dice::roll("d20");
	CPPUNIT_ASSERT(result == -1);
	result = Dice::roll("420");
	CPPUNIT_ASSERT(result == -1);
	result = Dice::roll("4d20+");
	CPPUNIT_ASSERT(result == -1);
}


//! test method for role function of the Dice class 
//! Test Case: the upperbound of all values returned from roll function
void DiceTest::testDiceRollingBounds()
{
	int result = 0;

	for (int j = 1; j <= 1000; j++) {
		result = Dice::roll("1d4");
		CPPUNIT_ASSERT(result >= 1);
		CPPUNIT_ASSERT(result <= 4);
	}
	for (int j = 1; j <= 1000; j++) {
		result = Dice::roll("1d6");
		CPPUNIT_ASSERT(result >= 1);
		CPPUNIT_ASSERT(result <= 6);
	}
	for (int j = 1; j <= 1000; j++) {
		int numbers = Dice::roll("1d8");
		CPPUNIT_ASSERT(result >= 1);
		CPPUNIT_ASSERT(result <= 8);
	}
	for (int j = 1; j <= 1000; j++) {
		int numbers = Dice::roll("1d10");
		CPPUNIT_ASSERT(result >= 1);
		CPPUNIT_ASSERT(result <= 10);
	}
	for (int j = 1; j <= 1000; j++) {
		int numbers = Dice::roll("1d12");
		CPPUNIT_ASSERT(result >= 1);
		CPPUNIT_ASSERT(result <= 12);
	}
	for (int j = 1; j <= 1000; j++) {
		int numbers = Dice::roll("1d20");
		CPPUNIT_ASSERT(result >= 1);
		CPPUNIT_ASSERT(result <= 20);
	}
	for (int j = 1; j <= 1000; j++) {
		int numbers = Dice::roll("1d100");
		CPPUNIT_ASSERT(result >= 1);
		CPPUNIT_ASSERT(result <= 100);
	}

}
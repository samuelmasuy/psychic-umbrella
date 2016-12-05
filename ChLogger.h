#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Observer.h"


using namespace std;
///
///Here is the method to prompt to the user whether they would like to turn the CharacterLog on or off
///
void Characterlog();
///
/// Here is the Character Logger class, this logs the Character Stats in game play throughout every move made, such as Player type, health, items held and attack power.
///
/**
* @brief Here is the Character Logger class, this logs the Character Stats in game play throughout every move made, such as Player type, health, items held and attack power.
*/
class ChLogger {

 public:
  ///
  ///Here we set a log file to outputted
  ///
  static bool setLogFile(const string &filename);
  ///
  ///Here we create the ability to turn the logger off
  ///
  static void logOn();
  ///
  ///Here we create the ability to turn the logger off
  ///
  static void logOff();
  ///
  ///Here we create the ability to check if the logger is on, to be able to log
  ///
  static bool isOn();
  ///
  ///Here to create the ability to write directly to the log with the desired labels
  ///
  static ofstream & fout();
  ///
  ///Here we create the append ability
  ///
  static void append(const string &s);
 private:
  static bool g_logOn;
  static string g_logFileName;
  static ofstream my_fstream;
};

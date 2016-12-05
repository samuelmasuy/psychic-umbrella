#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Observer.h"

using namespace std;
///
///Here is the method to prompt to the user whether they would like to turn the AttackLog on or off
///
void AttackLog();
///
/// Here is the Attack Logger class, this logs the Attack play, such as Monster found, and attack hit points.
///
/**
* @brief Here is the Attack Logger class, this logs the Attack play, such as Monster found, and attack hit points.
*/
class AttLogger {

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

#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "Observer.h"
#include "AttLogger.h"
#include "DiceLogger.h"
#include "ChLogger.h"
#include "Subject.h"

using namespace std;
///
///Here is the method to prompt to the user whether they would like to turn the GameLog on or off
///
void Gamelog();
///
///Here is the method to prompt to the user whether they would like to turn All the logs on or off
///
void AllLogs();
/**
* @brief  Here is the method to prompt to the user whether they would like to turn All the logs on or off
*/
class Logger : public Subject {
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


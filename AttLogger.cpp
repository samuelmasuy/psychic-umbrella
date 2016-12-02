#include "AttLogger.h"


bool AttLogger::g_logOn = true;
string AttLogger::g_logFileName = "log.txt";
ofstream AttLogger::my_fstream;


bool AttLogger::setLogFile(const string &filename) {
  g_logFileName = filename;
  if (my_fstream.is_open())
    my_fstream.close();
  try {
    my_fstream.open(filename, ios_base::app);
  } catch (...) {
    return false;
  }
  return true;
}

void AttLogger::logOn() {
  g_logOn = true;
}


void AttLogger::logOff() {
  g_logOn = false;
}

bool AttLogger::isOn() {
  return g_logOn;
}


ofstream &AttLogger::fout() {
  if (my_fstream.is_open())
    return my_fstream;
  try {
    my_fstream.open(g_logFileName, ios_base::app);
  } catch (...) {
    cout << "Cannot open log file " << g_logFileName << endl;
    exit(1);
  }
  return my_fstream;
}

void AttLogger::append(const string &s) {
  if (g_logOn) {
    if (!my_fstream.is_open()) {
      try {
        my_fstream.open(g_logFileName, ios_base::app);
      } catch (...) {
        cout << "Cannot open log file " << g_logFileName << endl;
        exit(1);
      }
    }
    my_fstream << s;
  }
}

void AttackLog() {
  bool enable = false;
  while (true) {
    string opc;
    getline(cin, opc);
    cout << "Toggle Attack log on/off (o/f)? -->";
    if (opc[0] == 'o' || opc[0] == 'O') {
      enable = true;
      break;
    }
    if (opc[0] == 'f' || opc[0] == 'F') {
      enable = false;
      break;
    } else {
      continue;
    }
  }
  if (enable)
    AttLogger::logOn();
  else
    AttLogger::logOff();
}


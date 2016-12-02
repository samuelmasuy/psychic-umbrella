#include "Logger.h"

bool Logger::g_logOn = true;
string Logger::g_logFileName = "log.txt";
ofstream Logger::my_fstream;


bool Logger::setLogFile(const string &filename) {
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

void Logger::logOn() {
  g_logOn = true;
}


void Logger::logOff() {
  g_logOn = false;
}

bool Logger::isOn() {
  return g_logOn;
}


ofstream &Logger::fout() {
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

void Logger::append(const string &s) {
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


void Gamelog() {
  bool enable = false;
  while (true) {
    string opc;
    getline(cin, opc);
    cout << "Toggle Game log on/off (o/f)? -->";
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
    Logger::logOn();
  else
    Logger::logOff();
}

void AllLogs() {
  bool enable = false;
  while (true) {
    string opc;
    getline(cin, opc);
    cout << "Toggle All logs on/off (o/f)? -->" << endl;
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
    if (enable) {
      Logger::logOn();
      AttLogger::logOn();
      DiceLogger::logOn();
      ChLogger::logOn();
    } else {
      Logger::logOff();
      AttLogger::logOff();
      DiceLogger::logOff();
      ChLogger::logOff();
    }
  }

}

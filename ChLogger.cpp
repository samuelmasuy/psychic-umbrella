#include "ChLogger.h"


bool ChLogger::g_logOn = true;
string ChLogger::g_logFileName = "log.txt";
ofstream ChLogger::my_fstream;


bool ChLogger::setLogFile(const string &filename) {
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

void ChLogger::logOn() {
  g_logOn = true;
}


void ChLogger::logOff() {
  g_logOn = false;
}

bool ChLogger::isOn() {
  return g_logOn;
}


ofstream &ChLogger::fout() {
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

void ChLogger::append(const string &s) {
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
void Characterlog() {
  bool enable = false;
  while (true) {
    string opc;
    getline(cin, opc);
    cout << "Toggle Character log on/off (o/f)? -->";
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
    ChLogger::logOn();
  else
    ChLogger::logOff();
}

#pragma once

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Logger
{
public:
	static bool setLogFile(const string &filename);
	static void logOn();
	static void logOff();
	static bool isOn();
	static ofstream & fout();
	static void append(const string &s);
private:
	static bool g_logOn;
	static string g_logFileName;
	static ofstream my_fstream;
};


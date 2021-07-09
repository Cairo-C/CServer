#pragma once

#include <memory.h>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using std::string;
using std::endl;
using std::cin;
using std::cout;
using std::ofstream;

void err_then_die(const string& msg);
void init_ofs(ofstream& ofs);
void log_write(const string& msg);

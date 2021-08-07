#ifndef __FILE_READ_WRITE__

#define __FILE_READ_WRITE__

#include <fstream>
#include <string>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <array>
using namespace std;

void write_ob(string file, string content);
string read_ob(string file);
#endif // __FILE_READ_WRITE__

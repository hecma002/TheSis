#include <iostream>
#include <string>
#include "queryMysql.h"
using namespace std;

int main(int argc, char **argv)
{
    string empid = argv[1];
    string numofdata = argv[2];
    cout << querrtoDO("select * from patient where (id=" + empid + ");", stoi(numofdata));
    return 0;
}
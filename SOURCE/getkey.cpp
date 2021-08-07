#include <iostream>
#include <string>
#include "queryMysql.h"
using namespace std;

int main(int argc, char **argv)
{
    string id = argv[1];
    string result = ServerQuery("select value from userkey where (empid=" + id + ");", 1);
    result.pop_back();
    cout << result;
    return 0;
}
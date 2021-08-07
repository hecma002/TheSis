#include <iostream>
#include <string>
#include "queryMysql.h"
using namespace std;

int main(int argc, char **argv)
{
    string id = argv[1];
    string numofdata = argv[2];
    string result = querrtoCL("select * from encryptdata where (id=" + id + ");", stoi(numofdata));
    if (result.length() > 10)
        result.pop_back();
    cout << result;
    return 0;
}
#include <iostream>
#include <string>
#include "queryMysql.h"
#include "shellcall.h"
using namespace std;

int main(int argc, char **argv)
{
    int numofUser = 1;

    while (querrtoDO("select empid from staff where (empid=" + to_string(numofUser) + ");", 1) != "NULL")
    {
        string containerkey = shellcall("./keygen " + to_string(numofUser));
        string id = containerkey.substr(0, containerkey.find(" "));
        containerkey.erase(0, containerkey.find(" ") + 1);
        string querr = "insert into userkey values ('" + id + "','" + containerkey + "');";
        ServerQuery(querr, 0);
        numofUser++;
    }

    return 0;
}
#include <iostream>
#include <string>
#include "queryMysql.h"
using namespace std;

string getattlist(string uid)
{
    string result = "";
    for (int i = 2; i <= 7; i++) // 7 is number of attribute
    {
        string att = querrtoDO("select * from staff where (empid=" + uid + ");", i);
        if (att != "NULL")
        {
            result += "|";
            result += att;
        }
    }
    return result;
}

int main(int argc, char **argv)
{
    string uid = argv[1];
    cout << getattlist(uid);
    return 0;
}
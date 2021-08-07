#ifndef __MYSQL_QUERY_
#define __MYSQL_QUERY_

// define information of mysql server
#include <stdlib.h>
#include <iostream>

#include <mysql_connection.h>
#include <mysql_driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>


#define user "root"
#define passwd "Aa123456@"
#define schema "thesis"

using namespace std;

string ServerQuery(string message, int value);
string querrtoDO(string message, int value);
string querrtoCL(string message, int value);
#endif // __MYSQL_QUERY_
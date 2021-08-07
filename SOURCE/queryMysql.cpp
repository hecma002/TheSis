#include "queryMysql.h"

string ServerQuery(string message, int value)
{
  sql::mysql::MySQL_Driver *driver;
  string result = "";
  // string message = "select name from maindata where (uid=4)";
  // int value = 1;

  try
  {
    sql::Connection *conn;
    sql::Statement *stmt;
    sql::ResultSet *res;

    driver = sql::mysql::get_driver_instance();
    conn = driver->connect("tcp://127.0.0.1:3306", user, passwd);
    conn->setSchema(schema);
    stmt = conn->createStatement();
    res = stmt->executeQuery(message.c_str());

    if (value != 0)
    {
      res->beforeFirst();
      if (res->next() == NULL)
        result = "NULL";
      else
        //result = res->getString(value.c_str()).c_str();
        result = res->getString(value).c_str();
    }
    delete res;
    delete conn;
    delete stmt;
  }
  catch (sql::SQLException &e)
  {
    if (e.getErrorCode() != NULL)
    {
      cout << "Query " << message << " error." << endl;
      cout << "# ERR: " << e.what() << endl;
    }
  }
  //cout << result << endl;
  return result;
}

string querrtoDO(string message, int value)
{
  sql::mysql::MySQL_Driver *driver;
  string result = "";
  // string message = "select name from maindata where (uid=4)";
  // int value = 1;

  try
  {
    sql::Connection *conn;
    sql::Statement *stmt;
    sql::ResultSet *res;

    driver = sql::mysql::get_driver_instance();
    conn = driver->connect("tcp://192.168.0.142:3306", "proxy", passwd);
    conn->setSchema(schema);
    stmt = conn->createStatement();
    res = stmt->executeQuery(message.c_str());

    if (value != 0)
    {
      res->beforeFirst();
      if (res->next() == NULL)
        result = "NULL";
      else
        //result = res->getString(value.c_str()).c_str();
        result = res->getString(value).c_str();
    }
    delete res;
    delete conn;
    delete stmt;
  }
  catch (sql::SQLException &e)
  {
    if (e.getErrorCode() != NULL)
    {
      cout << "Query " << message << " error." << endl;
      cout << "# ERR: " << e.what() << endl;
    }
  }
  //cout << result << endl;
  return result;
}

string querrtoCL(string message, int value)
{
  sql::mysql::MySQL_Driver *driver;
  string result = "";
  // string message = "select name from maindata where (uid=4)";
  // int value = 1;

  try
  {
    sql::Connection *conn;
    sql::Statement *stmt;
    sql::ResultSet *res;

    driver = sql::mysql::get_driver_instance();
    conn = driver->connect("tcp://192.168.0.143:3306", "proxy", passwd);
    conn->setSchema(schema);
    stmt = conn->createStatement();
    res = stmt->executeQuery(message.c_str());

    if (value != 0)
    {
      res->beforeFirst();
      if (res->next() == NULL)
        result = "NULL";
      else
        //result = res->getString(value.c_str()).c_str();
        result = res->getString(value).c_str();
    }
    delete res;
    delete conn;
    delete stmt;
  }
  catch (sql::SQLException &e)
  {
    if (e.getErrorCode() != NULL)
    {
      cout << "Query " << message << " error." << endl;
      cout << "# ERR: " << e.what() << endl;
    }
  }
  //cout << result << endl;
  return result;
}
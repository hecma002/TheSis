#include <iostream>
#include <string>
#include "queryMysql.h"
#include "shellcall.h"
using namespace std;

int main(int argc, char **argv)
{
    string policy1 = "ACME";
    string policy2 = "\"(cashier or doctor or nurse)\"";
    string policy3 = "cashier";
    int maxofUser = stoi(querrtoDO("select max(id) from patient", 1));
    int numberofcolumn = 8;
    string ciphertext, containerdata = "", querr = "";
    for (int i = 1; i < maxofUser + 1; i++)
    {
        if (shellcall("./getcell " + to_string(i) + " 1") != "NULL")
        {
            querr = "insert into encryptdata values ('" + to_string(i) + "'";
            if (shellcall("./getcell " + to_string(i) + " 8") == "ACME")
            {
                for (int j = 2; j < 9; j++)
                {
                    ciphertext = shellcall("./encrypt " + to_string(i) + " " + to_string(j) + " " + policy1);
                    querr = querr + ",'" + ciphertext + "'";
                }
            }
            else
            {
                for (int j = 2; j < 9; j++)
                {
                    if (j == 3 || j == 4 || j == 8)
                    {
                        ciphertext = shellcall("./encrypt " + to_string(i) + " " + to_string(j) + " " + policy2);
                        // if (i == 8 && j == 4)
                        //     cout << ciphertext << endl;
                        querr = querr + ",'" + ciphertext + "'";
                    }
                    else if (j == 6 || j == 7)
                    {

                        ciphertext = shellcall("./encrypt " + to_string(i) + " " + to_string(j) + " " + policy3);
                        querr = querr + ",'" + ciphertext + "'";
                    }
                    else
                    {
                        containerdata = shellcall("./getcell " + to_string(i) + " " + to_string(j));
                        querr = querr + ",'" + containerdata + "'";
                    }
                }
            }
            querr += ");";
            //cout<<querr<<endl;
            querrtoCL(querr,0);
        }
    }
    return 0;
}
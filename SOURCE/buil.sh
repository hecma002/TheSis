#!/bin/bash
. ./env
g++ -c queryMysql.cpp -l mysqlcppconn
g++ -c shellcall.cpp
g++ -c file_rw.cpp
ar rvs mylib.a *.o
rm -rf *.o
g++ -o getattlist getattlist.cpp mylib.a -l mysqlcppconn
g++ -o keygen keygen.cpp -std=c++11 -pthread -Wall -g -O2 -DSSL_LIB_INIT -I$(pwd)/include/openabe "-I/usr/local/include" -L$(pwd)/libs/openabe -L$(pwd)/libs "-L/usr/local/lib" mylib.a -lcrypto -lrelic -lrelic_ec -lopenabe
g++ -o importkey importkey.cpp mylib.a -l mysqlcppconn

g++ -o getcell getcell.cpp mylib.a -l mysqlcppconn
g++ -o encrypt encrypt.cpp -std=c++11 -pthread -Wall -g -O2 -DSSL_LIB_INIT -I$(pwd)/include/openabe "-I/usr/local/include" -L$(pwd)/libs/openabe -L$(pwd)/libs "-L/usr/local/lib" mylib.a -lcrypto -lrelic -lrelic_ec -lopenabe
g++ -o getdata getdata.cpp mylib.a -l mysqlcppconn

g++ -o getkey getkey.cpp mylib.a -l mysqlcppconn
g++ -o getcipher getcipher.cpp mylib.a -l mysqlcppconn
g++ -o decrypt decrypt.cpp -std=c++11 -pthread -Wall -g -O2 -DSSL_LIB_INIT -I$(pwd)/include/openabe "-I/usr/local/include" -L$(pwd)/libs/openabe -L$(pwd)/libs "-L/usr/local/lib" mylib.a -lcrypto -lrelic -lrelic_ec -lopenabe
g++ -o openabe openabe.cpp -std=c++11  -pthread -Wall -g -O2 -DSSL_LIB_INIT -I$(pwd)/include/openabe "-I/usr/local/include" -L$(pwd)/libs/openabe -L$(pwd)/libs "-L/usr/local/lib"  mylib.a -lcrypto -lrelic -lrelic_ec -lopenabe -l mysqlcppconn 
g++ -o exportuserdata exportuserdata.cpp -std=c++11  -pthread -Wall -g -O2 -DSSL_LIB_INIT -I$(pwd)/include/openabe "-I/usr/local/include" -L$(pwd)/libs/openabe -L$(pwd)/libs "-L/usr/local/lib"  mylib.a -lcrypto -lrelic -lrelic_ec -lopenabe -l mysqlcppconn 

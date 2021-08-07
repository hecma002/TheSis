#include <iostream>
#include <string>
#include <cassert>
#include <openabe/openabe.h>
#include <openabe/zsymcrypto.h>
#include "shellcall.h"
#include "file_rw.h"
using namespace std;
using namespace oabe;
using namespace oabe::crypto;

int main(int argc, char **argv)
{
    InitializeOpenABE();
    OpenABECryptoContext cpabe("CP-ABE");
    cpabe.importPublicParams(read_ob("param/pubparam.txt"));
    cpabe.importSecretParams(read_ob("param/secparam.txt"));
    string pt1, testexpkey, cipher;
    testexpkey = argv[1];
    string id = argv[2];
    cpabe.importUserKey("key1", testexpkey);
    cout << id << endl;
    for (int i = 2; i < 9; i++)
    {
        cipher = shellcall("./getcipher " + id + " " + to_string(i));
        bool isDecrypt = cpabe.decrypt("key1", cipher, pt1);
        if (isDecrypt)
            cout << pt1 << endl;
        else if (cipher.length() > 100)
            cout << "You cannot read this data" << endl;
        else
            cout << cipher << endl;
    }
    ShutdownOpenABE();

    return 0;
}
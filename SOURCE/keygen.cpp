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
    string id = argv[1];
    string listatt = shellcall("./getattlist " + id);
    cpabe.keygen(listatt, "key");
    string skBlob;
    cpabe.exportUserKey("key", skBlob);
    cout << id << " " << skBlob << endl;

    ShutdownOpenABE();

    return 0;
}
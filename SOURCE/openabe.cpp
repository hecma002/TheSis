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
    string pt1,testexpkey, ct;
    
    testexpkey = argv[1];
    string cipher = argv[2];
    cpabe.importUserKey("key1", testexpkey);
    
    cpabe.decrypt("key1", cipher, pt1);
    cout << pt1 << endl;
    ShutdownOpenABE();

    return 0;
}
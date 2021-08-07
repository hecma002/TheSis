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
    string idofstaff = argv[1];
    string idofpatient = argv[2];
    string numofdata = argv[3];
    string key = shellcall("./getkey " + idofstaff);
    cout<<key<<endl;
    string cipher = shellcall("./getcipher " + idofpatient + " " + numofdata);
    cout<<cipher<<endl;
    InitializeOpenABE();
    OpenABECryptoContext cpabe("CP-ABE");
    cpabe.importPublicParams(read_ob("param/pubparam.txt"));
    cpabe.importSecretParams(read_ob("param/secparam.txt"));
    cpabe.importUserKey("key1", key);
    string plaintext;
    cpabe.decrypt("key1", cipher, plaintext);
    ShutdownOpenABE();
    cout<<plaintext<<endl;
    return 0;
}
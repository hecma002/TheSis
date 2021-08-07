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
  string id = argv[1];
  string numofdata = argv[2];
  string policy = argv[3];
  string data = shellcall("./getcell " + id + " " + numofdata);
  InitializeOpenABE();
  OpenABECryptoContext cpabe("CP-ABE");
  cpabe.importPublicParams(read_ob("param/pubparam.txt"));
  cpabe.importSecretParams(read_ob("param/secparam.txt"));
  string ct;
  cpabe.encrypt(policy, data, ct);
  ShutdownOpenABE();
  cout << ct << endl;
  return 0;
}
#include "file_rw.h"

void write_ob(string file, string content)
{
    ofstream myfile;
    myfile.open(file, ios_base::app);
    if (myfile.is_open())
    {
        myfile << content;
        myfile.close();
    }
    else
        cout << "Can't write, Unable to open file " << file << endl;
}

string read_ob(string file)
{
    string line;
    ifstream myfile(file);
    string result = "";
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            result += line;
        }
        myfile.close();
    }
    else
        return "NULL";
    return result;
}

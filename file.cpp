#include <iostream>
#include <fstream>

using namespace std;

string* read_names(const string& f_name, int len) {
    auto *names = new string[len];

    fstream file;
    file.open(f_name, ios::in);
    if (file.is_open()) {
        for (int i = 0; i < len && !file.eof(); ++i) {
            string name;
            file >> name;
            names[i] = name;
        }
    }

    return names;
}

int main() {
    string *data = read_names("name.txt", 5);
    for (int i = 0; i < 5; ++i) {
        cout << data[i] << endl;
    }

    delete data;
}
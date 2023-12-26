#include <iostream>
#include <fstream>

using namespace std;

string* read_names(string f_name, int len) {
    string *names = new string[len];

    fstream file(f_name, ios::in);
    if (file.is_open()) {
        for (int i = 0; i < len; ++i) {
            string name;
            file >> name;
            names[i] = name;
        }
    }

    return names;
}

void append(string source, string dest, int len) {
    fstream file(source, ios::in);
    if (!file.is_open()) return;

    fstream dest_file(dest, ios::app);
    if (!dest_file.is_open()) return file.close();

    for (int i = 0; i < len; ++i) {
        string name;
        file >> name;
        dest_file << endl << name;
    }

    file.close();
    dest_file.close();
}

int main() {
    append("names.txt", "names2.txt", 5);
    string *names = read_names("names2.txt", 10);

    for (int i = 0; i < 10; ++i) {
        string name = names[i];
        int cnt = 0;

        for (int j = 0; j < 10; ++j) {
            string name2 = names[j];
            if (name == name2) {
                cnt++;
            }
        }

        cout << name << " " << cnt << endl;
    }
}
#include <iostream>
#include <fstream>

using namespace std;

bool write_names(string filename, string *names, int len)
{
    fstream file(filename, ios::out);
    if (!file.is_open())
        return false;

    for (int i = 0; i < len; ++i)
    {
        file << names[i] << endl;
    }

    file.close();
    return true;
}

string *read_names(string f_name, int len)
{
    string *names = new string[len];

    fstream file(f_name, ios::in);
    if (file.is_open())
    {
        for (int i = 0; i < len; ++i)
        {
            string name;
            file >> name;
            names[i] = name;
        }
    }

    return names;
}

void append(string source, string dest, int len)
{
    fstream file(source, ios::in);
    if (!file.is_open()) {
        cerr << "Can't open " << source << endl;
        return;
    }

    fstream dest_file(dest, ios::app);
    if (!dest_file.is_open()) {
        cerr << "Can't open " << dest << endl;
        return file.close();
    }

    for (int i = 0; i < len; ++i)
    {
        string name;
        file >> name;
        dest_file << name << endl;
    }

    file.close();
    dest_file.close();
}

int main()
{
    int SIZE = 5;
    int TOTAL = 10;

    string name_list1[SIZE] = {"Abebe", "Kebede", "Alemu", "John", "Doe"};
    if (!write_names("names.txt", name_list1, SIZE)) {
        cerr << "Can't open names.txt" << endl;
        return 1;
    }


    string name_list2[SIZE] = {"Kebede", "John", "John", "Tom", "Alemu"};
    if (!write_names("names2.txt", name_list2, SIZE)) {
        cerr << "Can't open names2.txt" << endl;
        return 1;
    }

    append("names.txt", "names2.txt", SIZE);
    string *names = read_names("names2.txt", TOTAL);

    for (int i = 0; i < TOTAL; ++i)
    {
        string name = names[i];
        if (name == "")
            continue;

        int cnt = 1;

        for (int j = i + 1; j < TOTAL; ++j)
        {
            string name2 = names[j];
            if (name2 != "" && name == name2)
            {
                cnt++;
                names[j] = "";
            }
        }

        cout << name << " " << cnt << endl;
    }
}
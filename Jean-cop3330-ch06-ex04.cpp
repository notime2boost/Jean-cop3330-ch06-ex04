
 //*  UCF COP3330 Fall 2021 Assignment 5 Solution
 //*  Copyright 2021 Christopher Jean

#include "C:\Users\cjean\Desktop\Cop3330\Cop3330 C++\std_lib_facilities.h"

class Name_value {
public:
    string name;
    int value;
    Name_value(string str, int val)
        :name(str), value(val) { }
};

int main()
try {
    
    cout << "Enter name/value pairs, like 'Chris 22'. Terminate with NoName 0\n";
    string name = "";
    int value = -1;
    vector<Name_value> nv_vec;
    while (cin>>name>>value && !(name=="NoName" && value==0)) {
        for (int i = 0; i<nv_vec.size(); ++i)
            if (name == nv_vec[i].name) error("name occurs twice: ",name);
        nv_vec.push_back(Name_value(name,value));
    }

    
    for (int i = 0; i<nv_vec.size(); ++i) {
        cout << "(" << nv_vec[i].name << ',' << nv_vec[i].value << ")\n";
    }
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}
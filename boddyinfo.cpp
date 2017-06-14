//
// Created by anastasia on 14.06.17.
//
#include <iostream>
#include <fstream>
int BoddyInfo() {
    std::ifstream f("cat /proc/buddyinfo");
    std::string s;
    int i = 0;
    while (getline(f, s)) {  // if (i == 0 || i == 4 || i == 7 || i == 8 || i == 27 || i == 54) {
        std::cout << s << std::endl;
//  }
// i+=1;
    }
    return 0;
}


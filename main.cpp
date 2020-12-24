//
//  main.cpp
//  VirusScanner
//
//  Created by ZQ314159 on 9/7/2563 BE.
//  Copyright © 2563 ZQ314159. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
int check(vector<unsigned char > b,vector<unsigned char>s)
{
    int j=2;
    for(unsigned int i=0;i<b.size();i++)
    {
        if (j == s.size()-1) {
            return 1;
        }
        if (b[i] != s[j]) {
            if (i!= 0 && j != 0 && b[i-1] == s[j-1]) {
                j = 0;
            }
            continue;
        }
        else
        {
            j++;
        }
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    
    
    ifstream in("/.../.../test_virus.dll");  // --------------insert file------------

    string hex_chars("0A 13 6F 29 35 18 70 00 03 35 42 73 9C AD FA 6C AD");
    vector<unsigned char>big{};
    for(unsigned char c; in>>c;)
    {
        big.push_back(c);
    }
    istringstream hex_chars_stream(hex_chars);
    vector<unsigned char> small;

    unsigned int c;
    while (hex_chars_stream >> hex >> c)
    {
        small.push_back(c);
    }
    int q;
    q = check(big, small);
    if (q == 1) {
        cout<<"this file have virus !!!!!!"<<endl;
    }
    else
        cout<<"this file don't have virus"<<endl;
    
    return 0;
}

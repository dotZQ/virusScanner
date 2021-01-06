

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
int check(vector<unsigned char > b,vector<unsigned char>s) // vector b is the vector of binary test file,vector s is refer to the hex virus pattern.
{
    int j=1;
    for(unsigned int i=0;i<b.size();i++)
    {
        //check that if it is equal all of the virus pattern vector
        if (j == s.size()-1) {
            return 1;
        }
        //if the pattern are not the same
        if (b[i] != s[j]) {
            cout<<"small["<<j<<"]="<<s[j]<<endl;
            cout<<"big["<<i<<"]="<<b[i]<<endl;
            
            // if the n-1 element are equal but n elem. are not equal reset the j value
            if (i!= 0 && j != 0 && b[i-1] == s[j-1]) {
                j = 1;
            }
            continue;
        }
        else
        {
            cout<<"small["<<j<<"]= \'"<<s[j]<<"\'  ==  "<<"big["<<i<<"]=\'"<<b[i]<<"\'"<<endl;
            
            // if the elem are similar , increase the j value until it reach the virus pattern size
            j++;
        }
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    
    
    ifstream in("/.../.../test_virus.dll");  // --------------insert file------------

    string hex_chars("0A 13 6F 29 35 18 70 00 03 35 42 73 9C AD FA 6C AD");
    vector<unsigned char>big{};
    //convert binaries to hexadecimal and store it in big vector
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
    
     for (int i=0; i<big.size(); i++) {
        cout<<"big "<<i<<"  "<<big[i]<<endl;
    }
    for (int i=0; i<small.size(); i++) {
        cout<<"small["<<i<<"]="<<small[i]<<endl;
    }
    cout<<endl;
    cout << "output fromm function //////////////" <<endl;
    cout<<endl;
    
    int q;
    q = check(big, small); // if it return 1,it mean this file has virus,else if it return 0,it mean this file don't have virus.
    if (q == 1) {
        cout<<"this file have virus !!!!!!"<<endl;
    }
    else
        cout<<"this file don't have virus"<<endl;
    
    return 0;
}

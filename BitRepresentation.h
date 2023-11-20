//
//  BitRepresentation.h
//  HW6
//
//  Created by Yusuf Erkam Köksal on 25.12.2022.
//

#ifndef BitRepresentation_h
#define BitRepresentation_h

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T>
class BitRepresentation {
    
private:
    T data;
public:
    BitRepresentation(T number);
    BitRepresentation(vector<bool> vec);
    string getBinary();
    string getHexadecimal();
    void setBit(unsigned int location);
    void unsetBit(unsigned int location);
    bool isBitSet(unsigned int location);
    T getNumber();
    ~BitRepresentation() {};
};

#endif /* BitRepresentation_h */

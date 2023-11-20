//
//  main.cpp
//  HW6
//
//  Created by Yusuf Erkam Köksal on 25.12.2022.
//

#include <iostream>
#include "BitRepresentation.h"
using namespace std;

template <class T>
BitRepresentation<T>::BitRepresentation(T number){
    data = number;
}

template <class T>
BitRepresentation<T>::BitRepresentation(vector<bool> vec){
    data = 0;
    int counter = 0;
    for (int i = vec.size() - 1; i < vec.size() && i!= -1; i--) {
        if (vec[i]) {
            data = data | (1 << counter);
        }
        counter ++;
    }
}

template <class T>
string BitRepresentation<T>::getBinary(){
    string result;
    for (int i = sizeof(data) * 8 - 1; i >= 0; i--) {
        int bit = (data >> i) & 1;
        result += to_string(bit);
      }
    return result;
}

template <class T>
string BitRepresentation<T>::getHexadecimal(){
    string hex;
    const char hex_table[] = "0123456789ABCDEF";
    
    while (data != 0) {
        int rmdr = data % 16;
        char digit = hex_table[rmdr];
        hex.push_back(digit);
        data /= 16;
    }

    while (hex.size() != (sizeof(T)*2)) {
        hex.push_back('0');
    }
    
    reverse(hex.begin(), hex.end());
    return hex;
}

template <class T>
void BitRepresentation<T>::setBit(unsigned int location) {
    if (location< sizeof(T)*8){
        int mask = 1 << location;
        data = data | mask;
    }
}

template<class T>
void BitRepresentation<T>::unsetBit(unsigned int location) {
    if (location < sizeof(T)*8) {
        int mask = ~(1 << location);
        data = data & mask;
    }
}

template <class T>
T BitRepresentation<T>::getNumber(){
    return data;
}

template <class T>
bool BitRepresentation<T>::isBitSet(unsigned int location) {
    if (location < sizeof(T)*8) {
        int mask = 1 << location;
        return (data & mask) != 0;
    }
    else{
        return false;
    }
}

int main() {
    
    BitRepresentation<short> s(0);
    s.setBit(0);
    s.setBit(1);
    s.setBit(3);
    short number = s.getNumber();
    cout << number << endl;
    return 0;
}

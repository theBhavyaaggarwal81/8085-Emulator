#include<bits/stdc++.h>
using namespace std;

#ifndef ESSENTIALS
#define ESSENTIALS

bool isValidHex4Digit(string);
bool isValidHex2Digit(string);
bool isInMemoryRange(string);
bool isValidRegister(string);
bool isValidRegisterPair(string);
int registerNumber(string);
string registerName(int);
string flagName(int);
string complement( string);
string increamentMemory(string , string);
string decrementMemory(string , string);
string decimalToHex(int*);
string hexAdd16bit (string ,string ,bool* ,bool );
string hexAdd(string ,string ,bool* ,bool);
void hexToDecimal(string ,int []);
string hexSub16bit(string ,string ,bool* ,bool );
string hexSub(string ,string ,bool* ,bool );

#endif
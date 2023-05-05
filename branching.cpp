#include<bits/stdc++.h>
#include"essentials.h"
using namespace std;

bool JMP(string address, string& pc){
    if(address.length() == 4){
        if(isValidHex4Digit(address) && isInMemoryRange(address)){
            pc = address;
            return true;
        }
    }
    return false;
}

bool JC(string address, string &pc, bool *flag){
    if(address.length() == 4){
        if(isValidHex4Digit(address) && isInMemoryRange(address)){
            if(flag[7]){
                pc = address;
            }else{
                pc = increamentMemory(pc,"0003");
            }
            return true;
        }
    }
    return false;
}

bool JNC(string address, string &pc, bool *flag){
    if(address.length() == 4){
        if(isValidHex4Digit(address) && isInMemoryRange(address)){
            if(!flag[7]){
                pc = address;
            }else{
                pc = increamentMemory(pc,"0003");
            }
            return true;
        }
    }
    return false;
}

bool JZ(string address, string &pc, bool *flag){
    if(address.length() == 4){
        if(isValidHex4Digit(address) && isInMemoryRange(address)){
            if(flag[1]){
                pc = address;
            }else{
                pc = increamentMemory(pc,"0003");
            }
            return true;
        }
    }
    return false;
}

bool JNZ(string address, string &pc, bool *flag){
    if(address.length() == 4){
        if(isValidHex4Digit(address) && isInMemoryRange(address)){
            if(!flag[1]){
                pc = address;
            }else{
                pc = increamentMemory(pc,"0003");
            }
            return true;
        }
    }
    return false;
}
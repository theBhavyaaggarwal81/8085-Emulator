#include<bits/stdc++.h>
#include"essentials.h"
using namespace std;

bool LDA(string operand, string *registers, map<string,string>&memory){
    if(operand.length() == 4){
        if(isValidHex4Digit(operand) && isInMemoryRange(operand)){
            registers[0] = memory[operand];
            return true;
        }
    }
    return false;
}

bool STA(string address,string *registers, map<string,string> &memory){
	if(address.length()==4)
	{
		if(isValidHex4Digit(address) && isInMemoryRange(address)){	
            memory[address]=registers[0];
            return true;
		}	
	}
    return false;
}

bool MOV(string operand1, string operand2, string *registers, map<string,string>&memory){
    if(operand1.length()==1 && operand2.length()==1){
        if(operand1 !="M" && operand2!="M"){
            if(isValidRegister(operand1) && isValidRegister(operand2)){
                registers[registerNumber(operand1)] = registers[registerNumber(operand2)];
                return true;
            }
        }
        else if(operand1 =="M" && operand2!="M"){
            string address = registers[5] + registers[6];
            if(isValidRegister(operand2) && isValidHex4Digit(address) && isInMemoryRange(address)){
                memory[address] = registers[registerNumber(operand2)];
                return true;
            }
        }
        else if(operand1 != "M" && operand2 == "M"){
            string address = registers[5] + registers[6];
            if(isValidHex4Digit(address) && isInMemoryRange(address) && isValidRegister(operand1) && isValidHex2Digit(memory[address])){
                registers[registerNumber(operand1)] = memory[address];
                return true;
            }
        }
    }
    return false;
}


bool MVI(string operand, string data, string *registers, map<string, string>&memory){
    if(operand.length()==1){
        if(operand == "M"){
            string address = registers[5] + registers[6];
            if(isValidHex4Digit(address) && isInMemoryRange(address) && isValidHex2Digit(data)){
                memory[address] = data;
                return true;
            }
        }
        if(isValidRegister(operand) && isValidHex2Digit(data)){
            registers[registerNumber(operand)] = data;
            return true;
        }
    }
    return false;
}

bool LXI (string operand,string address,string *registers,bool *flag,map<string,string>&memory){
	if(operand.length()==1&&address.length()==4){
		if(operand=="M"){
			if(isValidHex4Digit(address) && isInMemoryRange(address)){
				registers[5]=address[0]+address[1];
				registers[6]=address[2]+address[3];
                return true;
			}
		}
		else
		{
			if(isValidRegisterPair(operand)&& isValidHex4Digit(address) && isInMemoryRange(address))
			{
				registers[registerNumber(operand)]=address[0]+address[1];
				registers[registerNumber(operand)+1]=address[2]+address[3];
                return true;
			}
		}	
	}
    return false;
}

bool SHLD(string address,string *registers, map<string,string>&memory){
	if(address.length()==4)
	{
		if(isValidHex4Digit(address)&&isInMemoryRange(address)&&isValidHex4Digit(increamentMemory(address, "0001")))
		{
			memory[address]=registers[6];
			memory[increamentMemory(address, "0001")]=registers[5];
            return true;
		}
	}
    return false;
}

bool LHLD(string address, string *registers, map<string,string>& memory){
	if(address.length()==4)
	{
		if(isValidHex4Digit(address)&& isInMemoryRange(address) &&isValidHex4Digit(increamentMemory(address, "0001")))
		{
			registers[6]=memory[address];
			registers[5]=memory[increamentMemory(address, "0001")];
            return true;
		}
	}
    return false;
}

bool STAX(string operand, string *registers, map<string, string>&memory){
    if(operand.length()==1){
        if(isValidRegisterPair(operand)){
            string address = registers[registerNumber(operand)]+registers[registerNumber(operand)+1];
            if(isValidHex4Digit(address) && isInMemoryRange(address)){
                memory[address] = registers[0];
                return true;
            }
        }
    }
    return false;
}

bool XCHG(string *registers){
    try{
        string temp=registers[3];
	    registers[3]=registers[5];
	    registers[5]=temp;
	    temp=registers[4];
	    registers[4]=registers[6];
	    registers[6]=temp;
        return true;
    }
    catch(...){
        return false;
    }
}
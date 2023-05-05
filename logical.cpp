#include<bits/stdc++.h>
#include"essentials.h"
using namespace std;

bool CMP(string operand, string *registers, bool *flag, map<string, string>&memory){
	if(operand.length()==1)
	{
		if(operand=="M")
		{
		    string address=registers[5]+registers[6];
			if(registers[0]<memory[address]){
                flag[7] = true;
                flag[1] = false;
            }
			else if(registers[0]==memory[address]){
                flag[1] = true;
                flag[7] = false;
            }
			else{
				flag[1]=false;
				flag[7]=false;
			}
            return true;
		}
		else if(isValidRegister(operand) && operand!="A")
		{
			int ind=registerNumber(operand);
    		if(registers[0]<registers[ind]){
                flag[7] = true;
                flag[1] = false;
            }
			else if(registers[0]==registers[ind]){
                flag[1] = true;
                flag[7] = false;
            }
			else{
				flag[1]=false;
				flag[7]=false;
			}
            return true;
		}
	}
    return false;
}

bool CMA(string *registers){
	// not changing the flag!
	try{
		registers[0] = complement(registers[0]);
		return true;
	}
	catch(...){
		return false;
	}
}
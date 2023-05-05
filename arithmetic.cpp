#include<bits/stdc++.h>
#include "essentials.h"
using namespace std;

bool ADD(string operand,string* registers,bool* flag,map<string,string> &memory)
{
	int length=operand.length();
	if(length == 1){
		if(isValidRegister(operand)){
			int registerID = registerNumber(operand);
			registers[0] = hexAdd(registers[registerID],registers[0],flag,true);
			return true;
		}
		else if(operand == "M"){
			string address = registers[5] + registers[6];
			if(isValidHex4Digit(address) && isInMemoryRange(address)){
				registers[0] = hexAdd(memory[address],registers[0],flag,true);	
				return true;			 
			}						
		}
	}
	return false;
}

bool ADI(string operand,string* registers,bool* flag)
{
	int length = operand.length();
	if(length == 2){
		if(isValidHex2Digit(operand)){
			registers[0] = hexAdd(operand,registers[0],flag,true);
			return true;
		}
	}
	return false;
}

bool SUB(string operand,string* registers,bool* flag,map<string,string> &memory)
{
	int length=operand.length();
	if(length == 1){
		if(isValidRegister(operand)){
			int registerID = registerNumber(operand);              
			registers[0] = hexSub(registers[registerID],registers[0],flag,true);
			return true;
		}
		else if(operand == "M"){ 
			string address = registers[5] + registers[6];
			if(isValidHex4Digit(address) && isInMemoryRange(address)){
				registers[0] = hexSub(memory[address],registers[0],flag,true);				
				return true;
			}
		}
	}
	return false;
}

bool INR(string operand,string* registers,bool* flag,map<string,string> &memory)
{
	int length = operand.length();
	if(length == 1){
	
		if(isValidRegister(operand)){
			int registerID = registerNumber(operand);
			registers[registerID] = hexAdd(registers[registerID],"01",flag,false); 
			return true;
		}
		else if(operand == "M"){
			string address = registers[5] + registers[6];
			if(isValidHex4Digit(address) && isInMemoryRange(address)){
				memory[address] = hexAdd(memory[address],"01",flag,false);
				return true;
			}
		}
	}
	return false;
}

bool DCR(string operand,string* registers,bool* flag,map<string,string>& memory){	
	int length = operand.length();
		if(length == 1){
		if(isValidRegister(operand)){
			int registerID = registerNumber(operand);
			registers[registerID] = hexSub(registers[registerID],"01",flag,false);
			return true;
		}
		else if(operand == "M"){
			string address = registers[5] + registers[6];
			if(isValidHex4Digit(address) && isInMemoryRange(address)){
				memory[address] = hexSub(memory[address],"01",flag,false);
				return true;
			}
		}
	}
	return false;
}

bool INX(string operand,string* registers,bool* flag)
{
	int length = operand.length();
	if(length == 1){
		if(isValidRegisterPair(operand)){
			int registerID = registerNumber(operand);
			string data16bit = "";
			string temporary = "";	
			string s1 = "";
			string s2 = "";
			if(isValidHex2Digit(registers[registerID]) && isValidHex2Digit(registers[registerID+1])){
				data16bit = data16bit + registers[registerID] + registers[registerID + 1];
				temporary = increamentMemory(data16bit,"0001");
				s1 = s1 + temporary[0] + temporary[1];		
				s2 = s2 + temporary[2] + temporary[3];
				registers[registerID] = s1; 
				registers[registerID+1] = s2;
				return true;
			}
		}
	}
	return false;
}

bool DCX(string operand,string* registers,bool* flag)
{
	int length = operand.length();
	if(length == 1){
		if(isValidRegisterPair(operand)){
			int registerID = registerNumber(operand);
			string data16bit = "";
			string temporary = "";
			string s1 = "";
			string s2 = "";
			string x="5000";
			if(isValidHex2Digit(registers[registerID]) && isValidHex2Digit(registers[registerID+1])){
				data16bit = data16bit + registers[registerID] + registers[registerID + 1];
				temporary = hexSub16bit(data16bit,x,flag,false);
				s1 = s1 + temporary[0] + temporary[1];		
				s2 = s2 +temporary[2] + temporary[3];
				registers[registerID] = s1;
				registers[registerID+1] = s2;
				return true;
			}
		}
	}
	return false;
}

bool DAD(string operand,string* registers,bool* flag)
{
	int length = operand.length();
	if(length == 1){
		if(isValidRegisterPair(operand)){
			int registerID = registerNumber(operand);
			string data16bit = "";
			string data16bitHL = "";
			string resultant = "";
			if(isValidHex2Digit(registers[registerID]) && isValidHex2Digit(registers[registerID+1])){
				data16bit = data16bit + registers[registerID] + registers[registerID];
				data16bitHL = data16bitHL + registers[5] + registers[6];
				int value16bit[4];
				int value16bitHL[4];
				int carry = 0;
				hexToDecimal(operand,value16bit);
				hexToDecimal(operand,value16bitHL);	  
				for(int i = 3;i>=0;i--){
					int value = value16bit[i] + value16bitHL[i] + carry;
					if(value >= 16)
						flag[7] = true;
					else
						flag[7] = false;
					carry = value / 16;
					value = value % 16;
					if(value>=0 && value<=9)
						resultant = (char)('0' + value) + resultant;
					else{
						switch(value){
							case 10:
								resultant = "A" + resultant;
								break;
							case 11:
								resultant = "B" + resultant;
								break;
							case 12:
								resultant = "C" + resultant;
								break;
							case 13:
								resultant = "D" + resultant;
								break;
							case 14:
								resultant = "E" + resultant;
								break;
							case 15:
								resultant = "F" + resultant;
								break;	
						}
					}
				}
				registers[5] = resultant[0] + resultant[1];
				registers[6] = resultant[2] + resultant[3];	
				return true;
			}
		}
	}
	return false;
}

bool SUI(string operand,string* registers,bool* flag)
{
	if(operand.length() == 2){
		if(isValidHex2Digit(operand)){		
				registers[0] = hexSub(operand,registers[0],flag,true);
				return true;
		}
	}
	return false;
}
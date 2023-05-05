#include<bits/stdc++.h>
// #include"essentials.h"
#include"set.h"
#include"get.h"
#include"arithmetic.h"
#include"logical.h"
#include"branching.h"
#include"load_and_store.h"

using namespace std;


bool execute_statement(string command, bool *flag, string *registers, map<string,string>&memory, string &pc){

    char temp[command.length() + 1];
    copy(command.begin(), command.end(), temp);
    temp[command.length()] = '\0';
	const char *delimiter = " ,";
	char *token = strtok(temp,delimiter);
	vector<string> parts;
	while(token!=NULL){
		parts.push_back(token);
		token = strtok(NULL,delimiter);
	}
    // the parts vector consists of all the instructions, operands or values for each command. Now we need to check and call the respective functions.

    if(parts[0] == "MOV"){
        return MOV(parts[1], parts[2], registers, memory);
    }
    else if(parts[0] == "STAX"){
        return STAX(parts[1], registers, memory);
    }
    else if(parts[0] == "XCHG"){
        return XCHG(registers);
    }
    else if(parts[0] == "ADD"){
        return ADD(parts[1], registers, flag, memory);
    }
    else if(parts[0] == "DCR"){
        return DCR(parts[1], registers, flag, memory);
    }
    else if(parts[0] == "INR"){
        return INR(parts[1], registers, flag, memory);
    }
    else if(parts[0] == "SUB"){
        return SUB(parts[1], registers, flag, memory);
    }
    else if(parts[0] == "INX"){
        return INX(parts[1], registers, flag);
    }
    else if(parts[0] == "DCX"){
        return DCX(parts[1], registers, flag);
    }
    else if(parts[0] == "CMP"){
        return CMP(parts[1], registers, flag, memory);
    }
    else if(parts[0] == "CMA"){
        return CMA(registers);
    }
    else if(parts[0] == "DAD"){
        return DAD(parts[1], registers, flag);
    }
    else if(parts[0] == "ADI"){
        return ADI(parts[1], registers, flag);
    }
    else if(parts[0] == "SUI"){
        return SUI(parts[1], registers, flag);
    }
    else if(parts[0] == "MVI"){
        return MVI(parts[1], parts[2], registers, memory);
    }
    else if(parts[0] == "LDA"){
        return LDA(parts[1], registers, memory);
    }
    else if(parts[0] == "LXI"){
        return LXI(parts[1], parts[2], registers, flag, memory);
    }
    else if(parts[0] == "STA"){
        return STA(parts[1], registers, memory);
    }
    else if(parts[0] == "SHLD"){
        return SHLD(parts[1], registers, memory);
    }
    else if(parts[0] == "LHLD"){
        return LHLD(parts[1], registers, memory);
    }
    else if(parts[0] == "JMP"){
        return JMP(parts[1], pc);
    }
    else if(parts[0] == "JC"){
        return JC(parts[1], pc, flag);
    }
    else if(parts[0] == "JNC"){
        return JNC(parts[1], pc, flag);
    }
    else if(parts[0] == "JZ"){
        return JZ(parts[1], pc, flag);
    }
    else if(parts[0] == "JNZ"){
        return JNZ(parts[1], pc, flag);
    }
    else if(parts[0] == "SET"){
        return set_data(parts[1], parts[2], memory);
    }
    else if(parts[0] == "GET"){
        cout << "Memory at " << parts[1] << " : " << get_data(parts[1], memory) << endl;
        return true;
    }
    return true;
}
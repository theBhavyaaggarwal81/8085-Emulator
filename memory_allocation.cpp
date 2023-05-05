#include<bits/stdc++.h>
#include"essentials.h"
using namespace std;

string allocate_memory(string pc, string instruction){
    string instructionsize1[]={"MOV","LDAX","STAX","XCHG","ADD","DCR","INR","SUB","INX","DCX","CMP","CMA","DAD"};
	string instructionsize2[]={"ADI","SUI","MVI"};
	string instructionsize3[]={"LDA","LXI","STA","SHLD","LHLD","JMP","JC","JNC","JZ","JNZ"};
    string instructiontype4 = "HLT";
    string instructiontype5 = "SET"; // nothing will happen in the memory
    int size;
    size = sizeof(instructionsize1)/sizeof(instructionsize1[0]);
    for(int i=0;i<size;i++){
        if(!instructionsize1[i].compare(instruction)){
            pc = increamentMemory(pc, "0001");
        }
    }

    size = sizeof(instructionsize2)/sizeof(instructionsize2[0]);
    for(int i=0;i<size;i++){
        if(!instructionsize2[i].compare(instruction)){
            pc = increamentMemory(pc, "0002");
        }
    }

    size = sizeof(instructionsize3)/sizeof(instructionsize3[0]);
    for(int i=0;i<size;i++){
        if(!instructionsize3[i].compare(instruction)){
            pc = increamentMemory(pc, "0003");
        }
    }

    if(!instructiontype4.compare(instruction)){
            pc = decrementMemory(pc, "0001");
        }

    return pc;
}
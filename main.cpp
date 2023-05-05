#include<bits/stdc++.h>

#include"execution.h"
#include"essentials.h"
#include"memory_allocation.h"

#define FILE_NAME "sample_prg4.txt"

using namespace std;

int main(){

    // FILE NAME :
    //variables:
    map<string, string>memory;
    vector<string>sequence;
    string registers[]={"00", "00", "00", "00", "00", "00", "00"};
    bool flag[]={false, false, false, false, false, false, false, false};
    string pc;
    string start, end;
    string instruction,command;
    ifstream file(FILE_NAME);

    //entering the starting address :
    // can also be the first line of the program
    getline(file,pc);
    start = pc;

    if(isValidHex4Digit(pc) && isInMemoryRange(pc)){
        cout << endl << endl;
        cout << "\t---\tPROGRAM\t---" << endl;

        //Printing the program :
        while(!file.eof()){
            getline(file,command);
            cout << pc << "\t:  " << command << endl;
            instruction = command.substr(0, command.find(" "));
            pc = allocate_memory(pc, instruction);
        }
        end = pc;
        file.close();
        cout <<endl;

        //Setting the data :
        char option_character;
        string memory_address, data_to_set;
        cout << endl <<  "\tSET DATA : " << endl;
        do{
            cout << "Enter the memory address :" << endl;
            cin >> memory_address;
            cout << "Enter the data to set : " << endl;
            cin >> data_to_set;
            if(!execute_statement("SET "+memory_address+","+data_to_set, flag, registers, memory, pc)){
                cout << "Failed to execute above command!" << endl;
                assert(0);
            }
            cout << endl << "Want to set the values ? (Y/N)" << endl;
            cin >> option_character;
        }while(option_character == 'Y' || option_character == 'y');


        //Executing the program :
        int c=1;
        ifstream file(FILE_NAME);
        pc = "0x2000";
        getline(file,pc);
        while(!file.eof()){
            sequence.push_back(pc);
            getline(file,command);
            memory[pc] = command;
            string delimiter = " ,\0";
            instruction = command.substr(0, command.find(delimiter));
            pc = allocate_memory(pc, instruction);
            if(!execute_statement(command, flag, registers, memory, pc)){
                cout << "Failed to execute above command!" 
                << " (LINE : " << c << ")" << endl;
                assert(0);
            }
            c++;
        }
        cout << endl << endl <<  "\tPROGRAM EXECUTED..! " << endl << endl;
        file.close();


        //Printing Registers :
        cout << endl <<"INDEX\tREGISTER\tVALUE" << endl;
        for(int i=0;i<7;i++){
            cout << i << "\t" << registerName(i) << "\t\t" << registers[i] << endl;
        }

        //Printing the Flag :
        cout << endl << endl <<"INDEX\tFLAG_BIT\tVALUE" << endl;
        for(int i=0;i<8;i++){
            string t = (flag[i])?"TRUE":"FALSE";
            if(flagName(i) == "--")
            t = "--";
            cout << i << "\t" << flagName(i) << "\t\t" << t << endl;
        }

        //Printing the PC :
        cout << endl << endl;

        cout << "PROGRAM COUNTER : " <<endl<< start << " to "<< end << endl <<endl <<endl;

        //Printing the final output
        do{
            cout << "Enter the memory address to check : " << endl;
            cin >> memory_address;
            if(!execute_statement("GET "+memory_address, flag, registers, memory, pc)){
                cout << "Failed to execute above command!" << endl;
                assert(0);
            }
            cout << endl <<  "Want to check more values ? (Y/N)" << endl;
            cin >> option_character;
        }while(option_character == 'Y' || option_character == 'y');
        
        //Greeting message ;
        cout << endl << "\tTHANK YOU!" << endl << endl;
    }
    return 0;
}

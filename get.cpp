#include<bits/stdc++.h>
#include"essentials.h"
using namespace std;

string get_data(string instruction,map<string,string>& memory){
	if(instruction.length()==4)
		if(isValidHex4Digit(instruction))
			return memory[instruction];
	return "0000";
}


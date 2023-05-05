#include<bits/stdc++.h>
#include"essentials.h"
using namespace std;

bool set_data(string instruction1,string instruction2,map<string,string>& memory){
int length1=instruction1.length();
	int length2=instruction2.length();
	if(length1==4&&length2==2)
		if(isValidHex4Digit(instruction1) && isValidHex2Digit(instruction2)){
			memory[instruction1]=instruction2;		
			return true;
		}
	
	return false;
}
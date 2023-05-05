#include<bits/stdc++.h>
using namespace std;

void hexToDecimal(string ,int []);

bool isValidHex4Digit(string hex) {
    // Check if the string has exactly 4 characters
    if (hex.size() != 4) {
        cout << "Invalid Hex Address!" << endl;
        return false;
    }
    for (int i = 0; i < 4; i++) {
        char c = tolower(hex[i]);
        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f'))) {
            cout << "Invalid Hex Address!" << endl;
            return false;
        }
    }
    return true;
}

bool isValidHex2Digit(string hex) {
    // Check if the string has exactly 2 characters
    if (hex.size() != 2) {
        cout << "Invalid Hex Address!" << endl;
        return false;
    }
    for (int i = 0; i < 2; i++) {
        char c = tolower(hex[i]);
        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f'))) {
            cout << "Invalid Hex Address!" << endl;
            return false;
        }
    }
    return true;
}

bool isInMemoryRange(string pc) {
    int num;
    try {
        num = stoi(pc, nullptr, 16);
    } catch (...) {
        return false;
    }
    if(num >= 0x2000 && num <= 0xFFFF){
        return true;
    }
    cout << "Memory address not in range!" << endl;
    return false;
}

bool isValidRegister(string R){
    if(R.size() == 1){
        if(R == "A" || R == "B" || R == "C" || R == "D" || R == "E" || R == "H" || R == "L")
        return true;
    }
    return false;
}


bool isValidRegisterPair(string R){
    if(R.size() == 1){
        if(R == "B" || R == "D" || R == "H")
        return true;
    }
    return false;
}

int registerNumber(string R){
    if(R.size() == 1){
        if(R == "A") return 0;
        else if(R == "B") return 1;
        else if(R == "C") return 2;
        else if(R == "D") return 3;
        else if(R == "E") return 4;
        else if(R == "H") return 5;
        else if(R == "L") return 6;
    }
    return -1;
}

string registerName(int num){
    if(num == 0) return "A";
    else if(num == 1) return "B";
    else if(num == 2) return "C";
    else if(num == 3) return "D";
    else if(num == 4) return"E";
    else if(num == 5) return "H";
    else if(num == 6) return "L";
    return "-";
}

string flagName(int num){
    if(num == 0) return "S";
    else if(num == 1) return "Z";
    else if(num == 2) return "--";
    else if(num == 3) return "AC";
    else if(num == 4) return"--";
    else if(num == 5) return "P";
    else if(num == 6) return "--";
    else if(num == 7) return "CY";
    return "-";
}


string complement(string hexnum){
    int comp;
    int n;
    string result="";
    for(int i=0;i<hexnum.length();i++){
        if(hexnum[i]>='0' && hexnum[i]<='9'){
            n = hexnum[i] - '0';
        }
        else if(hexnum[i]>='A' && hexnum[i]<='F'){
            n = hexnum[i] - 'A'+10;
        }
        comp = 15 - n;
        if(comp>=0 && comp <=9)
            hexnum[i] = comp+'0';
        else if(comp>=10 && comp<=15)
            hexnum[i] = comp + 'A' - 10;
    }
    return hexnum;
}

string increamentMemory(string hex1, string hex2){
    string result;
    int carry = 0;
    for (int i = 3; i >= 0; i--) {
        int num1 = hex1[i] >= 'A' ? hex1[i] - 'A' + 10 : hex1[i] - '0';
        int num2 = hex2[i] >= 'A' ? hex2[i] - 'A' + 10 : hex2[i] - '0';

        int sum = num1 + num2 + carry;
        carry = sum / 16;
        sum %= 16;

        char digit = sum >= 10 ? 'A' + sum - 10 : '0' + sum;
        result = digit + result;
    }

    // If there's a carry at the end, add it as a new most significant digit
    /*
    if (carry > 0) {
        char digit = carry >= 10 ? 'A' + carry - 10 : '0' + carry;
        result = digit + result;
    }*/
    return result;
}

string decrementMemory(string hex1, string hex2){
        string result;
    int borrow = 0;
    for (int i = 3; i >= 0; i--) {
        int num1 = hex1[i] >= 'A' ? hex1[i] - 'A' + 10 : hex1[i] - '0';
        int num2 = hex2[i] >= 'A' ? hex2[i] - 'A' + 10 : hex2[i] - '0';

        int diff = num1 - num2 - borrow;
        borrow = diff < 0 ? 1 : 0;
        diff = (diff + 16) % 16;

        char digit = diff >= 10 ? 'A' + diff - 10 : '0' + diff;
        result = digit + result;
    }
    return result;
}

string decimalToHex(int* deciml)
{
	string hex="";
	int size=sizeof(deciml)/sizeof(deciml[0]);
	for(int i=0;i<size;i++)
	{
		if(deciml[i]>=0 && deciml[i]<=9)
			hex = hex + char('0' + deciml[i]);
		else if(deciml[i]>=10 && deciml[i]<=15)
			hex+=(char)('A'+(deciml[i]-10));
	}
	return hex;
}

string hexAdd16bit (string arg1,string arg2,bool* flag,bool check)
{
	int l1=arg1.length();
	int l2=arg2.length();
	string hex="";
	if(l1==1&&l2==4)
	{
		int value1[4]={0,0,0,0};
		for(int i=0;i<l1;i++)
		{
			if(arg1[i]>='0'&&arg1[i]<='9')
				value1[i]=(int)(arg1[i]-'0');
			else if(arg1[i]>='A'&&arg1[i]<='Z')
				value1[i]=(int)(arg1[i]-'A');
		}
		int i=l1-1;
		value1[l1-1]++;
		while(value1[i]>=16)
		{
			value1[i]=value1[i]%16;
			if(i==0)
			{
				flag[7]=true;
				break;
			}
			else
				value1[--i]++;
		}
		int value=value1[0]*16*16*16+value1[1]*16*16+value1[2]*16+value1[3];
		bitset<16>str(value);
		flag[0]=str[15];
		int parity=str.count();
		if(parity==0)
			flag[1]=true;
		else if(parity%2==0)
			flag[5]=true;
		else if(parity%2==1)
			flag[5]=false;
		for(int i=0;i<l1;i++)
		{
			if(value1[i]>=0&&value1[i]<=9)
				hex+=(char)value1[i];
			else if(value1[i]>=10&&value1[i]<=15)
				hex+=(char)('A'+(value1[i]-10));
		}
	}
	return hex;
}

string hexAdd(string arg1,string arg2,bool* flag,bool carry){
	string resultant = "";
	int variable;
	int value1[5] = {0,0};
	int value2[5] = {0,0};
	int tempAnswer[2];
	hexToDecimal(arg1,value1);
	hexToDecimal(arg2,value2);
	
	tempAnswer[1] = value1[1] + value2[1];
	if(tempAnswer[1]>=16){
	
		tempAnswer[1] = tempAnswer[1]%16;
		value1[0]++;
		flag[3] = true;
		}
	tempAnswer[0] = value1[0] + value2[0];
	if(tempAnswer[0]>=16){
	
		tempAnswer[0] = tempAnswer[0]%16;
		if(carry == true)
			flag[7] = true;
	}
	
	variable = tempAnswer[0]*16 + tempAnswer[1];
	bitset<8> dataInBinary(variable);
	int parity = dataInBinary.count();
	if(parity%2 == 0 && parity!=0)
		flag[5] = true;
	else
		flag[5] = false;
	flag[0] = dataInBinary[7];
	if(parity == 0)
		flag[1] = true;
	
	for(int i = 1;i>=0;--i){
		
		if(tempAnswer[i]>=0 && tempAnswer[i]<=9)
			resultant = char('0' + tempAnswer[i]) + resultant;
		else if(tempAnswer[i]>=10 && tempAnswer[i]<=15)
			resultant = (char)('A'+(tempAnswer[i] - 10)) + resultant;
		}
	return resultant;
}

void hexToDecimal(string pc,int arr[]){
 
	int l = pc.length();
	int p = 0;
	for(int i =0 ;i<l;i++){
	
		if(pc[i]>='0' && pc[i]<='9')
			arr[i] = pc[i] - '0';
		else 
			arr[i] = 10 + (pc[i] - 'A'); 
	}
}

string hexSub16bit(string arg1,string arg2,bool* flag,bool carry){
	string resultant = "";
	int variable;
	int parity;
	int value1[4];
	int value2[4];
	int tempAnswer[4];
	hexToDecimal(arg1,value1);
	hexToDecimal(arg2,value2);
	for(int i=3;i>=0;i--){
		
		if(value1[i] < value2[i]){
			
			tempAnswer[i] = (16 + value1[i]) - value2[i];
			if(i!=0)
				--value1[i-1];
			else{
				if(carry)
					flag[7] = true;
			}
		}
		else
		
			tempAnswer[i] = value1[i] - value2[i];
	}
	variable = tempAnswer[0]*16*16*16 + tempAnswer[1]*16*16 + tempAnswer[2]*16 + tempAnswer[3];
	bitset<16> dataInBinary(variable);
	parity = dataInBinary.count();
	if(parity%2 == 0 && parity!=0)
		flag[5] = true;
	else
		flag[5] = false;
	flag[0] = dataInBinary[7];
	if(parity == 0){

		flag[1] = true;
	}
	else{

		flag[1] = false;
	}
	for(int i = 3;i>=0;--i){
		
		if(tempAnswer[i]>=0 && tempAnswer[i]<=9)
			resultant = char('0'+tempAnswer[i]) + resultant;
		else if(tempAnswer[i]>=10 && tempAnswer[i]<=15)
			resultant = (char)('A'+(tempAnswer[i] - 10)) + resultant;
		}

	return resultant;
	
}

string hexSub(string arg1,string arg2,bool* flag,bool carry){
	string resultant = "";
	int variable;
	int parity;
	int value1[2];
	int value2[2];
	int tempAnswer[2];
	hexToDecimal(arg1,value1);
	hexToDecimal(arg2,value2);

	if(value1[1] < value2[1]){
		
		tempAnswer[1] = (16+value1[1])-value2[1];
		--value1[0];
		}
	else{
		tempAnswer[1] = value1[1] - value2[1];
	}

	if(value1[0] < value2[0]){
	
		if(carry == true)
			flag[0] = true;
			
		tempAnswer[0] = (16+value1[0]-value2[0]);
		}
	else
		tempAnswer[0] = value1[0] - value2[0];
		
	 
	variable = tempAnswer[0]*16 + tempAnswer[1];
	bitset<8> dataInBinary(variable);
	parity = dataInBinary.count();
	if(parity%2 == 0 && parity!=0)
		flag[5] = true;
	else
		flag[5] = false;
	flag[0] = dataInBinary[7];
	if(parity == 0)
		flag[1] = true;
	else
		flag[1] = false;
		
	for(int i = 1;i>=0;--i){
		
		if(tempAnswer[i]>=0 && tempAnswer[i]<=9)
			resultant = char('0'+tempAnswer[i]) + resultant;
		else if(tempAnswer[i]>=10 && tempAnswer[i]<=15)
			resultant = (char)('A'+(tempAnswer[i] - 10)) + resultant;
		}
	return resultant;
	
}
#include<iostream>
#include<vector>

/*
BRAINFUCK INTERPRETOR IN C++


To Quit: 0
*/

int main(){
	//declare array, data pointer, input program, instruction pointer
	int array[30000] = {0};
	int *dp = array;
	char program[1000] = {};
	std::cin>>program;
	char *ip = program;
	std::vector<char*> loopstack = {};

	while(*ip){
		switch(*ip){ 
			case '+':
				dp[0]+=1; //cant exceed array size
				break;
			case '-':
				if(dp[0]>0)
					dp[0]-=1; //cant increment below 0 n
				break;
			case '>':
				*dp++;
				break;
			case '<':
				*dp--;
				break;
			case '.':
				std::cout<<char(*dp);
				break;
			case ',':
				std::cin>>dp[0]; //accepts one byte of data from command-line | strictly accepts ascii, converts to int
				break;
			case '[':
				loopstack.push_back(ip);
				break;
			case ']':
				if(*dp>0){//if dp is non-zero, then iterate
					ip=loopstack.back();
				}
				if(*dp==0){//if dp is zero
					loopstack.pop_back(); //remove the loop intruction
				}
				break;
		}
		*ip++;
	}

	return 0;
}
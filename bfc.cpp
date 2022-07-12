#include<iostream>
#include<string.h>
#include<vector>

int main(int argc, char* argv[]){
	
	//declare array, data pointer, input program, instruction pointer
	int array[30000] = {0};
	int *dp = array;
	//read from file
	char *arg = argv[1];
	char fileName[100];
	char program[1000];
	char *pReadCounter = program;
	int n = strlen(argv[1]);
	for(int i=0; i<n; i++){
	fileName[i] = *arg;
	*arg++;
	}
	//std::cout<<fileName;
	FILE *fp;
	fp = fopen(fileName, "r");
	char ch;
	while((ch=getc(fp))!=EOF){
	*pReadCounter = ch;
	//std::cout<<*pReadCounter;
	*pReadCounter++;
	}
	char *ip = program;
	std::vector<char*> loopstack = {};
	int dpidx=0;

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
				dpidx+=1;
				break;
			case '<':
				*dp--;
				dpidx-=1;
				break;
			case '.':
				std::cout<<char(*dp);
				break;
			case ',':
				std::cin>>array[dpidx]; //accepts one byte of data from command-line | strictly accepts ascii, converts to int
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

	std::cout<<"\n======DEBUG=======";
	std::cout<<"\nArray: ";

	for(int i=0; i<25; i++){
		std::cout<<array[i]<<" ";
	}

	std::cout<<"\nData Pointer: "<<dpidx;
	std::cout<<"\nElement at Data Pointer: "<<*dp<<"\n";
	std::cout<<"==================\n";

	return 0;
}

#include<iostream>
#include<cstring>

using namespace std;

int main () {
	
	
	char numbers[5] = "1234";
	char initialPermutation[24][5] = {"", "", "", "", "", "","", "", "", "", "", "","", "", "", "", "", "","", "", "", "", "", ""};
	char lastPermutation[24][5] = {"", "", "", "", "", "","", "", "", "", "", "","", "", "", "", "", "","", "", "", "", "", ""};
	char stack[5] = "";
	
	int len = sizeof(initialPermutation)/sizeof(initialPermutation[0]);
	
	initialPermutation[0][0] = numbers[0];
	
	for (int i=1; i < sizeof(numbers)-1; i++) { 
		
		int index = 0;
		for (int j = 0; j < len; j++) { 
			
			if(strlen(initialPermutation[j]) == 0) break;
		
			for (int k = 0; k < strlen(initialPermutation[j]) + 1; k++) { 
				
				for (int l = 0; l < k; l++) { 
					stack[l] = initialPermutation[j][l];
				}
				
				stack[k] = numbers[i];
				
				for (int m = k+1; m < strlen(initialPermutation[j]) + 1; m++) {  
					stack[m] = initialPermutation[j][m-1];
				}
			
			
				for(int n = 0; n<strlen(stack); n++) {
					lastPermutation[index][n] = stack[n];
				}
				
				index++;
								
				memset(stack, '\0', sizeof(stack));
				stack[sizeof(stack)]='\0';
			
			}		
		
		}
		
		for(int j = 0; j < len; j++) {
			
			if(strlen(lastPermutation[j]) == 0) break;
			
			for(int k = 0; k<strlen(lastPermutation[j]); k++) {
				initialPermutation[j][k] = lastPermutation[j][k];
			}
		}
		
		for(int j = 0; j < len; j++) {
			memset(lastPermutation[j], '\0', sizeof(lastPermutation[j]));
			stack[sizeof(lastPermutation[j])]='\0';
		}
	}
	
	for (int i = 0; i < len; i++) {
		cout << initialPermutation[i] << endl;
	}

}
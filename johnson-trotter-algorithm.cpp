#include<iostream>
#include<cstring>

using namespace std;

int a = 0;

int fact(int n) {	
	return (n == 1) || (n == 0) ? 1 : n * fact(n-1);
}

void initializeArray (char** generatePermutation, int lenP, int len) {
	
	for (int i = 0; i < lenP; i++) {
		generatePermutation[i] = new char[len];
		memset(generatePermutation[i], '0', len);
		generatePermutation[i][len] = '\0';
	}
	
}

void fillOne (int* input, int len) {
	for (int i=0; i<len; i++) {
		input[i] = 1;
	}
}

int getLargestMobileComponentIndex (char* input, int* direction, int len) {
	
	int largestMobileComponentIndex = -1;
	char largestMobileComponent = '\0';
	
	for(int i = 0; i < len; i++) {
		
		if (direction[i] == 0) {
			
			if (i == (len - 1)) continue;
			
			if ((input[i] > input[i+1]) && (input[i] > largestMobileComponent)) {
				largestMobileComponentIndex = i;
				largestMobileComponent = input[i];
			}
			
		} else {
			
			if (i == 0) continue;

			if ((input[i] > input[i - 1]) && (input[i] > largestMobileComponent)) {
				largestMobileComponentIndex = i;
				largestMobileComponent = input[i];
			}
		}
		a++;
	}
	
	return largestMobileComponentIndex; 
}

void swapElement (char* input, int* direction, int firstIndex, int secondIndex) {	
	char temp1 = input[secondIndex];
	input[secondIndex] = input[firstIndex];
	input[firstIndex] = temp1;
	
	int temp2 = direction[secondIndex];
	direction[secondIndex] = direction[firstIndex];
	direction[firstIndex] = temp2;
}

void reverseDirection (int largestComponentIndex, char* input, int* direction, int len) {
	for (int i = 0; i < len; i++) {
		if(input[largestComponentIndex] < input[i]) {
			direction[i] = !direction[i];
		}
		a++;
	}
}

int main(int argc, char** argv) {
	
	char* input = argv[1];
	int len = strlen(input);
	int lenP = fact(len);
	char** generatePermutation = new char*[lenP];
	
	initializeArray(generatePermutation, lenP, len);
	
	// direction 0 : right arrow
	// direction 1 : left arrow
	int* direction = new int [len];
	fillOne(direction, len);
	
	for (int i = 0; i < len; i++) generatePermutation[0][i] = input[i]; 
	
	cout << generatePermutation[0] << endl;
	
	int index = 1;
	int largestComponentIndex = getLargestMobileComponentIndex(input, direction, len);
	char mobileComponent = input[largestComponentIndex];
	
	while (largestComponentIndex != -1) {

		if (direction[largestComponentIndex] == 0) {
			if (largestComponentIndex != (len - 1)) {
				swapElement(input, direction, largestComponentIndex, largestComponentIndex+1);
				largestComponentIndex += 1;
			}
		}
		else {
			if (largestComponentIndex != 0) {                                    
				swapElement(input, direction, largestComponentIndex, largestComponentIndex-1);
				largestComponentIndex -= 1;
			}	
		}
		
		for (int j = 0; j < len; j++) {
			generatePermutation[index][j] = input[j];
		}
				
		reverseDirection(largestComponentIndex, input, direction, len);
		largestComponentIndex = getLargestMobileComponentIndex(input, direction, len);
		mobileComponent = input[largestComponentIndex];
		index++;
		a++;
		
	}
	
	for (int i = 0; i < lenP; i++) {
		cout << generatePermutation[i] << endl;
	}
	
	cout << "Number of loop for " << len << " permutation : " << a << endl;
 
}
#include<iostream>
#include<cstring>

using namespace std;

int a = 0;

int fact(int n) {	
	return (n == 1) || (n == 0) ? 1 : n * fact(n-1);
}

void initializeArray (char** generatedPermutation, int lenP, int length) {
	
	for (int i = 0; i < lenP; i++) {
		generatedPermutation[i] = new char[length];
		memset(generatedPermutation[i], '0', length);
		generatedPermutation[i][length] = '\0';
	}
	
}

void fillOne (int* input, int length) {
	for (int i=0; i<length; i++) {
		input[i] = 1;
	}
}

int getLargestMobileComponentIndex (char* input, int* direction, int length) {
	
	int largestMobileComponentIndex = -1;
	char largestMobileComponent = '\0';
	
	for(int i = 0; i < length; i++) {
		
		if (direction[i] == 0) {
			
			if (i == (length - 1)) continue;
			
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

void swapElements (char* input, int* direction, int firstIndex, int secondIndex) {	
	char temp1 = input[secondIndex];
	input[secondIndex] = input[firstIndex];
	input[firstIndex] = temp1;
	
	int temp2 = direction[secondIndex];
	direction[secondIndex] = direction[firstIndex];
	direction[firstIndex] = temp2;
}

void reverseDirection (int largestComponentIndex, char* input, int* direction, int length) {
	for (int i = 0; i < length; i++) {
		if(input[largestComponentIndex] < input[i]) {
			direction[i] = !direction[i];
		}
		a++;
	}
}

int main(int argc, char** argv) {
	
	char* input = argv[1];
	int length = strlen(input);
	int lenP = fact(length);
	char** generatedPermutation = new char*[lenP];
	
	initializeArray(generatedPermutation, lenP, length);
	
	// direction 0 : right arrow
	// direction 1 : left arrow
	int* direction = new int [length];
	fillOne(direction, length);
	
	for (int i = 0; i < length; i++) generatedPermutation[0][i] = input[i]; 
	
	int index = 1;
	int largestComponentIndex = getLargestMobileComponentIndex(input, direction, length);
	char mobileComponent = input[largestComponentIndex];
	
	while (largestComponentIndex != -1) {

		if (direction[largestComponentIndex] == 0) {
			if (largestComponentIndex != (length - 1)) {
				swapElements(input, direction, largestComponentIndex, largestComponentIndex+1);
				largestComponentIndex += 1;
			}
		}
		else {
			if (largestComponentIndex != 0) {                                    
				swapElements(input, direction, largestComponentIndex, largestComponentIndex-1);
				largestComponentIndex -= 1;
			}	
		}
		
		for (int j = 0; j < length; j++) {
			generatedPermutation[index][j] = input[j];
		}
				
		reverseDirection(largestComponentIndex, input, direction, length);
		largestComponentIndex = getLargestMobileComponentIndex(input, direction, length);
		mobileComponent = input[largestComponentIndex];
		index++;
		a++;
		
	}
	
	for (int i = 0; i < lenP; i++) {
		cout << generatedPermutation[i] << endl;
	}
	
	cout << "Number of loop for " << length << " permutation : " << a << endl;
 
}
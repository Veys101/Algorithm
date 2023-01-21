#include<iostream>
#include<cstring>

using namespace std;

void fillEmpty (char* array, int len) {
	memset(array, '\0', len);
	array[len]='\0';
}

void initializeArray (char** &array, int lengthArray, int lengthRow) {
	
	array = new char*[lengthArray];
	
	for (int i=0; i<lengthArray; i++) {
		array[i] = new char [lengthRow]; 
		fillEmpty(array[i], lengthRow);
	}
	
}

int fact (int number) {
	
	int result = 1;
	
	while (number > 1) {
		result *= number;
		number--;
	}
	
	return result;
}

void swapElements (char* &elements, int i, int j) {
	
	char temp = elements[i];
	elements[i] = elements[j];
	elements[j] = temp;
}


int main(int argc, char** argv) {

	char* array = argv[1];
	
	int length = strlen(array);
	int permutationLength = fact(length);
	
	char** generatedPermutation;
    initializeArray (generatedPermutation, permutationLength, length);

	int c[length] = {0};
	
	int i = 0, a=0;
	int index = 1;
	
	for(int k=0; k<length; k++) generatedPermutation[0][k] = array[k];
		
	while (i < length) {
		
		if (c[i] < i) {
			
			if (i % 2 == 0) {
				swapElements(array, 0, i);
			} else {
				swapElements(array, c[i], i);
			}

			for (int j=0; j<length; j++) {
				generatedPermutation[index][j] = array[j];
				a++;
			}
			
			c[i] = c[i] + 1;
			i = 0;
			index++;
		} else {
			c[i] = 0;
			i++;
			a++;
		}	
				
	} 
		
	for (int k = 0; k < permutationLength; k++) {
		cout << generatedPermutation[k] << endl;
	}
	
	cout << "Number of loop for " << length << " permutation : " << a << endl;
}
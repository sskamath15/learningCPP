#include <iostream>
#include <cstdio>

using namespace std;

/*
This code almost certainly does not follow best practices in programming.

This code is intended to compute a histogram of 3-mers in a sequence of 
characters with the alphabet {A, C, G, T}. The code makes a distinction 
between 3-mers of the form AAA and TTT, i.e. base pairs.

The input is a single string of the sequence whose 3-mers must be counted.

The output is presented in the format
XYZ #
XYZ #
.	.
.	.
.	.

where XYZ stands for a 3-mer and # stands for the number of occurrences of 
the 3-mer in the sequence. Only 3-mers which occur in the sequence are listed 
in the output.
*/

int power(int base, int exponent){
	
	/*
	Didn't want to use the power function built into the library. I wrote this 
	for practice.
	*/
	
	int i, value = 1;
	if (exponent == 0)
		return value;
	for (i = 0; i < exponent; ++i)
		value *= base;

return value;
}

int letterToNumber (char &c){
	/*
	Utility function to code A, C, G, and T in base 4.
	*/
	if (c == 'A')
		return 0;
	else if (c == 'C')
		return 1;
	else if (c == 'G')
		return 2;
	else
		return 3;

}

char numberToLetter (int &i){
	/*
	Utility function to revert the number to a letter.
	*/
	if (i == 0)
		return 'A';
	else if (i == 1)
		return 'C';
	else if (i == 2)
		return 'G';
	else
		return 'T';
}

int arrayIndex (char &first, char &second, char &third){
	/*
	The counts of each 3-mer are stored in an array of length 64. This 
	function computes the appropriate index for a 3-mer.
	*/
	int i, index = 0;
	char arr[3] = {third, second, first};
		
	for (i = 0; i < 3; ++i)
		index = index + (letterToNumber(arr[i])*power(4,i));

return index;
}

void indexTo3Mer(int arr[3], char seq[3], int index){
	/*
	Utility function to help print the histogram.
	*/
	int i = 0;
	for (i = 2; i >= 0; --i){
		arr[i] = index % 4;
		seq[i] = numberToLetter(arr[i]);
		index = index / 4;
	}
}

int main() {
	
	/*
	The first three elements of a sequence are read into three char variables.
	Then, each letter in the input is read one-by-one and the 3-mer count is 
	updated.
	*/
	
	char first, second, third;	
	
	cin >> first >> second >> third;
	
	int index = arrayIndex(first, second, third);
	int counts[64], iter;
	
	for (iter = 0; iter < 64; ++iter)
		counts[iter] = 0;
	
	counts[index] += 1;
	
	// Pre-loop set up.
	first = second;
	second = third;
		
	while (cin >> third){
		index = arrayIndex(first, second, third);
		counts[index] += 1;
		first = second;
		second = third;
	}
	
	
	int arr[3];
	char seq[3];
	//Printing the histogram
	for (iter = 0; iter < 64; ++iter){
		if (counts[iter] == 0)
			continue;
		
		indexTo3Mer(arr, seq, iter);
		cout << seq[0] << seq[1] << seq[2] << " " << counts[iter] << endl;
	}
	
return 0;
}

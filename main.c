#include <stdio.h>
#include <stdlib.h>

#define dataType char*

#include "Sorter.h"

void callback(dataType* element) {
	printf("%s\n", *element);
}

dataType* reader(int* x) {
	*x = 10;
	dataType* applesSauce = (void*) malloc(*x * sizeof(dataType));
	applesSauce[0] = "Z";
	applesSauce[1] = "Y";
	applesSauce[2] = "X";
	applesSauce[3] = "A";
	applesSauce[4] = "C";
	applesSauce[5] = "G";
	applesSauce[6] = "I";
	applesSauce[7] = "K";
	applesSauce[8] = "B";
	applesSauce[9] = "M";
	return applesSauce;
}

int orderer(dataType* x, dataType* y) {
	int leftSum = 0;
	int rightSum = 0;

	int i = 0;
	while((*x)[i] != '\0') {
		leftSum += (*x)[i++];
	}

	i = 0;

	while((*y)[i] != '\0') {
		rightSum += (*y)[i++];
	}

	return leftSum - rightSum;
}

int main() {
	//data* sorter = createNewSorter((void*)callback, (void*)reader, (void*)orderer);
	freeSorter(sortAndCallback(createNewSorter((void*)callback, (void*)reader, (void*)orderer)));

	return 0;
}
#ifndef SORTERC
#define SORTERC

#include "Sorter.h"

data* createNewSorter(callback_function callback, read_function input) {
	data* this = (data*) malloc(sizeof(data));
	this->reader = input;
	this->callback = callback;
	this->size = 0;
	dataType* arr = this->reader(this->size);
	this->array = arr;
}

data* sortData(data* this) {
	quickSort(this->arr, 0, this->size - 1);
}

void quickSort(dataType* array, int low, int high, ordering_function order) {
	if(high > low) {
		int p = partition(array, low, high, order);
		quickSort(array, low, p - 1, order);
		quickSort(array, p + 1, high, order);
	}
}

int partition(dataType* array, int low, int high, ordering_function order) {
	int pivotVal = array[(high + low) / 2];
	while(low < high) {
		if(order(array[low], pivotVal) < 0) {
			low++;
		} else if(order(array[high], pivotVal) > 0) {
			high--;
		} else {
			dataType temp = array[low];
			array[low] = array[high];
			array[high] = temp;
			if(!order(array[low], pivotVal) && !order(array[high], pivotVal)) {
				low++;
			}
		}
	}
	return high;
}

data* useCallBack(data* this) {
	if(this != NULL) {
		int i;
		for(i = 0; i < this->size; i++) {
			this->callback(&this->array[i]);
		}
	}
	return this;
}

data* sortAndCallback(data* this) {
	if(this != NULL) {
		this->sortData(this);
		this->useCallBack(this);
	}
	return this;
}

void freeSorter(data* this) {
	if(this != NULL && this->array != NULL) {
		free(this->array);
	} else if(this != NULL) {
		free(this);
	}
}

#endif
#ifndef SorterH
#define SorterH

#ifndef dataType
#define dataType int
#endif

/*
	This function will be called on each element within the sorter.
	The parameter of the function must be a pointer to an element 
	of type dataType.
*/
typedef void (*callback_function)(dataType* x);

/*
	This function is where the sorter will populate it's data from.
	The parameter of the function must be a pointer to an integer,
	and after function is called the dereferenced value of that pointer
	must be the value of the size of the array. 
*/
typedef dataType* (*read_function)(int* size);

/*
	This function will define the ordering of the data.
	Both parameters are pointers to the dataType.
*/
typedef int (*ordering_function)(dataType* x, dataType* y);

typedef struct _data {
	dataType* array;
	int size;
	callback_function callback;
	read_function reader;
} data;

/*
	Creates a new sorter object which will populate from second argument,
	and call the function of the first argument.
*/
data* createNewSorter(callback_function callback, read_function input);

/*
	Sorts the data of this.
*/
data* sortData(data* this);

void quickSort(dataType* array, int low, int high, ordering_function order);

int partition(dataType* array, int low, int high, ordering_function order);


/*
	Calls the callback method for all elements.
*/
data* useCallBack(data* this);

/*
	Calls both the sort and callback method of this.
*/
data* sortAndCallback(data* this);

/*
	Frees mem of sorter.
*/
void freeSorter(data* this);

#endif
#include <stdio.h>
#include <stdlib.h>

// Dynamic Size Array
// By YCH 2018.11.19
// Written live in Review Recitation Class
// May be some errors...
// Let me know if there is any...
// Good luck with your midterm 2

typedef struct
{
	int* array;
	int capacity;
	int size;
} DSA;

void init(DSA* dsa)
{
	dsa->array = malloc(sizeof(int));
	dsa->capacity = 1;
	dsa->size = 0;
}


int num_element(DSA* dsa)
{
	return dsa->size;
}

int available_capacity(DSA* dsa)
{
	return dsa->capacity - dsa->size;
}

void push_back(DSA* dsa, int x)
{
	if (dsa->size == dsa->capacity)
	{
		int * new_array = malloc(2*dsa->capacity*sizeof(int));
		for (int i = 0; i < dsa->size; i++)
			new_array[i] = dsa->array[i];
		free(dsa->array);
		dsa->array = new_array;
	}
	dsa->array[dsa->size] = x;
	dsa->size++;
}

int is_empty(DSA* dsa)
{
	if (dsa->size == 0)
		return 1;
	return 0;
}

void pop_back(DSA* dsa)
{
	if (is_empty(dsa))
	{
		printf("Error! The array is empty!\n");
		return;
	}
	printf("%d\n", dsa->array[dsa->size - 1]);
	dsa->size--;
}

int sum(DSA* dsa)
{
	int sum = 0;
	for (int i = 0; i < dsa->size; i++)
		sum += dsa->array[i];
	return sum;
}

void reserve(DSA* dsa, int s)
{
	int* new_array = malloc(s * sizeof(int));
	for (int i = 0; i < dsa->size; i++)
		new_array[i] = dsa->array[i];
	free(dsa->array);
	dsa->array = new_array;
}


int main()
{
	// Leave it to you to test...
	return 0;
}

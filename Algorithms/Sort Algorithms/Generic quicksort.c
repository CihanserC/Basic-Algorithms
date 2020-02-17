#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE 10
#define NAME_SIZE 100

typedef struct Student {
	int id;
	char name[NAME_SIZE];
} STUDENT_t, *STUDENT;

//function to fill the contents of a student
void fill_STUDENT(void *a, void *b) {
	STUDENT p = (STUDENT) a;
	int i = *((int *) b);
	p->id = i;
	sprintf(p->name, "%x", i);
	//itoa(p->id, p->name, 2);
}

//function to print a student
void print_STUDENT(void *a) {
	STUDENT p = (STUDENT) a;
	printf("%d %s\n", p->id, p->name);
}

//function to fill an integer
void fill_int(void *a, void *b) {
	int *p = (int *) a;
	int i = *((int *) b);
	*p = i;
}

//function to print an integer
void print_int(void *a) {
	int *p = (int *) a;
	printf("%d\n", *p);
}

//function to compare two integers
int xcompare_int(void *a, void *b) {
	int *p = (int *) a;
	int *q = (int *) b;

	return *p <= *q;

}

//function to compare two students
int xcompare_STUDENT(void *a, void *b) {
	STUDENT p = (STUDENT) a;
	STUDENT q = (STUDENT) b;

	return strcmp(p->name, q->name) <= 0;
}

int partition(void **array, int start, int end, int (*compare)(void *a, void *b)) {

	int pi, j;
	void *temp;
	void *pivot = array[end];
	pi = start;
	for (j = start; j < end; j++) {
		if ((*compare)(array[j], pivot)) {
			temp = array[pi];
			array[pi] = array[j];
			array[j] = temp;
//			swap(&array[i],&array[j]);
			pi = pi + 1;
		}
	}
	temp = array[pi];
	array[pi] = array[end];
	array[end] = temp;
//	swap(&array[pi],&array[high]);
	return pi;
}

void xquicksort(void **array, int start, int end, int (*compare)(void *a, void *b)) {
	int p;
	if (start < end) {

		p = partition(array, start, end, compare);
		xquicksort(array, start, p - 1, compare);
		xquicksort(array, p + 1, end, compare);
	}
}

void fill_array_generic_random(void **arr, int size, unsigned int seed, void (*fill)(void *a, void *b)) {
	int i, r;
	srand(seed);
	for (i = 0; i < size; i++) {
		r = rand();
		(*fill)(arr[i], (void *) &r);
	}
}

//function to print an array of generic values
void print_array_generic(void **arr, int size, void (*print)(void *)) {
	int i;
	for (i = 0; i < size; i++) {
		(*print)(arr[i]);
	}
}

//an example using structured datatype
void main_STUDENT() {
	STUDENT_t a[ARRAY_SIZE];
	STUDENT p[ARRAY_SIZE];
	int size = ARRAY_SIZE;
	int start = 0;
	int i;

	for (i = 0; i < size; i++) {
		p[i] = &a[i];
	}

	printf("---before---\n");
	print_array_generic((void **) p, size, print_STUDENT);

	fill_array_generic_random((void **) p, size, time(NULL), fill_STUDENT);

	printf("---after---\n");
	print_array_generic((void **) p, size, print_STUDENT);

	xquicksort((void **) p,start,size-1,xcompare_STUDENT);

	printf("---after---sort\n");
	print_array_generic((void **) p, size, print_STUDENT);
}

//an example using primitive datatype
void main_int() {
	int a[ARRAY_SIZE];
	int *p[ARRAY_SIZE];
	int size = ARRAY_SIZE;
	int i;

	for (i = 0; i < size; i++) {
		p[i] = &a[i];
	}

	printf("---before---\n");
	print_array_generic((void **) p, size, print_int);

	fill_array_generic_random((void **) p, size, time(NULL), fill_int);

	printf("---after---\n");
	print_array_generic((void **) p, size, print_int);

	xquicksort((void **) p, 0, size - 1, xcompare_int);

	printf("---after---quick---sort\n");
	print_array_generic((void **) p, size, print_int);
}

//main
int main() {
	main_STUDENT();
	main_int();

	return 0;
}

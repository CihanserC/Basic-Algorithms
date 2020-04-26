#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 10
#define NAME_SIZE 100

typedef struct Student {
	int id;
	char name[NAME_SIZE];
} STUDENT_t, *STUDENT;

//function to fill the contents of a student
void fill_STUDENT(void *a, void *b)
{
	STUDENT p = (STUDENT)a;
	int i = *((int *)b);
	p->id = i;
	//itoa(p->id, p->name, 2);
	sprintf(p->name,"%x",p->id);
}

//function to print a student
void print_STUDENT(void *a)
{
	STUDENT p = (STUDENT)a;
	printf("%d %s\n", p->id, p->name);
}

//function to fill an integer
void fill_int(void *a, void *b)
{
	int *p = (int *)a;
	int i = *((int *)b);
	*p = i;
}

//function to print an integer
void print_int(void *a)
{
	int *p = (int *)a;
	printf("%d\n", *p);
}

//function to fill an array of generic values
void fill_array_generic_random(void **arr, int size, unsigned int seed, void (*fill)(void *a, void *b))
{
	int i, r;
	srand(seed);
	for(i=0; i<size; i++) {
		r = rand();
		(*fill)(arr[i], (void *)&r);
	}
}

//function to print an array of generic values
void print_array_generic(void **arr, int size, void (*print)(void *))
{
	int i;
	for(i=0; i<size; i++) {
		(*print)(arr[i]);
	}
}

void xsort(void **array, int size, int (*compare)(void * a, void * b))
{
    int i,j,k;
    int base;
    
    unsigned char *ptr = base;
    unsigned char tmp[256];

    if(num < 2 || width == 0)
        return;

    for(i = num-1; i >= 0; i--)
    {
        for(j = 1; j <= i; j++)
        {
            k = compar((void*)(ptr + width * (j-1)), (void*)(ptr + width * j));
            if(k > 0)
            {
                memcpy(tmp, ptr + width*(j-1), width);
                memcpy(ptr + width*(j-1), ptr + width*j, width);
                memcpy(ptr + width * j, tmp, width);
            }
        }
    }
}

int compare_int( void *a,  void *b)
{
    int *c = (int *)a;
    int *d = (int *)b;
    return *c - *d;
}

int compare_string( void *a,  void *b)
{
    const char *c = (char *)a;
    const char *d = (char *)b;
    return strcmp(c, d);
}

int compare_STUDENTID(void *a,void *b){
	STUDENT p=(STUDENT) a;
	STUDENT q=(STUDENT) b;
	return p->id > q->id ;
}

//an example using structured datatype
void main_STUDENT()
{
	STUDENT_t a[ARRAY_SIZE];
	STUDENT p[ARRAY_SIZE];
	int size = ARRAY_SIZE;
	int i;

	for(i=0; i<size; i++) {
		p[i] = &a[i];
	}

	printf("---before---\n");
	print_array_generic((void **)p, size, print_STUDENT);

	fill_array_generic_random((void **)p, size, 123456789, fill_STUDENT);

	printf("---after---\n");
	print_array_generic((void **)p, size, print_STUDENT);
	
	xsort((void **)p, size,compare_STUDENTID);
}

//an example using primitive datatype
void main_int()
{
	int a[ARRAY_SIZE];
	int *p[ARRAY_SIZE];
	int size = ARRAY_SIZE;
	int i;

	for(i=0; i<size; i++) {
		p[i] = &a[i];
	}

	printf("---before---\n");
	print_array_generic((void **)p, size, print_int);

	fill_array_generic_random((void **)p, size, 987654321, fill_int);

	printf("---after---\n");
	print_array_generic((void **)p, size, print_int);
}

//main
int main()
{
	main_STUDENT();
	main_int();

	return 0;
}


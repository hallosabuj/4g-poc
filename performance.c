#include<stdio.h>
#include <time.h>
#define LEN 300000

//Performance test for open_memstream
void func1(){
	long i;
	for(i=0;i<LEN;i++){
		FILE *stream;
		char *buf;
		size_t len;
   		stream = open_memstream (&buf, &len);
    		int size=fprintf (stream, "my name is %s mondal and age is %d","sabuj",23);
		char name[size+1];
        	sprintf(name,"my name is %s mondal and age is %d","sabuj",23);
        }
}

//Performance test for fopen
void func2(){
	long i;
	for(i=0;i<LEN;i++){
		FILE *fp;
		fp=fopen("/dev/null", "w");
		int size=fprintf(fp,"my name is %s mondal and age is %d","sabuj",23);
		char name[size+1];
		sprintf(name,"my name is %s mondal and age is %d","sabuj",23);
	}
}

//Performance test for snprintf
void func3(){
	long i;
	for(i=0;i<LEN;i++){
		char *ptr=NULL;
		int size=snprintf(ptr, 0, "my name is %s mondal and age is %d","sabuj",23);
		char name[size+1];
		sprintf(name,"my name is %s mondal and age is %d","sabuj",23);
	}
}

int main(){
	
	clock_t start, end;
	double time_taken;
	
	start = clock();
	func1();
	end =clock();
	time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("fun1() took %f seconds to execute \n", time_taken);
	
	/*start = clock();
	func2();
	end =clock();
	time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("fun2() took %f seconds to execute \n", time_taken);
	
	start = clock();
	func3();
	end =clock();
	time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("fun3() took %f seconds to execute \n", time_taken);*/
	
	return 0;
}

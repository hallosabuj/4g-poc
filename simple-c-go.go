//Example 1] Calling standard C function from Go.
package main
/*
#include <stdio.h>
#include <stdlib.h>
*/
import "C"
import "fmt"
func main() {
	fmt.Println("You are inside Go code")
	go2c := "Printed from C.printf"
        var cstr *C.char = C.CString(go2c)
        //defer C.free(unsafe.Pointer(cstr))
        C.puts(cstr)
	C.fflush(C.stdout)
}

//========================================================================
//Example 2] Calling a C function(user defined) defined in Go file from Go
package main
/*
#include<stdio.h>
void callFromC(void){
	printf("In c code\n");
    	fflush(stdout);
}
*/
import "C"
import "fmt"
func main() {
	fmt.Println("Inside GO code")
	C.callFromC()
}

//========================================================================
//Example 3] Calling a C function(user defined) defined in External .c file(present in same directory) from Go
// C file --> hello.c
#include<stdio.h>
void print_hello() {
	printf("Hello World!!!\n");
}
// Go file --> Go2C.go
package main
/*
#include<hello.c>
*/
import "C"
import "fmt"
func main() {
	fmt.Println("You are inside Go file")
	C.print_hello()
}
white_tick
eyes
raised_hands







#include <iostream>
#ifndef AXES
	#define AXES 0
	#include "Axis/Axis.h"
#endif
#include "FilePrinter/FilePrinter.h"

int main(int argc,char **argv){
	//TODO Arg parser object or function or WE
	char file_name[]="function";
	Axis ax(-1*3.141592,2*3.141592,3.141593/10,-20,10,1);
	Printer pr(file_name,ax);
	cout << "Hello World!\n";
	return 0;
}

#include <iostream>
#ifndef AXES
	#define AXES 0
	#include "Axes/Axes.h"
#endif
#include "FilePrinter/FilePrinter.h"

int main(int argc,char **argv){
	//TODO Arg parser object or function or WE
	char file_name[]="function";
	Axes ax;
	Printer pr(file_name,ax);
	cout << "Hello World!\n";
	return 0;
}

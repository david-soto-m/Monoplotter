#include <iostream>
#ifndef AXES
	#define AXES 0
	#include "Axis/Axis.h"
#endif
#define _USE_MATH_DEFINES
#include "FilePrinter/FilePrinter.h"
#include <cmath>
int main(int argc,char **argv){
	//TODO Arg parser object or function or WE
	char file_name[]="function";
	Axis ax(-10,10,0.1,-10,10,0.1);
	Axis theta('a',0,2*M_PI,M_PI/100);
	Printer pr(file_name,ax,theta);
	pr.print_function();
	cout << "Hello World!\n";
	return 0;
}

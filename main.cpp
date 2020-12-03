#include <iostream>
#include "FilePrinter/FilePrinter.h"
int main(int argc,char **argv){
	//TODO Arg parser object or function or WE
	char file_name[]="Function";
	Printer pr(file_name,10,10);
	double **a;
	pr.print_function(a);
	cout << "Hello World!\n";
	return 0;
}

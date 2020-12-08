#include <iostream>
#ifndef AXES
	#define AXES 0
	#include "Axis/Axis.h"
#endif
#include "FilePrinter/FilePrinter.h"
#include "Parser/Parser.h"

using namespace std;
int main(int argc,char **argv){
	Axis ax,theta;
	char file_name[100]="hola";
	
	Printer pr(file_name,ax,theta);
	pr.print_function();
	cout << "Hello World!\n";
	return 0;
}

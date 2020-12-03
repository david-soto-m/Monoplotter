#include "FilePrinter.h"
using namespace std;
Printer::Printer(char *file,int width,int height):width(width),height(height){
	this->file.open(file,ios::out);
	
	print_base();
}
Printer::~Printer(){
	file.close();
}


void Printer::print_base(){
	
}

void Printer::print_function(double **list){
	//TODO in the end this wil recieve a function object which will be passed the axes object
}

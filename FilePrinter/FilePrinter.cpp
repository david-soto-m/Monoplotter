#include "FilePrinter.h"
using namespace std;
Printer::Printer(char *file,int width,int height):width(width),height(height){
	this->file.open(file,ios::out);
	
	print_base();
}
Printer::~Printer(){
	file.close();
}

void translator(){
	//TODO This function should be ready to change from function evaluated pairs of values to the character number where you should print the token
}

void Printer::print_base(){
	//TODO this should paint the axes on the file and generally prepare the file
}

void Printer::print_function(double **list){
	//TODO in the future this wil recieve a function object which will be passed the axes object
}

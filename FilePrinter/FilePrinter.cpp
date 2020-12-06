#include "FilePrinter.h"
#include <cstring>
#include <iostream>

using namespace std;
//Constructors
Printer::Printer(char *file,Axis ax){
	name=new char[strlen(file)];strcpy(name,file);
	this->file.open(name,ios::out|ios::trunc);
	//For portability issues we are not going to use a file for anything else than
	//a function. Windows doesnt have a way to know the position of a character in
	//a file that doesnt involve too much fuzz
	this->ax=ax;
	
	print_base();
}
Printer::~Printer(){
	file.close();
}

//Main functions
void Printer::print_base(){
	//TODO this should paint the axes on the file and generally prepare the file
	for(int i=0;i<ax.height();i++){
		for(int j=0; j<ax.width();j++){
			bool x_ax=ax.step_x(i),y_ax=ax.step_y(j);//Evaluate once (DRY?)
			if (x_ax&&y_ax){
				file<<"+";
			}else if(x_ax){
				file<<"-";
			}else if(y_ax){
				file<<"|";
			}else{
				file<<" ";
			}
		}
		file<<"\n";
	}
	file<<"width: "<<ax.width()<<"; height: "<<ax.height()<<"\n";
	file<<"x_max: "<<ax.get_x_max()<<"; x_min: "<<ax.get_x_min()
	<<"; x_step: "<<ax.get_x_step()<<"\n";
	file<<"y_max: "<<ax.get_y_max()<<"; y_min: "<<ax.get_y_min()
	<<"; y_step: "<<ax.get_y_step()<<"\n";
}

void Printer::print_function(double **list){
	//TODO in the future this wil recieve a function object which will be passed the
	//axes object
}

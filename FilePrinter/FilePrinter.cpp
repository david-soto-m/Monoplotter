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
	
	ax.validate();
	width=ax.width();
	height=ax.height();
	
	print_base();
}
Printer::~Printer(){
	file.close();
}

//Printing auxiliary functions
bool Printer::axis_x(int i){
	if ( ax.x_max-(i-1)*ax.x_step>0 && ax.y_max-(i+1)*ax.x_step<0)
		return true;
	return false;
}

bool Printer::axis_y(int j){
	if ( (j-1)*ax.y_step+ax.y_min<0 && (j+1)*ax.y_step+ax.y_min>0)
		return true;
	return false;
}

void translator(){
	/*TODO This function should be ready to change from function evaluated pairs of
	 values to the character number where you should print the token*/
}

//Main functions
void Printer::print_base(){
	//TODO this should paint the axes on the file and generally prepare the file
	for(int i=0;i<width;i++){
		for(int j=0; j<height;j++){
			bool x_ax=axis_x(i),y_ax=axis_y(j);//Evaluate once (DRY?)
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
	file<<"width: "<<width<<"; height: "<<height<<"\n";
	file<<"x_max: "<<ax.x_max<<"; x_min: "<<ax.x_min<<"; x_step: "<<ax.x_step<<"\n";
	file<<"y_max: "<<ax.x_max<<"; y_min: "<<ax.x_min<<"; y_step: "<<ax.x_step<<"\n";
}

void Printer::print_function(double **list){
	//TODO in the future this wil recieve a function object which will be passed the
	//axes object
}

#include <cmath>
#include "Axis.h"
#include <iostream>
Axis::Axis(double x_min, double x_max, double x_step,
		   double y_min, double y_max, double y_step)
		   :x_min(x_min),x_max(x_max),x_step(x_step),
		   y_min(y_min),y_max(y_max),y_step(y_step){
	validate();
}

Axis::Axis(char dis,double x_min, double x_max, double x_step)
	:x_min(x_min),x_max(x_max),x_step(x_step){
	}
//Doesn't validate to give chance of imposible values

double Axis::get_x_min(){return x_min;}
double Axis::get_x_max(){return x_max;}
double Axis::get_x_step(){return x_step;}
double Axis::get_y_min(){return y_min;}
double Axis::get_y_max(){return y_max;}
double Axis::get_y_step(){return y_step;}

void Axis::set_x_min(double x){x_min=x;}
void Axis::set_x_max(double x){x_max=x;}
void Axis::set_x_step(double x){x_step=x;validate_x();}
void Axis::set_y_min(double y){y_min=y;}
void Axis::set_y_max(double y){y_max=y;}
void Axis::set_y_step(double y){y_step=y;validate_y();}

void Axis::validate_x(){
	if (x_min>x_max){
		double aux=x_max;
		x_max=x_min;
		x_min=aux;
	}
	if(x_step<=0||x_step>(x_max-x_min)){
		x_step=(x_max-x_min)/10;
	}
	if (round((x_max-x_min)/x_step)!=(x_max-x_min)/x_step){
		x_step=(x_max-x_min)/ceil((x_max-x_min)/x_step);
	}
}
void Axis::validate_y(){
	if (y_min>y_max){
		double aux=y_max;
		y_max=y_min;
		y_min=aux;
	}
	if(y_step<=0||y_step>(y_max-y_min)){
		y_step=(y_max-y_min)/10;
	}
	if (round((y_max-y_min)/y_step)!=(y_max-y_min)/y_step){
		y_step=(y_max-y_min)/ceil((y_max-y_min)/y_step);
	}
}
void Axis::validate(){validate_x();validate_y();}

int Axis::width(){return (x_max-x_min)/x_step+1;}
int Axis::height(){return (y_max-y_min)/y_step+1;}

bool Axis::step_on_x(int i){
	return (y_max-(i-1)*y_step>0 && y_max-(i+1)*y_step<0)?true:false;
}
bool Axis::step_on_y(int j){
	return ((j-1)*x_step+x_min<0 && (j+1)*x_step+x_min>0)?true:false;
}

int Axis::translator(double x,double y){
	std::cout<<x<<", "<<y<<"\n";
	int w=width(),h=height();
	int i=round((y_max-y)/y_step);
	int j=round((x-x_min)/x_step);
	if (i<0){i=0;}
	if (i>h){i=h-1;}
	if (j<0){j=0;}
	if (j>w){i=w;}
	return i*(w+1)+j; //The +1 is for newline characters
}

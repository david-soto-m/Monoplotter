#include <cmath>
#include "Axis.h"
#include <iostream>
Axis::Axis(double x_min, double x_max, double x_step,
		   double y_min, double y_max, double y_step)
		   :x_min(x_min),x_max(x_max),x_step(x_step),
		   y_min(y_min),y_max(y_max),y_step(y_step){
			validate();
		}
void Axis::validate(){
	if (x_min>x_max){
		double aux=x_max;
		x_max=x_min;
		x_min=aux;
	}
	if (y_min>y_max){
		double aux=y_max;
		y_max=y_min;
		y_min=aux;
	}
	if(x_step<0||x_step>(x_max-x_min)){
		x_step=(x_max-x_min)/10;
	}
	if(y_step<0||y_step>(y_max-y_min)){
		y_step=(y_max-y_min)/10;
	}
	if (round((x_max-x_min)/x_step)!=(x_max-x_min)/x_step){
		x_step=(x_max-x_min)/ceil((x_max-x_min)/x_step);
	}
	if (round((y_max-y_min)/y_step)!=(y_max-y_min)/y_step){
		y_step=(y_max-y_min)/ceil((y_max-y_min)/y_step);
	}
}
int Axis::width(){
	return (x_max-x_min)/x_step+1;
}
int Axis::height(){
	return (y_max-y_min)/y_step+1;
}

//Printing auxiliary functions
bool Axis::step_x(int i){
	if ( y_max-(i-1)*y_step>0 && y_max-(i+1)*y_step<0)
		return true;
	return false;
}

bool Axis::step_y(int j){
	if ( (j-1)*x_step+x_min<0 && (j+1)*x_step+x_min>0)
		return true;
	return false;
}

int Axis::translator(double x,double y){
	int i=round((y_max-y)/y_step);
	int j=round((x-x_min)/x_step);
	return i*width()+j;
}

double Axis::get_x_min(){
	return x_min;
}
double Axis::get_x_max(){
	return x_max;
}
double Axis::get_x_step(){
	return x_step;
}
double Axis::get_y_min(){
	return y_min;
}
double Axis::get_y_max(){
	return y_max;
}
double Axis::get_y_step(){
	return y_step;
}

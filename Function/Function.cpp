#include "Function.h"
#include <cmath>
#include <iostream>

PureFunct::~PureFunct(){
	secure=false;
	for(int i=0;i<length;i++)
		delete [] pointlist[i];
	delete [] pointlist;
}

void PureFunct::space_x(Axis ax){
	length=ax.width();
	pointlist = new double*[length];
	for (int i=0; i<length;i++){
		pointlist[i]=new double[2];
	}
	double x=ax.get_x_min();
	for(int i=0;i<length;i++){
		pointlist[i][0]=x;
		x+=ax.get_x_step();
	}
	secure=true;
}

void PureFunct::space_y(Axis ax){
	length=ax.height();
	pointlist = new double*[length];
	for (int i=0; i<length;i++){
		pointlist[i]=new double[2];
	}
	double y=ax.get_y_min();
	for(int i=0; i<length;i++){
		pointlist[i][0]=y;
		y+=ax.get_y_step();
	}
	secure=true;
}

void PureFunct::polar_to_cartesian(){
	if (secure==false)
		return;
	for(int i=0;i<length;i++) {
		double aux[2];
		aux[0]=pointlist[i][1]*cos(pointlist[i][0]);
		aux[1]=pointlist[i][1]*sin(pointlist[i][0]);
		pointlist[i][0]=aux[0];
		pointlist[i][1]=aux[1];
	}
}

void Function::eval(Axis ax,Axis ax_theta){
	space_x(ax_theta);
	
	double x,y,theta;
// 	x=ax.get_x_min();
// 	for(int i=0;i<length;i++){
// 		pointlist[i][1]=sin(x);
// 		x+=ax.get_x_step();
// 	}
	theta=ax_theta.get_x_min();
	for(int i=0;i<length;i++){
		pointlist[i][1]=theta;
		theta+=ax_theta.get_x_step();
	}
	polar_to_cartesian();
}

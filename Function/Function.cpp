#include "Function.h"
#include <cmath>
#include <iostream>
void Function::eval(Axis ax,Axis ax_theta){
// 	space_x(ax);
// 	double x;
// 	for(int i=0;i<length;i++){
// 		x=pointlist[i][0];
// 		pointlist[i][1]=1/(x);
// 	}

// 	space_y(ax);
// 	double y;
// 	for(int i=0;i<length;i++){
// 		y=pointlist[i][1];
// 		pointlist[i][0]=pow(y,2);
// 	}
	
// 	space_x(ax_theta);
// 	double theta;
// 	for(int i=0;i<length;i++){
// 		theta=pointlist[i][0];
// 		pointlist[i][1]=2*(1-cos(theta));
// 	}
// 	polar_to_cartesian();
	
	space_xy(ax);
	double x=ax.get_x_min(),y;
	for(int i=0;i<ax.width();i++){
		y=ax.get_y_min();
		for(int j=0;j<ax.height();j++){
			if (pow(x,2)+pow(y,2)>24&&pow(x,2)+pow(y,2)<26){
				pointlist[i*ax.width()+j][0]=x;
				pointlist[i*ax.width()+j][1]=y;
			}
			y+=ax.get_y_step();
		}
		std::cout<<x<<","<<y<<"\n";
		x+=ax.get_x_step();
	}
}

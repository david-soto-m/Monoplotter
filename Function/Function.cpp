#include "Function.h"
#include <cmath>
void Function::eval(Axis ax,Axis ax_theta){
	space_x(ax);
	double x;
	x=ax.get_x_min();
	for(int i=0;i<length;i++){
		pointlist[i][1]=-(sin(x)+pow(x,2));
		x+=ax.get_x_step();
	}
// 	space_x(ax_theta);
// 	double theta;
// 	theta=ax_theta.get_x_min();
// 	for(int i=0;i<length;i++){
// 		pointlist[i][1]=theta;
// 		theta+=ax_theta.get_x_step();
// 	}
// 	polar_to_cartesian();
}

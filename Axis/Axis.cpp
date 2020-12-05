#include "Axis.h"
Axis::Axis(double x_min, double x_max, double x_step,
		   double y_min, double y_max, double y_step)
		   :x_min(x_min),x_max(x_max),x_step(x_step),
		   y_min(y_min),y_max(y_max),y_step(y_step){}
void Axis::validate(){
	
}
int Axis::width(){
	return (x_max-x_min)/x_step+1;
}
int Axis::height(){
	return (y_max-y_min)/y_step+1;
}

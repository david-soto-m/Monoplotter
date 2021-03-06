#ifndef AXES
	#define AXES 0
	#include "../Axis/Axis.h"
#endif
class PureFunct{
	public:
// 		PureFunct();
		~PureFunct();
		bool secure=false;
		double **pointlist;
		int length;
		void space_x(Axis ax);
		void space_y(Axis ax);
		void space_xy(Axis ax);
		void polar_to_cartesian();
};
class Function:public PureFunct{
	public:
		void eval (Axis ax, Axis theta);
};

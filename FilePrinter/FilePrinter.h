#ifndef STREAM
	#define STREAM 0
	#include <fstream>
#endif
#ifndef AXES
	#define AXES 0
	#include "../Axis/Axis.h"
#endif
using namespace std;

class Printer{
	
	private:
		fstream file;
		Axis ax;
		
		int width, height;
		int *buffer;
		char *name;
		
		void translator();
		bool axis_x(int i);
		bool axis_y(int j);
		
		
	public:
		Printer(char *file,Axis ax);
		~Printer();
		void print_base();
		void print_function(double **list);
};

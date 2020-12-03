#ifndef STREAM
	#define STREAM 0
	#include <fstream>
#endif
using namespace std;

class Printer{
	typedef struct {
		int x_min=0,x_max=10,x_step=1,y_min=0,y_max=10,y_step=1;
	} axes;
	private:
		fstream file;
		int width, height;
		int *buffer;
		axes ax;
		void translator(double **list_orig,double **list,int width);
	public:
		Printer(char *file,int width=11,int height=11);
		~Printer();
		void print_base();
		void print_function(double **list);
};

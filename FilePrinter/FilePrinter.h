#ifndef STREAM
	#define STREAM 0
	#include <fstream>
#endif
using namespace std;

class Printer{
	typedef struct {
		int x_min=0,x_max=10,y_min=0,y_max=10;
	} axes;
	private:
		fstream file;
		int width, height;
		axes ax;
		void translator(double **list_orig,double **list,int width);
	public:
		Printer(char *file,int width,int height);
		~Printer();
		void print_base();
		void print_function(double **list);
};

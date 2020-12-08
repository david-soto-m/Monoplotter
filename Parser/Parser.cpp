#include "Parser.h"
#define _USE_MATH_DEFINES
#include <cstring>
#include <cmath>

void Parse(int argc,char **argv,Axis &ax,Axis &theta,char filename[100]){
	Axis ax1(-10,10,0.1,-10,10,0.1);
	Axis theta1('a',-1,-1,0);
	for (int i=1;i<argc;i++){
		char *word=argv[i];
	}
	ax=ax1;
	theta=theta1;
}

#include "Parser.h"
#include <cstring>
#include <iostream>

void Parse(int argc,char **argv,Axis &ax,Axis &theta,char filename[100]){
	Axis ax1(-10,10,0.1,-10,10,0.1);
	Axis theta1('a',0,6.283185307,0.01);
	strcpy(filename,"function");
	for (int i=1;i<argc;i++){
		char *word=argv[i];
		if (strcmp(word,"x")==0||strcmp(word,"y")==0||strcmp(word,"ax")==0||strcmp(word,"theta")==0){
			Axis ax2=strcmp(word,"theta")==0?theta1:ax1;
			char *end=0;
			int lim=strcmp(word,"ax")==0?6:3;
			bool flag=true;
			int j=1;
			while (flag&&j<=lim&&i+j<argc){
				char* number=argv[i+j];
				double num=std::strtod(number,&end);
				if (*end=='\0'&&!(end==number)){
					switch (j+(strcmp(word,"y")==0)*3){
						case 1:
							ax2.set_x_min(num);
							break;
						case 2:
							ax2.set_x_max(num);
							break;
						case 3:
							ax2.set_x_step(num);
							break;
						case 4:
							ax2.set_y_min(num);
							break;
						case 5:
							ax2.set_y_max(num);
							break;
						case 6:
							ax2.set_y_step(num);
							break;
					}
					j++;
				}else{
					flag=false;
				}
			}
			ax2.validate();
			i+=j-1;
			if(strcmp(word,"x")==0||strcmp(word,"y")==0||strcmp(word,"ax")==0){
				ax1=ax2;
			}else{
				theta1=ax2;
			}
		}
		if (strcmp(word, "-f")==0&&i+1<argc){
			strcpy(filename,argv[i+1]);
			i++;
		}
	}
	ax=ax1;
	theta=theta1;
}

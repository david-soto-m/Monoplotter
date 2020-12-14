#include "Parser.h"
#define _USE_MATH_DEFINES
#include <cstring>
#include <iostream>

void Parse(int argc,char **argv,Axis &ax,Axis &theta,char filename[100]){
	Axis ax1(-10,10,0.1,-10,10,0.1);
	Axis theta1('a',0,6.283185307,0.01);
	strcpy(filename,"function");
	for (int i=1;i<argc;i++){
		char *word=argv[i];
		if (strcmp(word,"x")==0){
			char *end=0;
			int j=1;
			bool flag=true;
			while (flag&&j<=3&& i+j<argc){
				char* number=argv[i+j];
				double num=std::strtod(number,&end);
				if (*end=='\0'){
					switch (j){
						case 1:
							ax1.set_x_min(num);
							break;
						case 2:
							ax1.set_x_max(num);
							break;
						case 3:
							ax1.set_x_step(num);
							break;
					}
				}else{
					flag=false;
				}
				j++;
			}
			ax1.validate_x();
			i+=j-1;
		}
		if (strcmp(word,"y")==0){
			char *end=0;
			int j=1;
			bool flag=true;
			while (flag&&j<=3&& i+j<argc){
				char* number=argv[i+j];
				double num=std::strtod(number,&end);
				if (*end=='\0'){
					switch (j){
						case 1:
							ax1.set_y_min(num);
							break;
						case 2:
							ax1.set_y_max(num);
							break;
						case 3:
							ax1.set_y_step(num);
							break;
					}
				}else{
					flag=false;
				}
				j++;
			}
			ax1.validate_y();
			i+=j-1;
		}
		if (strcmp(word,"ax")==0){
			char *end=0;
			int j=1;
			bool flag=true;
			while (flag&&j<=6&& i+j<argc){
				char* number=argv[i+j];
				double num=std::strtod(number,&end);
				if (*end=='\0'&&!(end==number)){
					switch (j){
						case 1:
							ax1.set_x_min(num);
							break;
						case 2:
							ax1.set_x_max(num);
							break;
						case 3:
							ax1.set_x_step(num);
							break;
						case 4:
							ax1.set_y_min(num);
							break;
						case 5:
							ax1.set_y_max(num);
							break;
						case 6:
							ax1.set_y_step(num);
							break;
					}
				}else{
					flag=false;
				}
				j++;
			}
			ax1.validate();
			i+=j-1;
		}
		if (strcmp(word,"theta")==0){
			char *end=0;
			int j=1;
			bool flag=true;
			while (flag&&j<=3&& i+j<argc){
				char* number=argv[i+j];
				double num=std::strtod(number,&end);
				if (*end=='\0'){
					switch (j){
						case 1:
							theta1.set_x_min(num);
							break;
						case 2:
							theta1.set_x_max(num);
							break;
						case 3:
							theta1.set_x_step(num);
							break;
					}
				}else{
					flag=false;
				}
				j++;
			}
			ax1.validate_x();
			i+=j-1;
		}
		if (strcmp(word, "-f")==0&&i+1<argc){
			strcpy(filename,argv[i+1]);
			i++;
		}
	}
	ax=ax1;
	theta=theta1;
}

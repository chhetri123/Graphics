#include <iostream>
#include <cmath>
#include<string.h>
#include "Transformation.h"
#define SIN(x) sin(x * 3.141592653589 / 180)
#define COS(x) cos(x * 3.141592653589 / 180)
using namespace std;
void Rotation(float x[],float y[],int size,float angle,const std::string& rotation_name){
	Plot(x,y,size,3);
		float xc=0,yc=0;
	if(rotation_name=="centroid"){	;
		for(int i=0;i<size;i++){
		xc+=x[i];
		yc+=y[i];
		
	}
	xc=xc/size;
	yc=yc/size;
	}
	

	
	float x_s ,y_s;
	for(int i=0;i<size;i++){
		x_s=x[i]-xc;
		y_s=y[i]-yc;
 	x[i] = xc + (x_s * COS(angle)) - (y_s * SIN(angle));
    y[i] = yc + (x_s * SIN(angle)) + (y_s * COS(angle));
		
}
Plot(x,y,size);
}

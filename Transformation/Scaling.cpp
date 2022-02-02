#include<iostream>
#include<math.h>
#include "Transformation.h"
using namespace std;

void Scaling(float x[], float y[],int size,float sk[],const std::string& scale_from){
		Plot(x,y,size,3);
	float xc=0;float yc =0;
	if(scale_from=="centroid"){
		for(int i=0;i<size;i++){
		xc+=x[i];
		yc+=y[i];
		
	}
	xc=xc/size;
	yc=yc/size;
	}
	
	float x_s , y_s ;
	for(int i=0;i<size;i++){
		x_s=x[i]-xc;
		y_s=y[i]-yc;
	x[i]=xc+x_s*sk[0];
	y[i]=yc+y_s*sk[1];

	}
	Plot(x,y,size);
}

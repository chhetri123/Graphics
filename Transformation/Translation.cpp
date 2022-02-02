#include <iostream>
#include<math.h>
#include<graphics.h>
#include "Transformation.h"
using namespace std;


void Translation (float x[],float y[],int size,float t[]){
Plot(x,y,size,3);
	for(int i;i<size;i++){
		x[i]=x[i]+t[0];
		y[i]=y[i]+t[1];
	}

	Plot(x,y,size);
	
}

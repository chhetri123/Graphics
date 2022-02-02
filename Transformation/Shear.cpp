#include<iostream>
#include "transformation.h"
using namespace std;
void Shear(float x[],float y[],int size,float ref[],float sh[]){
	 Plot(x,y,size,3);
	if(ref[1]){
	for(int i=0;i<size;i++){
	x[i]=x[i]+sh[0]*(y[i]-ref[1]);
	}
	}else if(ref[0]){
	for(int i=0;i<size;i++)	
			y[i]=y[i]+sh[1]*(x[i]-ref[0]);
	}

Plot(x,y,size);
}

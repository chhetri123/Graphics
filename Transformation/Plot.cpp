
#include <iostream>
#include<graphics.h>
#include <cmath>
#include <stdlib.h>
#include<string.h>
using namespace std;

void WriteInColor(unsigned short color, string outputString)
{
   HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hcon, color);
   cout << outputString<<endl;
}


void Plot(float x[], float y[],int size,int color)
{	
if(color==4) {
WriteInColor(4, "---------------Final coordinates------------------");
}
if(color==3) {
WriteInColor(3,"---------------Initial Coordinates----------------");
}
	for(int i=0;i<size;i++){
	
	cout<<x[i]<<" "<<y[i]<<endl;
	
	setcolor(color);
	delay(1);
	if(i==size-1){
		line(round(x[i]),round(y[i]),round(x[0]),round(y[0]));
		break;
	}
	line(round(x[i]),round(y[i]),round(x[i+1]),round(y[i+1]));
	}
  
}

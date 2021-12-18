#include<graphics.h>
#include<math.h>
#include<conio.h>
#include <dos.h>
#include<iostream>
#include <iomanip>
using namespace std;

void calculation(float x1,float y1,float x2,float y2 );
void display(int k,float x1,float x2);
void takeData();


void calculation(float x1,float y1,float x2,float y2){
	int step;
	float x,y;
	float dx,dy;
	dx=x2-x1;
    dy=y2-y1;
	
	if(abs(dx)>abs(dy)){ //  slope is less than 1 
	step=abs(dx);
		
	}else{
	step=abs(dy);
	}
	
x=dx/step;
y=dy/step;


display(1,x1,y1);
for (int i=0 ; i< (int) step; i++){

	x1=x1+x;
	y1=y1+y;
	delay(50);
	display(i+2,x1,y1);
	
}
};
void display(int k,float x1,float y1){
	putpixel(round(x1),round(y1),RED);
cout <<setw(5) << "|"<<setw(10) << k << "|  ("<<round(x1) << ","<<round(y1)  << ")  |" << endl;
    
};
void takeData(){
	float x1,y1, x2,y2 ;
	cout<<"Enter the Coordinates to draw Line :"<<endl;
	cout <<"Enter( x1, y1): ";
	cin>>x1>> y1;
	cout <<endl<<"Enter (x2,y2): ";
	cin >>x2>>y2;
cout<<"-------------------------------------"<<endl;
cout << left << setw(20)<< "No. of Steps" << "Point" << endl;
cout<<"-------------------------------------"<<endl;
	calculation(x1,y1,x2,y2);
	
			
};


int main(){
	
	int gd=DETECT ,gm,i;
initgraph(&gd,&gm,"chhetri");
//calculation(60,70,200,200);
	takeData();		
getch();
closegraph();
return 0;

}
